#include <algorithm>
#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;

    ListNode pre_pointer(0, head);

    int size = 0;
    ListNode* last_node = &pre_pointer;
    for (; last_node->next != nullptr; size++, last_node = last_node->next)
      ;

    k %= size;
    int offset = size - k;
    ListNode* offset_pointer = &pre_pointer;
    while (offset-- > 0) {
      // std::cout << offset_pointer->val << std::endl;
      offset_pointer = offset_pointer->next;
    }

    last_node->next = pre_pointer.next;
    pre_pointer.next = offset_pointer->next;
    offset_pointer->next = nullptr;
    return pre_pointer.next;
  }
};

int main() {
  Solution s;
  {
    ListNode node1(5, nullptr);
    ListNode node2(4, &node1);
    ListNode node3(3, &node2);
    ListNode node4(2, &node3);
    ListNode node5(1, &node4);
    ListNode* result = s.rotateRight(&node5, 2);

    for (ListNode* cur = result; cur != nullptr; cur = cur->next) {
      std::cout << cur->val << std::endl;
    }
  }
  return 0;
}