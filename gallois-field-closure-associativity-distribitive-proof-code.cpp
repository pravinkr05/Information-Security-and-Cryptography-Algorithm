// 1. Implement modular addition and multiplication in GF(2^n).
// Verify that these operations obey the properties of a finite field, such as closure, associativity, and
// distributivity.

#include <iostream>
#include <vector>
using namespace std;

// Define the field size (2^n)
const int n = 4;

// Define the irreducible polynomial (used for modulo operation)
const int irreduciblePoly = 0 b10011;	// x^4 + x + 1
// Function to perform modular addition in GF(2^n)
int
gfAdd (int a, int b)
{
  
return a ^ b;		// XOR operation
}


// Function to perform modular multiplication in GF(2^n)
  int
gfMultiply (int a, int b)
{
  
int result = 0;
  
while (b > 0)
    {
      
if (b & 1)		// If the least significant bit of b is 1
	result ^= a;		// Add a to the result using XOR
      a <<= 1;			// Left-shift a
      if (a & (1 << n))		// If a has a term greater than x^n, reduce it using the irreducible polynomial
	a ^= irreduciblePoly;
      
b >>= 1;			// Right-shift b
    }
  
return result;

}


int
main ()
{
  
cout << "Finite Field GF(2^" << n << ") Operations:" << endl;
  
// Verify closure (addition)
    for (int i = 0; i < (1 << n); i++)
    {
      
for (int j = 0; j < (1 << n); j++)
	{
	  
int result = gfAdd (i, j);
	  
if (result < 0 || result >= (1 << n))
	    {
	      
cout << "Addition does not satisfy closure property!" << endl;
	      
return 1;
	    
}
	
}
    
}
  
// Verify closure (multiplication)
    for (int i = 0; i < (1 << n); i++)
    {
      
for (int j = 0; j < (1 << n); j++)
	{
	  
int result = gfMultiply (i, j);
	  
if (result < 0 || result >= (1 << n))
	    {
	      
cout << "Multiplication does not satisfy closure property!" <<
		endl;
	      
return 1;
	    
}
	
}
    
}
  
// Verify associativity (addition)
    for (int i = 0; i < (1 << n); i++)
    {
      
for (int j = 0; j < (1 << n); j++)
	{
	  
for (int k = 0; k < (1 << n); k++)
	    {
	      
if (gfAdd (i, gfAdd (j, k)) != gfAdd (gfAdd (i, j), k))
		{
		  
cout << "Addition does not satisfy associativity property!"
		    << endl;
		  
return 1;
		
}
	    
}
	
}
    
}
  
// Verify associativity (multiplication)
    for (int i = 0; i < (1 << n); i++)
    {
      
for (int j = 0; j < (1 << n); j++)
	{
	  
for (int k = 0; k < (1 << n); k++)
	    {
	      
if (gfMultiply (i, gfMultiply (j, k)) !=
		   gfMultiply (gfMultiply (i, j), k))
		{
		  
cout <<
		    "Multiplication does not satisfy associativity property!"
		    << endl;
		  
return 1;
		
}
	    
}
	
}
    
}
  
// Verify distributivity
    for (int i = 0; i < (1 << n); i++)
    {
      
for (int j = 0; j < (1 << n); j++)
	{
	  
for (int k = 0; k < (1 << n); k++)
	    {
	      
if (gfMultiply (i, gfAdd (j, k)) !=
		   gfAdd (gfMultiply (i, j), gfMultiply (i, k)))
		{
		  
cout <<
		    "Multiplication does not satisfy distributivity property!"
		    << endl;
		  
return 1;
		
}
	    
}
	
}
    
}
  
cout << "All properties of a finite field are satisfied." << endl;
  
return 0;

}


