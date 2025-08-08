#include <iostream>
#include <string>
using namespace std;

const int M = 95;

int modInverse(int a, int m){
    a = a%m;
    for(int x=1; x<m; x++){
        if((a*x) % m==1) return x;
    }
    return -1;
}

string encrypt(string text, int a, int b){
    string result = "";
    for(char ch : text){
        if(ch >= 32 && ch <= 126){ 
            int x = ch - 32; 
            int enc = (a * x + b) % M;
            result += (char)(enc + 32);
        } else {
            result += ch;
        }
    }
    return result;
}

string decrypt(string text, int a, int b){
    string result = "";
    
    int a_inv = modInverse(a, M);
    if(a_inv == -1) return "Invalid 'a'!";

    for(char ch : text){
        if(ch >= 32 && ch <= 126){
            int y = ch - 32;
            int dec = (a_inv * (y - b + M)) % M;
            result += char(dec + 32);
        } else {
            result += ch;
        }
    }
    return result;
}

int main(){
    string text;
    int a, b;

    cout <<"Enter plain text: ";
    getline(cin, text);

    cout <<"Enter key a(coprime with 95): ";
    cin>>a;
    
    cout<<"Enter key b: ";
    cin>>b;

    if(modInverse(a, M) == -1){
        cout<<"a must be coprime with 95"<<endl;
        return 1;
    }

    string cipher = encrypt(text, a, b);
    cout <<"Encrypted: "<<cipher<<endl;
    cout <<"Decrypted: "<< decrypt(cipher, a, b)<<endl;

    return 0;
}
