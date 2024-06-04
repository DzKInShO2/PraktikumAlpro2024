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
    char c0 = cselector('Y', 'N', "Will You Add Function? (Y/N) : ");
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
