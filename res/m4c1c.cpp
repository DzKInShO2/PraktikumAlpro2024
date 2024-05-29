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
        pause(); }
      app_state = 1;
    } break;
    case 2: {
      cout << "List Makanan/Minuman\n";
      if (food_count == 0) {
        cout << "Makanan Belum Tersedia\n";
        app_state = 1; pause();
        break; }
      for (int i = 0, j = 0; i < food_count; ++i) {
        cout << i + 1 << ". "
           << foods[i] << " (Rp. "
           << food_prices[i] << ")\n";
      } cout << food_count + 1 << ". Kembali\n";
      int n = nselector(1, food_count + 1);
      if (n == food_count + 1) {
        app_state = 1;
        break; }
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
