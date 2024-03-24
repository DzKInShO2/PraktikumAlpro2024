#include <iostream>

int main()
{
    float temp;

    std::cout << "Suhu awal: ";
    std::cin >> temp;
    std::cout << std::endl;

    std::cout << "Suhu awal kamar Holil: " << std::endl;
    std::cout << "1. " << temp << " C" << std::endl;
    std::cout << "2. " << ((temp * 1.8f) + 32) << " F" << std::endl;
    std::cout << "3. " << (temp + 273.15f) << " K" << std::endl << std::endl;

    float temp0 = (temp - (temp * 0.25f));
    std::cout << "Setelah 15 menit" << std::endl;
    std::cout << "Suhu kamar Holil berkurang menjadi " << ((temp0 * 1.8f) + 32) << " F dengan pengurangan sebesar " << ((temp - temp0) + 273.15f) << " K" << std::endl;

    float temp1 = (temp - (temp * 0.65f));
    std::cout << "Setelah 25 menit" << std::endl;
    std::cout << "Suhu kamar Holil berkurang menjadi " << (temp1 + 273.15f) << " K dengan pengurangan sebesar " << (temp - temp1) << " C" << std::endl << std::endl;

    std::cout << "Suhu awal kamar Holil: " << temp << " C" << std::endl;
    std::cout << "Suhu kamar Holil saat ini: " << temp1 << " C" << std::endl << std::endl;

    std::cout << "Holil mematikan pendingin..." << std::endl << std::endl;

    float temp2 = (temp1 + (temp1 * 0.35f));
    std::cout << "Setelah 25 menit" << std::endl;
    std::cout << "Suhu kamar Holil naik menjadi " << temp2 << " C" << std::endl << std::endl;

    std::cout << "Hasil perbandingan :" << std::endl;
    std::cout << "1:" << (temp/temp2) << " untuk suhu saat ini" << std::endl;
    std::cout << "1:" << (temp/temp1) << " untuk suhu terdingin" << std::endl;
    std::cout << "1:" << (temp/temp0) << " untuk suhu 15 menit setelah pendinginan" << std::endl;

    return 0;
}
