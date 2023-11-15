/******************************************************************************
2. gcd(n,b) =1 Find the value t such that (b x t) mod n=1. [Hint : Find multiplicative inverse(t) of b where 1<b<n]
*******************************************************************************/

#include <iostream>

using namespace std;
int gcd(int a, int b){
    int q,r;
    while(b>0){
        q=a/b;
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int  FindMultiplicativeInverseUsingecludienAlgo(int n, int b)
{

  int t1 = 0;
  int t2 = 1;
  int q;
  int r;
  int a = n;

  while (b > 0)
    {
      q = a / b;
      r = a % b;
      a = b;
      b = r;

      int t3 = t1 - q * t2;
      t1 = t2;
      t2 = t3;

    }
  if (t1 < 0)
    t1 = (t1 + n) % n;
    
  return t1;
}

int main ()
{
  int b = 4,n=26;
  if(gcd(b,n)!=1){
      cout<<"multiplicative inverse does not exist!";
      return 0;
  }
  int B = FindMultiplicativeInverseUsingecludienAlgo(n,b);
  cout<<"multiplicative inverse of "<<b<<" is : "<<B;


  return 0;
}
