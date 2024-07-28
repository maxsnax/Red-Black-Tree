#include "tree.h"
#include <iostream>
#include <stdio.h>

Tree::Tree() {
	root = nullptr;
	numElements = 0;
	elementTracker = 0;
}


Tree::~Tree() {
}


TreeNode* Tree::GetRoot() {
	return root;
}

/*	================================================================================
 		Adding values and maintaining the tree
 	================================================================================  */

void Tree::AddValue(int value) {
	TreeNode* curr = root;
	TreeNode* parent = nullptr;
	++numElements;

	while (curr != nullptr) {
		parent = curr;
		if (value < curr->GetValue()) {
			curr = curr->GetLeft();
		}
		else {
			curr = curr->GetRight();
		}
	}

	TreeNode* newNode = new TreeNode;
	newNode->SetValue(value);
	newNode->SetParent(parent);
	newNode->SetColor(RED);

	if (newNode->GetParent() == nullptr) {
		root = newNode;
		root->SetColor(BLACK);
		return;
	}
	else if (parent->GetValue() > newNode->GetValue()) {
		parent->SetLeft(newNode);
	}
	else {
		parent->SetRight(newNode);
	}

	AddValueFixUp(newNode);
}


void Tree::AddValueFixUp(TreeNode* node) {
	TreeNode* parent = nullptr;
	TreeNode* grandParent = nullptr;

	while (node != root && node->GetColor() == RED && node->GetParent()->GetColor() == RED) {
		parent = node->GetParent();
		grandParent = parent->GetParent();
		if (grandParent != nullptr && parent == grandParent->GetLeft()) {
			TreeNode* uncle = grandParent->GetRight();
			// Case 1
			if (uncle->GetColor() == RED) {
				uncle->SetColor(BLACK);
				parent->SetColor(BLACK);
				grandParent->SetColor(RED);
				node = grandParent;
			}
			// Case 2
			else {
				if (node == parent->GetRight()) {
					LeftRotate(parent);
					node = parent;
					parent = node->GetParent();
				}
				RightRotate(grandParent);
				parent->SetColor(BLACK);
				grandParent->SetColor(RED);
				node = parent;
			}
		}
		// Case 3
		else {
			TreeNode* uncle = grandParent->GetLeft();
			if (uncle != nullptr && uncle->GetColor() == RED) {
				uncle->SetColor(BLACK);
				parent->SetColor(BLACK);
				grandParent->SetColor(RED);
				node = grandParent;
			}
			else {
				if (node == parent->GetLeft()) {
					RightRotate(parent);
					node = parent;
					parent = node->GetParent();
				}
				LeftRotate(grandParent);
				parent->SetColor(BLACK);
				grandParent->SetColor(RED);
				node = parent;
			}
		}
	}
	root->SetColor(BLACK);
}

void Tree::LeftRotate(TreeNode* node) {
    TreeNode *right_sibling = node->GetRight();
    node->SetRight(right_sibling->GetLeft());

    if (node->GetRight() != nullptr)
        node->GetRight()->SetParent(node);

    right_sibling->SetParent(node->GetParent());

    if (node->GetParent() == nullptr)
        root = right_sibling;
    else if (node == node->GetParent()->GetLeft())
        node->GetParent()->SetLeft(right_sibling);
    else
        node->GetParent()->SetRight(right_sibling);

    right_sibling->SetLeft(node);
    node->SetParent(right_sibling);
}

void Tree::RightRotate(TreeNode* node) {
    TreeNode *left_sibling = node->GetLeft();
    node->SetLeft(left_sibling->GetRight());

    if (node->GetLeft() != nullptr)
        node->GetLeft()->SetParent(node);

    left_sibling->SetParent(node->GetParent());

    if (node->GetParent() == nullptr)
        root = left_sibling;
    else if (node == node->GetParent()->GetLeft())
        node->GetParent()->SetLeft(left_sibling);
    else
        node->GetParent()->SetRight(left_sibling);

    left_sibling->SetRight(node);
    node->SetParent(left_sibling);
}


/*	================================================================================
 		Getting nodes from the tree of specific values
 	================================================================================  */

TreeNode* Tree::GetNode(int value) {
	TreeNode* curr = root;

	while (curr != nullptr) {
		TreeNode* left = curr->GetLeft();
		TreeNode* right = curr->GetRight();

		if (left != nullptr) {
			if (left->GetValue() >= value) {
				curr = left;
				continue;
			}
		}
		if (right != nullptr) {
			if (right->GetValue() <= value) {
				curr = right;
				continue;
			}
		}

		break;
	}

	if (curr == nullptr) {
	} else if (curr->GetValue() != value) {
		curr = nullptr;
	}
	return curr;
}

TreeNode* Tree::GetMinimum(TreeNode* root) {
	TreeNode* curr = this->root;
	while (curr->GetLeft() != nullptr) {
		curr = curr->GetLeft();
	}

	return curr;
}


/*	================================================================================
 		Removing nodes from the tree
 	================================================================================  */

void Tree::RemoveValue(int value) {
	/*
	TreeNode* node = GetNode(value);
	if (node == nullptr) return;
	DeleteNode(node);
	*/
}

void Tree::DeleteNode(TreeNode* z) {
	/*
	TreeNode* y = z;
	TreeNode* x = nullptr;
	bool yColor = y->GetColor();

	if (z->GetLeft() == nullptr) {
		x = z->GetRight();
		Transplant(z, z->GetRight());
	}
	else if (z->GetRight() == nullptr) {
		x = z->GetLeft();
		Transplant(z, z->GetLeft());
	}
	else {
		y = GetMinimum(z->GetRight());
		x = y->GetRight();
		if(y != z->GetRight()) {
			Transplant(y, y->GetRight());
			y->SetRight(z->GetRight());
			y->GetParent()->SetRight(y);
		}
		else {
			x->SetParent(y);
		}
		Transplant(z, y);
		y->SetLeft(z->GetLeft());
		y->GetParent()->SetLeft(y);
		y->SetColor(z->GetColor());
	}
	if (yColor == BLACK) {
		DeleteFixUp(x);
	}
	*/
}

void Tree::Transplant(TreeNode* u, TreeNode* v) {
	/*
	if (u->GetParent() == nullptr) {
		root = v;
	}
	else if (u == u->GetParent()->GetLeft()) {
		u->GetParent()->SetLeft(v);
	}
	else {
		u->GetParent()->SetRight(v);
	}
	if (v == nullptr) {
		v->SetParent(u->GetParent());
	}
	*/
}

void Tree::DeleteFixUp(TreeNode* x) {
	/*
	TreeNode* w = nullptr;

	while (x != GetRoot() && x->GetColor() == BLACK) {
		if (x == x->GetParent()->GetLeft()) {
			w = x->GetParent()->GetRight();
			if (w->GetColor() == RED) {
				w->SetColor(BLACK);
				x->GetParent()->SetColor(RED);
				LeftRotate(x->GetParent());
				w = x->GetParent()->GetRight();
			}
			if (w->GetLeft()->GetColor() == BLACK && w->GetRight()->GetColor() == BLACK) {
				w->SetColor(RED);
				x = x->GetParent();
			}
			else {
				if (w->GetRight()->GetColor() == BLACK) {
					w->GetRight()->SetColor(BLACK);
					w->SetColor(BLACK);
					RightRotate(w);
				}
				w->SetColor(x->GetParent()->GetColor());
				x->GetParent()->SetColor(BLACK);
				w->GetRight()->SetColor(BLACK);
				LeftRotate(x->GetParent());
				x = root;
			}
		}
		else {
			w = x->GetParent()->GetLeft();
			if (w->GetColor() == RED) {
				w->SetColor(BLACK);
				x->GetParent()->SetColor(RED);
				RightRotate(x->GetParent());
				w = x->GetParent()->GetLeft();
			}
			if (w->GetRight()->GetColor() == BLACK && w->GetLeft()->GetColor() == BLACK) {
				w->SetColor(RED);
				x = x->GetParent();
			}
			else {
				if (w->GetColor() == BLACK) {
					w->GetRight()->SetColor(BLACK);
					w->SetColor(RED);
					LeftRotate(w);
					w = x->GetParent()->GetLeft();
				}
				w->SetColor(w->GetParent()->GetColor());
				x->GetParent()->SetColor(BLACK);
				w->GetLeft()->SetColor(BLACK);
				RightRotate(x->GetParent());
				x = root;
			}
		}
	}
	x->SetColor(BLACK);
	*/
}


/*	================================================================================
 		Printing the tree's contents
 	================================================================================  */

void Tree::PrintTreeWalk(int orderNumber) {
	if (root == nullptr) {
		return;
	}

	switch (orderNumber) {
		case INORDER:
			printInorder(root);
			break;

		case PREORDER:
			printPreorder(root);
			break;

		case POSTORDER:
			printPostorder(root);
			break;
	}

	elementTracker = 0;
}


void Tree::printInorder(TreeNode* node) {
	if (node == nullptr) {
		return;
	}

	printInorder(node->GetLeft());
	printf("%d", node->GetValue());
	if (++elementTracker < numElements) {
		printf(" ");
	}
	printInorder(node->GetRight());
}


void Tree::printPreorder(TreeNode* node) {
	if (node == nullptr) {
		return;
	}

	printf("%d", node->GetValue());
	if (++elementTracker < numElements) {
		printf(" ");
	}
	printPreorder(node->GetLeft());
	printPreorder(node->GetRight());

}


void Tree::printPostorder(TreeNode* node) {
	if (node == nullptr) {
		return;
	}

	printPostorder(node->GetLeft());
	printPostorder(node->GetRight());
	printf("%d", node->GetValue());
	if (++elementTracker < numElements) {
		printf(" ");
	}
}

