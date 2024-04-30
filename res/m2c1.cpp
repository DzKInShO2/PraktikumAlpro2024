#include <iostream>
using namespace std;

int main()
{
    cout << "------------------------------------------\n";
    cout << "|    THR DARI HOLIL UNTUK SEMUA  ^_^     |\n";
    cout << "------------------------------------------\n";

    string name = " ";

    cout << "Masukan Nama  : ";
    getline(cin, name);

    while (true) {
        string sid = " ";

        cout << "Masukan NIM   : ";
        getline(cin, sid);
        if (sid.find("F1D0") == string::npos) {
            cout << "Input tidak valid!" << endl;
            continue;
        }
        break;
    }
    cout << "------------------------------------------\n";

    int type = 0;

    cout << "Yoo!!! " << name << ", Kamu Tipe Mahasiswa Seperti Apa?\n";
    cout << "1. Mahasiswa Kupu-kupu\n";
    cout << "2. Mahasiswa Kura-kura\n";
    cout << "3. Mahasiswa Kuda-kuda\n";

    while (true) {
        cout << "Masukan Pilihan Kamu: ";
        cin >> type;

        if (cin.fail() || (type < 1 || type > 3)) {
            cin.clear();
            cin.ignore();

            cout << "Input tidak valid!" << endl;
            continue;
        }
        break;
    }

    cout << "------------------------------------------\n";

    switch (type) {
    case 1:
        cout << "Selamat Datang " << name << " - Mahasiswa Kuliah-Pulang\n";
        cout << "Santai banget ya kamu :)\n";
        break;
    case 2:
        cout << "Selamat Datang " << name << " - Mahasiswa Kuliah-Rapat\n";
        cout << "Kasian banget ya kamu :)\n";
        break;
    case 3:
        cout << "Selamat Datang " << name << " - Mahasiswa Kuliah-Dagang\n";
        cout << "Semangat ya buat kamu :)\n";
        break;
    }
    cout << "------------------------------------------\n";

    int duration = 0;
    while (true) {
        cout << "Berapa Jam waktu Kuliahmu Ramadhan ini? ";
        cin >> duration;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();

            cout << "Input tidak valid!" << endl;
            continue;
        }
        break;
    }
    cout << "------------------------------------------\n";

    int money = 0;

    switch(type){
    case 1:
        money = 500000;
        break;
    case 2:
        money = 850000;
        break;
    case 3:
        money = 1000000;
        break;
    default:
        break;
    }

    cout << "THR buat kamu sebesar      : Rp." << money << "\n";
    cout << "Durasi Kuliah Minggu ini   : " << (duration *= 3600) << " Detik\n";
    cout << "------------------------------------------\n";

    char overtime = 'y';
    while (true) {
        cout << "Apakah Kamu Pernah Kuliah Sampai Malam? (Y/N): ";
        cin >> overtime;

        if (cin.fail() ||
            (overtime != 'Y' && overtime != 'N')
            && (overtime != 'y' && overtime != 'n')) {
            cin.clear();
            cin.ignore();

            cout << "Input tidak valid!" << endl;
            continue;
        }
        break;
    }

    if (overtime == 'Y' || overtime == 'y') {
        int duration1 = 0;

        cout << "Kamu Memang Rajin !!!\n";
        cout << "Holil Ingin Memberimu Lebih Banyak THR\n";
        while (true) {
            cout << "Masukan Total Waktu Kuliah Malam Kamu (Detik): ";
            cin >> duration1;

            if (cin.fail()) {
                cin.clear();
                cin.ignore();

                cout << "Input tidak valid!" << endl;
                continue;
            }
            break;
        }

        duration += duration1;
        if ((duration1/3600.0f) > 1.0f && (duration1/3600.0f) <= 2.0f) {
            money += 200000;
        } else if ((duration1/3600.0f) > 2.0f && (duration1/3600.0f) <= 3.0f) {
            money += 500000;
        } else if ((duration1/3600.0f) > 3.0f) {
            money *= 2;
        }
    }

    cout << "------------------------------------------\n";
    cout << "Total THR Ultraman Kocak Ramadhan Ini     : Rp." << money << "\n";
    cout << "Durasi Kuliah Ramadhan Ini  : " << (duration/3600) << " Jam, "
         << (duration/60) - ((duration/3600) * 60) << " Menit, " 
         << (duration - ((duration/3600) * 3600)) -
            (((duration - ((duration/3600) * 3600)) / 60) * 60) << " Detik\n";
    cout << "------------------------------------------\n";
    return 0;
}
