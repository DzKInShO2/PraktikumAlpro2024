      for (int k = mid + 1; k < l; ++k) { 
        if (numbers[k] != ' ') break; mid = k;
      }
    }
  }
  cout << "\nHasil rotasi 90 derajat searah jarum jam:" << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = m - 1; j >= 0; --j) cout <<matrix[j * m + i]<< " ";
    cout << endl; 
  }
  cout << "\nHasil pencerminan terhadap sumbu X:\n";
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) cout <<matrix[j * m + i]<< " ";
    cout << endl;
  }
}
