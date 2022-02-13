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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum_head = nullptr;
        ListNode *curr=nullptr;
        int carry=0;
        while(l1!=nullptr or l2!=nullptr){
            int val_one = (l1==nullptr?0:l1->val);
            int val_two =(l2==nullptr?0:l2->val);
            int sum=val_one+val_two+carry;
            ListNode *new_node = new ListNode(sum%10);
            carry=sum/10;
            if(sum_head == nullptr){
                sum_head=new_node;
                curr=new_node;
            }
            else{
                curr->next=new_node;
                curr=curr->next;
            }
            l1= (l1!=nullptr?l1->next:nullptr);
            l2= (l2!=nullptr?l2->next:nullptr);
        }
        if(carry!=0){
            curr->next=new ListNode(carry);
        }
        return sum_head;
    }
};