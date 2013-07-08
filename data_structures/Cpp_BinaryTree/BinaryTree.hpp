#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

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
		K key;
		T value;
		
	public:
		Node();
		Node(K key, T data);
		Node(K key, T data, Node* next);
		
		T getData();
		void setData(K key, T data);
		void setChildren(Node<K,T>* left, Node<K,T>* right);
		void setLeft(Node<K,T>* left);
		void setRight(Node<K,T>* right);
};

/*//////////////////////////////////////////////////////////////////////////*/
/*CLASS: 																	*/
/*		BinaryTree															*/
/*Binary search tree														*/
/*																			*/
/*Data Members: 															*/
/*		-Node* root:														*/
/*			The root of the tree											*/
/*		-int   size:														*/
/*			Number of entries in the tree									*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
class BinaryTree
{
	protected:
		Node<K,T>* root;
	public:
		BinaryTree();
		void append(K key, T value);
		void deleteEntry(K key);
		BinaryTree* balance();
		
		int  getSize();
		bool isEmpty();
		
		bool isInTree(K searchKey);
		T	 search(K searchKey);
		
		void printPreOrder();
		void printInOrder();
		void printPostOrder();
		
		T*  toArray(int ordering);
		K*	toKeyArray(int ordering);
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
/*No arg constructor for Node class. Initializes all members to NULL.		*/
/*																			*/
/*Args: 																	*/
/*		void																*/
/*//////////////////////////////////////////////////////////////////////////*/
template <typename K, typename T>
Node<K,T>::Node()
{
	this->key 	= 0;
	this->value	= 0;
	this->left	= nullptr;
	this->right	= nullptr;
}

/*//////////////////////////////////////////////////////////////////////////*/
/*CONSTRUCTOR: 																*/
/*		FUNCTION NAME										  				*/
/*DESCRIPTION																*/
/*																			*/
/*Args: 																	*/
/*		ARG 0:																*/
/*			DESCRIPTION														*/
/*		ARG 1:																*/
/*			DESCRIPTION														*/
/*		ARG n:																*/
/*			DESCRIPTION														*/
/*Except:																	*/
/*		Exception 0:														*/
/*			DESCRIPTION														*/
/*		Exception 1:														*/
/*			DESCRIPTION														*/
/*		Exception n:														*/
/*			DESCRIPTION														*/
/*Return:																	*/
/*		DESCRIPTION															*/
/*//////////////////////////////////////////////////////////////////////////*/


/////////////////////////////////////BINARYTREE///////////////////////////////

#endif