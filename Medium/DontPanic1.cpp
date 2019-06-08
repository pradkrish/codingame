#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
  int nbFloors; // number of floors
  int width; // width of the area
  int nbRounds; // maximum number of rounds
  int exitFloor; // floor on which the exit is found
  int exitPos; // position of the exit on its floor
  int nbTotalClones; // number of generated clones
  int nbAdditionalElevators; // ignore (always zero)
  int nbElevators; // number of elevators
  vector<int> elevatorPos(nbElevators);
  cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
  for (int i = 0; i < nbElevators; i++) {
    int elFloor; // floor on which this elevator is found
    int elPos; // position of the elevator on its floor
    cin >> elFloor >> elPos; cin.ignore();
    elevatorPos[elFloor] = elPos;
  }
    
  map<string, int> sgnDirection;
  sgnDirection["LEFT"] = -1;
  sgnDirection["RIGHT"] = 1;
    
  // game loop
  int count = 0;
  while (1) {
    int cloneFloor; // floor of the leading clone
    int clonePos; // position of the leading clone on its floor
    string direction; // direction of the leading clone: LEFT or RIGHT
    cin >> cloneFloor >> clonePos >> direction; cin.ignore();

    int targetPos;
        
    if (exitFloor == cloneFloor) {
      targetPos = exitPos;
    } else {
      targetPos = elevatorPos[cloneFloor];
    } 
        
    int multiplier = (targetPos - clonePos) * sgnDirection[direction];
    if (multiplier >= 0) {
      cout << "WAIT" << endl;
    } else if (!elevatorPos.empty()) {
      cout << "BLOCK" << endl;
    }
        
    ++count;
  }
}
