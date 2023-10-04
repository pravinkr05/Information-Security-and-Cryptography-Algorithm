#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <math.h>
using namespace std;



void printVector(vector<int> input_bit){
    for(int i=0;i<input_bit.size();i++){
    cout<<input_bit[i]<<" ";
    }
    cout<<endl;
}



vector<int> p_box(vector<int> s_box_output){
    
    int permutation_ind[8]={5,0,2,6,7,4,3,1};
    vector<int> perm_bit_output(8,0);
    for(int i=0;i<8;i++){
         perm_bit_output[permutation_ind[i]]=s_box_output[i];
    }
    
    return perm_bit_output;
    
}




vector<int> s_box(vector<int> output_bit){
   
    vector<int> s_box_output(8,0);
    
    map<int,pair<int,int>> s_box;//s-box
    s_box[0]={1,0};
    s_box[1]={1,1};
    s_box[10]={0,0};
    s_box[11]={0,1};
    
    
    for(int i=0;i<8;i+=2){
        pair<int,int> p;
        int t1=output_bit[i];
        int t2=output_bit[i+1];
        p=s_box[t1*10+t2];
        s_box_output[i]=p.first;
        s_box_output[i+1]=p.second;
    }
    
    return s_box_output;
        
}


vector<int> xorWithKey(vector<int> input_bit, vector<int> key_bit){
    
    vector<int> output_bit(8,0);
    for(int i=0;i<8;i++){
        output_bit[i]=input_bit[i]^key_bit[i];
    }
    return output_bit;
}



vector<int> productCipherRound(vector<int> input_bit, vector<int> key_bit){

   
    vector<int> output_bit = xorWithKey(input_bit,key_bit);
    
    vector<int> s_box_output=s_box(output_bit);
    
    vector<int> p_box_output=p_box(s_box_output);
    
    return p_box_output;

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

int conv8bitToDec(vector<int> input_bit){
    int dec_val=0;

    for(int i=7;i>=0;i--){
        int last_digit=input_bit[i];
        dec_val+=last_digit*pow(2,7-i);
    }
    
     return (dec_val);

}
vector<int> productCipherEncryption(string plain_text){
    vector<int> cipher;
    vector<int> input;
    vector<int> key_bit1={0,1,0,1,0,0,1,1};
    vector<int> key_bit2={0,1,1,0,1,0,0,1};
    vector<int> input_bit(8);
    for(int i=0;i<plain_text.length();i++){

        input_bit = charTo8bit(plain_text[i]);
        
         for (auto i:input_bit){
            input.push_back(i);
        }
  
        vector<int> middleText=productCipherRound(input_bit,key_bit1);
        
        vector<int> temp_cipher=productCipherRound(middleText,key_bit2);
        
     
        for (auto i:temp_cipher){
            cipher.push_back(i);
        }
   
    }
   cout<<"Message bits - ";
   printVector(input);
   cout<<"Cipher  bits - ";
   printVector(cipher);
   return cipher;
}

void percentageNBCR(vector<int> cipher1, vector<int> cipher2){
  vector<int> resultant = xorWithKey(cipher1,cipher2);
  int cnt=0;
  for(int i=0;i<8;i++){
      if(resultant[i]==1){
          cnt++;
      }
  }
  float percentage=(float(cnt)/float(8))*100;
  cout<<"Percentage : "<<float(percentage);
}


int main(){

string plain_text="pl";
vector<int> cipher1 = productCipherEncryption(plain_text);


cout<<endl;

string plain_text2="ql";
vector<int> cipher2 = productCipherEncryption(plain_text2);

cout<<endl;
percentageNBCR(cipher1,cipher2);






return 0;
}