#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
    char c;

    bool isFirst = true;
    int index_max = 0, count_max = 0;
    int index_start = 0, count = 0;
    int i = 0;
    while( (c = getchar() ) != '\n' ){
        if(isdigit(c) ){
            if(isFirst ){
                index_start = i;
                count = 1;

                isFirst = false;
            }
            else{
                count++;
            }
        }
        else{
            isFirst = true;
        }


        if(count > count_max){
            count_max = count;
            index_max = index_start;
        }
        i++;
    }

    if(!i){
        puts("NULL");
        return 0;
    }

    printf("%d %d\n", index_max, count_max);
}
