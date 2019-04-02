// -*- C++ -*-

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>
#include "Array.h"

/**
 * @class Queue
 *
 * Basic Queue for arbitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
  class empty_exception : public std::runtime_error
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::runtime_error () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::runtime_error (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & q);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Insert a new \a element into the end of the queue. The element is inserted
   * after all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Remove the first element from the queue.
   *
   * @exception      empty_exception    The queue is empty.
   * @retval         dequeued element
   */
  T dequeue (void);

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the queue.
   *
   * @return         Size of the queue.
   */
  size_t size (void) const;

  /// Remove all elements from the queue.
  void clear (void);
  
private:
	///Container to hold data in queue
	Array <T> queue_arr;
	
	///Number of elements in queue
	size_t cur_size;
	
	///Index of first element in queue (int because can be -1 if queue is empty)
	int head;
	
	///Index of last element in queue (int because can be -1 if queue is empty)
	int tail;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_
