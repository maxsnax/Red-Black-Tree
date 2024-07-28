#include <iostream>
#include <stdio.h>
#include "treeNode.h"


TreeNode::TreeNode() {
	value = -1;
	isBlack = true;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}


void TreeNode::SetValue(int newValue) {
	value = newValue;
}


void TreeNode::SetColor(bool state) {
    isBlack = state;
}


void TreeNode::SetParent(TreeNode* node) {
	parent = node;
}


void TreeNode::SetLeft(TreeNode* node) {
	left = node;
}


void TreeNode::SetRight(TreeNode* node) {
	right = node;
}


int TreeNode::GetValue() {
    return value;
}


bool TreeNode::GetColor() {
	return isBlack;
}


TreeNode* TreeNode::GetParent() {
    return parent;
}


TreeNode* TreeNode::GetLeft() {
    return left;
}


TreeNode* TreeNode::GetRight() {
    return right;
}


bool TreeNode::isEmpty() {
	return value == -1;
}

