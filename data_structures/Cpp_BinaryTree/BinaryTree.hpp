#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////INTERFACE///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*//////////////////////////////////////////////////////////////////////////*/
/*CLASS: 																	*/
/*		Node																*/
/*Nodes for Tree															*/
/*Template:																	*/
/*		K:																	*/
/*			Key data type													*/
/*		T:																	*/
/*			Value data type													*/
/*Data Members: 															*/
/*		-Node* left,														*/
/*		-Node* right:														*/
/*			Child nodes														*/
/*		-T* data:															*/
/*			Data held in the node											*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
class Node
{
	protected:
		Node<K,T>* left;
		Node<K,T>* right;
		K* key;
		T* value;
		
	public:
		Node();
		Node(K* key, T* data);
		Node(K* key, T* data, Node* left, Node* right);
		~Node();
		
		T& getValue() const;
		void setValue(T* input);
		K&   getKey() const;
		void setKey(K* input);
		void setData(K* key, T* value);
		Node<K,T>* getLeft() const;
		void setLeft(Node<K,T>* left);
		Node<K,T>* getRight() const;
		void setRight(Node<K,T>* right);
		
		//Operators
		bool operator>(const Node<K,T>& rhs) const;
		bool operator<(const Node<K,T>& rhs) const;
		bool operator==(const Node<K,T>& rhs) const;
		bool operator!=(const Node<K,T>& rhs) const;
		bool operator>=(const Node<K,T>& rhs) const;
		bool operator<=(const Node<K,T>& rhs) const;
		
		void print() const;
};

/*//////////////////////////////////////////////////////////////////////////*/
/*CLASS: 																	*/
/*		BinaryTree															*/
/*Binary search tree														*/
/*																			*/
/*Data Members: 															*/
/*		-Node* root:														*/
/*			The root of the tree											*/
/*		-unsigned int size:													*/
/*			Number of entries in the tree									*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
class BinaryTree
{	private:
		static void _preOrder(Node<K,T>* node);
		static void _inOrder(Node<K,T>* node);
		static void _postOrder(Node<K,T>* node);
	protected:
		Node<K,T>* root;
		unsigned int size;
		
		void increment();
		void decrement();
	public:
		BinaryTree();
		~BinaryTree();
		void append(K* key, T* value, bool replace = true);
		void deleteEntry(K* key);
		BinaryTree* balance();
		
		int  getSize() const;
		bool isEmpty() const;
		
		bool isInTree(K searchKey);
		T	 search(K searchKey);
		
		void print(int ordering) const;
		
		T*  toArray(int ordering) const;
		K*	toKeyArray(int ordering) const;
};
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////IMPLEMENTATION//////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;
///////////////////////////////////////NODE///////////////////////////////////

/*//////////////////////////////////////////////////////////////////////////*/
/*CONSTRUCTOR: 																*/
/*		Node()												  				*/
/*DESCRIPTION:																*/
/*		No arg constructor for Node class. Initializes all members to NULL.	*/
/*Args: 																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
Node<K,T>::Node()
{
	this->key 	= nullptr;
	this->value	= nullptr;
	this->left	= nullptr;
	this->right	= nullptr;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*CONSTRUCTOR: 																*/
/*		Node(K* key, T& data)									  			*/
/*DESCRIPTION:																*/
/*		Constructor initializes data.										*/
/*Args: 																	*/
/*		K* key:																*/
/*			Initial key data												*/
/*		T data:																*/
/*			Initial value data												*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
Node<K,T>::Node(K* key, T* data)
{
	this->key 	= key;
	this->value	= data;
	this->left	= nullptr;
	this->right	= nullptr;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*CONSTRUCTOR: 																*/
/*		Node(K* key, T data, Node* left, Node* right)						*/
/*DESCRIPTION:																*/
/*		Constructor initializes data along with children.					*/
/*Args: 																	*/
/*		K* key:																*/
/*			Initial key data												*/
/*		T data:																*/
/*			Initial value data												*/
/*		Node* left:															*/
/*		Node* right:														*/
/*			Children														*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
Node<K,T>::Node(K* key, T* data, Node* left, Node* right)
{
	this->key 	= *key;
	this->value	= *data;
	this->left	= left;
	this->right	= right;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*DESTRUCTOR: 																*/
/*		~Node()												  				*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
Node<K,T>::~Node()
{
	delete this->key;
	delete this->value;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		T& getValue()							  							*/
/*DESCRIPTION																*/
/*		Accessor for `value` data											*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		`value` member of a Node											*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
T& Node<K,T>::getValue() const
{
	return *(this->value);
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void setValue(T input)												*/
/*DESCRIPTION																*/
/*		Sets the `value` data												*/
/*Args: 																	*/
/*		T input:															*/
/*			New `value` data												*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void Node<K,T>::setValue(T* input)
{	
	(*this->value) = *input;
	delete input;										//Free memory
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		K& getKey()															*/
/*DESCRIPTION																*/
/*		Gets the `key` data	member 											*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		`key` data member													*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
K& Node<K,T>::getKey() const
{
	return *(this->key);
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void setKey(K input)												*/
/*DESCRIPTION																*/
/*		Sets the `key` data													*/
/*Args: 																	*/
/*		K* input:															*/
/*			New `key` data													*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void Node<K,T>::setKey(K* input)
{
	(*this->key) = *input;
	delete input;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void setData(K* key, T* value)										*/
/*DESCRIPTION																*/
/*		Sets both `key` and `value`											*/
/*Args: 																	*/
/*		K* key:																*/
/*			New `key` data													*/
/*		T* value:															*/
/*			New `value` data												*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void Node<K,T>::setData(K* key, T* value)
{
	this->key	= key;
	this->value = value;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		Node<K,T>* getLeft()												*/
/*DESCRIPTION:																*/
/*		Gets left child of the Node											*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		Child Node															*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
Node<K,T>* Node<K,T>::getLeft() const
{
	return this->left;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void setLeft(Node<K,T>* left)										*/
/*DESCRIPTION:																*/
/*		Sets left child of the Node											*/
/*Args: 																	*/
/*		Node<K,T>* left:													*/
/*			New child node													*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void Node<K,T>::setLeft(Node<K,T>* left)
{
	this->left = left;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		Node<K,T>* getRight()												*/
/*DESCRIPTION:																*/
/*		Gets right child of the Node										*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		Child Node															*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
Node<K,T>* Node<K,T>::getRight() const
{
	return this->right;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void setRight(Node<K,T>* right)										*/
/*DESCRIPTION:																*/
/*		Sets right child of the Node										*/
/*Args: 																	*/
/*		Node<K,T>* right:													*/
/*			New child node													*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void Node<K,T>::setRight(Node<K,T>* right)
{
	this->right = right;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*OPERATORS: 																*/
/*		<, >, ==, !=, <=, >=												*/
/*DESCRIPTION:																*/
/*		Overloaded comparison operators	for Node class. These compare		*/
/*		the keys of two Nodes to create the boolean value.					*/
/*//////////////////////////////////////////////////////////////////////////*/
//GREATER THAN//
template <typename K, typename T>
bool Node<K,T>::operator>(const Node<K,T>& rhs) const
{
	return this->getKey() > rhs.getKey();
}

//LESS THAN//
template <typename K, typename T>
bool Node<K,T>::operator<(const Node<K,T>& rhs) const
{
	return this->getKey() < rhs.getKey();
}

//EQUAL//
template <typename K, typename T>
bool Node<K,T>::operator==(const Node<K,T>& rhs) const
{
	return this->getKey() == rhs.getKey();
}

//NOT EQUAL//
template <typename K, typename T>
bool Node<K,T>::operator!=(const Node<K,T>& rhs) const
{
	return this->getKey() != rhs.getKey();
}

//GREATER THAN OR EQUAL//
template <typename K, typename T>
bool Node<K,T>::operator>=(const Node<K,T>& rhs) const
{
	return this->getKey() >= rhs.getKey();
}

//LESS THAN OR EQUAL//
template <typename K, typename T>
bool Node<K,T>::operator<=(const Node<K,T>& rhs) const
{
	return this->getKey() <= rhs.getKey();
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void print()														*/
/*DESCRIPTION:																*/
/*		Prints Node contents in form "(key, value) "						*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void Node<K,T>::print() const
{
	cout << "(" << this->getKey() << ", " << this->getValue() << ") ";
}

//////////////////////////////////BINARYTREE//////////////////////////////////

/*//////////////////////////////////////////////////////////////////////////*/
/*CONSTRUCTOR: 																*/
/*		BinaryTree()										  				*/
/*DESCRIPTION:																*/
/*		Constructor creates empty tree										*/
/*Args: 																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
BinaryTree<K,T>::BinaryTree()
{
	this->root = nullptr;
	size = 0;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*DESTRUCTOR: 																*/
/*		~BinaryTree()										  				*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
BinaryTree<K,T>::~BinaryTree()
{
	//TODO Destructor
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void append(K* key, T* value, bool replace)							*/
/*DESCRIPTION																*/
/*		Appends new data to the tree.										*/
/*Args: 																	*/
/*		K* key:																*/
/*			New `key` data													*/
/*		T* value:															*/
/*			New `value` data												*/
/*		bool replace:														*/
/*			If `true`, data will be replaces if a duplicate key is entered	*/
/*			If `false`, no changed are made and the append is cancelled		*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void BinaryTree<K,T>::append(K* key, T* value, bool replace)
{
	Node<K,T>* newNode = new Node<K,T>(key, value);
	Node<K,T>* cursor = this->root;
	
															
	if(this->isEmpty()){							//Check if empty
		this->root = newNode;						//If so, initialize the root and then return
		this->increment();					//Increment size
		return;
	}
		
	while(true){									//Loop through tree to find placement
		if(*newNode < *cursor){						//Less, go left
			if(cursor->getLeft() == nullptr){		//If null, place newNode and return.
				cursor->setLeft(newNode);
				this->increment();					//Increment size
				return;
			}else{									//Else, advance cursor
				cursor = cursor->getLeft();
			}
		}else if(*newNode > *cursor){				//newNode is larger, look right
			if(cursor->getRight() == nullptr){		//If null, place newNode and return.
				cursor->setRight(newNode);
				this->increment();					//Increment size
				return;
			}else{									//Else, advance cursor
				cursor = cursor->getRight();
			}
		}else if(*newNode == *cursor){				//If equal...	
			if(replace){							//Replace value if `replace` is true
				cursor->setValue(value);
				delete newNode;
				return;
			}else{									//Else, return without replacing
				delete newNode;
				return;
			}
		}
	}
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		int getSize()														*/
/*DESCRIPTION:																*/
/*		Retrieves the size of a tree										*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		Number of nodes in tree												*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
int BinaryTree<K,T>::getSize() const
{
	return this->size;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*HELPER: 																	*/
/*		void _preOrder(Node<K,T>* node)										*/
/*		void _inOrder(Node<K,T>* node)										*/
/*		void _postOrder(Node<K,T>* node)									*/
/*DESCRIPTION:																*/
/*		Private helpers to help with recursion in print()					*/
/*Args: 																	*/
/*		Node<K,T>* node:													*/
/*			Node to recurse on.												*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void BinaryTree<K, T>::_preOrder(Node<K,T>* node)
{
	if(node == nullptr){
		return;										//Base case
	}else{
		node->print();								//Recursive case
		_preOrder(node->getLeft());
		_preOrder(node->getRight());
	}
}

template <typename K, typename T>
void BinaryTree<K, T>::_inOrder(Node<K,T>* node)
{
	if(node == nullptr){
		return;										//Base case
	}else{
		_inOrder(node->getLeft());
		node->print();								//Recursive case
		_inOrder(node->getRight());
	}
}									

template <typename K, typename T>
void BinaryTree<K, T>::_postOrder(Node<K,T>* node)
{
	if(node == nullptr){
		return;										//Base case
	}else{
		_postOrder(node->getLeft());
		_postOrder(node->getRight());
		node->print();
	}
}


/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void print(int ordering)											*/
/*DESCRIPTION:																*/
/*		Prints the contents of a tree. Ordering is dependent on the int,	*/
/*		`ordering`:															*/
/*				ordering < 0: Pre-order										*/
/*				ordering > 0: Post-order									*/
/*				ordering = 0: In-order										*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void BinaryTree<K,T>::print(int ordering) const
{
	if(ordering < 0){
		BinaryTree::_preOrder(this->root);
	}else if(ordering > 0){
		BinaryTree::_inOrder(this->root);
	}else{
		BinaryTree::_postOrder(this->root);
	}
	cout << endl;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		bool isEmpty()														*/
/*DESCRIPTION:																*/
/*		Shows whether or not a tree is empty								*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		True if empty, else, false											*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
bool BinaryTree<K,T>::isEmpty() const
{
	if(this->getSize() == 0){
		return true;
	}else{
		return false;
	}
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void increment()													*/
/*DESCRIPTION:																*/
/*		Increments the `size` member of a tree								*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void BinaryTree<K,T>::increment()
{
	this->size += 1;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*FUNCTION: 																*/
/*		void decrement()													*/
/*DESCRIPTION:																*/
/*		Decrements the `size` member of a tree.								*/
/*Args: 																	*/
/*		void																*/
/*Return:																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
void BinaryTree<K,T>::decrement()
{
	if(this->getSize() < 0){							//Error checking prevents subtractions
		this->size -= 1;								//from 0.
	}else{
		return;
	}
}
#endif