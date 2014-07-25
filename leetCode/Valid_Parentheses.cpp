#include <iostream>
#include <string>
#include <map>

using namespace std;
class Solution{
    public:
        Solution(int n):top(-1){
            stack = new char[n + 1];
        }

        ~Solution(){
            delete []stack;
        }

        bool isValid(string s){
            for(unsigned long i = 0 ; i < s.size() ; i++){
                if( -1 == top ){
                    push(s[i]);
                    continue;
                }
                
                if( (s[i] == ')'&&stack[top]=='(') ||
                    (s[i] == '}'&&stack[top]=='{') ||
                    (s[i] == ']'&&stack[top]=='[') ){
                    pop();
                    continue;
                }

                push(s[i]);
            }

            if( -1 == top) 
                return true;
            else
                return false;
        }

        void push(char c){
            top ++;
            stack[top] = c;
        } 

        void pop(){
            top--;
        }
    
    private:
        char *stack;
        int top;
        map< int,int > table;
};

int main(){
    string s;
    cin >> s;
    Solution solution(s.size());
    cout << solution.isValid(s) << endl;
    return 0;
}
