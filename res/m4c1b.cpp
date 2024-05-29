      input_invalid();
      continue;
    } break;
  } return n; }
bool login(string name, string password) {
  for (int i = 0; i < user_count; ++i) {
    if (name == users[i * 2]
      && password == users[i * 2 + 1]) {
      user_logged_id = i;
      return true;
    }
  } return false; }
bool signin(string name, string password) {
  for (int i = 0; i < user_count; ++i) {
    if (name == users[i * 2]) return false;
  }
  users[user_count * 2] = name;
  users[user_count * 2 + 1] = password;
  user_membership[user_count] = false;
  user_bills[user_count] = 0;
  user_count++;
  return true; }
void topbar() {
  cout << "================================\n";
  cout << "=========Rental PS Rijal========\n";
  cout << "================================\n\n"; }
void unlogged_page() {
  switch ((app_state & 0x6) >> 0x1) {
    case 0: {
      topbar();
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
