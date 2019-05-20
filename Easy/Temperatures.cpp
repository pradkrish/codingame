#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int signChange(vector<int>& vec)
{
  int v = 0;
  while (v < vec.size() - 1) {
    if (signbit(vec.at(v)) != signbit(vec.at(v+1))) {
      return v;
    }
    ++v;
  }
  return v;
}

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    vector <int> vec;
    int res;
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        vec.push_back(t);
    }
    
    if (vec.size()) {
        sort(vec.begin(),vec.end());
        int index = signChange(vec);
        if (index != vec.size()-1) {
            res = min(abs(vec.at(index)),abs(vec.at(index+1)));
        } else if (index == vec.size()-1) {
            res = (vec.at(index) >= 0 ? vec.at(0) : vec.at(index));
        }
    } else {
        res = 0;
    }
    
    cout << res << endl;
    return 0;
}
