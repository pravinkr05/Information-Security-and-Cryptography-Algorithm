/******************************************************************************
1.  S x a + t x b = gcd(a, b)
    Find S and t using Extended Euclidean algo
*******************************************************************************/

#include <iostream>

using namespace std;

void extendedEcludienAlgo(int a, int b)
{
  int s1 = 1;
  int s2 = 0;
  int t1 = 0;
  int t2 = 1;
  int q;
  int r;
  while (b > 0)
    {
      q = a / b;
      r = a % b;
      a = b;
      b = r;

      int s3 = s1 - q * s2;
      s1 = s2;
      s2 = s3;

      int t3 = t1 - q * t2;
      t1 = t2;
      t2 = t3;

    }
  cout << "value of S : "<<s1 <<endl;
  cout<<"value of T : "<<t1<<endl;
  cout<<"GCD of these values : "<<a<<endl;

}

int main ()
{
  extendedEcludienAlgo(161,28);

  return 0;
}
