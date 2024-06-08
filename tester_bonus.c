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
    }
    if (elem->content == expect && elem->next == NULL)
        printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
    free(elem);
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
    for (int i = 0; i < size; i++){
        t_list *new = ft_lstnew(tab[i]);
        ft_lstadd_front(&list, new);
    }
    t_list *tmp = list;
    for (int i = 0; i < size; i++){
        
        if (tmp->content != expect[i]){
            printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
            return;
        }
        tmp = tmp->next;
    }
    printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
}

static void test_function_ft_lstadd_front(void){
    printf("\n\ntest ft_lstadd_front:\n\n");
    void *contents[] = {"abc", "lala", "ok"};
    void *expect[] = {"ok", "lala", "abc"};
    test_ft_lstadd_front(contents, 3,expect , 1);
    void *contents2[] = {NULL, "lala", "ok"};
    void *expect2[] = {"ok", "lala", NULL};
    test_ft_lstadd_front(contents2, 3,expect2 , 2);
    void *contents3[] = {NULL, "lala", NULL};
    void *expect3[] = {NULL, "lala", NULL};
    test_ft_lstadd_front(contents3, 3,expect3 , 3);
}


int main(void){
    // test_function_ft_lstnew();
    test_function_ft_lstadd_front();
}