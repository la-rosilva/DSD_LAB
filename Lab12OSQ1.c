#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>

void print_permissions(mode_t mode){
	char perms[11]="----------";
	if(S_ISREG(mode)){
	perms[0]='-';
	}else if(S_ISDIR(mode)){
	perms[0]='d';}
	else if(S_ISLNK(mode)){
	perms[0]='l';
	}else if(S_ISCHR(mode)){
	perms[0]='c';
	}else if(S_ISBLK(mode)){
	perms[0]='b';
	}else if(S_ISFIFO(mode)){
	perms[0]='p';
	}else if(S_ISSOCK(mode)){
	perms[0]='s';
	}
	
	if(mode & S_IRUSR){
	perms[1]='r';
	}
	if(mode & S_IWUSR){
	perms[2]='w';
	}
	if(mode & S_IXUSR){
	perms[3]='x';
	}
	
	if(mode & S_IRGRP){
	perms[4]='r';
	}
	if(mode & S_IWGRP){
	perms[5]='w';
	}
	if(mode & S_IXGRP){
	perms[6]='x';
	}
	
	if(mode & S_IROTH){
	perms[7]='r';
	}
	if(mode & S_IWOTH){
	perms[8]='w';
	}
	if(mode & S_IXOTH){
	perms[9]='x';
	}
	printf("%s ", perms);
}

int main(){
	DIR *dp=opendir(".");
	struct dirent *entry;
	struct stat statbuf;
	struct passwd *pwd;
	struct group *grp;
	char timebuf[80];
	unsigned long long totalBlocks=0;

	if(dp==NULL){
	perror("Failed to open cyurrent directory");
	return 1;
	}
	
	while((entry=readdir(dp))!=NULL){
		if(lstat (entry->d_name, &statbuf)==-1){
		perror("lstat error");
		continue;
		}
		totalBlocks+=statbuf.st_blocks;
		}
		printf("total %llu\n", totalBlocks/2);
		rewinddir(dp);
		while((entry=readdir(dp))!=NULL){
		if(lstat(entry->d_name, &statbuf)==-1){
		perror("lstat error");
		continue;
		}
		
		print_permissions(statbuf.st_mode);
		 printf("%lu", (unsigned long)statbuf.st_nlink);
		 
		 pwd=getpwuid(statbuf.st_uid);
		 printf("%s", pwd? pwd->pw_name:"unknown");
		 
		 grp=getgrgid(statbuf.st_gid);
		 printf("%s ", grp ? grp->gr_name: "unknown");
		 printf("%5lld", (long long)statbuf.st_size);
		 
		 strftime(timebuf, sizeof(timebuf),"%b %d %H:%M", localtime(&statbuf.st_mtime));
		 printf("%s ", timebuf);
		 printf("%s\n", entry->d_name);
		 
		 printf("%s\n", entry->d_name);
		 }
		 closedir(dp);
		 return 0;
		 }
		 
	
	


