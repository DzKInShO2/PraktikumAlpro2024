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
