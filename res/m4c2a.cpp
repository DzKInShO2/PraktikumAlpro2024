#include <iostream>
using namespace std;
int factorial(int n, int acc = 1) {
  if (n == 1) return acc;
  return factorial(n - 1, acc * n); }
int main() {
  cout << "1. Permutasi\n";
  cout << "2. Kombinasi\n";
  cout << "3. SPL\n";
  int choice;
  while (true) {
    cout << "Pilih: ";
    cin >> choice;
    if (cin.fail() || choice < 1
      || choice > 3) {
      cin.clear();
      cin.ignore();
      cout << "Masukan tidak valid." << endl;
      continue;
    } break; }
  switch (choice) {
    case 1: {
      int n, r;
      cout << "Masukan n: ";
      cin >> n;
      cout << "Masukan r: ";
      cin >> r;
      cout << "Hasil Permutasi: " 
         << factorial(n)/factorial(n - r)
         << endl;
    } break;
    case 2: {
      int n, r;
      cout << "Masukan n: ";
      cin >> n;
      cout << "Masukan r: ";
