#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; ++x) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

string encrypt(const string& plaintext, int a, int b) {
    string result = "";
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int x = ch - base;
            int enc = (a * x + b) % 26;
            result += (char)(enc + base);
        } else {
            result += ch;
        }
    }
    return result;
}

string decrypt(const string& ciphertext, int a, int b) {
    string result = "";
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        return "Invalid key: no modular inverse exists for a.";
    }

    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int y = ch - base;
            int dec = (a_inv * (y - b + 26)) % 26;
            result += (char)(dec + base);
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string text;
    int a, b;

    cout << "Enter the plaintext: ";
    getline(cin, text);

    cout << "Enter key a (coprime with 26): ";
    cin >> a;

    cout << "Enter key b: ";
    cin >> b;

    if (modInverse(a, 26) == -1) {
        cout << "Error: 'a' must be coprime with 26." << endl;
        return 1;
    }

    string encrypted = encrypt(text, a, b);
    string decrypted = decrypt(encrypted, a, b);

    cout << "Encrypted text: " << encrypted << endl;
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
