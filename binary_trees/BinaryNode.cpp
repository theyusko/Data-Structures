/**
* Title : Binary Node
* Author : Ecem Ilgun
* ID: 21502157
* Section : 3
* Assignment : 2
* Description : Binary Tree Node File
*/
#include "BinaryNode.h"
#include <string>

BinaryNode::BinaryNode(){
    item = -99999999; //let this be the sentimental value
    this->leftChildPtr = NULL;
    this->rightChildPtr = NULL;
}

BinaryNode::BinaryNode( const int& anItem ){
    item = anItem;
    this->leftChildPtr = NULL;
    this->rightChildPtr = NULL;
}

BinaryNode::BinaryNode( const int& anItem , BinaryNode* leftPtr , BinaryNode* rightPtr ){
    item = anItem;
    this->leftChildPtr = NULL;
    this->rightChildPtr = NULL;
}

int BinaryNode::getItem() const{
    return item;
}

BinaryNode* BinaryNode::getLeftChildPtr() const{
    return this->leftChildPtr;
}

BinaryNode* BinaryNode::getRightChildPtr() const{
    return this->rightChildPtr;
}

void BinaryNode::setItem(const int& anItem){
    this->item = anItem;
}

void BinaryNode::setLeftChildPtr ( BinaryNode* leftPtr ){
    this->leftChildPtr = leftPtr;
}

void BinaryNode::setRightChildPtr ( BinaryNode* rightPtr ){
    this->rightChildPtr = rightPtr;
}
