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
            if(l1==nullptr){
                return l2;
            }
            if(l2==nullptr){
                return l1;
            }
            ListNode *head = nullptr;
            ListNode *currPtr = nullptr;
            int carry = 0;
            while(l1!=nullptr or l2!=nullptr){
                int num1 = 0;
                int num2 = 0;
                if(l1!=nullptr){
                    num1=l1->val;
                }
                if(l2!=nullptr){
                    num2=l2->val;
                }
                int newValue = num1 + num2 + carry;
                int val = newValue%10;
                carry = newValue/10;
                ListNode *newNode = new ListNode(val);
                if(head==nullptr){
                    head = newNode;
                    currPtr = newNode;
                }else{
                    currPtr->next=newNode;
                    currPtr=newNode;
                }
                if(l1!=nullptr){
                    l1=l1->next;
                }
                if(l2!=nullptr){
                    l2=l2->next;
                }
            }
            if(carry!=0){
                currPtr->next = new ListNode(carry);
            }
            return head;
        }
 };

 