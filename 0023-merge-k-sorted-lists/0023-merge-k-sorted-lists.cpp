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
        ListNode* tc = c;

        while(ta!=NULL && tb!=NULL){
            if(ta->val >= tb->val){
                tc->next = tb;
                tc = tb;
                tb = tb->next;
            }
            else{
                tc->next = ta;
                tc = ta;
                ta = ta->next;
            }
        }
        if(ta==NULL)tc->next = tb;
        else if(tb==NULL)tc->next = ta;

        return c->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)return NULL;

        while(n>1){
            ListNode* a = lists[0];
            lists.erase(lists.begin()); //removes the 1st element temporarily

            ListNode* b = lists[0];
            lists.erase(lists.begin()); //remove the 2nd element temporarily

            ListNode* ans = mergeTwoLists(a,b);
            lists.push_back(ans);
            n = lists.size();
        }
        return lists[0];
    }
};