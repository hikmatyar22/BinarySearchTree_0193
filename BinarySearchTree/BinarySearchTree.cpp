#include <iostream>
#include <string>
using namespace std;


class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//constrctor for the node class
	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};


class BinaryTree {
public:
	Node* ROOT;

	BinaryTree() {
		ROOT = nullptr; //intializing ROOT to null
	}

	void insert(string element)// insert a node in the binary search tree 
	{
		Node* newNode = new Node(element, nullptr, nullptr); // Allocate memory for the new node
		newNode->info = element; // Assign value to the data field of the new node
		newNode->leftchild = nullptr; // Make the left child of the nwq node point to null
		newNode->rightchild = nullptr; // Make the right child of the nwq node point to null

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode); // locate the node which will be the parent of the node to be ins

		if (parent == nullptr) // if the parent is Null (tree is empty)
		{
			ROOT = newNode; // mark the new node as root
			return; // exit
		}
		if (element < parent->info) // if the value in the data field of the new node is less than that of the
		{
			parent->leftchild = newNode; // make the left child od the2 parent point to the new node
		}
		else if (element > parent->info) // if the value in the data field of the new node is greater than that of the
		{
			parent->rightchild = newNode; // make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		// this function searchrs the current node of the spesified node as well as the current node oif its parent
		currentNode = ROOT;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	} 

	void inorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr)
	{
		// performs the postorder traversal of the tree
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main() {
	BinaryTree x;
	while (true)
	{
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. exit" << endl;
		cout << "\nEnter your choice (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "Enter a word : ";
			string word;
			cin >> word;
			x.insert(word);
			break;
		}
		case '2':
		{
			x.inorder(x.ROOT);
			break;
		}
		case '3':
		{
			x.preorder(x.ROOT);
			break;
		}
		case '4':
		{
			x.postorder(x.ROOT);
			break;
		}
		case '5':
			return 0;
		default:
		{
			cout << "Invalid option" << endl;
			break;
		}
		}
	}
}
	

