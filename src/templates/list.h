/*
	*** Object list class
	*** src/templates/list.h
	Copyright T. Youngs 2010-2011

	This file is part of AtenCalc.

	AtenCalc is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AtenCalc is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AtenCalc.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ATENCALC_LIST_H
#define ATENCALC_LIST_H

#include <stdlib.h>
#include <stdio.h>

/*
// Template object for types not including prev/next pointers (e.g. PODs)
*/
template <class T> class ListItem
{
	public:
	// Constructor
	ListItem<T>();
	// List pointers
	ListItem<T> *prev, *next;

	private:
	// Data object
	T data_;

	public:
	// Set data object
	void setValue(T value);
	// Return data object
	T value();
};

// Constructor
template <class T> ListItem<T>::ListItem()
{
	prev = NULL;
	next = NULL;
}

// Set data object
template <class T> void ListItem<T>::setValue(T value)
{
	data_ = value;
}

// Set data object
template <class T> T ListItem<T>::value()
{
	return data_;
}

/*
// List structure for user-generated classes (containing prev/next pointers)
*/
template <class T> class List
{
	public:
	// Constructor / Destructor
	List<T>();
	~List();

	/*
	// Item List
	*/
	private:
	// Pointers to head and tail of list
	T *listHead_, *listTail_;
	// Number of items in list
	int nItems_;
	// Static array of items
	T **items_;
	// Array regeneration flag
	bool regenerate_;


	public:
	// Returns the number of items in the list
	int nItems() const;
	// Returns the list head
	T *first() const;
	// Returns the list tail
	T *last() const;
	// Append an item to the list
	T *add();
	// Insert an item into the list (after supplied item)
	T *insert(T* before);
	// Add the item into this list
	void own(T*);
	// Disown the item, but do not delete it
	void disown(T*);
	// Remove an item from the list
	void remove(T*);
	// Remove last item from the list
	void removeLast();
	// Return whether the item is owned by the list
	bool contains(T*);
	// Remove an item from the list, and return the next in the list
	T* removeAndGetNext(T*);
	// Bridge items either side of the specified item
	void cut(T*);
	// Fills the supplied array with pointer values to the list items
	void fillArray(int, T**);
	// Clear the list
	void clear();
	// Create empty list of size N
	void createEmpty(int);
	// Find list index of supplied item
	int indexOf(T*) const;
	// Return item at given position
	T *itemAt(int n);
	// Generate (if necessary) and return item array
	T **array();


	/*
	// Operators
	*/
	public:
	// Assignment operator
	void operator=(List<T> &source);
	// Element access operator
	T *operator[](int);

	/*
	// Item Moves
	*/
	private:
	// Swap two items in list
	void swapItems(T*, T*);

	public:
	// Shift item up (towards head)
	void shiftUp(T*);
	// Shift item down (towards tail)
	void shiftDown(T*);
	// Move item at position 'old' by 'delta' positions (+/-)
	void move(int target, int delta);
	// Move item to end of list
	void moveToEnd(T*);
	// Move item to start of list
	void moveToStart(T*);
};

// Constructors
template <class T> List<T>::List()
{
	listHead_ = NULL;
	listTail_ = NULL;
	nItems_ = 0;
	regenerate_ = 1;
	items_ = NULL;
}

// Destructor
template <class T> List<T>::~List()
{
	clear();
}

// Returns the number of items in the list
template <class T> int List<T>::nItems() const
{
	return nItems_;
}

// Returns the list head
template <class T> T *List<T>::first() const
{
	return listHead_;
}

// Returns the list tail
template <class T> T *List<T>::last() const
{
	return listTail_;
}

// Add item to list
template <class T> T* List<T>::add()
{
	T *newitem = new T;
	// Add the pointer to the list
	listHead_ == NULL ? listHead_ = newitem : listTail_->next = newitem;
	newitem->prev = listTail_;
	listTail_ = newitem;
	nItems_ ++;
	regenerate_ = 1;
	return newitem;
}

// Insert new item after supplied item
template <class T> T *List<T>::insert(T* newprev)
{
	T *newitem = new T;
	// Get pointer to next item after newprev (our newnext)
	T *newnext = (newprev == NULL ? listHead_ : newprev->next);
	// Re-point newprev and the new item
	if (newprev != NULL) newprev->next = newitem;
	else listHead_ = newitem;
	newitem->prev = newprev;
	// Re-point newnext and the new item
	if (newnext != NULL) newnext->prev = newitem;
	else listTail_ = newitem;
	newitem->next = newnext;
	nItems_ ++;
	regenerate_ = 1;
	return newitem;
}

// Own an existing item
template <class T> void List<T>::own(T* olditem)
{
	// In the interests of 'pointer cleanliness, refuse to own the item if its pointers are not NULL
	if ((olditem->next != NULL) || (olditem->prev != NULL))
	{
		printf("list::own <<<< List refused to own an item that still had ties >>>>\n");
		return;
	}
	listHead_ == NULL ? listHead_ = olditem : listTail_->next = olditem;
	olditem->prev = listTail_;
	olditem->next = NULL;
	listTail_ = olditem;
	nItems_ ++;
	regenerate_ = 1;
}

// Disown the item, but do not delete it
template <class T> void List<T>::disown(T* xitem)
{
	xitem->prev == NULL ? listHead_ = (T*) xitem->next : xitem->prev->next = (T*) xitem->next;
	xitem->next == NULL ? listTail_ = (T*) xitem->prev : xitem->next->prev = (T*) xitem->prev;
	xitem->next = NULL;
	xitem->prev = NULL;
	--nItems_;
	regenerate_ = 1;
}

// Remove the specified item from the list
template <class T> void List<T>::remove(T *xitem)
{
	// Delete a specific item from the list
	xitem->prev == NULL ? listHead_ = (T*) xitem->next : xitem->prev->next = (T*) xitem->next;
	xitem->next == NULL ? listTail_ = (T*) xitem->prev : xitem->next->prev = (T*) xitem->prev;
	delete xitem;
	--nItems_;
	regenerate_ = 1;
}

// Remove last item from the list
template <class T> void List<T>::removeLast()
{
	// Delete a specific item from the list
	T *xitem = listTail_;
	xitem->prev == NULL ? listHead_ = (T*) xitem->next : xitem->prev->next = (T*) xitem->next;
	listTail_ = (T*) xitem->prev;
	delete xitem;
	--nItems_;
	regenerate_ = 1;
}

// Return whether the item is owned by the list
template <class T> bool List<T>::contains(T *searchitem)
{
	T *item;
	for (item = listHead_; item != NULL; item = item->next) if (searchitem == item) break;
	return (item != NULL);
}

// Remove the specified item from the list, returning the next
template <class T> T* List<T>::removeAndGetNext(T *xitem)
{
	// Delete a specific item from the list, and return the next in the list
	T* result = xitem->next;
	xitem->prev == NULL ? listHead_ = (T*) xitem->next : xitem->prev->next = (T*) xitem->next;
	xitem->next == NULL ? listTail_ = (T*) xitem->prev : xitem->next->prev = (T*) xitem->prev;
	delete xitem;
	--nItems_;
	regenerate_ = 1;
	return result;
}

// Cut - Bridge items over specified item
template <class T> void List<T>::cut(T *item)
{
	T *prev, *next;
	prev = item->prev;
	next = item->next;
	if (prev == NULL) listHead_ = next;
	else prev->next = next;
	if (next == NULL) listTail_ = prev;
	else next->prev = prev;
	item->next = NULL;
	item->prev = NULL;
	regenerate_ = 1;
}

// Fill array
template <class T> void List<T>::fillArray(int n, T **data)
{
	int count = 0;
	T *i = listHead_;
	while (i != NULL)
	{
		data[count] = i->item;
		++count;
		if (count == n) break;
		i = i->next;
		if (i == NULL) printf("list::fill_array <<<< Not enough items in list - requested %i, had %i >>>>\n",n,nItems_);
	}
}

// Remove all items in the list
template <class T> void List<T>::clear()
{
	T *xitem = listHead_;
	while (xitem != NULL)
	{
		remove(xitem);
		xitem = listHead_;
	}
	// Delete static items array if its there
	if (items_ != NULL) delete[] items_;
	items_ = NULL;
	regenerate_ = 1;
}

// Find index of supplied item
template <class T> int List<T>::indexOf(T* item) const
{
	int result = 0;
	for (T* i = listHead_; i != NULL; i = i->next)
	{
		if (item == i) break;
		result ++;
	}
	if (result == nItems_)
	{
		printf("list::index_of <<<< Supplied item is not in this list >>>>.\n");
		result = -1;
	}
	return result;
}

// Return item at given position
template <class T> T *List<T>::itemAt(int n)
{
	return array()[n];
}

// Create empty list
template <class T> void List<T>::createEmpty(int newsize)
{
	clear();
	for (int n=0; n<newsize; n++) add();
	regenerate_ = 1;
}

// Create (or just return) the item array
template <class T> T **List<T>::array()
{
	if (regenerate_ == 0) return items_;
	// Delete old atom list (if there is one)
	if (items_ != NULL) delete[] items_;
	// Create new list
	items_ = new T*[nItems_];
	// Fill in pointers
	int count = 0;
	for (T *i = listHead_; i != NULL; i = i->next) items_[count++] = i;
	regenerate_ = 0;
	return items_;
}

/*
// Item Moves
*/

// Swap items
template <class T> void List<T>::swapItems(T* item1, T* item2)
{
	// If the items are adjacent, swap the pointers 'outside' the pair and swap the next/prev between them
	T *n1, *n2, *p1, *p2;
	if ((item1->next == item2) || (item2->next == item1))
	{
		// Order the pointers so that item1->next == item2
		if (item2->next == item1)
		{
			n1 = item2;
			item2 = item1;
			item1 = n1;
		}
		p1 = item1->prev; 
		n2 = item2->next;
		item2->prev = p1;
		item2->next = item1;
		if (p1 != NULL) p1->next = item2;
		else listHead_ = item2;
		item1->prev = item2;
		item1->next = n2;
		if (n2 != NULL) n2->prev = item1;
		else listTail_ = item1;
	}
	else
	{
		// Store the list pointers of the two items
		//printf("Item 1 %p next %p prev %p\n",item1,item1->next,item1->prev);
		//printf("Item 2 %p next %p prev %p\n",item2,item2->next,item2->prev);
		//printf("Item 1 nextprev %p prevnext %p\n",item1->next->prev,item1->prev->next);
		//printf("Item 2 nextprev %p prevnext %p\n",item2->next->prev,item2->prev->next);
		n1 = item1->next;
		p1 = item1->prev;
		n2 = item2->next;
		p2 = item2->prev;
		// Set new values of swapped items
		item1->next = n2;
		item1->prev = p2;
		item2->next = n1;
		item2->prev = p1;
		//printf("Item 1 next %p prev %p\n",item1->next,item1->prev);
		//printf("Item 2 next %p prev %p\n",item2->next,item2->prev);
		// Set new values of items around swapped items
		if (item1->next != NULL) item1->next->prev = item1;
		else listTail_ = item1;
		if (item1->prev != NULL) item1->prev->next = item1;
		else listHead_ = item1;
		if (item2->next != NULL) item2->next->prev = item2;
		else listTail_ = item2;
		if (item2->prev != NULL) item2->prev->next = item2;
		else listHead_ = item2;
		//printf("Item 1 nextprev %p prevnext %p\n",item1->next->prev,item1->prev->next);
		//printf("Item 2 nextprev %p prevnext %p\n",item2->next->prev,item2->prev->next);
	}
	regenerate_ = 1;
}

// Shift item towards head
template <class T> void List<T>::shiftUp(T* item)
{
	// If the item is already at the head of the list, return NULL.
	if (listHead_ == item) return;
	swapItems(item->prev,item);
	regenerate_ = 1;
}

// Shift item towards tail
template <class T> void List<T>::shiftDown(T* item)
{
	// If the item is already at the tail of the list, return.
	if (listTail_ == item) return;
	swapItems(item->next,item);
	regenerate_ = 1;
}

// Move item to end
template <class T> void List<T>::moveToEnd(T* item)
{
	// If the item is already at the tail, exit
	if (listTail_ == item) return;
	cut(item);
	item->prev = listTail_;
	item->next = NULL;
	if (listTail_ != NULL) listTail_->next = item;
	listTail_ = item;
	regenerate_ = 1;
}

// Move item to start
template <class T> void List<T>::moveToStart(T* item)
{
	// If the item is already at the head, exit
	if (listHead_ == item) return;
	cut(item);
	item->prev = NULL;
	item->next = listHead_;
	if (listHead_ != NULL) listHead_->prev = item;
	listHead_ = item;
	regenerate_ = 1;
}

// Move item at position 'target' the specified number of places up (+ve) or down (-ve)
template <class T> void List<T>::move(int target, int delta)
{
	// Check positions
	if ((target < 0) || (target >= nItems_))
	{
		printf("list::move <<<< Old position (%i) is out of range of list (0 - %i) >>>>\n",target,nItems_);
		return;
	}
	int newpos = target + delta;
	if ((newpos < 0) || (newpos >= nItems_))
	{
		printf("list::move <<<< New position (%i) is out of range of list (0 - %i) >>>>\n",newpos,nItems_);
		return;
	}
	// Get pointer to item that we're moving and shift it
	T *olditem = array()[target];
	for (int n=0; n<abs(delta); n++) (delta < 0 ? shiftUp(olditem) : shiftDown(olditem));
	// Flag for regeneration
	regenerate_ = 1;
}

/*
// Operators
*/

// Assignment operator =
template <class T> void List<T>::operator=(List<T> &source)
{
	// Clear any current data in the list...
	clear();
	T *newitem, *olditem;
	for (olditem = source.first(); olditem != NULL; olditem = olditem->next)
	{
		// To ensure that we don't mess around with the pointers of the old list, copy the object and then own it
		newitem = new T;
		*newitem = *olditem;
		newitem->prev = NULL;
		newitem->next = NULL;
		own(newitem);
	}
	// Don't deep-copy the static list, just flag that it must be regenerated if required.
	regenerate_ = 1;
}

// Element access operator
template <class T> T *List<T>::operator[](int index)
{
	if ((index < 0) || (index >= nItems_))
	{
		printf("list::[] <<<< SEVERE - Array index (%i) out of bounds (0-%i) >>>>\n",index,nItems_-1);
		return NULL;
	}
	return array()[index];
}

#endif
