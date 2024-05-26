      cout << "List Makanan/Minuman\n";
      if (food_count == 0) {
        cout << "Makanan Belum Tersedia\n";
        app_state = 1; pause();
        break;
      }
      for (int i = 0, j = 0; i < food_count; ++i) {
        cout << i + 1 << ". "
           << foods[i] << " (Rp. "
           << food_prices[i] << ")\n";
      } cout << food_count + 1 << ". Kembali\n";
      int n = nselector(1, food_count + 1);
      if (n == food_count + 1) {
        app_state = 1;
        break;
      }
      cout << "Makanan yang dipilih: " << foods[n - 1] << "\n";
      cout << "Harga: " << food_prices[n - 1] << "\n";
      user_bills[user_logged_id] += food_prices[n - 1]
            * nselector(1, 9*9*9, "Jumlah: ");
      cout << foods[n - 1] << " berhasil dipesan\n";
      pause();
    } break;
    case 3: {
      char choice = 'y';
      while (true) {
        cout << "Apakah anda ingin mendaftar sebagai"
           << " member rental PS?(Y/T): ";
        cin >> choice;
        if (cin.fail() ||
          ((choice != 'Y' && choice != 'y') &&
           (choice != 'T' && choice != 't'))) {
          input_invalid();
          continue;
        } break;
      }
      if (choice == 'Y' || choice == 'y') {
        if (user_membership[user_logged_id])
          cout << "Anda sudah terdaftar sebagai member\n";
        else {
          cout << "Anda berhasil mendaftar sebagai member\n";
          user_membership[user_logged_id] = true;
        }
      } app_state = 1; pause();
    } break; } }
void admin_page() {
  topbar();
  switch ((app_state & 0x6) >> 1) {
    case 0: {
      cout << "1. Jual Makanan\n";
      cout << "2. Data Penyewa\n";
      cout << "3. log-out\n";
      app_state |= (nselector(1, 3) << 0x1);
    } break;
    case 1: {
      cout << "List Makanan/Minuman\n";
      if (food_count == 0) {
