#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

const int MAX_ITEMS = 5;

template <class T>
class UnsortedList
{
public:
  UnsortedList();
  // Constructor
  
  void MakeEmpty();
  // Function: Returns the list to the empty state.
  // Post:  List is empty.
  
  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int GetLength() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  bool Contains(T someItem);
  // Function: Determines if someItem is in the list.
  // Pre:  List has been initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then the function returns true.
  // 	     otherwise it will return false. List is unchanged.

  void AddItem(T item);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  // Post: item is in list.

  void DeleteItem(T item);
  // Function: Deletes the first element whose key matches item's key.
  // Pre:  List has been initialized.
  // Post: First instance of item is removed. The array remains unchanged
  //       if the item does not exist in the array.

  void ResetIterator();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  T GetNextItem();
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

private:
  int length;
  T arr[MAX_ITEMS];
  //int *arr;  // arr represents an array of ints
  int currentPos; // used for iterator
};


template <class T>
UnsortedList<T>::UnsortedList() {
  length = 0;
  currentPos = 0;
}

template <class T>
void UnsortedList<T>::MakeEmpty() {
  length = 0;
}

template <class T>
bool UnsortedList<T>::IsFull() const {
  // bad way of doing this
  // if (length >= MAX_ITEMS) {
  //     return true;
  // } else {
  //     return false;
  // }
  return length >= MAX_ITEMS;
}

template <class T>
int UnsortedList<T>::GetLength() const {
  return length;
}

template <class T> // lets the compiler know that the function is a template function
bool UnsortedList<T>::Contains(T someItem) {
  for (int i = 0; i < length; i++) {
    if (arr[i] == someItem) {
      return true;
    }
  }
  return false;
}

template <class T>
void UnsortedList<T>::AddItem(T item) {
  arr[length] = item;
  length++;
}

template <class T>
void UnsortedList<T>::DeleteItem(T item) {
  // Find item in arr...
  for (int i = 0; i < length; i++) {
    if (arr[i] == item) {
      // swap with last elem in array
      arr[i] = arr[length - 1];
      length--;
      return;
    }
  }
}

template <class T>
void UnsortedList<T>::ResetIterator() {
  currentPos = 0;
}

template <class T>
T UnsortedList<T>::GetNextItem() {
  // int currVal = arr[currentPos];
  // currentPos++;
  // return currVal;
  return arr[currentPos++];
}


// #include "UnsortedList.cpp"

#endif
