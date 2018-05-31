template <typename T>
struct ListNode
{
	ListNode(const T &e) : data(e),
		                   next(0), prev(0)
	{ }

	T data;
	ListNode<T> *next;
	ListNode<T> *prev;
};

template <typename T>
class list
{
public:
	list() : head_(0), tail_(0),
		     size_(0)
	{ }

	int size() { return size_; }
private:
	ListNode<T> *head_;
	ListNode<T> *tail_;

	int size_;
};

template <typename T>
ListNode<T> *list<T>::insertInternal(const T &e, ListNode<T> *pos)
{
	ListNode<T> *n = new ListNode<T>(e);

	size_++;
	// no operation below this should throw
	// as state of the list has changed and memory allocated

	n->next = pos;

	if(pos)
	{
		n->prev = pos->prev;
		pos->prev = n;
	}
	else
	{
		// pos is null that is at the very end of the list
		n->prev = tail_;
		tail_ = n;
	}

	if(n->prev)
	{
		n->prev->next = n;
	}
	else
	{
		// at the very begining of the list
		head_ = n;
	}

	return n;
}

template <typename T>
void list<T>::push_back(const T &e)
{
	// inserts before the position, 
    // 0 is the end() iterator
	// hence insert at the end
	insertInternal(e, 0);
}

template <typename T>
void list<T>::push_front(const T &e)
{
	// insert before the head
	insertInternal(e, head_);
}

template <typename T>
void list<T>::removeInternal(ListNode<T> *pos)
{
	if(pos)
	{
		if(pos->prev)
			pos->prev->next = pos->next;

		if(pos->next)
			pos->next->prev = pos->prev;

		if(pos == head_)
			head_ = pos->next;

		if(pos == tail_)
			tail_ = pos->prev;

		delete pos;

		size_--;
	}
}

template <typename T>
void list<T>::pop_back()
{
	removeInternal(tail_);
}

template <typename T>
void list<T>::pop_front()
{		
	removeInternal(head_);
}

template <typename T>
list<T>::~list()
{
	ListNode<T> *current( head_ );

	while(current)
	{
		ListNode<T> *next( current->next );
		delete current;
		current = next;
	}
}
//http://codefreakr.com/how-is-c-stl-list-implemented-internally/