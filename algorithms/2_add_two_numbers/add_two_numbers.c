#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definition for singly-linked list. */
/* typedef set use the same struct name */
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

typedef struct llist {
	ListNode *head;
	ListNode *tail;
} llist;

static void initList(llist *list);
static int addListNode(llist *list, ListNode *entry);
static int setListNode(ListNode *entry, int val_carry);
static int freelist(llist *list);
static void printList(ListNode *head);
static int getlist(llist *list);

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *entry;
    static llist list;
    initList(&list);
    int v1,v2;
    int val_carry = 0;

    while(l1 || l2 || val_carry)
    {
        v1 = (l1 == NULL) ? 0 : l1->val;
        v2 = (l2 == NULL) ? 0 : l2->val;
        /* initialize new entry */
        entry = malloc(sizeof(struct ListNode));
        if (entry == NULL)
        {
            fprintf(stderr,"malloc for new list element failed!\n");
            return list.head;
        }
        addListNode(&list,entry);

        /* calculate */
        val_carry += v1 + v2;

        setListNode(entry,val_carry%10);
        val_carry /= 10;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }
    return list.head;
}

int main(int argc, char *argv)
{
    llist l1;
    llist l2;
    initList(&l1);
    initList(&l2);
    ListNode *res = NULL;

    fprintf(stdout,"Please input list1:\n");
    getlist(&l1);
    fprintf(stdout,"Please input list2:\n");
    getlist(&l2);

    res = addTwoNumbers(l1.head, l2.head);
    printList(res);
    
}

static void initList(llist *list)
{
    list->head = NULL;
    list->tail = NULL;
}

static int addListNode(llist *list, ListNode *entry)
{
    ListNode *phead = list->head;
    ListNode *ptail = list->tail;
    if (entry == NULL)
        return 0;
    if (phead == NULL)
        /* 1st element added */
        list->head = entry;
    if (ptail != NULL)
        ptail->next = entry;
    list->tail = entry;
    entry->next = NULL;
    return 0;
}

static int setListNode(ListNode *entry, int val_carry)
{
    entry->val = val_carry;
    return 0;
}

static int freelist(llist *list)
{
    ListNode *phead = list->head;
    ListNode *entry = phead;
    ListNode *temp = NULL;

    while(entry != NULL)
    {
        temp = entry->next;
        free(entry);
        entry = temp;
    }

    return 0;
}

static void printList(ListNode *head)
{
    ListNode *entry;
    entry = head;
    fprintf(stdout,"[");
    while(entry != NULL)
    {
        fprintf(stdout,"%d,",entry->val);
        entry = entry->next;
    }
    fprintf(stdout,"\b]\n");
}

static int getlist(llist *list)
{
    ListNode *entry;
    char buff[128];
    char *ptr = NULL;
    fgets(buff,sizeof(buff),stdin);
    ptr = strtok(buff," ");
    entry = malloc(sizeof(struct ListNode));
    addListNode(list,entry);
    setListNode(entry,atoi(ptr));
    while((ptr = strtok(NULL," ")) != NULL)
    {
        entry = malloc(sizeof(struct ListNode));
        addListNode(list,entry);
        setListNode(entry,atoi(ptr));
    }
    return 0;
}

