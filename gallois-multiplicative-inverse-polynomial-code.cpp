#include <iostream>
#include <vector>
using namespace std;
// Define the field size (2^n)
const int n = 8;
// Define the irreducible polynomial (used for modulo operation)
const int irreduciblePoly = 0b100011011; // x^8 + x^4 + x^3 + x + 1
// Function to perform modular multiplication in GF(2^n)
int gfMultiply(int a, int b) {
int result = 0;
for (int i = 0; i < n; i++) {
if (b & 1) {
result ^= a;
}
bool highestBitSet = (a >> (n - 1)) & 1;
a <<= 1;
if (highestBitSet) {
a ^= irreduciblePoly;
}
b >>= 1;
}
return result;
}
// Function to calculate the multiplicative inverse using Extended Euclidean Algorithm
int multiplicativeInverse(int element) {
int t0 = 0, t1 = 1;
int q, temp, quotient;
int a = element;
int b = irreduciblePoly;
while (a > 1) {
quotient = a / b;
temp = b;
b = a % b;
a = temp;
temp = t0;
t0 = t1 - quotient * t0;
t1 = temp;
}
if (t1 < 0) {
t1 += irreduciblePoly;
}
return t1;
}
int main() {
int IRP = irreduciblePoly;
cout << "Irreducible Polynomial: " << bitset<n>(IRP) << endl;
for (int element = 1; element < (1 << n); element++) {
int inverse = multiplicativeInverse(element);
cout << "Element: " << bitset<n>(element) << " - Inverse: " << bitset<n>(inverse) << endl;
}
return 0;
}