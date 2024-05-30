        } cout << endl; }
      float x;
      if (matrix[4] != 0 && matrix[8] != 0
        && matrix[9] != 0) {
        x = matrix[4]/matrix[0];
        for (int i = 0; i < 4; ++i)
          matrix[4 + i] += matrix[i] * -x;
        x = matrix[8]/matrix[0];
        for (int i = 0; i < 4; ++i)
          matrix[8 + i] += matrix[i] * -x;
        x = matrix[9]/matrix[5];
        for (int i = 0; i < 4; ++i)
          matrix[8 + i] += matrix[4 + i] * -x; }
      cout << "Matriks Segitiga Atas | SPL\n";
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          cout << matrix[i * 4 + j] << " ";
        } cout << " | " << matrix[(i + 1) * 4 - 1] << endl; }
      float z = matrix[11]/matrix[10];
      float y = (matrix[7] - (matrix[6] * z))/matrix[5];
      x = (matrix[3] - (matrix[2] * z) - matrix[1] * y)/matrix[0];
      cout << "x: " << x << "\n";
      cout << "y: " << y << "\n";
      cout << "z: " << z << "\n";
    } break; } }
