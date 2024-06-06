#include <iostream>
using namespace std;
const int WAGON_MAX = 26;
const int PASSANGER_MAX = 10;
struct Wagon {
  int passanger_count = 0;
  string passangers[PASSANGER_MAX]; };
string wagon_types[] = {
  "EKO", "BISNIS", "RAJA" };
void pause() {
  cout << "Press any key to continue. . .\n";
  cin.clear(); cin.ignore(); cin.get(); }
void input_invalid(string text = "Masukan tidak valid") {
  cin.clear(); cin.ignore();
  cout << text << "\n"; }
int nselector(int l, int u, string c = ">> ") {
  int n;
  while (true) {
    cout << c; cin >> n;
    if (cin.fail() || n < l || n > u) {
      input_invalid();
      continue;
    } break;
  }
  return n; }
string tselector(string msg) {
  string t;
  while (true) {
    cout << msg;
    cin >> t; 
    if (cin.fail() || (t != "EKO" &&
      t != "BISNIS" && t != "RAJA")) {
      input_invalid(
        string{
          "Harap masukkan kelas tiket EKO, BISNIS, "
        } + "atau RAJA"
      ); continue;
    } break; }
  return t; }
int wagon_type_to_index(string type) {
  return 0 + (type == wagon_types[1]) +
       (2 * (type == wagon_types[2])); }
void topbar() {
  cout << "\33[H\33[2J";
  cout << " /\\_/\\  PT KAP (KERETA API PROGRAMMER) \n";
  cout << "( o.o ) PROGRAM SISTEM TIKET DAN GERBONG KERETA \n";
  cout << " > ^ <  DIBUAT OLEH PJ MODUL 5 ALPRO 2024\n";
  cout << "================================================\n"; }
int main() {
  topbar();
  int n = nselector(1, WAGON_MAX,
          "Masukan jumlah gerbong kereta penumpang: ");
  int wagon_count = n;
  Wagon wagons[wagon_count] = { 0 }; int state = 0;
  bool is_severed = false; int severed_index = WAGON_MAX;
  while (true) {
    topbar(); cout << "A";
    for (int i = 0; i < n; ++i) {
      if (i == severed_index + 1)
        cout << "-- X -";
      cout << "-" << (char)(66 + i);
      if (i < severed_index + 1)
        cout << wagons[i].passanger_count;
    } cout << endl;
    switch (state) {
      case 0: {
        cout << "Menu:\n1. Tambah Penumpang\n";
        cout << "2. Hapus Penumpang\n3. Info Gerbong\n";
        if (!is_severed) cout << "4. Lepas Gerbong\n";
        state = nselector(1, 3 + (!is_severed), string{
          "Input (1,2,3"} + (is_severed ? "): ":",4): "));
        if (state == 4) {
          while (true) {
            cout << "Masukan nama gerbong yang ingin dilepas: ";
            char c; cin >> c;
            if (c > '`' && c < '{') c -= 32;
            if (cin.fail() || c < 'B'
              || c > (char)(66 + wagon_count)) {
              cin.clear(); cin.ignore();
              if (c == 'A') {
                cout << "Tidak bisa melepas gerbong A yang"
                   << " berisi mesin!\n";
                continue;
              }
              cout << "Masukan bukan merupakan gerbong!\n";
              continue;
            } wagon_count = (severed_index = c - 67) + 1;
            break;
          } state = 0; is_severed = true;
        }
      } break;
      case 1: {
        string name, type;
        cout << "Masukan nama penumpang: "; getline(cin >> ws, name);
        type = tselector("Pilih kelas tiket (EKO, BISNIS, RAJA): ");
        int wagon_index = wagon_type_to_index(type);
        while (wagon_index > wagon_count - 1) {
          input_invalid(
            string{"Gerbong kelas "} + type + " yang tersedia: " +
            "TIDAK ADA\nHarap pilih kelas lainnya!"
          );
          type=tselector("Pilih kelas tiket (EKO, BISNIS, RAJA): ");
          wagon_index = wagon_type_to_index(type);
        }
        cout << "Gerbong kelas " << type << " yang tersedia: ";
        for (int i = wagon_index; i < wagon_count; i += 3) {
          cout << (char)(66 + i) << " ";
        } cout << endl;
        while (true) {
          cout << "Pilih lokasi gerbong: ";
          char c; cin >> c;
          if (c > '`' && c < '{') c -= 32;
          if (cin.fail() || c < 'B'
            || c > (char)(66 + wagon_count)
            || ((c - 66) % 3) != wagon_index) {
            cin.clear(); cin.ignore();
            if (c == 'A') {
              cout << "Tidak bisa melepas gerbong mesin,"
                 << " harap pilih gerbong lainnya\n";
              continue; }
            cout << "Tidak bisa memilih gerbong " << c << " karena"
               << " gerbong bukanlah " << type << "\n";
            continue; }
          wagons[(c - 66)].passangers[
            wagons[(c - 66)].passanger_count++] = name;
          break; }
        pause(); state = 0;
      } break;
      case 2: {
        int match_count = 0;
        int match_id[wagon_count * PASSANGER_MAX * 2];
        string name; cout
        <<"Masukan nama penumpang yang ingin dihapus dari daftar: ";
        getline(cin >> ws, name); string type = tselector(
          "Masukan kelas tiket yang dimiliki(EKO, BISNIS, RAJA): ");
        for (int i=wagon_type_to_index(type);i<wagon_count;i+=3) {
          for (int j = 0; j < wagons[i].passanger_count; ++j) {
            if (name == wagons[i].passangers[j]) {
              match_id[match_count++] = i;
              match_id[match_count++] = j;
              cout << match_count/2 << ". "
                 << wagons[i].passangers[j]
                 << " (" << type << ") "
                 << "di Gerbong " << (char)(66+i)
                 << "\n"; } } }
        if (match_count == 0) {
          cout << "Tidak ditemukan penumpang dengan nama " << name
             << " di kelas " << type << "\n";
        } else {
          int d = nselector(1, match_count/2,
                    "Ingin menghapus penumpang nomor berapa: ");
          for (int i = match_id[d];
             i < wagons[match_id[d - 1]].passanger_count - 1; ++i) {
            wagons[match_id[d - 1]].passangers[i]
              = wagons[match_id[d - 1]].passangers[i + 1];
          }
          wagons[match_id[(wagons[match_id[d - 1]]
            .passanger_count == 1 ? d : d - 1)]].passanger_count--;
          cout << "Penumpang berhasil dihapus!\n"; }
        pause(); state = 0; } break;
      case 3: {
        cout << "Jumlah penumpang EKO: ";
        int m = 0;
        for (int i = 0; i < wagon_count; i += 3)
          m += wagons[i].passanger_count;
        cout << m << " Bisnis: "; m = 0;
        for (int i = 1; i < wagon_count; i += 3)
          m += wagons[i].passanger_count;
        cout << m << " RAJA: ";
        for (int i = 1; i < wagon_count; i += 3)
          m += wagons[i].passanger_count;
        cout << m << "\n";
        for (int i = 0; i < wagon_count; ++i) {
          cout << "Gerbong " << (char)(66 + i) << " ("
             << wagon_types[i % 3] << "):\n";
          if (wagons[i].passanger_count == 0) {
            cout << "Kosong\n"; continue; }
          for (int j = 0; j < wagons[i].passanger_count; ++j)
            cout << j + 1 << ". " << wagons[i].passangers[j] << "\n";
        } pause(); state = 0; } break; } } }
