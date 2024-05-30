        cout << "1. Masukan Makanan\n";
        cout << "2. Hapus Makanan\n";
        cout << "3. Kembali\n";
        int n = nselector(1, 3);
        if (n == 1) {
          cout << "\33[H\33[2J"; topbar();
          cout << "Masukan Makanan/Minuman: ";
          cin.clear(); cin.ignore();
          getline(cin, foods[food_count]);
          cout << "Masukan Harga: ";
          cin >> food_prices[food_count];
          cout << "Makanan/Minuman Berhasil"
             << " Dimasukan\n";
          food_count++;
          pause(); app_state = 3; break;
        } else if (n == 3) {
          app_state = 1; break; }
        app_state |= (0x1 << 4);
        break; }
      int n = nselector(1, food_count + 1);
      if (n == food_count + 1) {
        app_state = 3;
        break; }
      cout << foods[n - 1] << " berhasil dihapus\n";
      for (int i = (n - 1); i < food_max - 1; ++i) {
        foods[i] = foods[i + 1];
        food_prices[i] = food_prices[i + 1];
      } food_count--;
      pause(); app_state = 3;
    } break;
    case 2: {
      cout << "Data Penyewa\n";
      for (int i = 1; i < user_count; ++i) {
        cout << i << ". " << "Username: "
           << users[i * 2] << " (Rp."
           << user_bills[i] << ")\n"; }
      app_state = 1; pause();
    } break; } }
int main() {
  while (true) {
    cout << "\33[H\33[2J";
    if (app_state == 0x6) return 0;
    else if (app_state == 0x9) {
      user_logged_id = -1;
      app_state = 0; }
    else if (user_logged_id == 0 &&
         app_state == 0x7) {
      user_logged_id = -1;
      app_state = 0; }
    switch (app_state & 0x1) {
      case 0: {
        unlogged_page();
      } break;
      case 1: {
        if (user_logged_id == 0) admin_page();
        else logged_page(); } } } }
