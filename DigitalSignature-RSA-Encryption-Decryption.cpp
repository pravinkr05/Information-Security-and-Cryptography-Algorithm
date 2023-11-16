/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int modInverse(int e, int phi){
    int p;
    for(int i=1;i<phi;i++){
        if((i*e)%phi==1) return i;
    }
    return -1;
}

int mod_power(int a, int b, int c){
    long long mul=1;
    for(int i=1;i<=b;i++){
        mul=(mul*a)%c;
    }
    return mul%c;
}

void generateKeyPair(int& d, int& e, int& n){
  int p=823;
   int q=953;
   n=p*q;
   
   int phi=(p-1)*(q-1);
   
   e=313;
   d=modInverse(e,phi); // generates private key using multiplicative inverse
   
}

int signing( int msg, int d, int n){
    return mod_power(msg,d,n);
    
}

int verifying(int s, int e, int n){
    return mod_power(s,e,n);
}
int main()
{
    
    // step-1 key generation - public key and private key
    // step-2 signing message to digital signature
    // step-3 verifying digital signature to message
    int d,e,n;
    generateKeyPair(d, e, n);
    int m=19070;
    cout<<"original msg : "<<m<<endl;
    int S=signing(m,d,n);
    cout<<"after signing signature : "<<S<<endl;
    int M=verifying(S,e,n);
    
    cout<<"After verifying message : "<<M<<endl;
    
    if(m==M) cout<<"yes it is verified";
    else cout<<"not verified";

    return 0;
}
