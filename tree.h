#ifndef TREE_H
#define TREE_H

#include "treeNode.h"

#define INORDER 1
#define PREORDER 2
#define POSTORDER 3
#define BLACK true
#define RED false

// Defines a binary tree.
class Tree {
public:
	// Constructor/Destructor for Tree.
	Tree();
	~Tree();

	// Returns the root of the tree.
	TreeNode* GetRoot();

	// Adds the value to the tree.
	void AddValue(int value);

	void AddValueFixUp(TreeNode* node);

	void LeftRotate(TreeNode* node);

	void RightRotate(TreeNode* node);

	// Returns the node with the specified value.
	TreeNode* GetNode(int value);

	TreeNode* GetMinimum(TreeNode* root);

	void Transplant(TreeNode* u, TreeNode* v);

	void DeleteNode(TreeNode* node);

	void DeleteFixUp(TreeNode* node);

	// Removes the node with the specified value.
	void RemoveValue(int value);

	// Prints the list of values from the tree, using the specified order.
	void PrintTreeWalk(int orderNumber);

	// Gets called in PrintTreeWalk in switch case of orderNumber == 1
	void printInorder(TreeNode* node);

	// Called in PrintTreeTalk in switch case of 2
	void printPreorder(TreeNode* node);

	// Called in PrintTreeWalk in switch case of 3
	void printPostorder(TreeNode* node);

private:
	TreeNode* root;
	int numElements;
	int elementTracker;
};

#endif
