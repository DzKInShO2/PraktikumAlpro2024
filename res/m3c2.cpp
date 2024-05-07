      } int base = 1;
      for (int k = mid - 1; k >= 0; --k) {
        if (numbers[k] == ' ') break;
        if (numbers[k] == '-') {
          matrix[i * m + j] *= -1; break;
        }
        matrix[i * m + j] += (int)(numbers[k] - '0') * base;
        base *= 10;
      }
      for (int k = mid + 1; k < l; ++k) { 
        if (numbers[k] != ' ') break; mid = k;
      }
    }
  }
  cout << "\nHasil rotasi 90 derajat searah jarum jam:" << endl;
  for (int i = 0; i < m; ++i) {
    for (int j = n - 1; j >= 0; --j) cout <<matrix[j * n + i]<< " ";
    cout << endl; 
  }
  cout << "\nHasil pencerminan terhadap sumbu X:\n";
  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) cout <<matrix[j * n + i]<< " ";
    cout << endl;
  }
}
