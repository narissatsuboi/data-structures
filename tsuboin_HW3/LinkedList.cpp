/**String class implementation
 * @file String.cpp
 * @author Narissa T
 */
#include "LinkedList.h"
#include <stdexcept>
#include <iostream>
#include <assert.h>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& otherList)
 {
    itemCount = otherList.itemCount;
    if(otherList.isEmpty())
        LinkedList<ItemType>(); //call def. const for empty list
    else
    {
        // copy first node
        Node<ItemType>* temp = new Node<ItemType>(otherList.getEntry(1));
        headPtr = temp;

        // copy middle to end nodes
        for (int i = 1; i < otherList.getLength(); i++)
        {
            temp->setNext(new Node<ItemType>(otherList.getEntry(i + 1)));
            temp = temp->getNext();
        }
        temp = nullptr;
        delete temp;
        temp = nullptr;
    } //end if-else
} //end deep copy constructor

template<class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const
        LinkedList<ItemType>& otherList)
{
    if (this != &otherList)
    {
        this->clear();
        itemCount = otherList.itemCount;
        if(otherList.isEmpty())
             *this = LinkedList<ItemType>(); //call def. const for empty list
        else
        {
            // copy first node
            Node<ItemType>* temp = otherList.headPtr;
            temp = new Node<ItemType>(otherList.getEntry(1));
            headPtr = temp;

            // copy middle to end nodes
            for (int i = 1; i < otherList.getLength(); i++)
            {
                temp->setNext(new Node<ItemType>(otherList.getEntry(i + 1)));
                temp = temp->getNext();
            }
            delete temp;
            temp = nullptr;
        } //end if-else
    }
    return *this; // returns a reference to itself
} // end operator=

template<class ItemType>
LinkedList<ItemType>:: ~LinkedList()
{
    clear();
} // end destructor

template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
} // end clear

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}  // end getLength

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getItem() called with an empty listPtr or ";
        message = message + "invalid position.";
        throw(std::invalid_argument(message));
    } // end if
} // end getItem

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    // Debugging check of precondition
    assert( (position >= 1) && (position <= itemCount) );

    // Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}  // end getNodeAt

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        // Attach new node to chain
        if (newPosition == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);

        } // end if

        itemCount++; // Increase count of entries
    }  // end if

    return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType>* curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to remove
            Node<ItemType>* prevPtr = getNodeAt(position - 1);

            // Point to node to remove
            curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        } // end if

        // Return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--; // Decrease count of entries
    } // end if

    return ableToRemove;
} // end remove

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) {
    {
        std::cout << "replacing at position " << position << " with " + newEntry
                  << std::endl;

        bool ableToReplace = (position >= 1) && (position <= itemCount);
        if (ableToReplace) {
            //If its the first node, just set the entry at the headptr.
            if (position == 1) {
                headPtr->setItem(newEntry);
            } else {
                //Traverse to find the node
                Node<ItemType> *curPtr = getNodeAt(position);
                curPtr->setItem(newEntry);
                curPtr->setNext(nullptr);
                delete curPtr;
            }
        }
        return getEntry(3);
    }  // end replace
}

// TODO: LinkedList<ItemType>>::contains
template<class ItemType>
bool LinkedList<ItemType>::contains (ItemType entry)
{
    Node<ItemType>* curr = headPtr;
    while (curr != nullptr)
    {
        if (entry == curr->getItem())
            return true;
        else
            curr = curr->getNext();
    }
    curr = headPtr;
    return false;
}

// TODO: LinkedList<ItemType>>::containsRecursive
template<class ItemType>
bool LinkedList<ItemType>::containsRecursive(ItemType entry)
{
    Node<ItemType>* curr = headPtr;
        if (curr == NULL)
            return false;
        else if (entry == curr->getItem())
            return true;
        else {
            return containsHelperR(curr, entry);
        }
    delete curr;
    curr = nullptr;
    return false;
}

template<class ItemType>
bool LinkedList<ItemType>::containsHelperR(Node<ItemType> *p, ItemType entry)
{
    if (p == NULL)
        return false;
    if (p->getItem() == entry)
        return true;
    else
    {
        p = p->getNext();
        return containsHelperR(p, entry);
    }
}

template<class ItemType>
int LinkedList<ItemType>::getItemCount() {
    return itemCount;
}

template<class ItemType>
void LinkedList<ItemType>::reverse() {
    Node<ItemType>* p;
    Node<ItemType>* q;
    Node<ItemType>* r;

    p = headPtr;
    q = nullptr;
    r = nullptr;
    while (p != nullptr)
    {
        r = q;
        q = p;
        p = p->getNext();
        q->setNext(r);
    }
    headPtr = q;
}

template<class ItemType>
std::string LinkedList<ItemType>::toString() {
    std::string str = "";
    int listLength = getLength();
    for (int pos = 1; pos <= listLength; pos++)
        str += getEntry(pos);
    return str;
} // end toString()


