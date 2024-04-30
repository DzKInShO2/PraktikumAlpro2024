  cout<<"------------------------------------------\n";
  cout<<"THR buat kamu sebesar   : Rp."<< money << "\n";
  cout<<"Durasi Kuliah Minggu ini: "<<(duration *= 3600)<<" Detik\n";
  cout<<"------------------------------------------\n";
  char overtime = 'y';
  while (true) {
    cout << "Apakah Kamu Pernah Kuliah Sampai Malam? (Y/N): ";
    cin >> overtime;
    if (cin.fail() ||
        (overtime != 'Y' && overtime != 'N')
        &&(overtime!='y'&&overtime!='n')){cin.clear();cin.ignore();
        cout << "Input tidak valid!" << endl; continue; } break; }
  if (overtime == 'Y' || overtime == 'y') { int duration1 = 0;
    cout << "Kamu Memang Rajin !!!\n";
    cout << "Holil Ingin Memberimu Lebih Banyak THR\n";
    while (true) {
      cout << "Masukan Total Waktu Kuliah Malam Kamu (Detik): ";
      cin >> duration1;
      if (cin.fail()) { cin.clear(); cin.ignore();
        cout << "Input tidak valid!" << endl; continue; } break; }
    duration += duration1;
    if ((duration1/3600.0f)>1.0f&&(duration1/3600.0f)<=2.0f){
      money += 200000;
    }else if((duration1/3600.0f)>2.0f&&(duration1/3600.0f)<=3.0f){
      money += 500000;
    }else if((duration1/3600.0f)>3.0f) {
      money *= 2;
    }
  }
  cout<<"------------------------------------------\n";
  cout<<"Total THR "<<name<<" Ramadhan Ini: Rp. "<<money<<"\n";
  cout<<"Durasi Kuliah Ramadhan Ini: "<<(duration/3600)<<" Jam,"
      <<(duration/60)-((duration/3600)*60)<<" Menit,"
      <<(duration-((duration/3600)*3600))-
      (((duration-((duration/3600)*3600))/60)*60)<<" Detik\n";
  cout<<"------------------------------------------\n"; return 0; }
