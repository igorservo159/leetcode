struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode mergedList;
    ListNode *aux = &mergedList;
    while (list1 != nullptr && list2 != nullptr) {
      if (list2->val > list1->val) {
        aux->next = list1;
        list1 = list1->next;
      } else {
        aux->next = list2;
        list2 = list2->next;
      }
      aux = aux->next;
    }

    while (list1 != nullptr) {
      aux->next = list1;
      list1 = list1->next;
      aux = aux->next;
    }

    while (list2 != nullptr) {
      aux->next = list2;
      list2 = list2->next;
      aux = aux->next;
    }

    return mergedList.next;
  }
};
