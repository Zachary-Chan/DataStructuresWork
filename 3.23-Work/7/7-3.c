#include <stdio.h>

int main(){
    int number;
    scanf("%d", &number);

    int a[100000];
    for(int i = 0; i < number; i++){
        scanf("%d", a + i);
    }

    int count_max = 1, index_start = 0;
    for(int i = 0; i < number - 1; i++){

        int count = 1, plus = a[i + 1] - a[i];
        if(plus > 0){
            count++;
            for(int j = i + 2; j < number; j++){
                if(a[j] - a[j - 1] > 0){
                    count++;
                    continue;
                }

                break;
            }
        }

        if(count > count_max){
            count_max = count;
            index_start = i;
        }
    }

    for(int i = index_start; i < index_start + count_max; i++){
        printf("%d%s", a[i], i == index_start + count_max - 1 ? "" : " ");
    }
}
