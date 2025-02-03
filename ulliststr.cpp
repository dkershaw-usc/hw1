#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

// WRITE YOUR CODE HERE
//#####################

// Adds a new value to the back of the list
// O(1) req'd
void ULListStr::push_back(const std::string& val)
{
  // find rearmost element+1
  // case 0: has room. just insert
  // case 1: no room. allocate new, insert at front
}

// Removes a value from the back of the list
// O(1) req'd
void ULListStr::pop_back()
{
  // find rearmost element
  // trash it
}

// Adds a new value to the front of the list.
// O(1) req'd
void ULListStr::push_front(const std::string& val)
{
  // find frontmost element-1
  // case 0: has room. just insert
  // case 1: no room. allocate new, insert at back
}

// Removes a value from the front of the list
// O(1) req'd
void ULListStr::pop_front()
{

}

// Returns a const reference to the back element
// O(1) req'd
std::string const & ULListStr::back() const
{

}

// Returns a const reference to the front element
// O(1) req'd
std::string const & ULListStr::front() const
{

}

// Returns a pointer to the item at index, loc,
//  if loc is valid and NULL otherwise
// O(n) req'd
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  
}

//#####################

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
