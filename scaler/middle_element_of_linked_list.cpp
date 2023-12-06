
Q3. Middle element of linked list
        Solved
feature icon
Using hints is now penalty free
Use Hint

Problem Description

Given a linked list of integers, find and return the middle element of the linked list.

NOTE: If there are N nodes in the linked list and N is even then return the (N/2 + 1)th element.



Problem Constraints

1 <= length of the linked list <= 100000

1 <= Node value <= 109



Input Format

The only argument given head pointer of linked list.



Output Format

Return the middle element of the linked list.



Example Input

Input 1:

1 -> 2 -> 3 -> 4 -> 5

Input 2:

1 -> 5 -> 6 -> 2 -> 3 -> 4



Example Output

Output 1:

3

Output 2:

2



Example Explanation

Explanation 1:

The middle element is 3.

Explanation 2:

The middle element in even length linked list of length N is ((N/2) + 1)th element which is 2.



Expected Output
Provide sample input and click run to see the correct output for

----------------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A) {
    ListNode* slow= A;
    ListNode* fast=A;
    if(A->next==nullptr){
        return A->val;
    }
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->val;
}
