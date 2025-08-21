#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char table[5][5];

void makeTable(string key) {
    string all = "";
    for (char &c : key) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            if (all.find(c) == string::npos) all += c;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (all.find(c) == string::npos) all += c;
    }

    int k = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            table[i][j] = all[k++];
}

void findPos(char ch, int &row, int &col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (table[i][j] == ch) {
                row = i; col = j;
                return;
            }
        }
    }
}

string encrypt(string text) {
    string plain = "";
    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            plain += c;
        }
    }

    string prepared = "";
    for (int i = 0; i < plain.size(); i++) {
        prepared += plain[i];
        if (i + 1 < plain.size() && plain[i] == plain[i+1]) {
            prepared += 'X';
        }
    }
    cout<<prepared<<endl;
    if (prepared.size() % 2 != 0) prepared += 'X';

    string cipher = "";
    for (int i = 0; i < prepared.size(); i += 2) {
        int r1, c1, r2, c2;
        findPos(prepared[i], r1, c1);
        findPos(prepared[i+1], r2, c2);

        if (r1 == r2) {
            cipher += table[r1][(c1 + 1) % 5];
            cipher += table[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2) {
            cipher += table[(r1 + 1) % 5][c1];
            cipher += table[(r2 + 1) % 5][c2];
        }
        else {
            cipher += table[r1][c2];
            cipher += table[r2][c1];
        }
    }
    return cipher;
}

string decrypt(string cipher) {
    string plain = "";
    for (int i = 0; i < cipher.size(); i += 2) {
        int r1, c1, r2, c2;
        findPos(cipher[i], r1, c1);
        findPos(cipher[i+1], r2, c2);

        if (r1 == r2) {
            plain += table[r1][(c1 + 4) % 5];
            plain += table[r2][(c2 + 4) % 5];
        }
        else if (c1 == c2) {
            plain += table[(r1 + 4) % 5][c1];
            plain += table[(r2 + 4) % 5][c2];
        }
        else {
            plain += table[r1][c2];
            plain += table[r2][c1];
        }
    }

    string result = "";
    for (int i = 0; i < plain.size(); i++) {
        if (i+1 < plain.size() && plain[i] == plain[i+2] && plain[i+1] == 'X') {
            result += plain[i];
            i++; // skip the inserted X
        } else {
            result += plain[i];
        }
    }
    return result;
}

int main() {
    string key, plain;

    cout << "Enter keyword: ";
    getline(cin, key);

    makeTable(key);

    cout << "\nPlayfair Table:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << table[i][j] << " ";
        cout << endl;
    }

    cout << "\nEnter plaintext: ";
    getline(cin, plain);

    string cipher = encrypt(plain);
    cout << "\nCiphertext: " << cipher << endl;

    string decrypted = decrypt(cipher);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
