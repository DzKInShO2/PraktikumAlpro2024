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
