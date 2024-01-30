#include <cstddef>
#include <stdexcept>
// cmath used in getValAtLoc() implementation
#include <cmath>
#include "ulliststr.h"

#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// BEGIN: STUDENT CODE
//####################

// # Add and remove elements

// REQS: O(1) TIME
void ULListStr::push_back(const std::string& val)
{
  //Case 0: Tail doesn't exist!
  if(tail_ == NULL)
  {
    tail_ = new Item();
    if(head_ == NULL) head_ = tail_;
    tail_->val[tail_->last] = val;
  }
  //Case 1: Tail Item is full
  else if((tail_->last - tail_->first) >= ARRSIZE)
  {
    tail_->next = new Item();
    tail_ = tail_->next;
    tail_->val[0] = val;
  }
  //Case 2: Tail Item is not full
  else
  {
    tail_->val[tail_->last] = val;
    tail_->last++;
  }

  //no matter what, increment size
  this->size_++;
}

//REQS: O(1) TIME
void ULListStr::pop_front()
{
  //Case 1: Head Item is empty, or only has 1 element
  if(((int) head_->last - (int) head_->first) <= 1)
  {
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
  }
  //Case 2: Head Item has more than 1 element
  else 
  {
    head_->first += 1;
  }

  //no matter what, decrement size
  this->size_--;
}

//REQS: O(1) TIME
void ULListStr::push_front(const std::string& val)
{
  //Case 0: Head doesn't exist!
  if(head_ == NULL)
  {
    // this is uninitialized (or newly cleared). set head and tail.
    head_ = new Item();
    tail_ = head_;
    head_->val[0] = val;
  }
  //Case 1: Head Item is full
  else if(((int) head_->last - (int) head_->first) >= ARRSIZE)
  {
    head_->prev = new Item();
    head_ = head_->prev;
    head_->val[ARRSIZE-1] = val;
  }
  //Case 2: Head Item is not full
  else
  {
    head_->val[head_->first - 1] = val;
    head_->first--;
  }

  //no matter what, increment size
  this->size_++;
}

//REQS: O(1) TIME
void ULListStr::pop_back()
{
  //Case 1: Tail Item is empty, or only has 1 element
  if(((int) tail_->last - (int) tail_->first) <= 1)
  {
    Item* temp = tail_;
    tail_ = tail_->prev;
    delete temp;
  }
  //Case 2: Tail Item has more than 1 element
  else 
  {
    tail_->last -= 1;
  }

  //no matter what, decrement size
  this->size_--;
}

// # Query specific indices

//REQS: O(1) TIME
// * Returns a const reference to the back element
std::string const & ULListStr::back() const
{
  return this->tail_->val[(int) tail_->last];
}

//REQS: O(1) TIME
// * Returns a const reference to the front element
std::string const & ULListStr::front() const
{
  return this->head_->val[(int) head_->first];
}

//REQS: O(n) TIME
// * Returns a pointer to the item at index, loc,
// *  if loc is valid and NULL otherwise
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  //Case 1: loc outside of bounds
  if(loc > this->size_) return NULL;
  //Case 2: 
  else if(head_ == NULL || tail_ == NULL) return NULL;
  //Case 3: loc is a valid location
  else
  {
    int sum_checked = 0;
    Item* comparand = head_;
    // increment by size of each item traversed until within ARRSIZE of loc
    while(std::abs(sum_checked - (int) loc) > ARRSIZE)
    {
      sum_checked += ((int)comparand->last - (int)comparand->first);
      comparand = comparand->next;
    }

    int localIndex = (int) loc - sum_checked;
    return & comparand->val[localIndex];

  }

}

// END: STUDENT CODE
//####################

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
