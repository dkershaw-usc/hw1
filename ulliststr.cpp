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
//#####################
//#####################

// Adds a new value to the back of the list
// O(1) req'd
void ULListStr::push_back(const std::string& val)
{
  // goal: find rearmost element+1, insert there
  // null protection
  if(empty())
  {
    head_ = tail_ = new Item();
  }

  // case 0: has room; just insert
  if(tail_->last < ARRSIZE)
  {
    tail_->val[tail_->last] = val;
  }
  // case 1: no room; allocate new, insert at front
  else
  {
    Item* temp = tail_;
    tail_ = new Item();
    tail_->prev = temp;
    temp->next = tail_;
    tail_->next = NULL;
    
    tail_->val[0] = val;
  }

  tail_->last++;
  // no matter what, update size
  size_++;
}

// Removes a value from the back of the list
// O(1) req'd
void ULListStr::pop_back()
{
  if(empty()) return;

  // goal: find rearmost element and trash it
  // case 0: last element in array
  if(tail_->last - tail_->first == 1)
  {
    if(size_ == 1)
    {
      delete head_;
      head_ = tail_ = NULL;
      size_ = 0;
      return;
    }

    Item* temp = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    delete temp;
  }
  // case 1: not last element
  else
  {
    tail_->val[tail_->last - 1] = "ERROR_DELETED_ELEMENT";
    tail_->last--;
  }
  
  // no matter what, update size
  size_--;
}

// Adds a new value to the front of the list.
// O(1) req'd
void ULListStr::push_front(const std::string& val)
{
  // goal: find frontmost element-1
  // null protection
  if(empty())
  {
    head_ = tail_ = new Item();
  }

  // case 0: has room. just insert
  if(head_->first != 0)
  {
    head_->first--;
    head_->val[head_->first] = val;
  }
  // case 1: no room; allocate new
  else
  {
    Item* temp = head_;
    head_ = new Item();
    temp->prev = head_;
    head_->prev = NULL;

    head_->val[0] = val;
    head_->last++;
  }

  // no matter what, update size
  size_++;
}

// Removes a value from the front of the list
// O(1) req'd
void ULListStr::pop_front()
{
  if(empty()) return;

  // goal: find frontmost element and trash it
  // case 0: entry is "last survivor" in Item
  if(head_->last - head_->first == 1)
  {
    if(size_ == 1)
    {
      delete head_;
      head_ = tail_ = NULL;
      size_ = 0;
      return;
    }

    Item* temp = head_;
    head_ = head_->next;
    head_->prev = NULL;
    delete temp;
  }
  // case 1: Item has >= 2 entries
  else
  {
    head_->val[head_->first] = "#EXPECTED_DELETE";
    head_->first++;
  }

  // no matter what, update the size
  size_--;
}

// Returns a const reference to the back element
// O(1) req'd
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

// Returns a const reference to the front element
// O(1) req'd
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

// Returns a pointer to the item at index, loc,
//  if loc is valid and NULL otherwise
// O(n) req'd
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc > size_) return NULL;
  if(loc < 0) return NULL;

  Item* item = head_;

  if(loc < ARRSIZE)
  {
    return &head_->val[item->first+loc];
  }

  while(loc > ARRSIZE)
  {
    loc -= (item->last - item->first);
    item = item->next;
  }
  return &item->val[loc-1];
}

//#####################
//#####################
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
