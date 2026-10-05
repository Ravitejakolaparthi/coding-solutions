# Sort List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a linked list, return  *the list after sorting it in  **ascending order***.

 

 **Example 1:** 

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]

```

 **Example 2:** 

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

```

 **Example 3:** 

```
Input: head = []
Output: []

```

 

 **Constraints:** 

- The number of nodes in the list is in the range [0, 5 * 104].
- -105 <= Node.val <= 105

 

 **Follow up:**  Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?

## Solution

**Language:** C++  
**Runtime:** 15 ms (beats 62.94%)  
**Memory:** 57.1 MB (beats 82.66%)  
**Submitted:** 2026-10-05T16:15:16.957Z  

```cpp
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(second);
        return merge(l1, l2);
    }

private:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a != nullptr) ? a : b;
        return dummy.next;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sort-list/)