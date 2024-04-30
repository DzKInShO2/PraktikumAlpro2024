  		  	char ch = 'A';
  		  	for (int j = 0; j < n0; ++j) {
  		  		if (i > 0 && i == j) {
  		  			n1++;
  		  			ch = (char)(65 + n1);
  		  		}
  		  		cout << ch << " ";
  		  		if ((n1 - ((int)(ch) - 65)) > 0) {
  		  			ch++;
  		  		}
  		  	}
  		  	cout << endl;
  		  }
  		  cout << "-----------------------------------" << endl;
  		  cout << "           Pola Segitiga :|" << endl;
  		  while (true) {
  		  	cout << "Masukan Jumlah Baris: ";
  		  	cin >> n0;
  		  	if (cin.fail() || n0 < 1) {
  		  		cin.clear(); cin.ignore();
  		  		cout << "Input tidak valid!" << endl;
  		  		continue;
  		  	} break; }
  		  n1 = !((n0 + 2) % 2 == 0);
  		  for (int i = 0; i < n0; ++i) {
  		  	for (int j  = 0; j < (n0 - i) - 1; ++j) {
  		  	  cout << " ";
  		  	}
  		  	for (int j = 0; j < (i * 2) + 1; j += 2) {
  		  	  if ((i + 2) % 2 == 0) {
  		  	  	cout << (char)(65 + i + n1) << " ";
  		  	  } else {
  		  	  	cout << i + 1 - n1 << " ";
  		  	  }
  		  	}
  		  	cout << endl;
  		  }
  		  cout << "-----------------------------------" << endl;
  		  cout << "           Pola Persegi Lagi :(" << endl;
  		  while (true) {
  		  	cout << "Masukan Jumlah Baris: ";
  		  	cin >> n0;
  		  	if (cin.fail() || n0 < 1) {
  		  	  cin.clear(); cin.ignore();
  		  	  cout << "Input tidak valid!" << endl;
  		  	  continue;
  		  	} break; }
  		  for (int i = 0; i < n0; ++i) {
  		  	for (int j = 0; j < n0; ++j) {
  		  		int k = (i * n0) + j + 1;
  		  		if (k/10.0f < 1.0f)
  		  			cout << "0";
  		  		cout << k << " ";
  		  	}
  		  	cout << endl;
  		  }
  		} break;
