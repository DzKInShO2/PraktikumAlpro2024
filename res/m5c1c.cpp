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
