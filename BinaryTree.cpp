// Name: Tanner Dryden

#include <iostream>
#include "BiNode.h"
#include "BTree.h"
using namespace std;
//
//// Test code for Binary Tree Class
int main()
{
	BTree<char> tree1, tree2;
	BiNode<char> *node1, *node2;

	tree1.setHead(new BiNode<char>('A', nullptr, nullptr));

	// Level 1
	node1 = tree1.getHead();
	node1->setLeft(new BiNode<char>('B', nullptr, nullptr));
	node1->setRight(new BiNode<char>('C', nullptr, nullptr));

	// Level 2
	node2 = node1->getRight(); // C
	node1 = node1->getLeft(); // B

	node1->setRight(new BiNode<char>('D', nullptr, nullptr));
	node2->setLeft(new BiNode<char>('E', nullptr, nullptr));
	node2->setRight(new BiNode<char>('F', nullptr, nullptr));

	// Level 3
	node1 = node2->getLeft(); // E
	node2 = node2->getRight(); // F

	node1->setLeft(new BiNode<char>('G', nullptr, nullptr));
	node2->setLeft(new BiNode<char>('H', nullptr, nullptr));
	node2->setRight(new BiNode<char>('I', nullptr, nullptr));

	tree1.setTraverseOrder(TraverseType::PREORDER);
	cout << "Tree 1 (preorder)    : " << tree1 << endl;
	tree1.setTraverseOrder(TraverseType::INORDER);
	cout << "Tree 1 (inorder)     : " << tree1 << endl;
	tree1.setTraverseOrder(TraverseType::POSTORDER);
	cout << "Tree 1 (postorder)   : " << tree1 << endl;
	tree1.setTraverseOrder(TraverseType::BREADTHORDER);
	cout << "Tree 1 (breadthorder): " << tree1 << endl;

	//// Test the copy constructor and = method.
	tree2 = tree1;
	cout << "Tree 2               : " << tree2 << endl;

	BTree<char> tree3(tree1);
	cout << "Tree 3               : " << tree3 << endl;
	return 0;
}