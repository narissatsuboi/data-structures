//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Interface for the ADT listPtr
    Listing 8-1
    @file ListInterface.h */

#ifndef LIST_INTERFACE_
#define LIST_INTERFACE_

template<class ItemType>
class ListInterface
{
public:
    /** Sees whether this listPtr is empty.
     @return  True if the listPtr is empty; otherwise returns false. */
    virtual bool isEmpty() const = 0;

    /** Gets the current number of entries in this listPtr.
     @return  The integer number of entries currently in the listPtr. */
    virtual int getLength() const = 0;

    /** Inserts an entry into this listPtr at a given position.
     @pre  None.
     @post  If 1 <= position <= getLength() + 1 and the insertion is
        successful, newEntry is at the given position in the listPtr,
        other entries are renumbered accordingly, and the returned
        value is true.
     @param newPosition  The listPtr position at which to insert newEntry.
     @param newEntry  The entry to insert into the listPtr.
     @return  True if the insertion is successful, or false if not. */
    virtual bool insert(int newPosition, const ItemType& newEntry) = 0;

    /** Removes the entry at a given position from this listPtr.
     @pre  None.
     @post  If 1 <= position <= getLength() and the removal is successful,
        the entry at the given position in the listPtr is removed, other
        items are renumbered accordingly, and the returned value is true.
     @param position  The listPtr position of the entry to remove.
     @return  True if the removal is successful, or false if not. */
    virtual bool remove(int position) = 0;

    /** Removes all entries from this listPtr.
     @post  The listPtr contains no entries and the count of items is 0. */
    virtual void clear() = 0;

    /** Gets the entry at the given position in this listPtr.
     @pre  1 <= position <= getLength().
     @post  The desired entry has been returned.
     @param position  The listPtr position of the desired entry.
     @return  The entry at the given position. */
    virtual ItemType getEntry(int position) const = 0;

    /** Replaces the entry at the given position in this listPtr.
     @pre  1 <= position <= getLength().
     @post  The entry at the given position is newEntry.
     @param position  The listPtr position of the entry to replace.
     @param newEntry  The replacement entry.
     @return  The replaced entry. */
    virtual ItemType replace(int position, const ItemType& newEntry) = 0;

    /** Destroys this listPtr and frees its assigned memory. */
    virtual ~ListInterface() { }
}; // end ListInterface
#endif