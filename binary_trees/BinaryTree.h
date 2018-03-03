/**
* Title : Binary Tree Header
* Author : Ecem Ilgun
* ID: 21502157
* Section : 3
* Assignment : 2
* Description : Header File of BinaryTree.cpp
*/
#include "BinaryNode.h"

int kthLargestElement(BinaryNode *root, int k);
void reverseInorder(BinaryNode *root, int k, int* count, int* item);

bool isBalanced(BinaryNode *root);
bool actualIsBalanced(BinaryNode* root, int* height);


