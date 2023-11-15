/******************************************************************************
 3. Find all pairs (b_i, t_i) within n ( let n=100) such that for each pair (b_i x t_i) mod n =100 where i is integer.
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
  int b,t,n=100;
  
  for(int b=1;b<n;b++){
      if(gcd(b,n)==1){
         int t = FindMultiplicativeInverseUsingecludienAlgo(n,b);
         cout<<"multiplicative inverse of "<<b<<" is : "<<t<<endl;
      }
   }

  return 0;
}
