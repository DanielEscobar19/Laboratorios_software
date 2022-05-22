#include <iostream>
#include <string>
using namespace std;

int main() {
  string maze = "{";
  maze = maze + "\n\t" + "\"" + "maze" + "\" :";
  string room = "";

  room = room + "\n\t{\n\t\t\"Room\" : \n\t\t{";
  room = room + " \n\t\t\t\"Type\" : \"" + "tipo" + "\",";
  room = room + " \n\t\t\t\"id\" :" + to_string(2) + ',';
  room = room + "\n\t\t\t{puerta},";
  room = room + "\n\t\t\t{pared}";
  room = room + "\n\t\t}"; // finaliza el serializado de room 

  cout << "\n\n" << maze << room;
  maze = "\n}";
  cout << maze;
  cout << "\n\n";

  return 0;
}