#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    const int count_move = m % n;
    const int number = n + count_move;
    const int index_start = count_move;
    int* a = malloc(sizeof(int) * number);

    for(int i = index_start; i < number; i++){
        scanf("%d", a + i);
        a[i - count_move] = a[i];
    }

    for(int i = 0, j = number - count_move; i < index_start; i++, j++){
        a[j] = a[i];
    }

    for(int i = index_start; i < number; i++){
        printf("%d%s", a[i], i == number - 1 ? "" : " ");
    }
}
