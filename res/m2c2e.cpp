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
  		case 3: { // Keluar
  			return 0;
  		} break;
  
  		}
  		cout << "Tekan tombol apapun untuk kembali!" << endl;
  		if (getch()) {
  			state &= 0x0;
  		}
      } break;
  	}
  }
}
