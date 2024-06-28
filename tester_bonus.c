#include "libft.h"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define COLOR_RESET "\e[0m"

static void test_ft_lstnew(void *content, void *expect, int index){
    t_list *elem = ft_lstnew(content);
    if (elem == NULL){
        if (expect == NULL)
            printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
    }else{
        if (elem->content == expect && elem->next == NULL)
            printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
        free(elem);
    }
}

static void test_function_ft_lstnew(void){
    printf("\n\ntest ft_lstnew:\n\n");
    int a = 42;
    test_ft_lstnew(&a, &a, 1);
    char *str = "Hello, world!";
    test_ft_lstnew(str, str, 2);
    void *null_ptr = NULL;
    test_ft_lstnew(null_ptr, null_ptr, 3);
}

static void test_ft_lstadd_front(void **tab, int size, void **expect, int index){
    t_list *list = NULL;
    int t = 0;
    for (int i = 0; i < size; i++){
        t_list *new = ft_lstnew(tab[i]);
        if (new == NULL) t++;
        ft_lstadd_front(&list, new);
    }
    t_list *tmp = list;
    for (int i = 0; i < size - t; i++){
        if (tmp->content != expect[i]){
            printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
            return;
        }
        tmp = tmp->next;
    }
    printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);

    tmp = list;
    while (tmp != NULL){
        t_list *tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
}

static void test_function_ft_lstadd_front(void){
    printf("\n\ntest ft_lstadd_front:\n\n");
    void *contents[] = {"abc", "lala", "ok"};
    void *expect[] = {"ok", "lala", "abc"};
    test_ft_lstadd_front(contents, 3,expect , 1);
    void *contents2[] = {NULL, "lala", "ok"};
    void *expect2[] = {"ok", "lala"};
    test_ft_lstadd_front(contents2, 3,expect2 , 2);
    void *contents3[] = {NULL, "lala", NULL};
    void *expect3[] = {"lala"};
    test_ft_lstadd_front(contents3, 3,expect3 , 3);
}

static void test_ft_lstsize(void **tab, int size, int expect, int index){
    t_list *list = NULL;
    for (int i = 0; i < size; i++){
        t_list *new = ft_lstnew(tab[i]);
        ft_lstadd_front(&list, new);
    }
    t_list *tmp = list;
    int size2 = ft_lstsize(tmp);
    if (size2 == expect)
        printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);

    tmp = list;
    while (tmp != NULL){
        t_list *tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
}


static void test_function_ft_lstsize(void){
    printf("\n\ntest ft_lstsize:\n\n");
    void *contents[] = {"abc", "lala", "ok"};
    int expect = 3;
    test_ft_lstsize(contents, 3,expect , 1);
    void *contents2[] = {NULL, NULL, NULL};
    int expect2 = 0;
    test_ft_lstsize(contents2, 3,expect2 , 2);
    void *contents3[] = {NULL, NULL, "lala"};
    int expect3 = 0;
    test_ft_lstsize(contents3, 1,expect3 , 3);
}

static void test_ft_lstlast(void **tab, int size, t_list *expect, int index){
    t_list *list = NULL;
    for (int i = 0; i < size; i++){
        t_list *new = ft_lstnew(tab[i]);
        ft_lstadd_front(&list, new);
    }
    t_list *tmp = list;
    t_list *last = ft_lstlast(tmp);

    if (strcmp(last->content, expect->content) == 0 && last->next == expect->next)
        printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
    
    tmp = list;
    while (tmp != NULL){
        t_list *tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
}


static void test_function_ft_lstlast(void){
    printf("\n\ntest ft_lstlast:\n\n");
    void *contents[] = {"abc", "lala", "ok"};
    char *str = {"abc"};
    t_list expect;
    expect.content = str;
    expect.next = NULL;
    test_ft_lstlast(contents, 3, &expect, 1);

    void *contents2[] = {NULL, "lala", "ok"};
    char *str2 = {"lala"};
    t_list expect2;
    expect2.content = str2;
    expect2.next = NULL;
    test_ft_lstlast(contents2, 3, &expect2, 2);

    void *contents3[] = {NULL, NULL, "ok"};
    char *str3 = {"ok"};
    t_list expect3;
    expect3.content = str3;
    expect3.next = NULL;
    test_ft_lstlast(contents3, 3, &expect3, 3);
}

static void test_ft_lstadd_back(void **tab, int size, void **expect, int index){
    t_list *list = NULL;
    int t = 0;
    for (int i = 0; i < size; i++){
        t_list *new = ft_lstnew(tab[i]);
        if (new == NULL) t++;
        ft_lstadd_back(&list, new);
    }
    t_list *tmp = list;
    for (int i = 0; i < size - t; i++){
        if (tmp->content != expect[i]){
            printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
            return;
        }
        tmp = tmp->next;
    }
    printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);

    tmp = list;
    while (tmp != NULL){
        t_list *tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
}

static void test_function_ft_lstadd_back(void){
    printf("\n\ntest ft_lstadd_back:\n\n");
    void *contents[] = {"abc", "lala", "ok"};
    void *expect[] = {"abc", "lala", "ok"};
    test_ft_lstadd_back(contents, 3,expect , 1);
    void *contents2[] = {NULL, "lala", "ok"};
    void *expect2[] = {"lala", "ok"};
    test_ft_lstadd_back(contents2, 3,expect2 , 2);
    void *contents3[] = {NULL, "lala", NULL};
    void *expect3[] = {"lala"};
    test_ft_lstadd_back(contents3, 3,expect3 , 3);
}

static void test_ft_lstdelone(void **tab, int size, void **expect, char *des, int index){
    t_list *list = NULL;
    int t = 0;
    for (int i = 0; i < 3; i++){
        t_list *new = ft_lstnew(tab[i]);
        if (new == NULL) t++;
        ft_lstadd_back(&list, new);
    }
    t_list *tmp = list;
    t_list  *prev = tmp;
    tmp = tmp->next;
    int j = 0;
    while (strcmp(prev->content, des) == 0){
        ft_lstdelone(prev, free);
        list = tmp;
        prev = tmp;
        tmp = tmp->next;
    }
    while (tmp != NULL){
        t_list  *tmp2;
        tmp2 = tmp;
        tmp = tmp->next;
        if (strcmp(tmp2->content, des) == 0){
            ft_lstdelone(tmp2, free);
            prev->next = tmp;
        }else{
            prev = prev->next;
        }
    }
    tmp = list;
    int i = 0;
    while (tmp != NULL){
        if (i >= size){
            printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
            ft_lstclear(&list, free);
            return;
        }
        if (strcmp(tmp->content, expect[i]) != 0){
            printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
            ft_lstclear(&list, free);
            return;
        }
        i++;
        tmp = tmp->next;
    }
    ft_lstclear(&list, free);
    printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
}

static void test_function_ft_lstdelone(void){
    printf("\n\ntest ft_lstdelone:\n\n");
    char *lala = ft_strdup("lala");
    char *lili = ft_strdup("lili");
    char *ok = ft_strdup("ok");
    void *contents[] = {lala, lili, ok};
    void *expect[] = {"lili", "ok"};
    char *des = {"lala"};
    test_ft_lstdelone(contents, 2,expect, des, 1);
    char *lala2 = ft_strdup("lala");
    char *lili2 = ft_strdup("lili");
    char *ok2 = ft_strdup("ok");
    void *contents2[] = {lala2, lili2, ok2};
    void *expect2[] = {"lala", "ok"};
    char *des2 = {"lili"};
    test_ft_lstdelone(contents2, 2,expect2, des2, 2);
    char *lala3 = NULL;
    char *lili3 = ft_strdup("lili");
    char *ok3 = ft_strdup("ok");
    void *contents3[] = {lala3, lili3, ok3};
    void *expect3[] = {"lili"};
    char *des3 = {"ok"};
    test_ft_lstdelone(contents3, 1,expect3, des3, 3);
}

static void test_ft_lstclear(void **tab, int index){
    t_list *list = NULL;
    for (int i = 0; i < 3; i++){
        t_list *new = ft_lstnew(tab[i]);
        ft_lstadd_back(&list, new);
    }
    ft_lstclear(&list, free);
    if (list == NULL)
        printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
}

static void test_function_ft_lstclear(void){
    printf("\n\ntest ft_lstclear:\n\n");
    char *lala = ft_strdup("lala");
    char *lili = ft_strdup("lili");
    char *ok = ft_strdup("ok");
    void *contents[] = {lala, lili, ok};
    test_ft_lstclear(contents, 1);
    // char *lala2 = ft_strdup("lala");
    // char *lili2 = ft_strdup("lili");
    // char *ok2 = ft_strdup("ok");
    // void *contents2[] = {lala2, lili2, ok2};
    // void *expect2[] = {"lala", "ok"};
    // char *des2 = {"lili"};
    // test_ft_lstdelone(contents2, 2,expect2, des2, 2);
    // char *lala3 = NULL;
    // char *lili3 = ft_strdup("lili");
    // char *ok3 = ft_strdup("ok");
    // void *contents3[] = {lala3, lili3, ok3};
    // void *expect3[] = {"lili"};
    // char *des3 = {"ok"};
    // test_ft_lstdelone(contents3, 1,expect3, des3, 3);
}

int main(void){
    // test_function_ft_lstnew();
    // test_function_ft_lstadd_front();
    // test_function_ft_lstsize();
    // test_function_ft_lstlast();
    // test_function_ft_lstadd_back();
    // test_function_ft_lstdelone();
    test_function_ft_lstclear();
}