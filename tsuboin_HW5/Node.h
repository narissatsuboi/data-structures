// Narissa Tsuboi
// Node.h
// Specification file for the Node class used to store data in a LinkedList.

#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
    ItemType        item; // A data item
    Node<ItemType>* next; // Pointer to next node

public:
    Node();

    Node(const ItemType& anItem);
    // overloaded constructor w/ next set to nullptr

    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    // overloaded constructor w/ next pointing to nextNode

    void setItem(const ItemType& anItem);
    // mutator that changes the data held in anItem

    void setNext(Node<ItemType>* nextNodePtr);
    // mutator that changes the nextNode the current
    // Node is pointing to

    ItemType getItem() const ;
    // accessor that returns the data stored in item

    Node<ItemType>* getNext() const ;
    // access that returns the address of the next
    // Node

};
#include "Node.cpp"
#endif