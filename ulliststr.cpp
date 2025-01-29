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

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val){
    if (head_ == NULL){
      head_ = new Item();
      head_->val[0] = val;
      head_->first = 0;
      head_-> last = 1;
      tail_ = head_;
      size_++;
    } else if (tail_->last == ARRSIZE){
      Item* newTail = new Item();
      newTail->val[0] = val;
      newTail->first = 0;
      newTail->last = 1;
      tail_->next = newTail;
      newTail->prev = tail_;
      tail_ = newTail;
      size_++;
    } else {
      tail_->val[tail_->last] = val;
      tail_->last++;
      size_++;
    }
    }
  
  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
    if (size_ == 0){
      return;
    } else if (tail_->last == 1){
      Item* oldTail = tail_;
      tail_ = oldTail->prev;
      delete oldTail;
      size_--;
    } else {
      tail_->last--;
      size_--;
    }
    }

  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){
    if (head_ == NULL){
      head_ = new Item();
      head_->val[0] = val;
      head_->first = 0;
      head_-> last = 1;
      tail_ = head_;
      size_++;
    } else if (head_->first == 0){
      Item* newHead = new Item();
      newHead->val[ARRSIZE-1] = val;
      newHead->first = ARRSIZE-1;
      newHead->last = ARRSIZE;
      head_->prev = newHead;
      newHead->next = head_;
      head_ = newHead;
      size_++;
    } else {
      head_->first--;
      head_->val[head_->first] = val;
      size_++;
    }
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if (size_ == 0){
      return;
    } else if (head_->first == head_->last-1){
      Item* oldHead = head_;
      head_ = oldHead->next;
      delete oldHead;
      size_--;
    } else {
      head_->first++;
      size_--;
    }
  }

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const{
    if (loc >= size_ || size_ == 0 || loc < 0){
      return NULL;
    }
    Item* current = head_;
    while (loc >= ARRSIZE){
      loc -= ARRSIZE;
      current = current->next;
    }
    return &(current->val[current->first + loc]);
  }
  
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{
    return tail_->val[tail_->last-1];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
    return head_->val[head_->first];
  }


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