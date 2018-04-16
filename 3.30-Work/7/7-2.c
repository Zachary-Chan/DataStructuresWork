#include <stdio.h>
#include <stdlib.h> // for calloc(), free()
#include <stdbool.h>    // for boolean variables

typedef int datatype;
typedef struct node{
    datatype data;
    struct node* next;
}Node, *pNode;

pNode add(pNode p_head, datatype data){
    //如果是空指针
    if(!p_head){
        //从heap区分配节点空间，并初始化为0
        p_head = calloc(1, sizeof(Node));
        p_head->data = data;

        return p_head;
    }

    pNode p_temp = p_head;
    //找到链表的尾节点
    while(p_temp->next){
        p_temp = p_temp->next;
    }

    //建立新的节点
    pNode p_new = calloc(1, sizeof(Node));
    p_temp->next = p_new;
    p_new->data = data;

    return p_head;
}

pNode destroy(pNode p_head){
    //遍历链表
    while(p_head){
        pNode p_temp = p_head;
        p_head = p_head->next;

        free(p_temp);
    }

    return NULL;
}

bool isEqual(pNode s1, datatype data){
    while(s1){
        if(s1->data > data){
            return false;
        }

        if(s1->data == data){
            return true;
        }

        s1 = s1->next;
    }
    return false;
}

int main(){
    pNode s1 = NULL, s3 = NULL;

    int num;
    while( scanf("%d", &num) == 1 && num != -1 ){
        s1 = add(s1, num);
    }

    pNode p_temp = s1;
    while( scanf("%d", &num) == 1 && num != -1 ){
        while(p_temp){
            if(p_temp->data > num){
                break;
            }
            if(p_temp->data == num){
                s3 = add(s3, num);

                //去除重复元素
                p_temp = p_temp->next;
                break;
            }

            p_temp = p_temp->next;
        }
    }//完成输入
    

    if(!s3){
        puts("NULL");
        return 0;
    }

    p_temp = s3;
    while(p_temp->next){
        printf("%d ", p_temp->data);

        p_temp = p_temp->next;
    }
    printf("%d\n", p_temp->data);

    //释放heap区内存
    s1 = destroy(s1);
    s3 = destroy(s3);
}

