// -*- C++ -*-
//==============================================================================
/**
 * @file       Array_Base.h
 *
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

#include <cstring>          // for size_t definition


#define	DEF_CUR_SIZE (10)

/**
 * @class Array_Base
 *
 * Abstract Base Class for Array family
 *
 *	This class is abstract because it didn't make sense to me to be able to instantiate an Array_Base class on its own.
 *	It would have been just an Array class with less room for mutation. The pure virtual destructor makes this class abstract.
 *	Constructors are protected to ensure only derived classes can create an instance of Array_Base
 */
template <typename T>
class Array_Base
{

protected:
  /// Default constructor.
  Array_Base (void);
												
  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Array_Base (size_t length);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source Array_Base.
   */
  Array_Base (const Array_Base & arr_base);
  
  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Array_Base (size_t length, T fill);
 
  /// Current size of the base_array.
  size_t cur_size_;
  
  /// Pointer to the actual data.
  T * data_;
 
public:
  
  /// Type definition of the element type.
  typedef T type;
  
  /// Pure virtual destructor to make Array_Base class abstract
  virtual ~Array_Base (void) = 0;
  
   /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
   const Array_Base & operator = (const Array_Base & rhs);
  
  /**
   * Test the array for equality.
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
   bool operator == (const Array_Base & rhs) const;

  /**
   * Test the array for inequality.
   *
   * @param[in]       rhs                  Right-hand size of not equal to sign
   * @retval          true                 Left side is not equal to right side
   * @retval          false                Left size is equal to right side
   */
  bool operator != (const Array_Base & rhs) const;
	
  /**
   * Retrieve the current size of the Array_Base.
   *
   * @return          The current size
   */
   size_t size (void) const;
     
  /**
   * Get the object at the specified index. If the index is not
   * within the range of the array, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]       index               Zero-based location
   * @exception       std::out_of_range   Invalid \a index value
   */
  T & operator [] (size_t index);

  /**
   * @overload
   *
   * The returned character is not modifiable.
   */
  const T & operator [] (size_t index) const;

  /**
   * Get the object at the specified index. If the \a index is not within
   * the range of the array, then std::out_of_range exception is thrown.
   *
   * @param[in]       index                 Zero-based location
   * @return          Object at \index
   * @exception       std::out_of_range     Invalid index value
   */  
  T get (size_t index) const;

  /** 
   * Set the object at the specified \a index. If the \a index is not
   * within range of the array, then std::out_of_range exception is 
   * thrown.
   *
   * @param[in]       index                 Zero-based location
   * @param[in]       value                 New value for object
   * @exception       std::out_of_range     Invalid \a index value
   */
  void set (size_t index, T value);

  /**
   * Locate the specified object in the array. The index of the first
   * occurrence of the object is returned. If the object is not
   * found in the array, then -1 is returned.
   *
   * @param[in]        obj        Object to search for
   * @return           Index value of the character
   * @retval           -1        Character not found
   */
  int find (T obj) const;

  /**
   * @overload
   *
   * This version allows you to specify the start index of the search. If
   * the start index is not within the range of the array, then the
   * std::out_of_range exception is thrown.
   *
   * @param[in]       obj                  Object to search for
   * @param[in]       start                Index to begin search
   * @return          Index value of first occurrence
   * @retval          -1                   Object not found
   * @exception       std::out_of_range    Invalid index
   */
  int find (T obj, size_t start) const;

  /**
   * Fill the contents of the array.
   *
   * @param[in]       obj                   Fill object
   */
  void fill (T obj);

  /// Reverse the contents of the array such that the first element is now
  /// the last element and the last element is the first element.
  void reverse (void);

};

#include "Array_Base.inl"
#include "Array_Base.cpp"

#endif   // !defined _ARRAY_H_
