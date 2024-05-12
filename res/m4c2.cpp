#include <iostream>
using namespace std;
int factorial(int n, int acc = 1)
{
  if (n == 1) return acc;
  return factorial(n - 1, acc * n);
}
int main()
{
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
    } break;
  }
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
      cin >> r;
      cout << "Hasil Kombinasi: " 
         << factorial(n)/(factorial(n - r) * factorial(r))
         << endl;
    } break;
    case 3: {
      cout << "Masukan Nilai Matriks 3x3\n";
      float matrix[12];
      for (int i = 0; i < 3; ++i) {
        for (int j = 0, mid = 0; j < 3; ++j) {
          cin >> matrix[i * 4 + j];
        }
      }
      cout << "Masukan Nilai B\n";
      for (int i = 0; i < 3; ++i) {
        cin >> matrix[(i + 1) * 4 - 1];
      }
      cout << "Augmented Matriks\n";
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
          cout << matrix[i * 4 + j] << " ";
        }
        cout << endl;
      }
      float x;
      if (matrix[4] != 0 && matrix[8] != 0
        && matrix[9] != 0) {
        x = matrix[4]/matrix[0];
        for (int i = 0; i < 4; ++i) {
          matrix[4 + i] += matrix[i] * -x;
        }

        x = matrix[8]/matrix[0];
        for (int i = 0; i < 4; ++i) {
          matrix[8 + i] += matrix[i] * -x;
        }
        x = matrix[9]/matrix[5];
        for (int i = 0; i < 4; ++i) {
          matrix[8 + i] += matrix[4 + i] * -x;
        }
      }
      cout << "Matriks Segitiga Atas | SPL\n";
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          cout << matrix[i * 4 + j] << " ";
        }
        cout << " | " << matrix[(i + 1) * 4 - 1] << endl;
      }
      float z = matrix[11]/matrix[10];
      float y = (matrix[7] - (matrix[6] * z))/matrix[5];
      x = (matrix[3] - (matrix[2] * z) - matrix[1] * y)/matrix[0];
      cout << "x: " << x << "\n";
      cout << "y: " << y << "\n";
      cout << "z: " << z << "\n";
    } break;
  }
}
