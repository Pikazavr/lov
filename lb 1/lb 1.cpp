#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int max = 0;
    int min = 999;
    int res = 0;
    int mas[10];
       
    srand(time(NULL)); 
    for (int i = 0; i < 10; i++) {
        mas[i] = rand() % 100; 
        printf("%d ", mas[i]); 
    }
    printf("\n");

       for (int i = 0; i < 10; i++) {
        if (mas[i] > max) {
            max = mas[i];
        }
        if (mas[i] < min) {
            min = mas[i];
        }
    }

        res = max - min;
    printf("Diff %d \n", res);
    return 0;
}
