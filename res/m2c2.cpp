#include <conio.h>
#include <iostream>
using namespace std;
int main() {
  char state = 0; int n0 = 0; int n1 = 0;
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
  			  	if (prime) {
  			  	  if (n0 <= 50 && (i % 10) == 3)  {
  			  	  	cout << "(" << i << "*n = " << (i * n0) << ") ";
  			  	  	continue;
  			  	  }
  			  	  cout << "<" << i << "> ";
  			  	}
  			  }
  			  cout << endl;
  			  break;
  			}
  			unsigned long long n = 1;
  			for (unsigned int i = 0; i < n0; ++i) {
  				if (i == 0) {
  					cout << n;
  					continue; }
  				n *= 11;
  				cout << ", " << n;
  			}
  			cout << endl;
  		} break;
  		case 3: {
  			return 0;
  		} break; }
  		cout << "Tekan tombol apapun untuk kembali!" << endl;
  		if (getch()) {
  			state &= 0x0; }
      } break; } } return 0; }
