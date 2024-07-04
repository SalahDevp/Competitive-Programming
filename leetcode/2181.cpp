#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode *list_ptr;

class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    list_ptr p, q;
    p = head->next;
    q = new ListNode(0, head);

    int acc = 0;
    while (p) {
      if (p->val) {
        acc += p->val;
      } else {
        q->next->val = acc;
        acc = 0;
        q = q->next;
      }
      p = p->next;
    }
    q->next = nullptr;

    return head;
  }
};
