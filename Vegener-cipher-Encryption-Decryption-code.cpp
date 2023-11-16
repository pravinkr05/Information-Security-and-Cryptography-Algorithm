#include <iostream>
using namespace std;


string vegenerCypherEncryption(string pt, string key){
    string cipher="";
    for(int i=0;i<pt.size();){
        
        for(int j=0;j<key.size() && i<pt.size();j++){
            char ch=tolower(pt[i]);
            int val1= ch-'a';
            char ch2=tolower(key[j]);
            int val2=ch2-'a';
            int val3=(val1+val2)%26;
            cipher+=(val3+'a');
            i++;
        }
    }
    return cipher;
}

string vegenerCypherDecryption(string cipher, string key){
    string pt="";
    for(int i=0;i<cipher.size();){
        
        for(int j=0;j<key.size() && i<cipher.size();j++){
            char ch=tolower(cipher[i]);
            int val1= ch-'a';
            char ch2=tolower(key[j]);
            int val2=ch2-'a';
            int val3=(val1-val2)%26;
            val3=(26+val3)%26;
            pt+=(val3+'a');
            i++;
        }
    }
    return pt;
}
int main()
{
    string pt="geeksforgeeks";
    cout<<"The original plaintext : "<<pt<<endl;
    string key="ayush";
    string cipher = vegenerCypherEncryption(pt,key);
    cout<<"After encryption cipher : "<<cipher<<endl;
    string plain = vegenerCypherDecryption(cipher, key);
     cout<<"After decryption plain : "<<plain<<endl;
    return 0;
}