#include <iostream>
using namespace std;

int main() {
    float temp;
    cout << "Suhu awal: ";
    cin >> temp;
    cout << endl;
    cout << "Suhu awal kamar Holil: " << endl;
    cout << "1. " << temp << " C" << endl;
    cout << "2. " << ((temp * 1.8f) + 32) << " F" << endl;
    cout << "3. " << (temp + 273.15f) << " K" << endl << endl;
    float temp0 = (temp - (temp * 0.25f));
    cout << "Setelah 15 menit" << endl;
    cout << "Suhu kamar Holil berkurang menjadi "
         << ((temp0 * 1.8f) + 32) << " F dengan pengurangan sebesar "
         << ((temp - temp0) + 273.15f)
         << " K" << endl;
    float temp1 = (temp - (temp * 0.65f));
    cout << "Setelah 45 menit" << endl;
    cout << "Suhu kamar Holil berkurang menjadi " << (temp1 + 273.15f)
         << " K dengan pengurangan sebesar " << (temp - temp1) << " C"
         << endl << endl;
    cout << "Suhu awal kamar Holil: " << temp << " C" << endl;
    cout << "Suhu kamar Holil saat ini: " << temp1 << " C"
         <<endl<<endl;
    cout << "Holil mematikan pendingin..." << endl << endl;
    float temp2 = (temp1 + (temp1 * 0.35f));
    cout << "Setelah 25 menit" << endl;
    cout << "Suhu kamar Holil naik menjadi " << temp2 << " C" << endl 
         <<endl;
    cout << "Hasil perbandingan:" << endl;
    cout << "1:" << (temp/temp2) << " untuk suhu saat ini" << endl;
    cout << "1:" << (temp/temp1) << " untuk suhu terdingin" << endl;
    cout << "1:" << (temp/temp0)
         << " untuk suhu 15 menit setelah pendinginan" << endl;

    return 0;
}
