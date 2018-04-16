#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1, const void* p2){
    const int* a = p1;
    const int* b = p2;

    if(*a > *b){
        return 1;
    }else if(*a == *b){
        return 0;
    }else{
        return -1;
    }
}

int main(){
    int N;
    int a[200000];

    scanf("%d", &N);

    for(int i = 0; i < N * 2; i++){
        scanf("%d", a + i);
    }
    qsort(a, N * 2, sizeof(int), compare);

    printf("%d\n", a[(N * 2 - 1) / 2]);
}
