# 23. Merge k Sorted Lists

>Merge *k* sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
>
>**Example:**
>
>```
>Input:
>[
>  1->4->5,
>  1->3->4,
>  2->6
>]
>Output: 1->1->2->3->4->4->5->6
>```

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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int total = lists.size();
    for (int step = 1; step < total; step *= 2) {
      for (int i = 0; i < total - step; i += step * 2) {
        lists[i] = mergeTwoLists(lists[i], lists[i + step]);
      }
    }
    return total > 0 ? lists[0] : nullptr;
  }
  
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = (ListNode*) malloc(sizeof(ListNode));
    ListNode *curr = head;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val <= l2->val) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l1;
        l1 = curr->next->next;
      }
      curr = curr->next;
    }
    if (l1 == nullptr) {
      curr->next = l2;
    } else {
      curr->next = l1;
    }
    curr = head->next;
    free(head);
    return curr;
  }
};
```

