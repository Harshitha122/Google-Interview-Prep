struct NodeWParent : TreeNode {
    NodeWParent* parent;
    NodeWParent(int x) : TreeNode(x), parent(NULL) {}
};