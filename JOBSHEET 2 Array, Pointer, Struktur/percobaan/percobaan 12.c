/*
	nama : Muhammad Devin Rahadi
	NIM : 23343076
	kasus : nested structure percobaan 12
*/

#include <stdio.h>

struct level1 {
    int a;
    struct level2 {
        int b;
        struct level3 {
            int c;
            struct level4 {
                int d;
                struct level5 {
                    int e;
                } level5;
            } level4;
        } level3;
    } level2;
} level1;

int main() {
    level1.a = 1;
    level1.level2.b = 2;
    level1.level2.level3.c = 3;
    level1.level2.level3.level4.d = 4;
    level1.level2.level3.level4.level5.e = 5;

    printf("level1.a = %d\n", level1.a);
    printf("level1.level2.b = %d\n", level1.level2.b);
    printf("level1.level2.level3.c = %d\n", level1.level2.level3.c);
    printf("level1.level2.level3.level4.d = %d\n", level1.level2.level3.level4.d);
    printf("level1.level2.level3.level4.level5.e = %d\n", level1.level2.level3.level4.level5.e);

    return 0;
}