int user_bills[user_max];
int user_logged_id = -1;
int user_count = 1;
int console_prices[4] = { 0, 5000, 10000, 15000 };
const int food_max = 20;
string foods[food_max];
int food_prices[food_max];
int food_count = 0;
int app_state = 0;
void pause() {
  cout << "Press any key to continue. . .\n";
  cin.clear(); cin.ignore(); cin.get(); }
void input_invalid() {
  cin.clear(); cin.ignore();
  cout << "Masukan tidak valid\n"; }
int nselector(int l, int u, string c = ">> ") {
  int n;
  while (true) {
    cout << c;
    cin >> n;
    if (cin.fail() || n < l || n > u) {
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
