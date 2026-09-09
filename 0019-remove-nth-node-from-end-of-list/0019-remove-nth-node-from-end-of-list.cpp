/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* t;
        int s=0;
        // finding length
        while(temp != NULL){
            s++; temp = temp->next;
        }
        if(n==s)return head->next;
        int p = s-n-1; //finding that pre node of the node to beremoved
        temp = head;
        while(p > 0){
            temp= temp->next; p--;
        }
        t = temp->next;
        temp->next = t->next;
        // t->next = NULL;
        return head;
    }
};