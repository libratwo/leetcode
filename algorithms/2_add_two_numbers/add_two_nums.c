/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/* Optimize:
 * 1. use dummyhead for storing return list head,
 *      condense the complexity of logic
 * 2. condense judgement for l1,l2 NULL state
 * 3. unite l1,l2 and carry judgement */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    /* a dummyhead */
    struct ListNode head = {0,NULL};
    /* a pointer to curr list last entry */
    struct ListNode *pcur = &head;

    /* store new entry for result */
    struct ListNode *entry;
    int v1,v2;
    int val_with_carry = 0;

    while (l1 || l2 || val_with_carry)
    {
        v1 = (l1 == NULL) ? 0 : l1->val;
        if (l1)
            l1 = l1->next;
        v2 = (l2 == NULL) ? 0 : l2->val;
        if (l2)
            l2 = l2->next;

        val_with_carry += v1 + v2;

        entry = malloc(sizeof(struct ListNode));
        entry->next = NULL;
        pcur->next = entry;
        pcur = pcur->next;

        entry->val = val_with_carry%10;
        val_with_carry /= 10;
    }
    return head.next;
}
