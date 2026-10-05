# Reorder List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given the head of a singly linked-list. The list can be represented as:

```
L0 → L1 → … → Ln - 1 → Ln

```

 *Reorder the list to be on the following form:* 

```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

 **Example 1:** 

```
Input: head = [1,2,3,4]
Output: [1,4,2,3]

```

 **Example 2:** 

```
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

```

 

 **Constraints:** 

- The number of nodes in the list is in the range [1, 5 * 104].
- 1 <= Node.val <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 22.8 MB (beats 77.29%)  
**Submitted:** 2026-10-05T16:14:35.056Z  

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (second != nullptr) {
            ListNode* nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }

        ListNode* first = head;
        second = prev;
        while (second != nullptr) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reorder-list/)