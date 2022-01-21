#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;

        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;

        return secondNode;
    }
};
int main(){
    ListNode node1(1,&ListNode(2));
}