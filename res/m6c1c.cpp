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
