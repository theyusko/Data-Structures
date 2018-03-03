#include "List.h"
#include <cstddef>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

    List::List() : size(0), head(NULL) {}
    List::List(const List& aList): size(aList.size){
        if (aList.head == NULL)
            head = NULL;  // original list is empty
        else {
            // copy first node
            head = new ListNode;
            head->first = aList.head->first;
            head->last = aList.head->last;
            head->role = aList.head->role;
            // copy rest of list
            ListNode *newPtr = head;  // new list ptr
            for (ListNode *origPtr = aList.head->next; origPtr != NULL;
                 origPtr = origPtr->next){
                newPtr->next = new ListNode;
                newPtr = newPtr->next;
                newPtr->role = origPtr->role;
                newPtr->first = origPtr->first;
                newPtr->last = origPtr->last;
            }
            newPtr->next = NULL;
        }
    }

    List::~List(){
        ListNode*temp;
        while(head!=NULL) {
            temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        size = 0;
        delete head; // not sure??
    }

    bool List::isEmpty() const { return size == 0; }

    int List::getLength() const { return size; }

    bool List::insert(string first, string last, string role) {

        ListNode* newPtr = find(first, last);
        ListNode* cur = head;
        if (newPtr == NULL) { // not found, insert
            newPtr = new ListNode;
            size++;
            newPtr->first = first;
            newPtr->last = last;
            newPtr->role = role;
            newPtr->next = NULL;
            if (cur == NULL) {
                cur = newPtr;
            }
            while(cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = newPtr;
            return true;
        }
        return false;
    }

    bool List::remove(string first, string last){
        ListNode* cur = head;
        bool found = false;
        lowercase(first);
        lowercase(last);
        lowercase(cur->first);
        lowercase(cur->last);
        if( (cur->first).compare(first) == 0 && (cur->last).compare(last) == 0 ){
            //remove from head
            head = head->next;
            cur ->next = NULL;
            delete cur;
            return found;
        }
        while ( !found && cur->next!= NULL ) {
            if( (cur->next->first).compare(first) == 0 && (cur->next->last).compare(last) == 0 )
                found = true;
            else
                cur = cur->next;
        }

        if(found){
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
        return found;
    }

    void List::display() {
        ListNode* cur = head;
        int index = 0;
        while(cur!= NULL) {
            cout<< cur->first <<" "<< cur->last << " ," <<cur-> role<<" (for the "<< index<<"th musician)"<<endl;
            index++;
        }
        return;
    }

    ListNode* List::find(string first, string last) {
        ListNode* cur = head;
        lowercase(first);
        lowercase(last);
        if (head == NULL)
            return head;
        while ( cur != NULL ) {
            lowercase(cur->first);
            lowercase(cur->last);
            if( (cur->first).compare(first) == 0 && (cur->last).compare(last) == 0 ){
                return cur;
            }
            cur = cur->next;
        }
        return NULL;
    }


    void List::lowercase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

