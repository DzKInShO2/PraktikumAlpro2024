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
    } break;
  }
  cout << "------------------------------------------\n";
  int type = 0;
  cout<< "Yoo!!! "<<name<<", Kamu Tipe Mahasiswa Seperti Apa?\n";
  cout<< "1. Mahasiswa Kupu-kupu\n";
  cout<< "2. Mahasiswa Kura-kura\n";
  cout<< "3. Mahasiswa Kuda-kuda\n";
  while (true) {
    cout << "Masukan Pilihan Kamu: ";
    cin >> type;
    if (cin.fail() || (type < 1 || type > 3)) {
      cin.clear();
      cin.ignore();
      cout << "Input tidak valid!" << endl;
      continue;
    } break;
  }
  cout << "------------------------------------------\n";
  int money = 0;
  switch (type) {
  case 1:
    cout<<"Selamat Datang "<<name<<" - Mahasiswa Kuliah-Pulang\n";
    cout<<"Santai banget ya kamu :)\n";
    money = 500000; break;
  case 2:
    cout<<"Selamat Datang "<<name<<" - Mahasiswa Kuliah-Rapat\n";
    cout<<"Kasian banget ya kamu :)\n";
    money = 850000; break;
  case 3:
    cout<<"Selamat Datang "<<name<<" - Mahasiswa Kuliah-Dagang\n";
    cout<<"Semangat ya buat kamu :)\n";
    money = 1000000; break;
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
    } break;
  }
