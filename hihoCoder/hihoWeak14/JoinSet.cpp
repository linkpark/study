#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, string> represent;

void Init(string &name) { represent[name] = name; }

string FindRepresent(string &name) {
  if (name == represent[name])
    return name;

  else {
    represent[name] = FindRepresent(represent[name]);
    return represent[name];
  }
}

void JoinTwoSet(string &name_1, string &name_2) {
  string represent_set_1 = FindRepresent(name_1);
  string represent_set_2 = FindRepresent(name_2);

  represent[represent_set_1] = represent_set_2;
}

int main(void) {
  int t;
  int op_i;
  string name_1, name_2;
  cin >> t;

  while (t--) {
    cin >> op_i >> name_1 >> name_2;

    if (represent.find(name_1) == represent.end()) {
      Init(name_1);
    }

    if (represent.find(name_2) == represent.end()) {
      Init(name_2);
    }

    if (op_i == 0) {
      JoinTwoSet(name_1, name_2);
    } else if (op_i == 1) {
      if (FindRepresent(name_1) != FindRepresent(name_2))
        cout << "no" << endl;
      else
        cout << "yes" << endl;
    }
  }

  return 0;
}
