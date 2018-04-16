#include <stdio.h>

typedef struct{
    int number;
    int number_next, number_prior;
}Node;

int main(){
    int N, p;
    scanf("%d%d", &N, &p);

    //下标从1开始，最大为3000
    Node array[3001];

    //循环，从第二位到倒数第二位
    for(int i = 2; i <= N - 1; i++){
        array[i].number = i;
        array[i].number_next = i + 1;
        array[i].number_prior = i - 1;
    }
    array[1].number = 1;
    array[1].number_next = 2;
    array[1].number_prior = N;

    array[N].number = N;
    array[N].number_next = 1;
    array[N].number_prior = N - 1;  //完成初始化

    int number_quit[3000];

    int count_persist = 1;
    int count_quit = 0;
    int number = 1;
    while(array[number].number_next != number){
        if(!(count_persist % p) ){  //达到计数个数
            number_quit[count_quit++] = number;

            //重构连接关系
            int number_prior = array[number].number_prior;
            int number_next = array[number].number_next;
            array[number_prior].number_next = number_next;
            array[number_next].number_prior = number_prior;
        }

        number = array[number].number_next;
        count_persist++;
    }
    number_quit[N - 1] = number;

    for(int i = 0; i < N; i++){
        printf("%d%c", number_quit[i], i == N - 1 ? '\n' : ' ');
    }
}

