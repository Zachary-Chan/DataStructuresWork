#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node, *pNode;

void add(pNode* p_head, int data){
    if(!(*p_head) ){
        (*p_head) = calloc(1, sizeof(Node));

        (*p_head)->data = data;
        return;
    }

    pNode p_tail = *p_head;
    while(p_tail->next){
        p_tail = p_tail->next;
    }

    pNode p_new = calloc(1, sizeof(Node));
    p_tail->next = p_new;

    p_new->data = data;
}

void destroy(pNode* const p_head){
    pNode p_temp = *p_head;

    while(p_temp){
        pNode p = p_temp;
        p_temp = p_temp->next;

        free(p);
    }
}

int main(){
    pNode p_head = NULL;
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);

        add(&p_head, num);
    }

    int x, y;
    scanf("%d%d", &x, &y);

    pNode p_legal = NULL;

    pNode p_temp = p_head;
    while(p_temp){
        if(p_temp->data >= x && p_temp->data <= y){
            p_temp = p_temp->next;

            continue;
        }

        add(&p_legal, p_temp->data);
        p_temp = p_temp->next;
    }

    p_temp = p_legal;
    while(p_temp->next){
        printf("%d ", p_temp->data);

        p_temp = p_temp->next;
    }
    printf("%d\n", p_temp->data);

    destroy(&p_head);
    destroy(&p_legal);
}
