/**
* Title : Binary Node Header
* Author : Ecem Ilgun
* ID: 21502157
* Section : 3
* Assignment : 2
* Description : header file of BinaryNode.cpp
*/
#ifndef BINARYNODE_H
#define BINARYNODE_H

class BinaryNode {
private :
    int item ; // Data portion
    BinaryNode* leftChildPtr ; // Pointer to left child
    BinaryNode* rightChildPtr ; // Pointer to right child
public :
    BinaryNode ();
    BinaryNode ( const int& anItem );
    BinaryNode ( const int& anItem , BinaryNode* leftPtr , BinaryNode* rightPtr );
    int getItem () const ;
    BinaryNode* getLeftChildPtr () const ;
    BinaryNode* getRightChildPtr () const ;
    void setItem ( const int & anItem );
    void setLeftChildPtr ( BinaryNode* leftPtr );
    void setRightChildPtr ( BinaryNode* rightPtr );
}; // end BinaryNode

#endif
