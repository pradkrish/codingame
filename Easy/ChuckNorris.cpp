#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

string stringToBinary(string& text) {
  string binaryString = "";
  for (char& c : text) {
    binaryString +=bitset<7>(c).to_string();
  }
  return binaryString;
}

void vectorizeBinaryText(string& binText, vector<string>& vec)
{
  string str = "";
  str += binText[0];
  for (int i = 1; i<binText.size(); ++i) {
    if (binText[i] == binText[i-1]) {
      str += binText[i];
    } else {
      vec.push_back(str);
      str.clear();
      str += binText[i];
    }
  }
  vec.push_back(str);
}

string binaryToUnary(vector<string>& vec)
{
  string result = "";
  for (auto v : vec) {
    string initial = "";
    initial += v[0];
    if (initial == "0") {
      result = result + "00" + " " + string(v.size(),'0') + " ";
    } else {
      result = result + "0" + " " + string(v.size(),'0') + " ";
    }
  }
  result.pop_back();
  return result;
}

int main()
{
  string MESSAGE;
  getline(cin, MESSAGE);
  string binText =  stringToBinary(MESSAGE);

  vector<string> vec;
  vectorizeBinaryText(binText, vec);
   
  cout << binaryToUnary(vec) << endl;
}
