// 2. Write a program to find primitive elements in GF(2^n). A primitive element is a generator of the field.
// Take n=3 and IRP as (x^3+x^2+1)

#include <iostream>
#include <vector>
using namespace std;

// Define the field size (2^n)
const int n = 3;

// Function to perform modular exponentiation in GF(2^n)
  int
gfPow (int base, int exponent, int prime)
{
  
int result = 1;
  
while (exponent > 0)
    {
      
if (exponent % 2 == 1)
	{
	  
result = (result * base) % prime;
	
}
      
base = (base * base) % prime;
      
exponent /= 2;
    
}
  
return result;

}


// Function to find primitive elements in GF(2^n)
  void
findPrimitiveElements ()
{
  
int prime = (1 << n) - 1;	// Prime number for GF(2^n)
  vector < int >primitiveElements;
  
for (int x = 2; x < prime; x++)
    {
      
bool isPrimitive = true;
      
for (int i = 1; i <= prime - 2; i++)
	{
	  
int power = gfPow (x, i, prime);
	  
if (power == 1)
	    {
	      
isPrimitive = false;
	      
break;
	    
}
	
}
      
if (isPrimitive)
	{
	  
primitiveElements.push_back (x);
	
}
    
}
  
cout << "Primitive elements in GF(2^" << n << "): ";

for (int element:primitiveElements)
    {
      
cout << element << " ";
    
} 
cout << endl;

} 
int

main ()
{
  
findPrimitiveElements ();
  
return 0;

}


