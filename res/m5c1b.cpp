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
