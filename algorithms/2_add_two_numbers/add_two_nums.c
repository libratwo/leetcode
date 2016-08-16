/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    /* store new entry for result */
    struct ListNode *entry;
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    int v1,v2;
    int val = 0;
    while (l1 != NULL || l2 != NULL)
    {
        if (l1 == NULL)
            v1 = 0;
        else
        {
            v1 = l1->val;
            l1 = l1->next;
        }
        if (l2 == NULL)
            v2 = 0;
        else
        {
            v2 = l2->val;
            l2 = l2->next;
        }

        val += v1 + v2;

        entry = malloc(sizeof(struct ListNode));
        entry->next = NULL;
        if (head == NULL)
            head = entry;
        if (tail != NULL)
            tail->next = entry;
        tail = entry;

        entry->val = val%10;
        val = val/10;
    }
    if (val)
    {
        entry = malloc(sizeof(struct ListNode));
        entry->next = NULL;
        if (head == NULL)
            head = entry;
        if (tail != NULL)
            tail->next = entry;
        tail = entry;

        entry->val = val;
    }

    return head;
}
