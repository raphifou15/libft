#include "libft.h"
#include <limits.h>
#include <strings.h>
#include <ctype.h>


#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define COLOR_RESET "\e[0m"

struct test_atoi {
    const char *input;
    int expected;
};

struct test_atoi tests_atoi[] = {
    {"123", 123},
    {"-123", -123},
    {"   456", 456},
    {"789   ", 789},
    {"321abc", 321},
    {"654.321", 654},
    {"+123", 123},
    {"  -456", -456},
    {"", 0},
    {"abc", 0},
    {"2147483647", INT_MAX},
    {"-2147483648", INT_MIN},
};

struct test_calloc {
    int nmemb;
    int size; 
};

struct test_calloc tests_calloc[] = {
    {0, 1},
    {1, 1},
    {5, 10},
    {10, 5},
    {50, 2},
    {2, 50},
    {100, 1},
    {1, 100}
};

char test_isalnum[] = {'0', '9', 'A', 'Z', 'a', 'z', '!', '@', '[', '`', '{', ' ', '\n', '5'};



static void test_function_atoi(void){
    printf("test atoi:\n");
    int size = sizeof(tests_atoi) / sizeof(tests_atoi[0]);
    for (int i = 0; i < size; i++){
        int myRes = ft_atoi(tests_atoi[i].input);
        int res = atoi(tests_atoi[i].input);
        if (myRes == res){
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        }
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
    }
    printf("\n");
}

static void test_function_bzero(void){
    printf("test bzero:\n");
    int tests_bzero[] = {0, 1, 5, 10, 50, 100};
    int size = sizeof(tests_bzero) / sizeof(tests_bzero[0]);
    for (int i = 0; i < size; i++){
        char *myStr = malloc(tests_bzero[i]);
        char *str = malloc(tests_bzero[i]);

        memset(myStr, 'a', tests_bzero[i]);
        memset(str, 'a', tests_bzero[i]);

        ft_bzero(myStr, tests_bzero[i]);
        bzero(str, tests_bzero[i]);

        for (int y = 0; y < tests_bzero[i]; y++){
            if (myStr[y] != str[y]){
                printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
                y = tests_bzero[i];
            }
            if (y == tests_bzero[i] - 1){
                printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
            }
        }   
    }
    printf("\n");
}

static void test_function_calloc(void){
    printf("test calloc:\n");
    int size = sizeof(tests_calloc) / sizeof(tests_calloc[0]);
    for (int i = 0; i < size; i++){
        int total_size =  tests_calloc[i].nmemb * tests_calloc[i].size;

        char *ptr = calloc(tests_calloc[i].nmemb, tests_calloc[i].size);
        char *myPtr = ft_calloc(tests_calloc[i].nmemb, tests_calloc[i].size);

        for (int y = 0; y < total_size; y++){
            if (ptr[y] != myPtr[y]){
                printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
                y = total_size;
            }
            if (y == total_size -1)
                printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        }

    }
    printf("\n");
    return;
}

static void test_function_ft_isalnum(void){
    printf("test isalnum:\n");
    int size = strlen(test_isalnum);
    for (int i = 0; i < size; i++){
        int res = isalnum(test_isalnum[i]);
        int myRes = ft_isalnum(test_isalnum[i]);
        if ((res == 0 && myRes == 0) || (res != 0 && myRes != 0))
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
            
    }
    printf("\n");
}


int main(void){
    test_function_atoi();
    test_function_bzero();
    test_function_calloc();
    test_function_ft_isalnum();
    return 0;
}

