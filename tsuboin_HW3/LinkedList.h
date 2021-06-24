//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT listPtr: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

/**
 *  I added comments to the functions that I wrote or modified, not the
 *  lecture code functions. - Narissa.
 */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include <string>

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node in the chain;
    // (contains the first entry in the listPtr)
    int itemCount;           // Current count of listPtr items

    // Locates a specified node in this linked listPtr.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<ItemType>* getNodeAt(int position) const;

public:
    LinkedList();

    // performs deep copy of existing list during initialization of new list
    // @pre none
    // @post the new list is a deep copy of the parameter list
    // @para otherList the list to be copied into a new list
    LinkedList(const LinkedList<ItemType>& otherList);

    // performs deep copy of existing list and returns it to another list
    // @pre two LinkedList objects
    // @post the first operand list a deep copy of the parameter list
    // @para otherList the list to be copied into a new list
    LinkedList<ItemType>& operator =(const LinkedList<ItemType>& otherList);

    virtual ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();

    /** @throw std::invalid_argument if position < 1 or
                                        position > getLength(). */
    ItemType getEntry(int position) const;

    /** @throw std::invalid_argument if position < 1 or
                                        position > getLength(). */
    ItemType replace(int position, const ItemType& newEntry);

    // returns true if entry is found in linked list
    // @pre given a linked list object
    // @post returns true if entry is found
    // @parameter value/object to search for
    bool contains (ItemType entry);

    // returns true if entry is found in linked list
    // @pre given a linked list object
    // @post returns true if entry is found
    // @parameter value/object to search for
    bool containsRecursive(ItemType entry);

    // helper function for containsRecursive
    // @pre is called by Contains or ContainsRecursive
    // @post returns true if value/object found
    // @para Node pointer and entry
    bool containsHelperR(Node<ItemType> *p, ItemType entry);

    // returns current itemCount
    // @pre none
    // @post returns number of nodes in the list
    int getItemCount();

    // reverses the elements of the linkedlist
    // @pre none
    // @post list is reversed
    void reverse();

    //return concatentation of all nodes as a string
    // @pre none
    // @post none
    std::string toString();

}; // end LinkedList

#include "LinkedList.cpp"
#endif
