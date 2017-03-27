#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "ListDoublyLinkedIterator.h"
#include "SortedListDoublyLinked.h"

template < class T >
class Hybrid
{

   private:
      QueueLinked<DoubleNode<T> >* q;
      SortedListDoublyLinked<T>* sldl;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
   q = new QueueLinked<DoubleNode<T> >();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove

template < class T >
bool Hybrid<T>::isEmpty()
{
	//Had to create this function also, returns a bool of true when the Queueue is empty.
	return q->isEmpty();
}

template < class T >
void Hybrid<T>::enqueue(T* item)
{
	//As stated in the lab, the item that we get from the parameter is added into the sortedDoublyLinked,
	//and returned to us, from here we enqueue that item onto the Queue that uses double nodes.
	DoubleNode<T>* itemAdd = sldl->addDN(item);
	q->enqueue(itemAdd);
}
template < class T >
T* Hybrid<T>::dequeue()
{
	//As also stated in the lab when we dequeue the item from the queue it's returned to us, this allows us to
	//remove it from the sortedDoublyLinked.
	DoubleNode<T>* item = q->dequeue();
	sldl->remove(item);
}
template < class T >

ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
{
  //Had to make this function, gives us an iterator to iterate over the items.
   DoubleNode<T>* head = sldl->findHead();
   ListDoublyLinkedIterator<T>* iter = new ListDoublyLinkedIterator<T>(head);
   return iter;
} 

#endif
