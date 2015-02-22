#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validchar(char c, char *str);
void decode(char *str, char *decoded);
void xorall(char c, char *str, char *coded);

void decode(char *str, char *decoded) {
    int temp = 0, n;
    char key, i;
    char ans;
    for (i = 'a'; i <= 'z'; i++) {
        if (validchar(i, str) >= temp) {
            temp = validchar(i, str);
            printf("Validchars: %c(%d)\n", i, temp);
            key = i;
        }
    }
    printf("\nMelyik?\n");
    scanf("%c", &ans);
    xorall(ans, str, decoded);
    n = 0;
    while (decoded[n] != '\0') {
        printf("%c -- %d\n", decoded[n], decoded[n]);
        n++;
    }
    printf("\n\n");
}

int validchar(char c, char *str) {
    int i = 0, cnt = 0, test;
    while (i < 10) {
        if ((str[i]^c) <= 'z' && (str[i]^c) >= 'a') {
            cnt++;
        }
        i++;
    }
    return cnt;
}

void xorall(char c, char *str, char *empty) {
    int i = 0;
    while (i < 10) {
        empty[i] = str[i]^c;
        i++;
    }
}

int main()
{
    char key = 'd', prob[] = "asdf jkle";
    char encrypted[10] = {};
    char decoded[10] = {};

    int i = 0;
    xorall(key, prob, encrypted);
    while (prob[i] != '\0') {
        printf("%c -- %d --> %c -- %d\n",prob[i], prob[i], encrypted[i], encrypted[i]);
        i++;
    }
    printf("\n\n");

    i = 0;
    xorall(key, encrypted, prob);
    while (prob[i] != '\0') {
        printf("%c -- %d --> %c -- %d\n", encrypted[i], encrypted[i], prob[i], prob[i]);
        i++;
    }
    printf("\n\n");

    decode(encrypted, decoded);

    return 0;
}
