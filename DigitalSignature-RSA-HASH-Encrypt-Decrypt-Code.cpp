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


int verifying(int s, int e, int n){
    return mod_power(s,e,n);
}


int signing( int msg, int d, int n){
    return mod_power(msg,d,n);
}



// Simple hash function (sum of ASCII values)
int hashMessage(string& message) {
    int sum = 0;
    for (char ch : message) {
        sum += static_cast<int>(ch);
    }
    return sum;
}


void generateKeyPair(int& d, int& e, int& n){
  int p=823;
   int q=953;
   n=p*q;
   
   int phi=(p-1)*(q-1);
   
   e=313;
   d=modInverse(e,phi);
   
}


int main()
{
    
    // step-1 key generation - public key and private key
    // step-2 message to hash
    // step-3 signing hash value to digital signature
    // step-4 verifying digital signature to hash value
    
    int d,e,n;
    generateKeyPair(d, e, n);
    
    string msg="hello";
    
    cout<<"original msg : "<<msg<<endl;
    
    int hashS= hashMessage(msg);
    cout<<"sender side hash value : "<<hashS<<endl;
    
    int S=signing(hashS,d,n);
    cout<<"After signing hash, signature value : "<<S<<endl;
    
    int hashR=verifying(S,e,n);
    cout<<"After verifying, receiver side hash value : "<<hashR<<endl;
    
    if(hashS==hashR) cout<<"yes it is verified";
    else cout<<"not verified";

    return 0;
}
