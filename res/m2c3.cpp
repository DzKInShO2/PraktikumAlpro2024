#include <iostream>
using namespace std;
int main() {
  cout << "---------------------" << endl;
  cout << "Program Animasi Bulan" << endl;
  cout << "---------------------" << endl;
  int r = 0;
  while (true) {
    cout << "Masukan Radius Bulan: ";
    cin >> r;
    if (cin.fail() || r < 1) {
      cin.clear(); cin.ignore();
      cout << "Input tidak valid!" << endl;
      continue;
    } break; }
  int mask = r * 3; int operation = -1;
  while (true) {
    cout<<"\e[H\e[2J";
    for (int y = 0; y < (r * 2) + 1; ++y) {
      for (int x = 0; x < (r * 2) + 1; ++x) {
        if (((x-r)*(x-r))+(((y-r)*(y-r))*2)<r*r
          &&(x+2)%2==0){
          cout<<"\e["<<y<<";"<<x<<"H"<< "*"; }
        if (((x-mask)*(x-mask))+(((y-r)*(y-r))*2)<(r-1)*(r-1)
          &&(x+2)%2==0) {
          cout<<"\e["<<y<<";"<<x<<"H"<<" "; }
      } cout << endl;
    } mask += operation;
    if (mask < 0) operation = 1;
    else if (mask > (r * 3)) operation = -1;
  } return 0; }
