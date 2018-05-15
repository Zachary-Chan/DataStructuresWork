void PreorderPrintLeaves(BinTree BT) {  
    if ( !BT)     return;
    
    if ((!BT->Left) && (!BT->Right))  // 若是叶节点  
        printf(" %c", BT->Data);  
    PreorderPrintLeaves(BT->Left);  
    PreorderPrintLeaves(BT->Right);  
}  
