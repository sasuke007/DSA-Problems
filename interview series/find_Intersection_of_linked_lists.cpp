/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int get_size(ListNode *head){
        int length=0;
        while(head){
            ++length;
            head=head->next;
        }
        return length;
    }
    void increment_pointer(ListNode** headA,ListNode** headB,int h1_size,int h2_size){
        if(h1_size>=h2_size){
            int diff=h1_size-h2_size;
            while(diff){
                *headA=(*headA)->next;
                --diff;
            }
        }
        else{
            int diff=h2_size-h1_size;
            while(diff){
                *headB=(*headB)->next;
                --diff;
            }
        }
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        increment_pointer(&headA,&headB,get_size(headA),get_size(headB));
        while(headA!=nullptr and headB!=nullptr and headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};