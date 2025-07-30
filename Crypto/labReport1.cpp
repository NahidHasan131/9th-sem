#include <iostream>
using namespace std;

string encrypt(string text, int key) {
    string result = "";
    for (char c : text) {
        if (isupper(c))
            result += char(int((c + key - 'A') % 26 + 'A'));
        else if (islower(c))
            result += char(int((c + key - 'a') % 26 + 'a'));
        else
            result += c;
    }
    return result;
}

string decrypt(string text, int key) {
    return encrypt(text, 26 - key);
}

int main() {
    string text;
    int key;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key (0-25): ";
    cin >> key;

    string encrypted = encrypt(text, key);
    string decrypted = decrypt(encrypted, key);

    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
