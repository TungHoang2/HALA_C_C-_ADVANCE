#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Nhap do dai ten cua ban: ");
    scanf("%d",&n);
    char *ptr =(char*)calloc(n,sizeof(char));

    printf("Nhap ten cua ban:");
    scanf("%s",ptr);

    printf("%s",ptr);
    free(ptr);
}