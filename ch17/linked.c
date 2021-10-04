#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node head;

head *make_linked()
{
    head *h = (head *)malloc(sizeof(head));
    return h;
}

void clear(head *h)
{
    struct node *temp, *curr;
    temp = h->next;
    for (; temp != NULL;)
    {
        curr = temp;
        temp = temp->next;
        free(curr);
    }
}
struct node *new_node(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insert_head(head *h, int value)
{
    struct node *n = new_node(value);
    if (n == NULL)
    {
        printf("Malloc failed\n");
        exit(EXIT_FAILURE);
    }
    n->next = h->next;
    h->next = n;
}
int insert_sort(head *h, int value)
{
    struct node *temp = (struct node *)h;
    for (; temp->next != NULL;)
    {
        if (temp->next->value < value)
        {
            temp = temp->next;
        }
        else
        {
            break;
        }
    }
    if (temp->next != NULL && temp->next->value == value)
    {
        return 0;
    }
    struct node *n = new_node(value);
    if (n == NULL)
    {
        printf("Malloc failed\n");
        exit(EXIT_FAILURE);
    }
    n->next = temp->next;
    temp->next = n;
    return 1;
}
void insert_array(head *h, int *arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        insert_sort(h, arr[i]);
    }
}
struct node *_search_list(struct node *node, int value)
{

    for (; node != NULL; node = node->next)
    {
        if (node->value == value)
        {
            return node;
        }
    }
    return NULL;
}
struct node *search_list(head *h, int value)
{
    return _search_list(h->next, value);
}
void search_list_all(head *h, int value, struct node ***result, int *size)
{
    *size = 0;
    struct node *temp = h->next;
    for (;;)
    {
        temp = _search_list(temp, value);
        if (temp == NULL)
        {
            break;
        }
        (*size)++;
        *result = realloc(*result, (*size) * sizeof(struct node *));
        (*result)[*size - 1] = temp;
        temp = temp->next;
    }
}

int delete (head *h, int value)
{
    int result = 0;
    struct node *temp = (struct node *)h, *delete_node;
    for (; temp->next != NULL;)
    {
        if (temp->next->value == value)
        {
            delete_node = temp->next;
            temp->next = temp->next->next;
            free(delete_node);
            ++result;
        }
        else
        {
            temp = temp->next;
        }
    }
    return result;
}

void linked_print(head *h)
{
    struct node *temp = h->next;
    for (; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->value);
    }
    puts("");
}

int main(void)
{
    head *h = make_linked();
    insert_array(h, (int[]){154, 233, 23, 97, 14, 25, 61, 6, 7, 988, 9}, 11);
    struct node **result = NULL;
    int size;
    search_list_all(h, 9, &result, &size);
    linked_print(h);
    for (int i = 0; i < size; i++)
    {
        printf("SEARCH : %d=>%d\n", i, result[i]->value);
    }
    printf("delete (h, 9) = %d\n", delete (h, 9));
    insert_sort(h, 100);
    linked_print(h);
    return 0;
}