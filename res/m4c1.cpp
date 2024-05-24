#include <iostream>
using namespace std;
const int user_max = 20;
string users[user_max * 2] = { [0] = "admin", [1] = users[0] };
bool user_membership[user_max];
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
        cout << "Makanan/Minuman Belum Tersedia\n";
      } else {
        for (int i = 0; i < food_count; ++i) {
          if (app_state >> 4 == 0) cout << "~ ";
          else cout << i + 1 << ". ";
          cout << foods[i] << " (Rp. "
             << food_prices[i] << ")\n";
        }
        if (app_state >> 4 != 0)
          cout << food_count + 1 << ". Kembali\n";
        else cout << "\n";
      }
      if ((app_state >> 4) == 0) {
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
          app_state = 1; break;
        }
        app_state |= (0x1 << 4);
        break;
      }
      int n = nselector(1, food_count + 1);
      if (n == food_count + 1) {
        app_state = 3;
        break;
      }
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
           << user_bills[i] << ")\n";
      }
      app_state = 1; pause();
    } break; } }
int main() {
  while (true) {
    cout << "\33[H\33[2J";
    if (app_state == 0x6) return 0;
    else if (app_state == 0x9) {
      user_logged_id = -1;
      app_state = 0;
    }
    else if (user_logged_id == 0 &&
         app_state == 0x7) {
      user_logged_id = -1;
      app_state = 0;
    }
    switch (app_state & 0x1) {
      case 0: {
        unlogged_page();
      } break;
      case 1: {
        if (user_logged_id == 0) admin_page();
        else logged_page();
      } } } }
