#include <iostream>
using namespace std;
const string registers[] = {
  "RDI", "RSI", "RDX", "RCX", "R8 ", "R9 "
};
const int register_max = sizeof registers / sizeof *registers;
struct Function {
  string name;
  string arguments[register_max];
  int argument_count;
};
const int stack_max = 9;
struct Stack {
  void *ptr[stack_max];
  int type[stack_max] = { -1 };
  int count = 3;
  bool filled = false;
};
Stack stack;
const int STACK_TYPE_VALUE = 0;
const int STACK_TYPE_FUNCTION = 1;
void topbar() {
  cout << "\33[H\33[2J";
  cout << " LEARN STACK LAYOUT\n";
  cout << "\n\n\n";
}
void pause() {
  cout << "Press any key to continue. . .\n"; cin.get();
}
void input_invalid() {
  cin.clear(); cin.ignore();
  cout << "Masukan tidak valid\n";
}
int nselector(int l, int u, const string& c = ">> ") {
  int n;
  while (true) {
    cout << c;
    cin >> n;
    if (cin.fail() || n < l || n > u) {
      input_invalid();
      continue;
    } break; }
  return n;
}
int nselector(const string& c = "", int i = 0) {
  int n;
  while (true) {
    cout << c << i << " : ";
    cin >> n;
    if (cin.fail()) {
      input_invalid();
      continue;
    } break; }
  return n;
}
char cselector(char y='Y', char n='N', string c = ">> ") {
