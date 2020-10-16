#include "list.h"
ostream& operator<<(ostream& os, IntList& il)
{
   Node *ptr = il.first;
   while (ptr != 0) {
      os << ptr->data << " "; ptr = ptr->link; }
   os << endl;
   return os;
}

void IntList::InsertBack(int e)
{
   if (!first)
      first = last = new Node(e);
   else {
      last->link = new Node(e);
      last = last->link;
   }
}
void IntList::InsertFront(int e) { 
    if(!first)
    first = last = new Node(e);
    else {
        Node *tmp = new Node(e);
        tmp->link = first;
        first = tmp;
    }
 }
void IntList::Insert(int e) {
    Node* prev, *cur;
    prev = cur = first;
    if(e<cur->data)
    InsertFront(e);
    else {
        while(e>cur->data){
            prev = cur;
            cur = cur->link;
            if(cur == last && e!=cur->data){
                InsertBack(e);
                return ;
            }
        }
        if(e!=cur->data){
            Node *tmp = new Node(e);
            tmp->link = prev->link;
            prev->link = tmp;
        }
    }
 }
void IntList::Delete(int e) { 
    Node* prev, *cur;
    prev = cur = first;
    if(e == cur->data){
        first = first->link;
    }
    else{
        while(e!=cur->data){
            prev = cur;
            cur = cur->link;
        }
        prev->link = cur->link;
    }  
 }
