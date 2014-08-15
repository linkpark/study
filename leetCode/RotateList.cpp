#include <iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

class Solution{
public:
    ListNode *rotateRight(ListNode *head,int k){
        if(NULL == head )
            return head;

        ListNode *p,*q;
        int ListLength = 1;
        p = q = head;

        while( q->next != NULL){
            q = q -> next;
            ListLength++;
        }
        
        k = k % ListLength;

        for(int i = 0 ;i < ListLength - k - 1; i++){
            p = p->next;
        }

        q->next = head;
        head = p -> next;
        p->next = NULL;

        return head;
    }
};

int main(){
    struct ListNode *p,*q,*tmp;
    p = new ListNode(1);
    q = p;
    for(int i = 1 ;i < 5 ; i++){
        tmp =  new ListNode(i + 1);
        q -> next = tmp;
        q = q -> next;
    }
    
    q = p;
    while(q != NULL){
        cout << q->val << " ";
        q = q -> next;
    }
    cout <<endl;
    
    Solution s;
    p = s.rotateRight(p,2);
    q = p;
    while(q != NULL){
        cout << q->val << " ";
        q = q->next;
    }

    cout <<endl;
    return 0;

}
