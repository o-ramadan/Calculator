// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Queue
//

#define DEF_SIZE (5)
#define INIT_START (-1)

template <typename T>
Queue <T>::Queue (void)
:	queue_arr(DEF_SIZE),
	cur_size(0),
	head(INIT_START),
	tail(INIT_START)
{

}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & Queue)
:	queue_arr(Queue.queue_arr.size()),
	cur_size(Queue.cur_size),
	head(Queue.head),
	tail(Queue.tail)
{
	int count = 0;
	int index = head;
	
	while (count < cur_size)
	{
		this->queue_arr[index] = Queue.queue_arr[index];
		
		//If (end index) < (start index) 
		if (++index == queue_arr.size())
			index = 0;
		
		count++;
	}
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
  // COMMENT You do not delete data members declared on the stack.
  
  // ADDRESSED COMMENT Removed the line below from code. It is commented out (and not deleted) to show the changes made
	//delete queue_arr; 
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
	//Max size of queue is current size of array
	size_t maxsize = queue_arr.size();

	//Increase size of array if array size limit is reached
	if (maxsize == cur_size)
	{
    // COMMENT This approach can work, but its design is very expensive. You
    // should find a better design that tries to use as much space as possible
    // while minimizing the amount of copying that must occur.
	
	/*
	 ADDRESSED COMMENT To implement a resizeable circular queue, I found this to be the most feasible method. If 
	 the queue becomes full, a resize is necessary. There are two cases that appear if a resize becomes necessary. 1. If
	 the head element is before the tail element (similar to a non-circular queue), then no extra copying is necessary. However,
	 2. if tail is before head, then only elements from index = 0 to index = tail are copied to newly created space after the end 
	 of pre-resized array. This is done to be able to track the order of elements in the queue.
	*/
	
		// resize and switch elements from end to after start
		if (maxsize != 0)
			queue_arr.resize(2*maxsize);
		else 
			queue_arr.resize(5);
		
		
		//Move elements before "start" index to newly created space after it
		if (tail < head)
		{
			for (int i = 0; i <= tail; i++)
				queue_arr[maxsize + i] = queue_arr[i];
			
			//new tail is in the newly created space
			tail = tail + maxsize + 1;
		}
		
		else
		{
			tail++;
			
			if (maxsize == 0)
				head++;
		}
	}
	else 
	{	
		//If "end" index reached the end of the array, move 
		//it to empty location at the start
		if (++tail == maxsize)
			tail = 0;
		
		//Set head and tail to be the same element if the queue was empty prior to enqueue operation
		if (is_empty() == true)
			head = tail;
	}	
		//Add element to queue and increase its current size
		queue_arr[tail] = element;	
		cur_size++;
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
	if (is_empty())
		throw empty_exception("Queue already empty");
	
	T dequeuedElement = queue_arr[head];
	
	//If array limit is reached, move back to start (if not then head index was automatically pre-incremented)
	if (++head == queue_arr.size())
		head = 0;
	
	cur_size--;
	
	//Set tail and head to be -1 if the queue is empty after the dequeue operation 
	if (is_empty())
		tail = head = INIT_START ;
	
	return dequeuedElement;
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	if (this != &rhs)
	{
    // COMMENT You could simplify this design by just using the
    // assignment operator on the array class.
	
	// ADDRESSED COMMENT Used Array class assignment operator
    
		if (this->queue_arr != rhs.queue_arr)
			this->queue_arr = rhs.queue_arr;
			
		//Set rest of members equal to rhs'
		cur_size = rhs.cur_size;
		head = rhs.head;
		tail = rhs.tail;
			
	}
	
	return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
  // COMMENT This works, but is a very expensive operation. You should find a
  // way to just reset the state without having the dequeue every element.
  
  // ADDRESSED COMMENT reset relevant variables
  
  head = INIT_START;
  tail = INIT_START;
  cur_size = 0;
  
  queue_arr.resize(0);

}
