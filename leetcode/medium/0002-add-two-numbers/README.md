# Add Two Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two  **non-empty**  linked lists representing two non-negative integers. The digits are stored in  **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

 **Example 1:** 

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

```

 **Example 2:** 

```
Input: l1 = [0], l2 = [0]
Output: [0]

```

 **Example 3:** 

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

```

 

 **Constraints:** 

- The number of nodes in each linked list is in the range [1, 100].
- 0 <= Node.val <= 9
- It is guaranteed that the list represents a number that does not have leading zeros.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 77.1 MB (beats 45.52%)  
**Submitted:** 2026-07-10T01:54:51.166Z  

```cpp
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
                ListNode*dummy = new ListNode(0);
                ListNode* temp = dummy; 
               while(l1!=nullptr && l2!=nullptr)
               {
    
                        ListNode* newnode = new ListNode(l1->val + l2->val);
                        temp -> next = newnode;
                        temp = temp -> next;
                    l1 = l1->next;
                    l2 = l2->next;
               }
               while(l1!=nullptr)
               {
                   ListNode* newnode = new ListNode(l1->val + 0);
                        temp -> next = newnode;
                        temp = temp -> next; 
                        l1 = l1 ->next;
               }
                while(l2!=nullptr)
               {
                   ListNode* newnode = new ListNode(l2->val + 0);
                        temp -> next = newnode;
                        temp = temp -> next; 
                        l2 =l2->next;
               }
               ListNode * head = dummy->next;
                while(head->next!=nullptr){
                        if(head -> val > 9)
                        {
                            head -> val = (head ->val)%10;
                            (head -> next) -> val +=1;
                           
                        }
                         head = head ->next;
                }
                if(head -> val > 9)
                {
                    head -> val = (head ->val)%10;
                    ListNode * newnode = new ListNode(1);
                    head ->next = newnode; 
                }
                return dummy -> next;
              
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/add-two-numbers/)