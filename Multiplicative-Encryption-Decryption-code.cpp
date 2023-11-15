/******************************************************************************
 4. Let you are EVE and have received a ciphertext
"farkgffqnzalqfqtqnlpgdlsaw"
you know the algorithm used is multiplicative cipher. Find the plaintext.
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

string multiplicativeDecryption(string cipher, int key){
    key=key%26;
    string plain="";
    for(int i=0;i<cipher.size();i++){
    char ch=cipher[i];
    int val1=ch-'a';
    int val2=(val1*key)%26;
    ch = val2 +'a';
    plain+=ch;

    }
    return plain;
}

string multiplicativeEncryption(string pt, int key){
    key=key%26;
    string cipher="";
    for(int i=0;i<pt.size();i++){
    char ch=pt[i];
    int val1=ch-'a';
    int val2=(val1*key)%26;
    ch = val2 +'a';
    cipher+=ch;

    }
    return cipher;
}
int main ()
{
  int key=3,n=26;
  string pt="hello";
  cout<<"Original msg : "<<pt<<endl;
  
  if(gcd(n,key)!=1){
      cout<<"inverse key not exist"; return 0;
  }
  
  string cipher = multiplicativeEncryption(pt,key);
  cout<<"Cipher text : "<<cipher<<endl;
  int keyInv=FindMultiplicativeInverseUsingecludienAlgo(n,key);
  cout<<"key : "<<key<<", invKey : "<<keyInv<<endl;
  string plain=multiplicativeDecryption(cipher, keyInv);
  cout<<"Plain Text : "<<plain<<endl;
 
  return 0;
}
