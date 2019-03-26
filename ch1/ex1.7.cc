#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Pixel {
  unsigned char r,g,b,a;

  string toString() {
    return "(" + 
             to_string(r) + "," +
             to_string(g) + "," +
             to_string(b) + "," +
             to_string(a) + 
            ")";
  }

};

using Image = vector<vector<Pixel>>;

inline void swapPixel(Pixel& a, Pixel& b) {
  Pixel aux = a;
  a = b;
  b = aux;
}

void transposeImage(Image& img, int size) {
  for (int d = 0; d < size; ++d) {
    for (int p = d + 1; p < size; ++p) {
      swapPixel(img[d][p], img[p][d]);
    }
  }
}

void mirrorImage(Image& img, int size) {
  int middle = size / 2;
  for (int topRow = 0; topRow < middle; ++topRow) {
    int bottonRow = size - topRow - 1;
    for (int col = 0; col < size; ++col) {
      swapPixel(img[topRow][col], img[bottonRow][col]);
    }
  }
}

void rotateImage(Image& img, int size) {
  transposeImage(img, size);
  mirrorImage(img, size);
}

int main(void) {
  int size;
  cin >> size;

  Image img(size, vector<Pixel>(size, {0,0,0,0}));

  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      unsigned char value = row * size + col;
      img[row][col] = {value, value, value, value};
      cout << img[row][col].toString() << " ";
    }
    cout << endl;
  }
  cout << endl;

  rotateImage(img, size);

  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      cout << img[row][col].toString() << " ";
    }
    cout << endl;
  }

  return 0;
}