#include <iostream>
using namespace std;
int main() {
  cout << "=========== BERMAIN DENGAN MATRIKS ============\n"; int m, n; 
  cout << "Masukan jumlah baris matriks: "; cin >> n;
  cout << "Masukan jumlah kolom matriks: "; cin >> m; cin.clear();
  int matrix[m * n]; cout << "Masukan elemen matriks:\n"; cin.ignore();
  for (int i = 0; i < n; ++i) {
    string numbers; getline(cin, numbers); numbers.push_back(' ');
    int l = 0; while (numbers[l++] != '\0') {}
    for (int j = 0, mid = 0; j < m; ++j) { matrix[i * m + j] = 0;
      for (int k = mid + 1; k < l; ++k) {
        if (numbers[k] == ' ') { mid = k; break; }
      } int base = 1;
      for (int k = mid - 1; k >= 0; --k) {
        if (numbers[k] == ' ') break;
        if (numbers[k] == '-') {
          matrix[i * m + j] *= -1; break;
        }
        matrix[i * m + j] += (int)(numbers[k] - '0') * base;
        base *= 10;
      }
