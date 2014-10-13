// This is the file to include in your code if you want access to the
// complete LList template class

#pragma once
#include <iostream>
using namespace std;

// First, get the declaration for the base list class
#include "List.h"

// Singly-linked list node
template <class Elem>
class Link
{
public:
    Elem element;      // Value for this node
    Link *next;        // Pointer to next node in list
    
    Link( const Elem& elemval , Link* nextval= NULL ) // 1st Constructor
    { element= elemval ;  next= nextval; }
    
    Link( Link* nextval= NULL ) // 2nd Constructor
    { next= nextval; }
};

// Linked list implementation
template <class Elem> class LList: public List<Elem> {
private:
  Link<Elem>* head;       // Pointer to list header
  Link<Elem>* tail;       // Pointer to last Elem in list 
  Link<Elem>* fence;      // Last element on left side
  int leftcnt;            // Size of left partition
  int rightcnt;           // Size of right partition
  void init() {           // Intialization routine
    fence = tail = head = new Link<Elem>;
    leftcnt = rightcnt = 0;
  }
  void removeall() {   // Return link nodes to free store
    while(head != NULL) {
      fence = head;
      head = head->next;
      delete fence;
    }
  }
public:
  LList(int size=DefaultListSize) { init(); }
  ~LList() { removeall(); }  // Destructor
  void clear() { removeall(); init(); }
  bool insert(const Elem&);
  bool append(const Elem&);
  bool remove(Elem&);
  void setStart()
    { fence = head; rightcnt += leftcnt; leftcnt = 0; }
  void setEnd()
    { fence = tail; leftcnt += rightcnt; rightcnt = 0; }
  void prev();
  void next() {
    if (fence != tail) // Don't move fence if right empty
      { fence = fence->next; rightcnt--; leftcnt++; }
  }
  int leftLength() const  { return leftcnt; }
  int rightLength() const { return rightcnt; }
  bool setPos(int pos);
  bool getValue(Elem& it) const {
    if(rightLength() == 0) return false;
    it = fence->next->element;
    return true;
  }
  void print() const;
};

template <class Elem> // Insert at front of right partition
bool LList<Elem>::insert(const Elem& item) {
  fence->next = new Link<Elem>(item, fence->next);  
  if (tail == fence) tail = fence->next;  // New tail
  rightcnt++;
  return true;
}

template <class Elem> // Append Elem to end of the list
bool LList<Elem>::append(const Elem& item) {
  tail = tail->next = new Link<Elem>(item, NULL);
  rightcnt++;
  return true;
}

// Remove and return first Elem in right partition
template <class Elem> bool LList<Elem>::remove(Elem& it) {
  if (fence->next == NULL) return false; // Empty right
  it = fence->next->element;       // Remember value
  Link<Elem>* ltemp = fence->next; // Remember link node
  fence->next = ltemp->next;       // Remove from list
  if (tail == ltemp) tail = fence; // Reset tail
  delete ltemp;                    // Reclaim space
  rightcnt--;
  return true;
}

// Move fence one step left; no change if left is empty
template <class Elem> void LList<Elem>::prev() {
  Link<Elem>* temp = head;
  if (fence == head) return; // No previous Elem
  while (temp->next!=fence) temp=temp->next;
  fence = temp;
  leftcnt--; rightcnt++;
}

// Set the size of left partition to pos
template <class Elem> bool LList<Elem>::setPos(int pos) {
  if ((pos < 0) || (pos > rightcnt+leftcnt)) return false;
  fence = head;
  for(int i=0; i<pos; i++) fence = fence->next;
  return true;
}

template <class Elem> void LList<Elem>::print() const {
  Link<Elem>* temp = head;
  cout << "< ";
  while (temp != fence) {
    cout << temp->next->element << " ";
    temp = temp->next;
  }
  cout << "| ";
  while (temp->next != NULL) {
    cout << temp->next->element << " ";
    temp = temp->next;
  }
  cout << ">\n";
}
