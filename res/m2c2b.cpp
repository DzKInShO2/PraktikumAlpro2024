  while (true) {
  	cout << "\e[H\e[2J\e[0m";
      switch (state & 0x1) {
      case 0: {
        cout << "-----------------------------------" << endl;
        cout << "|          MOTIF BATIK            |" << endl;
        cout << "|             HOLIL               |" << endl;
        cout << "-----------------------------------" << endl;
        if ((state >> 1) == 0) cout << "\e[35m";
        cout << "-----------------------------------" << endl;
        cout << "|          BANGUN DATAR           |" << endl;
        cout << "-----------------------------------\e[39m" << endl;
        if ((state >> 1) == 1) cout << "\e[35m";
        cout << "-----------------------------------" << endl;
        cout << "|          POHON CEMARA           |" << endl;
        cout << "-----------------------------------\e[39m" << endl;
        if ((state >> 1) == 2) cout << "\e[35m";
        cout << "-----------------------------------" << endl;
        cout << "|          POLA BILANGAN          |" << endl;
        cout << "-----------------------------------\e[39m" << endl;
        if ((state >> 1) == 3) cout << "\e[35m";
        cout << "-----------------------------------" << endl;
        cout << "|             KELUAR              |" << endl;
        cout << "-----------------------------------\e[39m" << endl;
        n0 = getch();
        if (n0 == 13) {
          state |= 0x1;
        }
        if (n0 == 72) {
          state = (((state >> 1) - 1) << 1);
        } else if (n0 == 80) {
          state = (((state >> 1) + 1) << 1);
        }
        if ((state >> 1) > 3) {
            state = 0x0;
        } else if ((state >> 1) < 0) {
            state = 0x6;
        } } break;
      case 1: {
  		n0 = 0;
  		n1 = 0;
  
  		switch ((state >> 1)) {
  		case 0: { // Bangun Datar
  		  cout << "-----------------------------------" << endl;
  		  cout << "|          BANGUN DATAR           |" << endl;
  		  cout << "-----------------------------------" << endl;
  		  cout << "           Pola Persegi :)" << endl;
  		  while (true) {
  		  	cout << "Masukan Jumlah Baris: ";
  		  	cin >> n0;
  		  	if (cin.fail() || n0 < 1) {
  		  	  cin.clear(); cin.ignore();
  		  	  cout << "Input tidak valid!" << endl;
  		  	  continue;
  		  	} break; }
  		  for (int i = 0; i < n0; ++i) {
