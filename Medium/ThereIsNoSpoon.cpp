#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int W; // the number of cells on the X axis
  cin >> W; cin.ignore();
  int H; // the number of cells on the Y axis
  cin >> H; cin.ignore();

  string* node = new string[H];
  for (int i = 0; i < H; i++) {
    getline(cin, node[i]); 
  }

  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      if (node[y][x] == '0') {
	cout << x << ' ' << y << ' ';
	int xR, yD, rightX = -1, rightY = -1;
	int downX = -1, downY = -1;
	for (xR = x+1; xR < W; ++xR) {
	  if (node[y][xR] == '0') {
	    rightX = xR;
	    rightY = y;
	    break;
	  }
	}
	cout << rightX << ' ' << rightY << ' ';
	for (yD = y+1; yD < H; ++yD) {
	  if (node[yD][x] == '0') {
	    downX = x;
	    downY = yD;
	    break;
	  }
	}
	cout << downX << ' ' << downY << '\n';
      }
    }
  }
}
