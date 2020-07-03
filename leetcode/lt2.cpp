#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ret = nullptr;
    ListNode* pre = nullptr;
    bool will_add = false;
    while (l1 != nullptr || l2 != nullptr || will_add) {
      int num1 = 0, num2 = 0;
      if (l1 != nullptr) {
        num1 = l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        num2 = l2->val;
        l2 = l2->next;
      }
      int value = num1 + num2;
      if (will_add) value++;
      if (value > 9) {
        value -= 10;
        will_add = true;
      } else {
        will_add = false;
      }

      ListNode* cur;

      if (ret == nullptr) {
        cur = ret = new ListNode(value);
      } else {
        cur = new ListNode(value);
        pre->next = cur;
      }
      pre = cur;
    }
    if (ret == nullptr) {
      ret = new ListNode();
    }
    return ret;
  }
};

int main() {
  Solution s;
  {
    ListNode *l1, *l2;
    {
      ListNode* n1 = new ListNode(3);
      ListNode* n2 = new ListNode(4, n1);
      ListNode* n3 = new ListNode(2, n2);
      l1 = n3;
    }
    {
      ListNode* n1 = new ListNode(4);
      ListNode* n2 = new ListNode(6, n1);
      ListNode* n3 = new ListNode(5, n2);
      l2 = n3;
    }
    ListNode* ans = s.addTwoNumbers(l1, l2);
    while (ans != nullptr) {
      printf("%d ", ans->val);
      ans = ans->next;
    }
    puts("\n");
  }
  {
    ListNode *l1, *l2;
    {
      ListNode* n1 = new ListNode(5);
      l1 = n1;
    }
    {
      ListNode* n1 = new ListNode(5);
      l2 = n1;
    }
    ListNode* ans = s.addTwoNumbers(l1, l2);
    while (ans != nullptr) {
      printf("%d ", ans->val);
      ans = ans->next;
    }
    puts("\n");
  }

  return 0;
}