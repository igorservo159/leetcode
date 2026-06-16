struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode *res = malloc(sizeof(struct ListNode));
  res->next = NULL;
  struct ListNode *itrRes = res;

  int carry = 0;
  int tmpSum;
  while (l1 != NULL || l2 != NULL || carry != 0) {
    tmpSum = carry;

    if (l1 != NULL){
      tmpSum += l1->val;
      l1 = l1->next;
    }
    if (l2 != NULL){
      tmpSum += l2->val;
      l2 = l2->next;
    }

    itrRes->next = malloc(sizeof(struct ListNode));
    itrRes = itrRes->next;
    itrRes->val = tmpSum%10;
    itrRes->next = NULL;
    carry = tmpSum/10;
  }

  return res->next;
}
