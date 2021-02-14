#pragma once
#include "BinaryTree.h"
#include "Exception.h"
#include <iostream>

template<class TKey, class TElement>
struct Pair
{
    TKey key;
    TElement element;
};

template<class TKey, class TElement>
std::ostream& operator<< (std::ostream& out, const Pair<TKey, TElement>& p)
{
	out << p.key << " " << p.element << " ";

	return out;
}

template<class TKey, class TElement>
bool operator>= (const Pair<TKey, TElement>& p1, const Pair<TKey, TElement>& p2)
{
	return  p1.key >= p2.key;
}

template<class TKey, class TElement>
bool operator<= (const TKey key, const Pair<TKey, TElement>& p2)
{
	return key <= p2.key;
}

template<class TKey, class TElement>
bool operator<= (const Pair<TKey, TElement>& p1, const Pair<TKey, TElement>& p2)
{
	return p1.key <= p2.key;
}
template<class TKey, class TElement>

bool operator< (const Pair<TKey, TElement>& p1, const Pair<TKey, TElement>& p2)
{
	return p1.key < p2.key;
}

template<class TKey, class TElement>
bool operator> (const Pair<TKey, TElement>& p1, const Pair<TKey, TElement>& p2)
{
	return  p1.key > p2.key;
}

 template <class TKey, class TElement>
 class Dictionary
 {
 private:
	 BinaryTree<Pair<TKey, TElement>>* tree { nullptr };

 public:

	 Dictionary(TKey key, TElement element)
	 {
		 Pair<TKey, TElement> p;
		 p.element = element;
		 p.key = key;
		 this->tree = new BinaryTree< Pair<TKey, TElement>>(p);
	 }

	 Dictionary(Pair<TKey, TElement> p)
	 {
		 this->tree = new BinaryTree<Pair<TKey, TElement>>(p);
	 }

	 Dictionary(TKey key)
	 {
		 Pair<TKey, TElement> p;
		 p.key = key;
		 this->tree = new BinaryTree<Pair<TKey, TElement>>(p);
	 }

	 Dictionary(Pair<TKey, TElement>* p, int size)
	 {
		this->tree = new BinaryTree<Pair<TKey, TElement>> (p, size);
	 }


	 ~Dictionary()
	 {
		delete this->tree;
		this->tree = nullptr;
	 }

	 int GetCount()
	 {
		 return this->tree->getSize();
	 }

	 TElement Get(TKey key)
	 {
		 Pair<TKey, TElement> searchPair;
		 searchPair.key = key;
		 if (tree->search(searchPair))
			 return tree->getDataNode(tree->search(searchPair)).element;
		 else 
			 throw IndexOutOfRange();
	 }
	 TKey* GetKey(TKey key)
	 {
		 Pair<TKey, TElement> searchPair;
		 searchPair.key = key;
		 if (tree->search(searchPair))
			 return &(tree->getDataNode(tree->search(searchPair)).key);
		 else return nullptr;
	 }
	 /*Pair<TKey, TElement>* GetPointer(TKey key)
	 {
		 Pair<TKey, TElement> searchPair;
		 searchPair.key = key;

		 if (tree->search(searchPair))
		 {
			
		 }
		 else
			 return nullptr;
	 }*/

	 bool ContainsKey(TKey key)
	 {
		 Pair<TKey, TElement> searchPair;
		 searchPair.key = key;
		 if (tree->search(searchPair) == nullptr)
			 return false;
		 else
			 return true;
	 }

	 void Add(TKey key, TElement element)
	 {
		 Pair<TKey, TElement> addPair;
		 addPair.key = key;
		 addPair.element = element;
		 this->tree->insert(addPair); 
	 }

	 void Remove(TKey key)
	 {
		 Pair<TKey, TElement> removePair;
		 removePair.key = key;
		 this->tree->remove(removePair);
	 }

	 void Print()
	 {
		 this->tree->print();
	 }

	 void ChangeElement(TKey key, TElement newElement)
	 {
		 Pair<TKey, TElement> pSearch{ key, 0 };
		 Pair<TKey, TElement>* p = this->tree->getNode(pSearch);
		 p->element = newElement;
	 }
 };