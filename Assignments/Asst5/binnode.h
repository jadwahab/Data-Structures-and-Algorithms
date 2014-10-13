#pragma once

// Binary tree node abstract class
template <class Elem> 
class BinNode
{
public:
  // Return the node's element
  virtual Elem& val() = 0;
  // Set the node's element
  virtual void setVal(const Elem&) = 0;
  // Return the node's left child
  virtual BinNode* left() const = 0;
  // Set the node's left child
  virtual void setLeft(BinNode*) = 0;
  // Return the node's right child
  virtual BinNode* right() const = 0;
  // Set the node's right child
  virtual void setRight(BinNode*) = 0;
  // Return true iff the node is a leaf
  virtual bool isLeaf() = 0;
};

// Binary tree node class
template <class Elem>
class BinNodePtr : public BinNode<Elem>
{
private:
  Elem it;                     // The node's value
  BinNodePtr* lc;              // Pointer to left child
  BinNodePtr* rc;              // Pointer to right child
public:
  // Two constructors -- with and without initial values
  BinNodePtr() { lc = rc = NULL; }
  BinNodePtr(Elem e, BinNodePtr* l =NULL,
                     BinNodePtr* r =NULL)
    { it = e; lc = l; rc = r; }
  ~BinNodePtr() {}             // Destructor
  Elem& val() { return it; }
  void setVal(const Elem& e) { it = e; }
  inline BinNode<Elem>* left() const { return lc; }
  void setLeft(BinNode<Elem>* b) { lc = (BinNodePtr*)b; } //conversion must be explicit
  inline BinNode<Elem>* right() const { return rc; }
  void setRight(BinNode<Elem>* b) { rc = (BinNodePtr*)b; }
  bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};


