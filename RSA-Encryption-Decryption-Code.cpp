#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}


int mod_power(int a, int b, int c){
    long long mul=1;
    for(int i=1;i<=b;i++){
        mul=(mul*a)%c;
    }
    return mul%c;
}

int RSAdecryption(int cipher, int d, int n){
    return mod_power(cipher,d,n);
}

int RSAencryption(int pt, int e, int n){
    return mod_power(pt,e,n);
}

int mulInverse(int e, int phi){
    int d;    
    for(int i=1;i<phi;i++){
        d=(i*e)%phi;
        if(d==1) return i;
    }
    return -1;
}

int primeFactor(int n){
    int pf;
    int i=2;
    for(i=2; i<n; i++){
        if(isPrime(i) && (n%i)==0){
            pf=n/i;
            if(isPrime(pf)) {
                break;}
        }
       pf=-1;
    }
   cout<<"Prime Factors : "<<i<<"-"<<pf<<endl;;
   int phi=(i-1)*(pf-1);
    return phi;
}


int main()
{
  
    int n=3127;
    int e=3;
    int phi=primeFactor(n);
    
    int d=mulInverse(e,phi);
    cout<<"private key : "<<d<<endl;
    
    int pt=89;
     cout<<"PlainText : "<<pt<<endl;
    int cipher = RSAencryption(pt,e,n);
    
    cout<<"After Encryption Cipher : "<<cipher<<endl;
    int plain = RSAdecryption(cipher,d,n);
    
    cout<<"After Decryption Message : "<<plain<<endl;
    return 0;
}