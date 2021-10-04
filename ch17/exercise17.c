#ifndef EXERCISE17_C
#define EXERCISE17_C
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stack.c"

void func_17_1(void);
void func_17_2(void);
void func_17_3(void);
void func_17_4(void);
void func_17_5(void);
void func_17_6(void);
void func_17_7(void);
void func_17_8(void);
void func_17_9(void);
void func_17_10(void);
void func_17_11(void);
void func_17_12(void);
void func_17_13(void);
void func_17_14(void);
void func_17_15(void);
void func_17_16(void);
void func_17_17(void);
void func_17_18(void);
void func_17_19(void);

void func_p_17_5(void);
void func_p_17_6(void);
int main(void)
{
    func_17_1();
    func_17_2();
    func_17_3();
    func_17_4();
    func_17_5();
    func_17_6();
    func_17_7();
    func_17_8();
    func_17_9();
    func_17_10();
    func_17_11();
    func_17_12();
    func_17_13();
    func_17_14();
    func_17_15();
    func_17_16();
    func_17_17();
    func_17_18();
    func_17_19();

    func_p_17_5();
    func_p_17_6();
    return 0;
}

void func_17_1(void)
{
    void *result = my_malloc(1000);
    printf("%d\n", (int)sizeof(result));
    free(result);
}

char *duplicate(char *str)
{
    char *result = malloc(strlen(str) + 1);
    if (result == NULL)
    {
        return NULL;
    }
    strcpy(result, str);
    return result;
}
void func_17_2(void)
{
    char name[] = "lxq";
    char *name2 = duplicate(name);
    printf("%p %p %s %s\n", name, name2, name, name2);
    free(name2);
}
int *create_array(int n, int initial_value)
{
    int *result = malloc(n * sizeof(*result));
    if (result == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        result[i] = initial_value;
    }
    return result;
}
void func_17_3(void)
{
    int *result = create_array(10, 99);
    printf("%d %d\n", result[0], result[9]);
}
void func_17_4(void)
{
    struct point
    {
        int x, y;
    };
    struct rectangle
    {
        struct point upper_left, lower_right;
    };
    struct rectangle *p;
    p = malloc(sizeof(*p));
    p->upper_left.x = 10;
    p->upper_left.y = 25;
    p->lower_right.x = 20;
    p->lower_right.y = 15;
}
void func_17_5(void)
{
    struct
    {
        union
        {
            char a, b;
            int c;
        } d;
        int e[5];
    } f, *p = &f;

    // p->b = ' '; error
}
void func_17_6(void)
{
    // linked.c  delete方法
}
void func_17_7(void)
{
    // 悬空指针问题 见linked.c clear
}

void func_17_8(void)
{
    stackHead *h = make_stack();
    push(h, 100);
    push(h, 200);
    push(h, 300);
    printf("%d %d %d %p\n", pop(h)->value, pop(h)->value, pop(h)->value, pop(h));
}
void func_17_9(void)
{
    struct
    {
        int a;
    } x;
    x.a = 9989;
    printf("17.9: %d %d\n", (&x)->a, x.a);
}
struct node
{
    int value;
    struct node *next;
};

void func_17_10(void) {}
int count_occurrences(struct node *list, int n)
{
    int result = 0;
    for (; list != NULL; list = list->next)
    {
        if (list->value == n)
            result++;
    }
    return result;
}
void func_17_11(void)
{
    // count_occurrences
}
struct node *find_last(struct node *list, int n)
{
    struct node *result = NULL;
    for (; list != NULL; list = list->next)
    {
        if (list->value == n)
            result = list;
    }
    return result;
}
void func_17_12(void)
{
    // find_last
}
void insert_into_ordered_list_2(struct node **list, struct node *new_node)
{
    struct node *cur = *list, *prev = NULL;
    for (; cur != NULL;)
    {
        if (cur->value <= new_node->value)
        {
            prev = cur;
            cur = cur->next;
        }
        else
        {
            break;
        }
    }
    if (prev == NULL)
    {
        *list = new_node;
    }
    else
    {
        prev->next = new_node;
    }
    new_node->next = cur;
}
struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
    struct node *cur = list, *prev = NULL;
    for (; cur != NULL;)
    {
        if (cur->value <= new_node->value)
        {
            prev = cur;
            cur = cur->next;
        }
        else
        {
            break;
        }
    }
    if (prev == NULL)
    {
        list = new_node;
    }
    else
    {
        prev->next = new_node;
    }
    new_node->next = cur;
    return list;
}
void func_17_13(void)
{
    // insert_into_ordered_list
    // insert_into_ordered_list_2
}
void func_17_14(void) {}
void func_17_15(void) {}
int sum(int (*f)(int), int start, int end)
{
    int result = 0;
    for (int i = start; i <= end; i++)
    {
        result += (*f)(i);
    }
    return result;
}
int ff1(int v)
{
    return v;
}
int ff2(int v)
{
    return v * v;
}
int ff3(int v)
{
    return v * v * v;
}
void func_17_16(void)
{
    printf("%d %d %d\n", sum(ff1, 1, 10), sum(ff2, 1, 10), sum(ff3, 1, 10));
}

int compare_int(const void *x, const void *y)
{
    if (*(int *)x < *(int *)y)
    {
        return -1;
    }
    else if (*(int *)x == *(int *)y)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void func_17_17(void)
{
    int arr[100];
    srand((int)time(NULL));
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 10000;
        if (i == 50)
            printf("-m-m-");
        printf("%d ", arr[i]);
    }
    puts("");
    puts("");
    qsort(&arr[50], 50, sizeof(*arr), compare_int);
    for (int i = 0; i < 100; i++)
    {
        if (i == 50)
            printf("-m-m-");
        printf("%d ", arr[i]);
    }
    puts("");
}

int compare_int2(const void *x, const void *y)
{
    if (*(int *)x < *(int *)y)
    {
        return 1;
    }
    else if (*(int *)x == *(int *)y)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
void func_17_18(void)
{
    int arr[100];
    srand((int)time(NULL));
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 10000;
        if (i == 50)
            printf("-m-m-");
        printf("%d ", arr[i]);
    }
    puts("");
    puts("");
    qsort(&arr[50], 50, sizeof(*arr), compare_int2); // 修改compare_int2
    for (int i = 0; i < 100; i++)
    {
        if (i == 50)
            printf("-m-m-");
        printf("%d ", arr[i]);
    }
    puts("");
}
void new_cmd(void) {}
void open_cmd(void) {}
void close_cmd(void) {}
void close_all_cmd(void) {}
void save_cmd(void) {}
void save_as_cmd(void) {}
void save_all_cmd(void) {}
void print_cmd(void) {}
void exit_cmd(void) {}
void func_17_19(void)
{
    typedef enum
    {
        NEW,
        OPEN,
        CLOSE,
        CLOSE_ALL,
        SAVE,
        SAVE_AS,
        SAVE_ALL,
        PRINT,
        EXIT
    } cmd;
    struct
    {
        char *cmd_name;
        void (*cmd_pointer)(void);
    } file_cmd[] = {
        {"new", new_cmd},
        {"open", open_cmd},
        {"close", close_cmd},
        {"close all", close_all_cmd},
        {"save", save_cmd},
        {"save as", save_as_cmd},
        {"save all", save_all_cmd},
        {"print", print_cmd},
        {"exit", exit_cmd},
    };
    cmd c = NEW;
    switch (c)
    {
    case NEW:
        new_cmd();
        break;
    case OPEN:
        open_cmd();
        break;
    case CLOSE:
        close_cmd();
        break;
    case CLOSE_ALL:
        close_all_cmd();
        break;
    case SAVE:
        save_cmd();
        break;
    case SAVE_AS:
        save_as_cmd();
        break;
    case SAVE_ALL:
        save_all_cmd();
        break;
    case PRINT:
        print_cmd();
        break;
    case EXIT:
        exit_cmd();
        break;
    default:;
    }
}

void func_p_17_5(void)
{
    char **words = NULL;
    char temp[21] = {0};
    char *word;
    int size = 0;
    for (;;)
    {
        printf("Enter word: ");
        scanf("%s", temp);
        if (strcmp(temp, "quit") == 0)
        {
            break;
        }

        word = my_malloc(strlen(temp) + 1);
        strcpy(word, temp);
        ++size;
        words = realloc(words, size * sizeof(*words));
        words[size - 1] = word;
    }

    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                word = words[j + 1];
                words[j + 1] = words[j];
                words[j] = word;
            }
        }
    }
    printf("In sorted order:");
    for (int i = 0; i < size; i++)
    {
        printf(" %s", words[i]);
    }
    puts("");
}

int compare_str(const void *x, const void *y)
{
    return strcmp(*(const char **)x, *(const char **)y);
}

void func_p_17_6(void)
{
    char **words = NULL;
    char temp[21] = {0};
    char *word;
    int size = 0;
    for (;;)
    {
        printf("Enter word: ");
        scanf("%s", temp);
        if (strcmp(temp, "quit") == 0)
        {
            break;
        }

        word = my_malloc(strlen(temp) + 1);
        strcpy(word, temp);
        ++size;
        words = realloc(words, size * sizeof(*words));
        words[size - 1] = word;
    }
    qsort(words, size, sizeof(*words), compare_str);
    printf("In sorted order:");
    for (int i = 0; i < size; i++)
    {
        printf(" %s", words[i]);
    }
    puts("");
}

#endif