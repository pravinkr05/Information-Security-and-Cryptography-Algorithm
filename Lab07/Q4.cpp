/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// for(int i=0;i<s.length();i++){
    //     plainText[i]=tolower(plaintext[i])-'a';
    // }
    
    
    
    
    
    
    
    
    
#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
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


vector<int> xorOperation(vector<int> A, vector<int> B){
for(int i=0;i<A.size();i++){
    A[i]=A[i]^B[i];
}
    return A;
}


void percentageNBCR(vector<int> cipher1, vector<int> cipher2){
  vector<int> resultant = xorOperation(cipher1,cipher2);
  int cnt=0;
  for(int i=0;i<8;i++){
      if(resultant[i]==1){
          cnt++;
      }
  }
  float percentage=(float(cnt)/float(8))*100;
  cout<<"Percentage : "<<float(percentage);
}


vector<int> roundFiestalCipher(vector<int> plaintext,vector<int> key){
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

vector<int> fiestalCipher(vector<int> plainText, vector<int> fullKey){

    int circularLeft=2;
    vector<int> key=generatedKey(fullKey,circularLeft);
    
    vector<int> midText=roundFiestalCipher(plainText,key);
    circularLeft=3;
    key=generatedKey(fullKey,circularLeft);
    vector<int> cipherText=roundFiestalCipher(midText,key);
    return cipherText;
}



int main()
{
   vector<int> fullKey={0,1,1,0,0,0,1,1};
   vector<int> plainText={1,0,1,0,0,1,0,1};
   vector<int> cipher1=fiestalCipher(plainText, fullKey);
   printArray(cipher1);

   plainText={1,0,1,0,0,1,0,0};
   vector<int> cipher2=fiestalCipher(plainText, fullKey);
   printArray(cipher2);
   percentageNBCR(cipher1,cipher2);
   
    return 0;
}
