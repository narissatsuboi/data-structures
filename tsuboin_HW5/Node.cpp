// Narissa Tsuboi
// Node.cpp
// Purpose: Implementation for Node described in Node.h

#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
    // default constructor
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
    // overloaded constructor w/ next set to nullptr
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
        item(anItem), next(nextNodePtr)
{
    // overloaded constructor w/ next pointing to nextNode
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    // mutator that changes the data held in anItem
    item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    // mutator that changes the nextNode the current
    // Node is pointing to
    next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
    // accessor that returns the data stored in item
    return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    // access that returns the address of the next
    // Node
    return next;
}