#include <vector>
#include <iostream>

using namespace std;

using Row = vector<int>;
using Matrix = vector<Row>;

void extendZeros(Matrix &matrix, int rows, int cols) {
  vector<bool> zeroRow(rows, false);
  vector<bool> zeroCol(cols, false);

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
        bool zeroFound = (matrix[r][c] == 0);
        zeroRow[r] = zeroRow[r] || zeroFound;
        zeroCol[c] = zeroCol[c] || zeroFound;
    }
  }

  for (int r = 0; r < rows; ++r) {
    if (zeroRow[r]) {
      for (int c = 0; c < cols; ++c) {
        matrix[r][c] = 0;
      }
    }
  }

  for (int c = 0; c < cols; ++c) {
    if (zeroCol[c]) {
      for (int r = 0; r < rows; ++r) {
        matrix[r][c] = 0;
      }
    }
  }
}

int main(void) {
  int rows, cols;
  cin >> rows >> cols;

  Matrix matrix(rows, Row(cols, 0));

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      cin >> matrix[row][col];
    }
  }

  extendZeros(matrix, rows, cols);

  cout << endl;
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      cout << matrix[row][col] << " ";
    }
    cout << endl;
  }

  return 0;
}