#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void buildFactory(vector<string>& allRows, vector<vector<string>>& letterFactory, 
                  int types, int H)
{
  int L =  allRows[0].size()/types;
  for (int j = 0; j < types; ++j) {
    vector<string> letter;
    for (int i = 0; i < H; ++i) {
      letter.push_back(allRows.at(i).substr(L*j,L));
    }
    letterFactory.push_back(letter);
  }
}

void buildOutput(vector<vector<string>>& letterFactory, vector<int>& outputIndex,
		vector<string>& output)
{
  int H = letterFactory[0].size();
  int types = letterFactory.size();
  
  for (int j = 0; j < H; ++j) {
    string str;
    for (auto i : outputIndex) {
      if (i < 0 || i > types-2) {
	str += letterFactory[types-1][j];
      } else {
	str += letterFactory[i][j];
      }
    }
    output.push_back(str);
  }
}

int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    string firstLetter = "A";
    getline(cin, T);
    vector<string> allRows;
    vector<vector<string>> letterFactory;
    vector<int> outputIndex;
    vector<string> output;
    
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
	    allRows.push_back(ROW);
    }
    
    int types = allRows.at(0).size()/L;
    buildFactory(allRows, letterFactory, types, H);

    std::transform(T.begin(), T.end(), T.begin(), ::toupper);

    for (int s = 0; s < T.size(); ++s) {
      outputIndex.push_back(T[s] - firstLetter[0]);
    }

    buildOutput(letterFactory, outputIndex, output);
    for (auto str : output)
      cout << str  << endl;
}
