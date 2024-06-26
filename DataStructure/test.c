/**
* 类名:test
* 描述:
* 当前用户:21204
* 当前时间:2024/6/26:17:43
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 10;
    float a = 1.0f;
    double b = 2.0;
    printf("hello world\n");
    printf("int:%d\n",num);
    printf("float:%.1f\n",a);
    printf("double:%.2lf\n",b);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    printf("--------------------------\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10-i; ++j) {
            printf("*");
        }
        printf("\n");

    }

    system("start cmd");


    return 0;
}