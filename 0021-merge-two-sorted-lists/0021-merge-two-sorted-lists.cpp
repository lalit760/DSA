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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ta = list1;
        ListNode* tb = list2;
        ListNode* c = new ListNode(-1);
        ListNode* tc=c;

        while(ta!=NULL && tb!=NULL){
            if(ta->val >= tb->val){
                tc->next = tb;
                tc=tb; tb=tb->next;
            }
            else{
                tc->next = ta;
                tc=ta; ta=ta->next;
            }
        }
        if(tb==NULL)tc->next=ta;
        else if(ta==NULL)tc->next=tb;
        return c->next;
    }
};