#include <iostream>

using namespace std;

string additiveEncryption(string pt, int key){
    string cipher="";
    for(int i=0;i<pt.size();i++){
        char ch = pt[i];
        int val1=ch-'a';
        int val2=(val1+key)%26;
        ch=val2+'a';
        cipher+=ch;
    }
    return cipher;
}

string additiveDecryption(string cipher, int key){
    string plain="";
    for(int i=0;i<cipher.size();i++){
        char ch = cipher[i];
        int val1=ch-'a';
        int val2=(val1-key)%26;
        val2=(26+val2)%26;
        ch=val2+'a';
        plain+=ch;
    }
    return plain;
}
int main()
{
    string pt="helloza";
    cout<<"Plaintext : "<<pt<<endl;
    int key=5;
    string cipher = additiveEncryption(pt,key);
    cout<<"After Encryption cipher text : "<<cipher<<endl;
    
    string plain = additiveDecryption(cipher,key);
    cout<<"After Decryption plain text : "<<plain<<endl;
    return 0;
}
