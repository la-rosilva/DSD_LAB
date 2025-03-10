import React from 'react';
import { Link } from 'react-router-dom'; // Import Link for routing
import logo from '../assets/icon.png';

const Navbar = () => {
  return (
    <div className='flex justify-between items-center px-4 mx-10 bg-transparent'>
      {/* <div>logo</div> */}
      <div className='flex gap-2 translate-y-2 -translate-x-10'>
 <img src={logo} className='w-12 h-12'/>
  <h6 className='text-pink-800 text-lg font-bold py-3'>CareConnect</h6>
  </div>    
<button class="learn-more">
  <span class="circle -translate-x-18" aria-hidden="true">
  <span class="icon arrow"></span>
  </span>
  <span class="button-text -translate-x-20">Join as a caretaker</span>
</button>
  
   <div className='flex glass py-3 my-3 rounded-full -translate-x-25'>
        <Link to="/" className='px-10 text-pink-800 font-semibold text-md hover:text-pink-900 transition-all duration-400'>Home</Link>
        <Link to="/caregivers" className='px-10 text-pink-800 font-semibold text-md hover:text-pink-900 transition-all duration-400'>Find a caregiver</Link>
        <Link to="/about" className='px-10 text-pink-800 font-semibold text-md hover:text-pink-900 transition-all duration-400'>About Us</Link>
        <Link to="/contact" className='px-10 text-pink-800 font-semibold text-md hover:text-pink-900 transition-all duration-400'>Contact Us</Link>
      </div>
  
   
    <div className='flex space-x-4'>
    <button 
  style={{
    background: '#9D174D', 
    color: 'white', 
    padding: '10px 20px', // 10px vertical (y), 20px horizontal (x)
    borderRadius: '6px', 
    transition: 'background-color 0.3s ease-in-out'
  }}
  onMouseEnter={(e) => e.target.style.background = '#831843'} // Darker pink on hover
  onMouseLeave={(e) => e.target.style.background = '#9D174D'} // Original color on mouse leave
>
  Log in
</button>

<button 
  style={{
    background: 'transparent', 
    padding: '8px 16px', 
    borderRadius: '6px', 
    border: '2px solid #9D174D', 
    color: '#9D174D', 
    transition: 'all 0.3s ease-in-out'
  }}
  onMouseEnter={(e) => {
    e.target.style.borderColor = '#831843'; // Darker pink border on hover
    e.target.style.color = '#831843'; // Darker text color on hover
  }}
  onMouseLeave={(e) => {
    e.target.style.borderColor = '#9D174D'; // Restore original color
    e.target.style.color = '#9D174D';
  }}
>
  Sign up
</button>

    </div>
  </div>
  
    
  )
}

export default Navbar


