// Name: Tanner Dryden
// Description: This class helps create a binary tree

#pragma once
#include <ostream>
using namespace std;

template<class P>
class BiNode
{
private:
	char payload;
	BiNode<P>* left;
	BiNode<P>* right;

public:

	// Constructors
	BiNode(P newPayload, BiNode<P>* newLeft, BiNode<P>* newRight)
	{
		setPayload(newPayload);
		setLeft(newLeft);
		setRight(newRight);
	}

	// Accessors 
	P getPayload() const
	{
		return payload;
	}
	BiNode* getLeft() const
	{
		return left;
	}
	BiNode* getRight() const
	{
		return right;
	}

	// Mutators
	void setPayload(P newPayload)
	{
		payload = newPayload;
	}
	void setLeft(BiNode<P>* newLeft)
	{
		left = newLeft;
	}
	void setRight(BiNode<P>* newRight)
	{
		right = newRight;
	}

	// Operators
	friend ostream& operator <<(ostream& outStream, const BiNode<P>& node)
	{
		outStream << node.getPayload();
		return outStream;
	}
};

