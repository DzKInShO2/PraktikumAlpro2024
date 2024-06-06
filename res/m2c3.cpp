#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  int radius;
  cout << "-------------------------" << endl;
  cout << "| Program Animasi Bulan |" << endl;
  cout << "-------------------------" << endl;
  cout << "Masukkan Radius Bulan: ";
  cin >> radius;
  while (true) {
    for (int arah = -(2 * radius); arah < 2 * radius; arah++) {
      for (int y = -radius; y < radius; y++) {
        for (int x = -(radius); x < (radius); x++) {
          int jarak = x * x + y * y;
          int rsquare = (radius * radius) - radius;
          int jarak2 = (x + arah) * (x + arah) + y * y;
          int rsquare2 = (radius - 1) * (radius - 1);
          int bulan1 = jarak <= rsquare;
          int bulan2 = jarak2 >= rsquare2;
          if (bulan1 && bulan2) {
            cout << setw(2) << "*";
          } else {
            cout << setw(2) << " ";}}
        cout << endl;
      }
      cout << "\33[H\33[2J";
    }
  }
}
