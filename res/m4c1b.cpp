      cout << "1. Login\n2. Sign-In\n";
      cout << "3. Exit\n";
      app_state = (nselector(1, 3) << 0x1);
    } break;
    case 1: {
      cout << "================================\n";
      cout << "=============Log-In=============\n";
      cout << "================================\n\n";
      string name, password;
      cout << "Masukan Username: "; cin >> name;
      cout << "Masukan Password: "; cin >> password;
      if (app_state = login(name, password))
        cout << "Log-In Berhasil\n";
      else cout << "Log-In Tidak Berhasil\n";
      pause();
    } break;
    case 2: {
      cout << "================================\n";
      cout << "=============Sign-In============\n";
      cout << "================================\n\n";
      string name, password;
      cout << "Masukan Username: "; cin >> name;
      cout << "Masukan Password: "; cin >> password;
      if (signin(name, password)) cout << "Sing-In Berhasil\n";
      else cout << "Username sudah ada\n";
      pause(); app_state = 0;
    } break; } }
void logged_page() {
  topbar();
  switch ((app_state & 0x6) >> 0x1) {
    case 0: {
      cout << "1. Melakukan Rental PS\n";
      cout << "2. Memesan Makanan\n";
      cout << "3. Daftar Member\n";
      cout << "4. log-out\n";
      app_state |= (nselector(1, 4) << 0x1);
    } break;
    case 1: {
      cout << "Harga Rental PS\n";
      cout << "1. PS 3: 1 Jam (Rp. 5.000)\n";
      cout << "2. PS 4: 1 Jam (Rp. 10.000)\n";
      cout << "3. PS 5: 1 Jam (Rp. 15.000)\n";
      cout << "4. Kembali\n";
      {
        int n = nselector(1, 4);
        if (n == 4) break;
        int m = nselector(1, 9*9*9*9, "Jumlah Jam: ");
        float discount = (float)(console_prices[n] * m) *
          ((0.1f * (m >= 3 && m < 6)) + (0.2f * (m >= 6))
           + (user_membership[user_logged_id] * 0.2f));
        user_bills[user_logged_id]
          += (console_prices[n] * m) - discount;
        pause();
      }
      app_state = 1;
    } break;
    case 2: {
