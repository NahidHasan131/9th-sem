#include <iostream>
#include <string>
using namespace std;

const int M = 95; // total printable ASCII characters (32–126)

// Modular inverse function
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Encryption function
string encrypt(string text, int a, int b) {
    string result = "";
    for (char c : text) {
        if (c >= 32 && c <= 126) { // printable characters only
            int x = c - 32; // shift to 0–94 range
            int enc = (a * x + b) % M;
            result += char(enc + 32);
        } else {
            result += c; // leave non-printable unchanged
        }
    }
    return result;
}

// Decryption function
string decrypt(string text, int a, int b) {
    string result = "";
    int a_inv = modInverse(a, M);
    if (a_inv == -1) return "Invalid 'a' (no modular inverse)";

    for (char c : text) {
        if (c >= 32 && c <= 126) {
            int y = c - 32;
            int dec = (a_inv * (y - b + M)) % M;
            result += char(dec + 32);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string plaintext;
    int a, b;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key a (coprime with 95): ";
    cin >> a;
    cout << "Enter key b: ";
    cin >> b;

    if (modInverse(a, M) == -1) {
        cout << "Error: 'a' must be coprime with 95." << endl;
        return 0;
    }

    string cipher = encrypt(plaintext, a, b);
    cout << "Encrypted: " << cipher << endl;

    string decrypted = decrypt(cipher, a, b);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}

