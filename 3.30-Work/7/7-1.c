#include<stdio.h>  
  
typedef struct node *ptrNode;  
typedef ptrNode LinkList;  //头结点  
typedef ptrNode Position;//中间节点  
typedef int ElementType;  
struct node{  
    ElementType Element;  
    Position next;  
};  
  
int IsEmpty(LinkList L)  
{  
    return L->next == NULL;  
}  
  
LinkList creatList(void)                
{  
    LinkList head,r,p;  
    int x;  
    head = (struct node*)malloc(sizeof(struct node));    //生成新结点  
    r = head;  
    scanf("%d",&x);  
  
    while(x != -1){  
        p = (struct node*)malloc(sizeof(struct node));  
        p->Element = x;  
        r->next = p;  
        r = p;  
        scanf("%d",&x);  
    }  
    r->next = NULL;  
    return head;  
}  
  
LinkList mergeList(LinkList a, LinkList b)  
{  
    Position ha, hb,hc;  
    LinkList c,r,p;  
  
    ha = a->next;  
    hb = b->next;  
      
    c = (struct node*)malloc(sizeof(struct node));  
    r = c;  
    while((ha != NULL)&&(hb != NULL)){  
        p = (struct node*)malloc(sizeof(struct node));  
        if(ha->Element <= hb->Element){  
            p->Element = ha->Element;  
            ha = ha->next;  
        }  
        else{  
            p->Element = hb->Element;  
            hb = hb->next;  
        }  
  
        r->next = p;  
        r = p;  
    }  
    if(ha == NULL){  
        while(hb != NULL){  
            p = (struct node*)malloc(sizeof(struct node));  
            p->Element = hb->Element;  
            hb = hb->next;  
            r->next = p;  
            r = p;  
        }  
    }  
    if(hb == NULL){  
        while(ha != NULL){  
            p = (struct node*)malloc(sizeof(struct node));  
            p->Element = ha->Element;  
            ha = ha->next;  
            r->next = p;  
            r = p;  
        }  
    }  
  
    r->next = NULL;  
  
    return c;  
}  
  
void printList(LinkList L)  
{  
    LinkList hc;  
    int flag = 0;  
  
    hc = L->next;  
    if(hc == NULL)  
        printf("NULL");  
    while(hc != NULL){  
        if(flag)  
            printf(" ");  
        else  
            flag = 1;  
        printf("%d",hc->Element);  
        hc = hc->next;  
    }  
}  
  
int main(void)  
{  
    LinkList L1,L2,L3;  
  
    L1 = creatList();  
    L2 = creatList();  
  
    L3 = mergeList(L1,L2);  
      
    printList(L3);  
  
    return 0;  
}  

