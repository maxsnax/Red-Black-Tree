#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "tree.h"
#include "treeNode.h"

using namespace std;

/* You may use this file to test your program.
	This file will not be submitted, as a different test4.cpp will be used.
  Every required method is included here so that you can verify that
		you have included everything the test engine will call. */
int main(int argv, char **argc) {

	printf("Starting Program:\n");

	Tree mainTree;	// Tree to use for testing

	for (int i = 1; i <= 8; i++) {
		mainTree.AddValue(i);
	}

	mainTree.PrintTreeWalk(3);



}
