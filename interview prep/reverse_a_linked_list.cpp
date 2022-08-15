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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode * prev=nullptr;
        ListNode * curr=head;
        ListNode * next=head->next;
        //cout<<curr->val<<" "<<next->val<<endl;
        while(next!=nullptr){
            //cout<<curr->val<<endl;
            ListNode * temp=next->next;
            next->next=curr;
            curr->next=prev;
            prev=curr;
            curr=next;
            next=temp;
        }
        return curr;
    }
};