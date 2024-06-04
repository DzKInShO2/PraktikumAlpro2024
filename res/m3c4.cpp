#include <iostream>
using namespace std;
int main() {
  int n = 0;
  while (true) {
    cout << "Banyak kembang api : ";
    cin >> n;
    cin.clear();
    cin.ignore();
    if (cin.fail() || n < 1 || n > 26) {
      cout << "Masukan tidak valid." << endl;
      continue;
    } break;
  }
  for (int i = 0; i < n; ++i) cout << " ? ";
  cout << endl;
  char fireworks[n * 2];
  for (int i = 0; i < n; ++i)
    cout << "[" << (fireworks[i * 2] = 'A' + i) << "]";
  cout << endl << " ";
  {
    string powers;
    getline(cin, powers);
    powers.push_back(' ');
    int l = 0;
    while (powers[l++] != '\0') {}
    for (int i = 0, mid = 0; i < n; ++i) {
