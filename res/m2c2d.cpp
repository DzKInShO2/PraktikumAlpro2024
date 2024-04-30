  		case 1: {
  		  cout << "-----------------------------------" << endl;
  		  cout << "|          POHON CEMARA           |" << endl;
  		  cout << "-----------------------------------" << endl;
  		  while (true) {
  		  	cout << "Masukan Tinggi: ";
  		  	cin >> n0;
  		  	if (cin.fail() || n0 < 1) {
  		  	  cin.clear(); cin.ignore();
  		  	  cout << "Input tidak valid!" << endl;
  		  	  continue;
  		  	} break; }
  		  while (true) {
  		  	cout << "Masukan Lebar: ";
  		  	cin >> n1;
  		  	if (cin.fail() || n1 < 1) {
  		  		cin.clear(); cin.ignore();
  		  		cout << "Input tidak valid!" << endl;
  		  		continue;
  		  	} break; }
  		  for (int i = 0; i < n0; ++i) {
  		  	for (int j = 0; j < n1; ++j) {
  		  		for (int k = 0; k < (n1 - j + 1)
  		  			 + (n0 - i) * 2; ++k) {
  		  			cout << " "	; }
  		  		for (int k = 0; k < ((j * 2) + 1) + (i * 4); k += 2) {
  		  			cout << "* "; }
  		  		cout << endl;
  		  	}
  		  }
  		  for (int i = 0; i < 4; ++i) {
  		  	for (int j = 0; j < (n1 + n0) + (n0 - 2); ++j) {
  		  		cout << " ";
  		  	}
  		  	cout << "* * * *" << endl;
  		  }
  		} break;
  		case 2: {
  			cout << "-----------------------------------" << endl;
  			cout << "|          POLA BILANGAN          |" << endl;
  			cout << "-----------------------------------" << endl;
  			while (true) {
  			  cout << "Masukan nilai n: ";
  			  cin >> n0;
  			  if (cin.fail() || n0 < 1) {
  			  	cin.clear(); cin.ignore();
  			  	cout << "Input tidak valid!" << endl;
  			  	continue;
  			  } break; }
  			if ((n0 & 0x1) == 0) {
  			  cout << "<1> ";
  			  for (unsigned int i = 2; i < n0; ++i) {
  			  	bool prime = true;
  
  			  	for (unsigned int j = 2; j < i; ++j) {
  			  	  if (i % j == 0) prime = false;
  			  	}
