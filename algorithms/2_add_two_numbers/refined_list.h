#ifndef REFINED_LIST_H
#define REFINED_LIST_H 1

/*********** LIST ENTRY STYLE ********
 * elt(entry)
 * struct {
 *      type elment;
 *      LINK(type);
 * }
 */
#define HEAD(list)  ((list).head)
#define TAIL(list)  ((list).tail)
#define EMPTY(list) ((list).head == NULL)

#define PREV(elt)   ((elt)->link.prev)
#define NEXT(elt)   ((elt)->link.next)

#define LIST(type)   struct { type *head, *tail; }
#define INIT_LIST(list) \
    do { HEAD(list) = NULL; TAIL(list) = NULL; } while(0)

#define LINK(type)  struct { type *prev, *next;}
#define INIT_LINK(elt, link)    \
    do { \
        PREV(elt) = (void *)(-1); \
        NEXT(elt) = (void *)(-1); \
    } while(0)

#define LINKED(elt, link)   (PREV(elt) != (void *)(-1))

#define PREPEND(list, elt, link) \
    do { \
        if (HEAD(list) != NULL) \
            PREV(HEAD(list)) = (elt); \
        else \
            TAIL(list) = (elt); \
        PREV(elt) = NULL; \
        NEXT(elt) = HEAD(list); \
        HEAD(list) = (elt); \
    } while(0)

#define APPEND(list, elt, link) \
    do { \
        if (TAIL(list) != NULL) \
            NEXT(TAIL(list)) = (elt); \
        else \
            HEAD(list) = (elt); \
        NEXT(elt) = NULL; \
        PREV(elt) = TAIL(list); \
        TAIL(list) = (elt); \
    } while(0)

#define UNLINK(list, elt, link) \
    do { \
        if (NEXT(elt) == NULL) \
            TAIL(list) = PREV(elt); \
        else \
            PREV(NEXT(elt)) = PREV(elt); \
        if (PREV(elt) == NULL) \
            HEAD(list) = NEXT(elt); \
        else \
            NEXT(PREV(elt)) = NEXT(elt); \
        INIT_LINK(elt, link); \
    } while(0)

#define INSERTBEFORE(list, before, elt, link) \
    do { \
        if (PREV(before) == NULL) \
            PREPEND(list, elt, link); \
        else { \
            PREV(elt) = PREV(before); \
            PREV(before) = (elt); \
            NEXT(PREV(before)) = (elt); \
            NEXT(elt) = (before); \
        } \
    } while(0)




#endif

