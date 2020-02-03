# 25. Reverse Nodes in k-Group

>Given a linked list, reverse the nodes of a linked list *k* at a time and return its modified list.
>
>*k* is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of *k* then left-out nodes in the end should remain as it is.
>
>
>
>**Example:**
>
>Given this linked list: `1->2->3->4->5`
>
>For *k* = 2, you should return: `2->1->4->3->5`
>
>For *k* = 3, you should return: `3->2->1->4->5`
>
>**Note:**
>
>- Only constant extra memory is allowed.
>- You may not alter the values in the list's nodes, only nodes itself may be changed.

**Solution**

// TODO

```C++
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *gHead = head, *gTail = head, *prevHead = nullptr;
    ListNode *result = nullptr;
    while (true) {
      int count = 0;
      while (gTail != nullptr && count < k) {
        count++;
        gTail = gTail->next;
      }
      if (count < k) {
        if (prevHead != nullptr) {
          prevHead->next = gHead;
        } else {
          result = gHead;
        }
        break;
      }
      
      ListNode *prev = nullptr, *curr = gHead, *temp;
      for (int i = 0; i < k; i++) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
      }      
      if (prevHead != nullptr) {
        prevHead->next = prev;
      } else {
        result = prev;
      }
      
      prevHead = gHead;
      gHead = gTail;
    }
    return result;
  }
};
```



