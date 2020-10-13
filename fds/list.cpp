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
    Node *tmp = first;
    if(e<first->data)
    InsertFront(e);
    else if(e>first->data){
        while(e>tmp->link->data){
            tmp = tmp->link;
            if(tmp==last){
                InsertBack(e);
                return ;
            }
        }
        if(e!=tmp->link->data){
            Node *nod = new Node(e);
            nod->link = tmp->link;
            tmp->link = nod;
        }      
    }
 }
void IntList::Delete(int e) { 
    Node *tmp = first;
    if(e==first->data){
        first = first->link;
    }
    else{
        while(e!=tmp->link->data){
            if(tmp->link==last){
                last=tmp;
                return ;
            }
            tmp=tmp->link;
        }
        tmp->link=tmp->link->link;
    }
 }