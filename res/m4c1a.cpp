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
