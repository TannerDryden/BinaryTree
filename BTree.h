// Name: Tanner Dryden
// Description: This class is a binary tree class

#pragma once
#include "BiNode.h"
#include "Queue.h"
#include <iostream>
using namespace std;

enum class TraverseType { INORDER , PREORDER, POSTORDER, BREADTHORDER };

template<class T>
class BTree
{
private:

	// Attributes
	BiNode<T>* head;
	TraverseType traverseOrder; // program 9 exclusive

	// Helpers
	BiNode<T>* copyHelper(BiNode<T>* temp)
	{
		BiNode<T>* newNode = nullptr;
		if (temp != nullptr)
		{
			try {
				newNode = new BiNode<T>(temp->getPayload(), nullptr, nullptr);
				newNode->setLeft(copyHelper(temp->getLeft()));
				newNode->setRight(copyHelper(temp->getRight()));
			}
			catch (exception & error)
			{
				error;
			}
		}
		return newNode;
	}

	void clearTree(BiNode<T>* temp)
	{
		if (temp != nullptr)
		{
			clearTree(temp->getLeft());
			clearTree(temp->getRight());
			delete temp;
		}
	}

	void inOrderTraversal(ostream& outStream, const BiNode<T>* temp) const
	{
		if (temp != nullptr)
		{
			inOrderTraversal(outStream, temp->getLeft());
			outStream << *temp;
			inOrderTraversal(outStream, temp->getRight());
		}
	}

	void preOrderTraversal(ostream& outStream, const BiNode<T>* temp) const
	{
		if (temp != nullptr)
		{
			outStream << *temp;
			preOrderTraversal(outStream, temp->getLeft());
			preOrderTraversal(outStream, temp->getRight());
		}
	}

	void postOrderTraversal(ostream& outStream, const BiNode<T>* temp) const
	{
		if (temp != nullptr)
		{
			postOrderTraversal(outStream, temp->getLeft());
			postOrderTraversal(outStream, temp->getRight());
			outStream << *temp;
		}
	}

	void breadthOrderTraversal(ostream& outStream, BiNode<T> *root) const
	{
		Queue <BiNode<T>*> queue;

		if (head != nullptr)
		{
			queue.enqueue(root);
		}

		while (!queue.isEmpty())
		{
			BiNode<T>* tempPtr = queue.dequeue();

			if (tempPtr->getLeft() != nullptr)
			{
				queue.enqueue(tempPtr->getLeft());
			}
			if (tempPtr->getRight() != nullptr)
			{
				queue.enqueue(tempPtr->getRight());
			}
			outStream << *tempPtr;
		}
	}

public:
	// Constructors
	BTree() 
	{
		head = nullptr;
		traverseOrder = TraverseType::INORDER;
	}

	BTree(const BTree& fromHead)
	{
		head = nullptr;

		this->head = copyHelper(fromHead.head);
		traverseOrder = fromHead.traverseOrder;
	}

	// Accessors
	BiNode<T>* getHead() const // program 9 exclusive
	{
		return head;
	}

	// Mutators
	void setHead(BiNode<T>* node) // program 9 exclusive
	{
		head = node;
	}


	// Operators
	friend ostream& operator <<(ostream& outStream, const BTree<T>& tree)
	{
		switch (tree.traverseOrder)
		{
		case TraverseType::INORDER:
				tree.inOrderTraversal(outStream, tree.getHead());
				break;
			case TraverseType::PREORDER:
				tree.preOrderTraversal(outStream, tree.getHead());
				break;
			case TraverseType::POSTORDER:
				tree.postOrderTraversal(outStream, tree.getHead());
				break;
			case TraverseType::BREADTHORDER:
				tree.breadthOrderTraversal(outStream, tree.getHead());
				break;
			default:
				outStream << "traverse type invalid or not set" << endl;
				break;
		}
		return outStream;
	}

	BTree& operator=(const BTree& tree)
	{
		if (this != &tree)
		{
			this->clearTree(this->getHead());
			this->head = this->copyHelper(tree.head);
			this->traverseOrder = tree.traverseOrder;
		}
		return(*this);
	}

	// Traverse Order
	void setTraverseOrder(TraverseType inputOrder) // program 9 exclusive
	{
		traverseOrder = inputOrder;
	}

	// Destructor
	~BTree()
	{
		clearTree(head);
	}
};

