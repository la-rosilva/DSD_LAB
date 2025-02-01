#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}


void reverse(int arr[], int start, int end){
	while(start<end){
		swap(&arr[start],&arr[end]);
		start++;
		end--;
	}
}

int nextPermutation(int arr[],int n){
	int k,l;
	k=-1;
	for(int i=n-2;i>=0;i--){
		if(arr[i]<arr[i+1]){
			k=i;
			break;
		}
	}
	if(k==-1){
		return 0;
	}

	for(l=n-1; l>k;l--){
		if(arr[l]>arr[k]){
			
			break;
		}

	}
	swap(&arr[l],&arr[k]);
	
	reverse(arr, k+1,n-1);
	return 1;





}

int calculateCost(int **costMatrix,int *perm,int n){
	int cost=0;
	for(int i=0; i<n;i++){
		cost+=costMatrix[i][perm[i]];
	}
	return cost;





}


void solveAssignmentProblem(int n, int **costMatrix){
	int *perm=malloc(n*sizeof(int));
	int bestperm[n];
	int mincost=INT_MAX;
	for(int i=0; i<n;i++){
		perm[i]=i;
	}
	do{

	int cost=calculateCost(costMatrix,perm,n);
	if(cost<mincost){
		mincost=cost;
		for(int i=0; i<n;i++){
			bestperm[i]=perm[i];
		}
	}
}while(nextPermutation(perm,n));

printf("The best permutation is: ");
for(int i=0; i<n;i++){
	printf("%d ",bestperm[i]);
}

printf("\nThe minimum cost is:%d",mincost);













}




int main(){
	int n;
	printf("Enter the number of people: ");
	scanf("%d",&n);

	int **arr = malloc(n * sizeof(int *));  // Allocate memory for 'n' rows
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(n * sizeof(int));  // Allocate memory for 'n' columns in each row
    }

    // Input elements into the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the matrix
    printf("The matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

	solveAssignmentProblem(n,arr);




}
