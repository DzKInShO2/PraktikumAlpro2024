#include <iostream>
using namespace std;
int main() {
  string text; int key;
  cout << "Masukan Pesan: ";
  getline(cin, text);
  cout << "Masukan Key Caesar Cipher: ";
  cin >> key;
  int l = 0; while (text[l++] != '\0') {}
  cout << "\nHasil  Enkripsi dengan Reverse Cipher:\n";
  for (int i = l - 2; i >= 0; --i) cout << text[i];
  cout << "\n\nHasil Enkripsi dengan Reverse + Caesar Cipher:\n";
  for (int i = l - 2; i >= 0; --i) {
    if (text[i] == ' ') { cout << " "; continue; }
    char c = text[i] + key;
    if (text[i] >= 'a' && text[i] <= 'z'
      && c - 'z' > 0) { c = '`' + (c - 'z');
    } else if (text[i] >= 'A'
      && text[i] <= 'Z'
      && c - 'Z' > 0) { c = '@' + (c - 'Z');
    } cout << c;
  } cout << endl;
}
