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
