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
    int get_size(ListNode *head){
        int length=0;
        while(head!=nullptr){
            ++length;
            head=head->next;
        }
        return length;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_size=get_size(l1);
        int l2_size=get_size(l2);
        ListNode* start=nullptr;
        ListNode* end=nullptr;
        if(l1_size>=l2_size){
            start=l1;
            end=l2;
        }
        else{
            start=l2;
            end=l1;
        }
        int carry=0;
        ListNode* answer=start;
        ListNode * prev=start;
        while(end!=nullptr){
            int add=start->val+end->val+carry;
            int rem=add%10;
            int val=add/10;
            carry=val;
            start->val=rem;
            prev=start;
            start=start->next;
            end=end->next;
        }

        while(start!=nullptr){
            int val=start->val+carry;
            carry=val/10;
            start->val=val%10;
            prev=start;
            start=start->next;
        }
        if(carry){
            ListNode * node = new ListNode(carry);
            prev->next=node;
        }
        return answer;
    }
};