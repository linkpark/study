#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;
struct Array{
    int value;
    int position;
};

class Solution
{
public:
    static int Comp( const void* elem1,const void* elem2){
        const struct Array *a1 = (const struct Array*)elem1;
        const struct Array *a2 = (const struct Array*)elem2;

        if(a1->value < a2->value)
            return -1;
        else if( a1->value == a2->value)
            return 0;
        else
            return 1;    
    }

    vector< int > twoSum( vector< int > &numbers, int target){
        struct Array *array = new Array[numbers.size()];
        vector< int > result(2);
        for(unsigned long i = 0 ; i < numbers.size() ; i++){
            array[i].value = numbers[i];
            array[i].position = i + 1; 
        }

        qsort(array,numbers.size(),sizeof(struct Array),Comp);
        
        int token = 0;
        int i = 0;
        int j = numbers.size() - 1;
        int secondNumber;

        while( i < j){
            if(token == 0){
                result[0] = array[i].position;
                secondNumber = target - array[i].value;
                if(secondNumber == array[j].value){
                    result[1] = array[j].position;
                    return result;
                }else if( secondNumber > array[j].value){
                    i++;
                    token = 1;
                    continue;
                }
                j--;
            }else if(token == 1){
                result[1] = array[j].position;
                secondNumber = target - array[j].value;
                if(secondNumber == array[i].value){
                    result[0] = array[i].position;
                    return result;
                }else if( secondNumber < array[i].value){
                    j--;
                    token = 0;
                    continue;
                }
                i++;
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
  vector < int >numbers (n, n + 3);
  vector < int >result = s.twoSum (numbers, 6);

  cout << result[0] << endl;
  cout << result[1] << endl;
}
