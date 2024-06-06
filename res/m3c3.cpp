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
      for (int j = mid + 1; j < l; ++j) {
        if (powers[j] == ' ') {
          mid = j;
          break;
        }
      }
      int c = 0, base = 1;
      for (int j = mid - 1; j >= 0; --j) {
        if (powers[j] == ' ') break;
        c += (int)(powers[j] - '0') * base;
        base *= 10;
      }
      fireworks[i * 2 + 1] = c > 9 ? 9 : (c < 0 ? 0 : c);
      for (int i = mid + 1; i < l; ++i) {
        if (powers[i] != ' ') break;
        mid = i;
      }
    }
  }
  char name;
  while (true) {
    cout << "Kembang api yang diledakan (nama kembang api) : ";
    cin >> name;
    cin.clear();
    cin.ignore();
    if (cin.fail() || name < 'A'
      || (name > '@' + n && name < 'a')
      || name > '`' + n){
      cout << "Masukan tidak valid." << endl;
      continue;
    } break;
  }
  for (int i = 0; i < n; ++i) {
    if (fireworks[i * 2] == name||fireworks[i * 2] == (name - ' ')){
      int range = i + (int)fireworks[i * 2 + 1];
      for (int j = i + 1; j <= range && j < n; ++j) {
        if (j + fireworks[j * 2 + 1] > range)
          range = j + fireworks[j * 2 + 1];
        fireworks[j * 2 + 1] = -1;
      }
      range = i - (int)fireworks[i * 2 + 1];
      for (int j = i - 1; j >= range && j >= 0; --j) {
        if (j - fireworks[j * 2 + 1] < range)
          range = j - fireworks[j * 2 + 1];
        fireworks[j * 2 + 1] = -1;
      }
      fireworks[i * 2 + 1] = -1;
    }
  }
  cout << "Kembang api yang tersisa : \n";
  for (int i = 0; i < n; ++i) {
    if (fireworks[i * 2 + 1] < 0) continue;
    cout << fireworks[i * 2] << ". " << (int)fireworks[i * 2 + 1];
    cout << endl;
  }
  return 0; }
