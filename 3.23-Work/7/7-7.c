#include <stdio.h>
#include <stdbool.h>

int main(){
    char ch;

    bool hasRunned = false;
    while( (ch = getchar()) != '\n'){
        hasRunned = true;

        if( ch >= 'A' && ch <= 'Z' ){
            ch -= 5;

            if(ch < 'A'){
                putchar('Z' - ('A' - ch) + 1);
            }
            else{
                putchar(ch);
            }
        }
        else{
            putchar(ch);
        }
    }

    if(!hasRunned){
        puts("NULL");
    }
}
