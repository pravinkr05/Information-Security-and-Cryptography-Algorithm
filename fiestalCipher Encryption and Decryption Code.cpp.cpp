#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> v){
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


vector<int> xorOperation(vector<int> A, vector<int> B){
for(int i=0;i<A.size();i++){
    A[i]=A[i]^B[i];
}
    return A;
}

vector<int> roundFiestalCipherDecryption(vector<int> ciphertext,vector<int> key){
    int size=ciphertext.size();
    int h=size/2;
    vector<int> l1(h,0);
    vector<int> r1(h,0);
    
    for(int i=0;i<size;i++){
        if(i<h){
            l1[i]=ciphertext[i];
        }
        else
        r1[i-h]=ciphertext[i];
    }
    
    vector<int> fun=xorOperation(l1,key);
    vector<int> l2=xorOperation(r1,fun);
    vector<int> r2=l1;
    
    
     for(int i=0;i<size;i++){
        if(i<h){
            ciphertext[i]=l2[i];
        }
        else
        ciphertext[i]=r2[i-h];
    }
    return ciphertext;
    
}

vector<int> FiestalCipherDecryption(vector<int> cipherText, vector<int> key2, vector<int> key1){
    
    vector<int> midText=roundFiestalCipherDecryption(cipherText,key2);
    vector<int> plainText=roundFiestalCipherDecryption(midText,key1);
    return (plainText);
    
}


int conv8bitToDec(vector<int> input_bit){
    int dec_val=0;

    int power=1;
    for(int i=7;i>=0;i--){
        int last_digit=input_bit[i];
        dec_val+=last_digit*power;
        power*=2;
    }
    
     return (dec_val);

}

vector<int> roundFiestalCipherEnc(vector<int> plaintext,vector<int> key){
    int size=plaintext.size();
    int h=size/2;
    vector<int> l1(h,0);
    vector<int> r1(h,0);
    
    for(int i=0;i<size;i++){
        if(i<h){
            l1[i]=plaintext[i];
        }
        else
        r1[i-h]=plaintext[i];
    }
    
    vector<int> fun=xorOperation(r1,key);
    vector<int> r2=xorOperation(l1,fun);
    vector<int> l2=r1;
    
    
     for(int i=0;i<size;i++){
        if(i<h){
            plaintext[i]=l2[i];
        }
        else
        plaintext[i]=r2[i-h];
    }
    return plaintext;
    
}


vector<int> fiestalCipherEncryption(vector<int> plainText, vector<int> key1, vector<int> key2){
    
    vector<int> midText=roundFiestalCipherEnc(plainText,key1);
    
    vector<int> cipherText=roundFiestalCipherEnc(midText,key2);
    return cipherText;
}


vector<int> charTo8bit(char ch){
    vector<int> input_bit(8,0);
    int t=7;
    int val=ch;
    
    while(t>=1){
        int bit=val%2;
        input_bit[t--]=bit;
        val=val/2;
    }
    return input_bit;
}


vector<int> generatedKey( vector<int> key,int c){
   
    while(c--){
    int temp=key[0];    
    for(int i=0;i<7;i++){
        key[i]=key[i+1];
    }
    key[7]=temp;
    }
    
    int decimalVal=2*key[0] + 1*key[7];
    int squareVal=decimalVal*decimalVal;
    
    vector<int> k(4,0);
    
    for(int i=3;i>=0;i--){
        k[i]=squareVal%2;
        squareVal=squareVal/2;
    }
    return k;
}


int main()
{
    vector<int> fullKey={0,1,1,0,0,0,1,1};
    int circularLeft=2;
    vector<int> key1=generatedKey(fullKey,circularLeft);
 
    circularLeft=3;
    vector<int> key2=generatedKey(fullKey,circularLeft);
    
    char pt='i';
    cout<<"plaintext : "<<pt<<endl;
    
    vector<int> plainText=charTo8bit(pt);
//   vector<int> plainText={1,0,1,0,0,1,0,1};
   vector<int> cipher1=fiestalCipherEncryption(plainText,key1,key2);
   cout<<"\nAfter encryption\nciphertext : "<<(char)conv8bitToDec(cipher1)<<endl;
   
  
    vector<int> plain = FiestalCipherDecryption(cipher1, key2, key1);
    cout<<"\nAfter decryption\nplaintext : "<<(char)conv8bitToDec(plain)<<endl;
   
    return 0;
}