/**
* Title : Binary Tree
* Author : Ecem Ilgun
* ID: 21502157
* Section : 3
* Assignment : 2
* Description : Binary Tree File
*/
#include <cmath>
#include "BinaryNode.h"
#include "BinaryTree.h"
#include <string>
#include <iostream>
using namespace std;

/***********
Homework Part 2
************/

/****
question b
****/
/**
0) An empty tree is height-balanced.
A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.
(source: geeksforgeeks.org)
**/
bool isBalanced(BinaryNode *root){
    int height = -1;
    return actualIsBalanced(root, &height);
}

//Helper function
bool actualIsBalanced(BinaryNode* root, int* height) {
    //Define height of left and right subtrees according to 3rd rule above
    int leftHeight = 0, rightHeight = 0;
    //Rules 1 and 2 above
    bool leftBalanced = false, rightBalanced = false;
    //Rule 0 above
    if (root == NULL) {
        *height = 0;
        return true;
    }
    //Check rule 1 and 2 recursively
    leftBalanced = actualIsBalanced(root->getLeftChildPtr(), &leftHeight);
    rightBalanced = actualIsBalanced(root->getRightChildPtr(), &rightHeight);

    //hight of a node is (max of right and left subtrees) + 1
    *height = (leftHeight > rightHeight? leftHeight : rightHeight) + 1;

    //Check rule 3
    if( std::abs(leftHeight - rightHeight) > 1 )
        return false;
    else {
        //Now if rule 1 and 2 also apply, tree is balanced
        return leftBalanced && rightBalanced;
    }
}

/****
question c
****/
int kthLargestElement( BinaryNode *root, int k ){
    int count = 0, item = -666;
    reverseInorder(root, k, &count, &item);
    return item;
}

void reverseInorder( BinaryNode* root, int k, int* count, int* item ) {
    if (root == NULL || (*count) >= k)
        return;
    else{
        cout << "do you enter reverse?" << "count is " << *count << endl << endl;
        //Reverse Inorder Algorithm is used here:
        reverseInorder(root->getRightChildPtr(), k, count, item);
        (*count)++;
        if(k == (*count)){
            (*item) = root->getItem();
            return;
        }
        reverseInorder(root->getLeftChildPtr(), k, count, item);
    }
}
