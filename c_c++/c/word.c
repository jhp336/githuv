#include <stdio.h>

int main() {
    printf("문자열을 입력하세요.\n");

    char a[256];
    scanf("%s",a);
    printf("\"%s\"를 입력하셨네요.",a);

    return 0;

}