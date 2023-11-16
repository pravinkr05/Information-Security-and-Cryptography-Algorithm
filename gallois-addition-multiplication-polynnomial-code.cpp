// 3. represent elements of GF(2^n) using polynomial notation. For example, represent the element 1010101
// as the polynomial x^6 + x^4 + x^2 + 1. Implement addition and multiplication of polynomials in GF(2^n).

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// Define the field size (2^n)
const int n = 8;

// Define the irreducible polynomial (used for modulo operation)
const int irreduciblePoly = 0 b100011011;	// x^8 + x^4 + x^3 + x + 1
// Function to add two polynomials in GF(2^n)
int
addPolynomials (int poly1, int poly2)
{
  
return poly1 ^ poly2;

}


// Function to multiply two polynomials in GF(2^n)
  int
multiplyPolynomials (int poly1, int poly2)
{
  
int result = 0;
  
for (int i = 0; i < n; i++)
    {
      
if ((poly1 >> i) & 1)
	{
	  
result ^= (poly2 << i);
	
}
    
}
  
// Perform modulo operation using the irreducible polynomial
    while (result >= (1 << n))
    {
      
int shift = 0;
      
while (((result >> shift) & 1) == 0)
	{
	  
shift++;
	
}
      
result ^= (irreduciblePoly << shift);
    
}
  
return result;

}


// Function to convert a binary number to polynomial notation
  string binaryToPolynomial (int binary)
{
  
string polynomial;
  
for (int i = n - 1; i >= 0; i--)
    {
      
if ((binary >> i) & 1)
	{
	  
if (i == 0)
	    {
	      
polynomial += "1";
	    
}
	  else if (i == 1)
	    {
	      
polynomial += "x + ";
	    
}
	  else
	    {
	      
polynomial += "x^" + to_string (i) + " + ";
	    
}
	
}
    
}
  
return polynomial;

}


int
main ()
{
  
int poly1 = 0 b1010101;	// x^6 + x^4 + x^2 + 1
  int poly2 = 0 b1101;		// x^3 + x^2 + 1
  cout << "Polynomial 1: " << binaryToPolynomial (poly1) << endl;
  
cout << "Polynomial 2: " << binaryToPolynomial (poly2) << endl;
  
int sum = addPolynomials (poly1, poly2);
  
cout << "Polynomial 1 + Polynomial 2: " << binaryToPolynomial (sum) <<
    endl;
  
int product = multiplyPolynomials (poly1, poly2);
  
cout << "Polynomial 1 * Polynomial 2: " << binaryToPolynomial (product) <<
    endl;
  
return 0;

}
