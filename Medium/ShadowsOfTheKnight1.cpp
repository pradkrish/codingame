#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Contains(string str, string s)
{
  size_t found = str.find(s);
  if (found != string::npos)
    return true;
  
  return false;
}

int main()
{
  int W; // width of the building.
  int H; // height of the building.
  cin >> W >> H; cin.ignore();
  int N; // maximum number of turns before game over.
  cin >> N; cin.ignore();
  int x;
  int y;
  cin >> x >> y; cin.ignore();

  int x1 = 0;
  int y1 = 0;
  int x2 = W - 1;
  int y2 = H - 1;
  
  // game loop
  while (1) {
    string bombDir; 
    cin >> bombDir; cin.ignore();
    
    if (Contains(bombDir,"U")) {
      y2 = y - 1;
    } else if (Contains(bombDir,"D")) {
      y1 = y + 1; 
    } 
    
    if (Contains(bombDir, "L")) {
      x2 = x - 1;
    } else if (Contains(bombDir, "R")) {
      x1 = x + 1;
    }
    
    x = (x1 + x2)/2;
    y = (y1 + y2)/2;
    
    cout << to_string(x) + " " + to_string(y) << endl;
  }
}
