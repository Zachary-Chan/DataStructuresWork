void InOrder(BTreeNode*BT) {
    if ( !BT)       return;
    
    InOrder(BT->left);
    std::cout <<BT->data << ' ';
    InOrder(BT->right);
}
