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
  char ch;
  while (true) {
    cout << c;
    cin >> ch;
    if (ch > '`' && ch < '{') ch -= 32;
    if (cin.fail() || (ch != 'Y' && ch != 'N')) {
      input_invalid();
      continue;
    } break; }
  return ch;
}
void free_stack(Stack *st) {
  for (int i = 0; i < stack.count; ++i) {
      if (st->type[i] == STACK_TYPE_VALUE)
        delete (int *)st->ptr[i];
      else if (st->type[i] == STACK_TYPE_FUNCTION)
        delete (Function *)st->ptr[i]; }
}
void* push_to_stack(int type) {
  if (type == STACK_TYPE_FUNCTION)
    return (void *)new Function();
  return (void *)new int;
}
void add_data() {
  if (stack.filled) {
    free_stack(&stack);
    stack.filled = false;
    if (stack.count == 6) stack.count = 9;
    if (stack.count == 3) stack.count = 6; }
  cout << "Current Stack Size: " << stack.count << endl;
  for (int i = 0; i < stack.count; ++i) {
    char c0=cselector('Y', 'N', "Will You Add Function? (Y/N) : ");
    if (c0 == 'Y') {
      stack.type[i] = STACK_TYPE_FUNCTION;
      stack.ptr[i] = push_to_stack(STACK_TYPE_FUNCTION);
      Function *fp = (Function *)stack.ptr[i];
      char c1 = cselector('Y', 'N', "Have Argument(s)? (Y/N): ");
      cout << "Function - " << i + 1 << " To Push : ";
      getline(cin >> ws, fp->name);
      if (c1 == 'Y') {
        fp->argument_count = nselector(1, register_max,
                         "How many arguments ? ");
        for (int j = 0; j < fp->argument_count; ++j) {
          cout << "Argument - " << j + 1 << " : ";
          getline(cin >> ws, fp->arguments[j]);
        }
      } else fp->argument_count = 0;
    } else if (c0 == 'N') {
      stack.type[i] = STACK_TYPE_VALUE;
      stack.ptr[i] = push_to_stack(STACK_TYPE_VALUE);
      *((int *)stack.ptr[i]) = nselector("Nilai - ", i + 1);
    }
  } stack.filled = true;
}
void debug_mode() {
  while (true) {
    string arg;
    cout << "Debug Command => ";
    getline(cin >> ws, arg);
    if (arg == "exit") return;
    if (arg == "info stack") {
      int i = 0;
      if (stack.type[i] < 0) {
        cout << "Anda seharusnya tidak berada disini...\n";
        continue; }
      while (true) {
        topbar();
        if (i > stack.count - 1) {
          cout << "REGISTER\n";
          cout << "No Registers!\n";
          cout << "STACK\n";
          cout << "No Stacks!\n";
          pause(); return; }
        cout << "REGISTER\n";
        for (int j = 0; j < register_max; ++j) {
          cout << registers[j] << " : ";
          if (stack.type[i] == STACK_TYPE_FUNCTION) {
            Function *fp = (Function *)stack.ptr[i];
            if (j < fp->argument_count) {
              cout << fp->arguments[j] << endl;
              continue; }
          } cout << "0\n"; }
        cout << "STACK\n";
        for (int j = 0; j < stack.count; ++j) {
          if (j == i) cout << "=> ";
          else cout << "   ";
          cout << stack.ptr[j] << "   ";
          if (stack.type[j] == STACK_TYPE_FUNCTION) {
            cout << ((Function *)stack.ptr[j])->name << "\n";
          } else if (stack.type[j] == STACK_TYPE_VALUE) {
            cout << *((int *)stack.ptr[j]) << "\n";
          } }
        cout << "Debug Command => ";
        getline(cin >> ws, arg);
        if (arg == "ni") i++;
        if (arg == "pi") i--;
        if (i < 0) i = stack.count - 1;
      } } } }
int main() {
  int state = 0;
  while (true) {
    topbar();
    cout << "1. Add Data\n";
    cout << "2. Debug Mode\n";
    cout << "3. Exit\n";
    state = (nselector(1, 3) - 1);
    switch (state) {
      case 0: {
        add_data();
      } break;
      case 1: {
        debug_mode();
      } break;
      case 2: return 0; } } }
