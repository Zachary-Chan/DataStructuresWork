void InorderTraversal( BinTree BT ){
    if(BT){
        InorderTraversal(BT->Left);
        printf(" %c",BT->Data);
        InorderTraversal(BT->Right);
    }
}
void PreorderTraversal( BinTree BT ){
    if(BT){
        printf(" %c",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void PostorderTraversal( BinTree BT ){
    if(BT){
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c",BT->Data);
    }

}
void LevelorderTraversal( BinTree BT ){
    BinTree q[100];
    BinTree p;
    int head=0,tail=0;
    if(!BT) return;
    if(BT){
        q[tail++]=BT; 
        while(tail!=head){
            p=q[head++];
            printf(" %c",p->Data);
            if(p->Left)     q[tail++]=p->Left;
            if(p->Right)    q[tail++]=p->Right;
        } 
    }
} 
