int GetHeight(BinTree BT) {
    if ( !BT)       return 0;
    return fmax(GetHeight(BT->Left), GetHeight(BT->Right) ) + 1;
}
