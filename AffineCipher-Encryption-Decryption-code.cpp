#include <iostream>

using namespace std;
int
gcd (int a, int b)
{
  int q, r;
  while (b > 0)
    {
      q = a / b;
      r = a % b;
      a = b;
      b = r;
    }
  return a;
}

int
FindMultiplicativeInverseUsingecludienAlgo (int n, int b)
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

// string multiplicativeDecryption(string cipher, int key){
//     key=key%26;
//     string plain="";
//     for(int i=0;i<cipher.size();i++){
//     char ch=cipher[i];
//     int val1=ch-'a';
//     int val2=(val1*key)%26;
//     ch = val2 +'a';
//     plain+=ch;

//     }
//     return plain;
// }

// string multiplicativeEncryption(string pt, int key){
//     key=key%26;
//     string cipher="";
//     for(int i=0;i<pt.size();i++){
//     char ch=pt[i];
//     int val1=ch-'a';
//     int val2=(val1*key)%26;
//     ch = val2 +'a';
//     cipher+=ch;

//     }
//     return cipher;
// }

string
affineEncryption (string pt, int mKey, int aKey)
{
  mKey = mKey % 26;
  aKey = aKey % 26;

  string cipherText = "";
  for (int i = 0; i < pt.length (); i++)
    {
      char ch = tolower (pt[i]);
      int val1 = ch - 'a';
      int val2 = (val1 * mKey) % 26;
      int val3 = (val2 + aKey) % 26;
      ch = val3 + 'a';
      cipherText += ch;

    }
  return cipherText;
}

string
affineDecryption (string cipher, int mKeyInv, int aKeyInv)
{

  string plain = "";
  for (int i = 0; i < cipher.length (); i++)
    {
      char ch = tolower (cipher[i]);

      int val1 = ch - 'a';
      int val2 = (val1 - aKeyInv) % 26;
      val2 = (26 + val2) % 26;

      int val3 = (val2 * mKeyInv) % 26;
      ch = val3 + 'a';
      plain += ch;

    }
  return plain;

}

int
main ()
{
  int aKey = 7, mKey = 11, n = 26;
  string pt = "hello";
  cout << "Original msg : " << pt << endl;

  if (gcd (n, mKey) != 1)
    {
      cout << "inverse key not exist";
      return 0;
    }

  string cipher = affineEncryption (pt, mKey, aKey);
  cout << "Cipher text : " << cipher << endl;
  int mKeyInv = FindMultiplicativeInverseUsingecludienAlgo (n, mKey);
  int aKeyInv = aKey;
  cout << "mkeyInv : " << mKeyInv << ", aKeyInv : " << -aKeyInv << endl;
  string plain = affineDecryption (cipher, mKeyInv, aKeyInv);
  cout << "Plain Text : " << plain << endl;

  return 0;
}
