#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
  vector < int >twoSum (vector < int >&numbers, int target)
  {
    map < int, int >numberContainer;
      vector < int >result (2);
    int secondNumber;

    for (unsigned long int i = 0; i < numbers.size (); i++)
      {
	numberContainer[numbers[i]] = i;
      }

    for (unsigned int i = 0; i < numbers.size (); i++)
      {
	result[0] = i + 1;
	secondNumber = target - numbers[i];
	if (numberContainer.count (secondNumber) > 0 && numberContainer[secondNumber] != i)
	  {
	    result[1] = numberContainer[secondNumber] + 1;
	    return result;
	  }
      }

    return result;
  }
};

int
main ()
{
  int n[3] = { 3, 2, 4 };
  Solution s;
  vector < int >numbers (n, n + 4);
  vector < int >result = s.twoSum (numbers, 6);

  cout << result[0] << endl;
  cout << result[1] << endl;
}
