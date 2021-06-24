// Narissa Tsuboi
// LinkedList.h
// Specification file for the LinkedList class abstract data structure used
// to create, modify, and return information about the list. The LinkedList
// data structure is often used as the physical structure of a larger
// logical data structure.

#ifndef HW5_LINKEDLIST_H
#define HW5_LINKEDLIST_H

#include "ListInterface.h"
#include "Node.h"
#include <string>
#include <assert.h>
#include <stdexcept>

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Ptr to the first node in the chain.
    int itemCount; // Current number of elements in the chain.

    Node<ItemType>* getNodeAt(int position) const;
    // locates a specified node in this linked listPtr
    // pre: position is the number of the desired node
    //      position >= 1 and position <= itemCount
    // post:  The node is found and a pointer to it is returned

public:
    LinkedList();
    // default  constructor

    virtual ~LinkedList();
    // virtual destructor

    bool isEmpty() const;
    // determines if the LinkedList has no nodes
    // pre: given an existing LinkedList
    // post: returns true of the LinkedList has no nodes

    int getLength() const;
    // determines the number of nodes in the LinkedList
    // pre: given an existing LinkedList
    // post: returns the number of nodes in the list

    /** @throw std::invalid_argument if position < 1 or
                                    position > getLength(). */
    ItemType getEntry(int position) const;
    // retrieves the data stored in a node at a given position
    // pre: given a position > than 1 or <= getLength()
    // post: returns the data of ItemType from the node

    bool insert(int newPosition, const ItemType& newEntry);
    // inserts a new node with data at a given position
    // pre: given a position and data
    // post: an additional node is added to the LinkedList

    bool remove(int position);
    // deletes a node at the given position
    // pre: given a position to delete
    // post: number of nodes in LinkedList is decreased by 1

    void clear();
    // deletes all the nodes in the LinkedList
    // pre: none
    // post: LinkedList is empty

    std::string toString();
    // returns LinkedList in string form

    /** @throw std::invalid_argument if position < 1 or
                                    position > getLength(). */
    ItemType replace(int position, const ItemType& newEntry);
    // replaces a node at the given position with a node
    // containing the given data

};

#include "LinkedList.cpp"
#endif //HW5_LINKEDLIST_H
