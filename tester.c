#include "libft.h"
#include <limits.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>
#include <bsd/string.h>


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
    printf("\n\ntest atoi:\n\n");
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
    printf("\n\ntest bzero:\n\n");
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
    printf("\n\ntest calloc:\n\n");
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
    printf("\n\ntest isalnum:\n\n");
    int size = strlen(test_isalnum);
    for (int i = 0; i < 127; i++){
        int res = isalnum(i);
        int myRes = ft_isalnum(i);
        if ((res == 0 && myRes == 0) || (res != 0 && myRes != 0))
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
            
    }
    printf("\n");
}

static void test_function_ft_isalpha(void){
    printf("\n\ntest isalpha:\n\n");
    for (int i = 0; i < 127; i++){
        int myRes = ft_isalpha(i);
        int res = isalpha(i);
        if ((res == 0 && myRes == 0) || (res != 0 && myRes != 0))
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
    }
    printf("\n");
}

static void test_function_ft_isascii(void){
    printf("\n\ntest isascii:\n\n");
    for (int i = 0; i < 500; i++){
        int myRes = ft_isascii(i);
        int res = isascii(i);
        if ((res == 0 && myRes == 0) || (res != 0 && myRes != 0))
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
    }
    printf("\n");
}

static void test_function_ft_isdigit(void){
    printf("\n\ntest isdigit:\n\n");
    for (int i = 0; i < 127; i++){
        int myRes = ft_isascii(i);
        int res = isascii(i);
        if ((res == 0 && myRes == 0) || (res != 0 && myRes != 0))
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
    }
    printf("\n");
}

static void test_function_ft_isprint(void){
    printf("\n\ntest isprint:\n\n");
    for (int i = 0; i < 127; i++){
        int myRes = ft_isascii(i);
        int res = isascii(i);
        if ((res == 0 && myRes == 0) || (res != 0 && myRes != 0))
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
    }
    printf("\n");
}

static void test_function_ft_strlen(void){
    printf("\n\ntest strlen:\n\n");
    int t = 0;
    char *a = NULL;
    srand(time(NULL));
    for (int i = 0; i < 100; i++){
        t++;
        int size = rand() % 100;
        a = malloc(sizeof(char) * size + 1);
        if (a == NULL) return;
        for (int y = 0; y < size; y++){
            char c = rand() % 256;
            a[y] = c;
        }
        a[size] = '\0';
        int lib = strlen(a);
        int myLib = ft_strlen(a);
        if (lib == myLib)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
        free(a);
        a = NULL;
    }
	char *b = "";
    t++;
    int lib = strlen(b);
    int myLib = ft_strlen(b);
    if (lib == myLib)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
    free(a);
    a = NULL;
}

static void test_function_ft_memset(void){
     printf("\n\ntest memset:\n\n");
    int t = 0;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100 + 1; // Taille aléatoire entre 1 et 100
        char *a = malloc(size);
        char *b = malloc(size);
        if (a == NULL || b == NULL) return;

        char c = rand() % 256; // Caractère aléatoire pour le remplissage
        memset(a, c, size);
        ft_memset(b, c, size);

        int result = memcmp(a, b, size); // Comparaison des deux buffers
        if (result == 0)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(a);
        free(b);
    }
}

static void test_function_memcpy(void){
    printf("\n\ntest memcpy:\n\n");
    int t = 0;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100 + 1; // Taille aléatoire entre 1 et 100
        char *src = malloc(size);
        char *dst_lib = malloc(size);
        char *dst_my = malloc(size);
        if (src == NULL || dst_lib == NULL || dst_my == NULL) return;

        // Remplir le buffer source avec des données aléatoires
        for (int j = 0; j < size; j++) {
            src[j] = rand() % 256;
        }

        // Utilisation des fonctions memcpy et ft_memcpy
        memcpy(dst_lib, src, size);
        ft_memcpy(dst_my, src, size);

        // Comparaison des deux buffers
        int result = memcmp(dst_lib, dst_my, size); // Comparaison des deux buffers
        if (result == 0)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(src);
        free(dst_lib);
        free(dst_my);
    }
}

static void test_function_ft_memmove(void){
      printf("\n\ntest memmove:\n\n");
    int t = 0;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100 + 1; // Taille aléatoire entre 1 et 100
        char *buffer1 = malloc(size * 2); // Buffer suffisamment grand pour des tests de chevauchement
        char *buffer2 = malloc(size * 2);
        if (buffer1 == NULL || buffer2 == NULL) return;

        // Remplir le buffer source avec des données aléatoires
        for (int j = 0; j < size * 2; j++) {
            buffer1[j] = rand() % 256;
            buffer2[j] = buffer1[j];
        }

        // Pointeurs de départ pour les tests de chevauchement
        char *src1 = buffer1;
        char *dst1 = buffer1 + size / 2;
        char *src2 = buffer2;
        char *dst2 = buffer2 + size / 2;

        // Utilisation des fonctions memmove et ft_memmove
        memmove(dst1, src1, size);
        ft_memmove(dst2, src2, size);

        // Comparaison des deux buffers
        int result = memcmp(buffer1, buffer2, size * 2); // Comparaison des deux buffers
        if (result == 0)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(buffer1);
        free(buffer2);
    }
}

// Implémentation simplifiée de strlcpy
size_t my_strlcpy(char *dst, const char *src, size_t dstsize) {
    size_t src_len = strlen(src);
    if (dstsize == 0) {
        return src_len;
    }

    size_t copy_len = src_len < dstsize - 1 ? src_len : dstsize - 1;
    memcpy(dst, src, copy_len);
    dst[copy_len] = '\0';

    return src_len;
}



// Fonction de test pour ft_strlcpy
static void test_function_ft_strlcpy(void) {
    printf("\n\ntest strlcpy:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100 + 1; // Taille aléatoire entre 1 et 100
        char *src = malloc(size);
        if (src == NULL) return;

        // Remplir le buffer source avec des données aléatoires
        for (int j = 0; j < size - 1; j++) {
            src[j] = 'A' + (rand() % 26); // Remplir avec des lettres de A à Z
        }
        src[size - 1] = '\0'; // Terminer la chaîne avec '\0'

        // Définir différentes tailles de destination pour tester
        int dstsize = rand() % (size + 20); // Taille aléatoire entre 0 et size + 20
        char *dst_lib = malloc(dstsize);
        char *dst_my = malloc(dstsize);
        if (dst_lib == NULL || dst_my == NULL) return;

        // Utilisation des fonctions my_strlcpy et ft_strlcpy
        size_t lib_len = my_strlcpy(dst_lib, src, dstsize);
        size_t my_len = ft_strlcpy(dst_my, src, dstsize);

        // Comparaison des résultats
        int result = (lib_len == my_len) && (dstsize == 0 || strcmp(dst_lib, dst_my) == 0);
        if (result)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(src);
        free(dst_lib);
        free(dst_my);
    }

    // Test avec une chaîne vide
    char *empty_src = "";
    char empty_dst_lib[10];
    char empty_dst_my[10];
    size_t empty_lib_len = my_strlcpy(empty_dst_lib, empty_src, sizeof(empty_dst_lib));
    size_t empty_my_len = ft_strlcpy(empty_dst_my, empty_src, sizeof(empty_dst_my));

    int empty_result = (empty_lib_len == empty_my_len) && (strcmp(empty_dst_lib, empty_dst_my) == 0);
    if (empty_result)
        printf("%d:%s\u2714 %s", t++, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t++, RED, COLOR_RESET);
}



int main(void){
    test_function_ft_isalpha();
    test_function_ft_isdigit();
    test_function_ft_isalnum();
    test_function_ft_isascii();
    test_function_ft_isprint();
    test_function_ft_strlen();
    test_function_ft_memset();
    test_function_bzero();
    test_function_memcpy();
    test_function_ft_memmove();
    test_function_ft_strlcpy();

    test_function_atoi();
    
    test_function_calloc();
    return 0;
}

