#include "libft.h"
#include <limits.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>
#include <stddef.h>
#include <bsd/string.h>


#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define COLOR_RESET "\e[0m"


char test_isalnum[] = {'0', '9', 'A', 'Z', 'a', 'z', '!', '@', '[', '`', '{', ' ', '\n', '5'};



static void test_function_ft_atoi(void) {
    printf("\n\ntest atoi:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 18;
        char *str = malloc(sizeof(char) * (size + 1));
        if (str == NULL) return;

        for (int y = 0; y < size; y++) {
            str[y] = rand() % 10 + '0'; // Caractères numériques aléatoires
        }
        str[size] = '\0';

        int lib = atoi(str);
        int myLib = ft_atoi(str);
        

        if (lib == myLib)
            printf("%d : %s\u2714 %s", i, GRN, COLOR_RESET);
        else{
            printf("\nstr = %s, lib = %d, myLib = %d\n", str, lib, myLib);
            printf("%d : %s\U00010102 %s", i, RED, COLOR_RESET);
            printf("\n");
        }    
        free(str);
    }

    // Test supplémentaire pour une chaîne vide
    t++;
    char *empty_str = "";
    int lib = atoi(empty_str);
    int myLib = ft_atoi(empty_str);

    if (lib == myLib)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
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

static void test_function_ft_calloc(void) {
    printf("\n\ntest calloc:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        size_t count = rand() % 100 + 1;
        size_t size = rand() % 100 + 1;
        void *ptr_lib = calloc(count, size);
        void *ptr_my = ft_calloc(count, size);

        int result = (ptr_lib != NULL && ptr_my != NULL);

        // Vérifier si les blocs alloués sont identiques
        if (result && memcmp(ptr_lib, ptr_my, count * size) == 0)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        // Libérer la mémoire allouée
        free(ptr_lib);
        free(ptr_my);
    }

    // Test supplémentaire pour une allocation de taille nulle
    t++;
    size_t count = 0;
    size_t size = 0;
    void *ptr_lib = calloc(count, size);
    void *ptr_my = ft_calloc(count, size);

    int result = (ptr_lib != NULL && ptr_my != NULL);

    // Vérifier si les blocs alloués sont identiques
    if (result && memcmp(ptr_lib, ptr_my, count * size) == 0)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);

    // Libérer la mémoire allouée
    free(ptr_lib);
    free(ptr_my);
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
    }
	char *b = "";
    t++;
    int lib = strlen(b);
    int myLib = ft_strlen(b);
    if (lib == myLib)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
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

static size_t my_strlcat(char *dst, const char *src, size_t dstsize) {
    size_t dlen = strnlen(dst, dstsize);
    size_t slen = strlen(src);

    if (dlen == dstsize) {
        return dstsize + slen;
    }

    if (slen < dstsize - dlen) {
        memcpy(dst + dlen, src, slen + 1);
    } else {
        memcpy(dst + dlen, src, dstsize - dlen - 1);
        dst[dstsize - 1] = '\0';
    }

    return dlen + slen;
}

static void test_function_ft_strlcat(void) {
    printf("\n\ntest strlcat:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100 + 1; // Taille aléatoire entre 1 et 100

        // Allouer les buffers de destination
        char *buffer1 = malloc(size * 2);
        char *buffer2 = malloc(size * 2);
        if (buffer1 == NULL || buffer2 == NULL) return;

        // Remplir les buffers de destination avec des données aléatoires
        for (int j = 0; j < size - 1; j++) {
            buffer1[j] = 'A' + (rand() % 26); // Remplir avec des lettres de A à Z
            buffer2[j] = buffer1[j];
        }
        buffer1[size - 1] = '\0';
        buffer2[size - 1] = '\0';

        // Créer une source aléatoire
        char *src = malloc(size);
        if (src == NULL) return;

        for (int j = 0; j < size - 1; j++) {
            src[j] = 'A' + (rand() % 26); // Remplir avec des lettres de A à Z
        }
        src[size - 1] = '\0'; // Terminer la chaîne avec '\0'

        // Définir différentes tailles de destination pour tester
        int dstsize = rand() % (size + 20); // Taille aléatoire entre 0 et size + 20

        // Utilisation des fonctions my_strlcat et ft_strlcat
        size_t lib_len = my_strlcat(buffer1, src, dstsize);
        size_t my_len = ft_strlcat(buffer2, src, dstsize);

        // Comparaison des résultats
        int result = (lib_len == my_len) && (strcmp(buffer1, buffer2) == 0);
        if (result)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(buffer1);
        free(buffer2);
        free(src);
    }
}

static void test_function_ft_toupper(void) {
    printf("\n\ntest toupper:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100;
        char *a = malloc(sizeof(char) * size + 1);
        if (a == NULL) return;

        for (int y = 0; y < size; y++) {
            char c = rand() % 256;
            a[y] = c;
        }
        a[size] = '\0';

        int correct = 1;
        for (int j = 0; j < size; j++) {
            if (toupper(a[j]) != ft_toupper(a[j])) {
                correct = 0;
                break;
            }
        }

        if (correct)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
        free(a);
    }

    // Test supplémentaire pour un cas particulier (chaîne vide)
    t++;
    char *b = "";
    int correct = 1;
    for (int j = 0; b[j] != '\0'; j++) {
        if (toupper(b[j]) != ft_toupper(b[j])) {
            correct = 0;
            break;
        }
    }

    if (correct)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
}

static void test_function_ft_tolower(void) {
    printf("\n\ntest tolower:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100;
        char *a = malloc(sizeof(char) * size + 1);
        if (a == NULL) return;

        for (int y = 0; y < size; y++) {
            char c = rand() % 256;
            a[y] = c;
        }
        a[size] = '\0';

        int correct = 1;
        for (int j = 0; j < size; j++) {
            if (tolower(a[j]) != ft_tolower(a[j])) {
                printf("original = %d, tolower = %d, ft_tolower = %d\n", a[j], tolower(a[j]), ft_tolower(a[j]));
                correct = 0;
                break;
            }
        }

        if (correct)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(a);
    }

    // Test supplémentaire pour un cas particulier (chaîne vide)
    t++;
    char *b = "";
    int correct = 1;
    for (int j = 0; b[j] != '\0'; j++) {
        if (tolower(b[j]) != ft_tolower(b[j])) {
            correct = 0;
            break;
        }
    }

    if (correct)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
    printf("\n");
}

static void test_function_ft_strchr(void) {
    printf("\n\ntest strchr:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100 + 1;
        char *a = malloc(sizeof(char) * size + 1);
        if (a == NULL) return;

        for (int y = 0; y < size; y++) {
            a[y] = rand() % 256;
        }
        a[size] = '\0';

        // Générer un caractère aléatoire à rechercher
        char c = rand() % 256;

        char *lib = strchr(a, c);
        char *myLib = ft_strchr(a, c);

        int result = ((lib == NULL && myLib == NULL) || (lib != NULL && myLib != NULL && lib == myLib));

        if (result)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(a);
    }

    // Test supplémentaire pour un cas particulier (chaîne vide)
    t++;
    char *b = "";
    char c = 'a'; // caractère arbitraire pour le test
    char *lib = strchr(b, c);
    char *myLib = ft_strchr(b, c);

    int result = ((lib == NULL && myLib == NULL) || (lib != NULL && myLib != NULL && lib == myLib));

    if (result)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
}

static void test_function_ft_strrchr(void) {
    printf("\n\ntest strrchr:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100 + 1;
        char *a = malloc(sizeof(char) * size + 1);
        if (a == NULL) return;

        for (int y = 0; y < size; y++) {
            a[y] = rand() % 256;
        }
        a[size] = '\0';

        // Générer un caractère aléatoire à rechercher
        char c = rand() % 256;

        char *lib = strrchr(a, c);
        char *myLib = ft_strrchr(a, c);

        int result = ((lib == NULL && myLib == NULL) || (lib != NULL && myLib != NULL && strcmp(lib, myLib) == 0));

        if (result)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(a);
    }

    // Test supplémentaire pour un cas particulier (chaîne vide)
    t++;
    char *b = "";
    char c = 'a'; // caractère arbitraire pour le test
    char *lib = strrchr(b, c);
    char *myLib = ft_strrchr(b, c);

    int result = ((lib == NULL && myLib == NULL) || (lib != NULL && myLib != NULL && strcmp(lib, myLib) == 0));

    if (result)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
}

static void test_function_ft_strncmp(void) {
    printf("\n\ntest strncmp:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size1 = rand() % 100 + 1;
        int size2 = rand() % 100 + 1;
        char *a = malloc(sizeof(char) * size1 + 1);
        char *b = malloc(sizeof(char) * size2 + 1);
        if (a == NULL || b == NULL) return;

        for (int y = 0; y < size1; y++) {
            a[y] = rand() % 256;
        }
        a[size1] = '\0';

        for (int y = 0; y < size2; y++) {
            b[y] = rand() % 256;
        }
        b[size2] = '\0';

        size_t n = rand() % (size1 + size2); // Taille aléatoire pour comparaison

        int lib = strncmp(a, b, n);
        int myLib = ft_strncmp(a, b, n);
        int result = (lib == myLib);

        if (result)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);
        free(a);
        free(b);
    }

    // Test supplémentaire pour des cas particuliers
    t++;
    char *c = "hello";
    char *d = "hello";
    size_t n = 5;
    int lib = strncmp(c, d, n);
    int myLib = ft_strncmp(c, d, n);

    int result = (lib == myLib);

    if (result)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
}

static void test_function_ft_memchr(void) {
    printf("\n\ntest memchr:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100 + 1;
        char *a = malloc(sizeof(char) * size);
        if (a == NULL) return;

        for (int y = 0; y < size; y++) {
            a[y] = rand() % 256;
        }

        // Générer un caractère aléatoire à rechercher
        char c = rand() % 256;

        size_t n = rand() % size; // Taille aléatoire pour la recherche

        void *lib = memchr(a, c, n);
        void *myLib = ft_memchr(a, c, n);

        int result = ((lib == NULL && myLib == NULL) || (lib != NULL && myLib != NULL && lib == myLib));

        if (result)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(a);
    }

    // Test supplémentaire pour des cas particuliers
    t++;
    char *b = "hello";
    char c = 'e'; // caractère à rechercher
    size_t n = 5;
    void *lib = memchr(b, c, n);
    void *myLib = ft_memchr(b, c, n);

    int result = ((lib == NULL && myLib == NULL) || (lib != NULL && myLib != NULL && lib == myLib));

    if (result)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
}

static void test_function_ft_memcmp(void) {
    printf("\n\ntest memcmp:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size1 = rand() % 100 + 1;
        int size2 = rand() % 100 + 1;
        char *a = malloc(sizeof(char) * size1);
        char *b = malloc(sizeof(char) * size2);
        if (a == NULL || b == NULL) return;

        for (int y = 0; y < size1; y++) {
            a[y] = rand() % 256;
        }

        for (int y = 0; y < size2; y++) {
            b[y] = rand() % 256;
        }

        size_t n = rand() % (size1 + size2); // Taille aléatoire pour la comparaison

        int lib = memcmp(a, b, n);
        int myLib = ft_memcmp(a, b, n);

        int result = (lib == myLib);

        if (result)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(a);
        free(b);
    }

    // Test supplémentaire pour des cas particuliers
    t++;
    char *c = "hello";
    char *d = "hello";
    size_t n = 5;
    int lib = memcmp(c, d, n);
    int myLib = ft_memcmp(c, d, n);

    int result = (lib == myLib);

    if (result)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
}

static char *my_strnstr(const char *haystack, const char *needle, size_t len) {
    if (*needle == '\0') // Si l'aiguille est une chaîne vide, renvoyer l'adresse de la base du foin
        return (char *)haystack;

    size_t needle_len = 0;
    while (needle[needle_len] != '\0')
        needle_len++;

    if (len < needle_len) // Si la longueur de recherche est inférieure à la longueur de l'aiguille, l'aiguille ne peut pas être trouvée
        return NULL;

    for (size_t i = 0; i <= len - needle_len && haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) { // Si le caractère courant du foin correspond au premier caractère de l'aiguille
            size_t j;
            for (j = 1; j < needle_len; j++) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == needle_len) // Si tous les caractères de l'aiguille ont été trouvés dans le foin
                return (char *)&haystack[i];
        }
    }
    return NULL; // Aucune occurrence de l'aiguille trouvée dans le foin
}

static void test_function_ft_strnstr(void) {
    printf("\n\ntest strnstr:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size_haystack = rand() % 100 + 1;
        int size_needle = rand() % size_haystack + 1; // La taille de l'aiguille doit être inférieure ou égale à la taille du foin
        char *haystack = malloc(sizeof(char) * size_haystack + 1);
        char *needle = malloc(sizeof(char) * size_needle + 1);
        if (haystack == NULL || needle == NULL) return;

        for (int y = 0; y < size_haystack; y++) {
            haystack[y] = rand() % 256;
        }
        haystack[size_haystack] = '\0';

        for (int y = 0; y < size_needle; y++) {
            needle[y] = rand() % 256;
        }
        needle[size_needle] = '\0';

        size_t len = rand() % size_haystack; // Longueur de recherche aléatoire

        char *lib = my_strnstr(haystack, needle, len);
        char *myLib = ft_strnstr(haystack, needle, len);

        int result = ((lib == NULL && myLib == NULL) || (lib != NULL && myLib != NULL && strcmp(lib, myLib) == 0));

        if (result)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(haystack);
        free(needle);
    }

    // Test supplémentaire pour des cas particuliers
    t++;
    char *haystack = "hello";
    char *needle = "lo";
    size_t len = 5;
    char *lib = my_strnstr(haystack, needle, len);
    char *myLib = ft_strnstr(haystack, needle, len);

    int result = ((lib == NULL && myLib == NULL) || (lib != NULL && myLib != NULL && strcmp(lib, myLib) == 0));

    if (result)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);
}

static void test_function_ft_strdup(void) {
    printf("\n\ntest strdup:\n\n");
    int t = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        t++;
        int size = rand() % 100 + 1;
        char *str = malloc(sizeof(char) * (size + 1));
        if (str == NULL) return;

        for (int y = 0; y < size; y++) {
            str[y] = rand() % 256;
        }
        str[size] = '\0';

        char *ptr_lib = strdup(str);
        char *ptr_my = ft_strdup(str);

        int result = (ptr_lib != NULL && ptr_my != NULL && strcmp(ptr_lib, ptr_my) == 0);

        if (result)
            printf("%d:%s\u2714 %s", i, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", i, RED, COLOR_RESET);

        free(str);
        free(ptr_lib);
        free(ptr_my);
    }

    // Test supplémentaire pour une chaîne vide
    t++;
    char *empty_str = "";
    char *ptr_lib = strdup(empty_str);
    char *ptr_my = ft_strdup(empty_str);

    int result = (ptr_lib != NULL && ptr_my != NULL && strcmp(ptr_lib, ptr_my) == 0);

    if (result)
        printf("%d:%s\u2714 %s", t, GRN, COLOR_RESET);
    else
        printf("%d:%s\U00010102 %s", t, RED, COLOR_RESET);

    free(ptr_lib);
    free(ptr_my);
}

static void test_substr(char *str, char *expect, int index){
    if (str == NULL){
        if (expect == NULL)
            printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
    }
    else{
        if (expect != NULL && strcmp(str, expect) == 0)
            printf("%d:%s\u2714 %s", index, GRN, COLOR_RESET);
        else
            printf("%d:%s\U00010102 %s", index, RED, COLOR_RESET);
    }
}

static void test_function_ft_substr(void){
    printf("\n\ntest ft_substr:\n\n");
    test_substr(ft_substr("Hello World", 6, 5), "World", 1); // Attendu: "World"
    test_substr(ft_substr("Testing", 2, 10), "sting", 2); // Attendu: "sting"
    test_substr(ft_substr("Substring", 0, 3), "Sub", 3); // Attendu: "Sub"
    test_substr(ft_substr(NULL, 0, 3), NULL, 4); // Attendu: NULL
}

static void test_ft_strjoin(){
    
}

static void test_function_ft_strjoin(void){
    printf("\n\ntest ft_strjoin:\n\n");

}

int main(void){
    // test_function_ft_isalpha();
    // test_function_ft_isdigit();
    // test_function_ft_isalnum();
    // test_function_ft_isascii();
    // test_function_ft_isprint();
    // test_function_ft_strlen();
    // test_function_ft_memset();
    // test_function_bzero();
    // test_function_memcpy();
    // test_function_ft_memmove();
    // test_function_ft_strlcpy();
    // test_function_ft_strlcat();
    // test_function_ft_toupper();
    // test_function_ft_tolower();
    // test_function_ft_strchr();
    // test_function_ft_strrchr();
    // test_function_ft_strncmp();
    // test_function_ft_memchr();
    // test_function_ft_memcmp();
    // test_function_ft_strnstr();
    // test_function_ft_atoi();
    // test_function_ft_calloc();
    // test_function_ft_strdup();
    // test_function_ft_substr();
    test_function_ft_strjoin();
    return 0;
}

