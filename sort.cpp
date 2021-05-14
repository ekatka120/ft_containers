#include <iostream>

struct node {
    void *data;
    struct node *prev;
    struct node *next;
};

struct linklist {
    struct node *head;
    struct node *tail;
    size_t size;
};

static struct node *split(struct node *head, size_t pos) {
    struct node *slow = head;

    while (pos-- > 1) {
        slow = slow->next;
    }
    struct node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

static struct node *merge(struct node *first, struct node *second,
                          int (*comp)(const void *, const void *))
{
    struct node *head = NULL;
    struct node *prev = NULL;
    struct node **linkp = &head;

    for (;;) {
        if (first == NULL) {
            second->prev = prev;
            *linkp = second;
            break;
        }
        if (second == NULL) {
            first->prev = prev;
            *linkp = first;
            break;
        }
        if (comp(first->data, second->data)) <= 0 {
            first->prev = prev;
            prev = *linkp = first;
            linkp = &first->next;
        } else {
            second->prev = prev;
            prev = *linkp = second;
            linkp = &second->next;
        }
    }
    return head;
}

static struct node *merge_sort(struct node *head, size_t size,
                               int (*comp)(const void *, const void *))
{
    if (size < 2) {
        return head;
    }

    struct node *second = split(head, size / 2);

    head = merge_sort(head, size / 2, comp);
    second = merge_sort(second, size - size / 2, comp);
    return merge(head, second, comp);
}

void linklist_sort(struct linklist *list, int (*comp)(const void *, const void *)) {
    list->head = merge_sort(list->head, comp, list->size);
    if (list->tail) {
        struct node *tail = list->tail;
        while (tail->next)
            tail = tail->next;
        list->tail = tail;
    }
}
