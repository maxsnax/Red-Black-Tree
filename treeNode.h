#ifndef TREE_NODE_H
#define TREE_NODE_H

// Defines a node of a tree.
class TreeNode {
public:
    TreeNode();
    bool isEmpty();
    void SetValue(int newValue);
    void SetColor(bool isBlack);
    void SetParent(TreeNode* node);
    void SetLeft(TreeNode* node);
    void SetRight(TreeNode* node);
    int GetValue();
    bool GetColor();
    TreeNode* GetParent();
    TreeNode* GetLeft();
    TreeNode* GetRight();

private:
    int value;
    bool isBlack;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

#endif
