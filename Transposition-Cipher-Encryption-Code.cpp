#include <cmath>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

double chaotic_logistic_map(double r, double x) {
    return r * x * (1 - x);
}

void generatePermutaionBox(vector<double>& permutation, double r,double x_n){

    // Generate the chaotic sequence
    double sequence[100];
    for (int i = 0; i < 100; i++) {
        sequence[i] = x_n;
        x_n = chaotic_logistic_map(r, x_n);
    }
    
    // Take the last ten entries
    vector<double> last_ten_entries(10,0);
    for (int i = 90; i < 100; i++) {
        last_ten_entries[i - 90] = sequence[i];
    }
    permutation=last_ten_entries;
    sort(permutation.begin(),permutation.end());
    
    for(int i=0;i<10;i++){
        double t=permutation[i];
        for(int j=0;j<10;j++){
            if(t==last_ten_entries[j]){
                permutation[i]=j; 
            }
        }
    }
    
       
    
    
}

void print2dArray(vector<string> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
}

void transpositionEncryption(string pt, vector<double> permutation){
    int n=pt.size();
    int row=ceil(n/10.0);
    vector<string> cipher1(row);
    //break into 10 columns
    for(int i=0;i<row;i++){
        for(int j=0;j<10;j++){
            //add padding
            int ind=i*10+j;
            if(ind<n)
            cipher1[i].push_back(pt[i*10 + j]);
            else
            cipher1[i].push_back('x');
        }
    }
   
    // cout<<"convert pt into 2d array\n";
    // print2dArray(cipher1);
      cout<<endl<<"permutation box \n";
     for(int i=0;i<10;i++) cout<<i<<"-"<<permutation[i]<<" ";
     
    vector<string> cipher=cipher1;
    for(int i=0;i<10;i++){
        int shiftCol=permutation[i];
       
        for(int j=0;j<row;j++){
            cipher[j][shiftCol]=cipher1[j][i];
           
        }
    }
    // cout<<"\n\nafter permutation convert 2d array cipher\n";
    // print2dArray(cipher);
   
   vector<char> ciphertext;
   for(int i=0;i<10;i++){
       for(int j=0;j<row;j++){
          ciphertext.push_back(cipher[j][i]); 
       }
   }
   cout<<"\noriginal ciphertext \n";
   for(int i=0;i<ciphertext.size();i++) cout<<ciphertext[i]<<" ";
}

int main() {
    double r = 3.741;
    double x_n = 0.748;
    vector<double> permutation(10,0);
    generatePermutaionBox(permutation,r,x_n);

    string pt = "IIESTShibpurowesitsorigintotheerstwhileBengalEngineeringCo";
    transpositionEncryption(pt,permutation);
    

    return 0;
}
