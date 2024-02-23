#include "tree.h"
//implementing the definitions for the class method

void GatorTree::deleteTree(Node *_rootNode) {
	//use recursion to delete every node of the tree
	
	if (_rootNode->right != nullptr) {		//go to the left
		deleteTree(_rootNode->right);
	}
	if (_rootNode->left != nullptr) {		//go to the right
		deleteTree(_rootNode->left);
	}
	//delete the root
	if (_rootNode != nullptr) {
		delete _rootNode;
	}
}

Node *GatorTree::insert(Node *_rootNode, int _id, string _name) {
	//insert the node at an empty place or when the tree is empty
	if (_rootNode == nullptr) {
		cout << "successful\n";
		return new Node(_id, _name);
	}
	//if ID is bigger than current, go to the right subtree
	else if (_id > _rootNode->gatorId) {
		_rootNode->right = insert(_rootNode->right, _id, _name);
		_rootNode = balanceTree(_rootNode);
	}
	//if ID is smaller than current, go to the left subtree
	else if (_id < _rootNode->gatorId) {
		_rootNode->left = insert(_rootNode->left, _id, _name);
		_rootNode = balanceTree(_rootNode);
	}
	//if it is equal we dont insert the node and return unsuccessful
	else if (_id == _rootNode->gatorId) {
		cout << "unsuccessful\n";
	}

	return _rootNode;

}

Node *GatorTree::getInorderSuccessor(Node *rightSubNode) {
	//loop until the end of left tree
	while (rightSubNode->left != nullptr) {
		rightSubNode = rightSubNode->left;
	}

	return rightSubNode;
}

Node *GatorTree::removeID(Node *_rootNode, int _id) {
	if (_rootNode == nullptr) {		//unsuccessful if tree is empty
		cout << "unsuccessful\n";
		return _rootNode;
	} else if (_id > _rootNode->gatorId) {		//if larger than current, go to right tree
		_rootNode->right = removeID(_rootNode->right, _id);
	} else if (_id < _rootNode->gatorId) {		//if smaller than current, go to left tree
		_rootNode->left = removeID(_rootNode->left, _id);
	}
	//delete the node based on the case
	else if (_id == _rootNode->gatorId) {
		// Seperated into different cases for removal
		if (_rootNode->left == nullptr && _rootNode->right == nullptr) {
			cout << "successful\n";
			return _rootNode;
		}
		//only one right child
		else if (_rootNode->left == nullptr) {
			cout << "successful\n";
			Node *newNode = _rootNode->right;
			delete _rootNode;
			return newNode;
		}
		//only one left child
		else if (_rootNode->right == nullptr) {
			cout << "successful\n";
			Node *newNode = _rootNode->left;
			delete _rootNode;
			return newNode;
		}
		//there are two child nodes
		else {
			//find the inorder successor to find and delete it
			Node *newNode = getInorderSuccessor(_rootNode->right);
			_rootNode->gatorId = newNode->gatorId;
			_rootNode->studentName = newNode->studentName;
			_rootNode->right = removeID(_rootNode->right, _rootNode->gatorId);
			// return
		}
	}
	return _rootNode;

};

void GatorTree::insertAllocatedRoot(int _id, string _name) {
	rootNode = insert(rootNode, _id, _name);
	treeHeight = findLevelCount(rootNode);
}

void GatorTree::removeAllocatedRoot(int _id) {
	rootNode = removeID(rootNode, _id);
	treeHeight = findLevelCount(rootNode);
}

int GatorTree::findLevelCount(Node *_rootNode) {		//recursive through two sides of the tree to find the level
	if (_rootNode == nullptr) {
		return 0;
	} else {
		return 1 + max(findLevelCount(_rootNode->left), findLevelCount(_rootNode->right));
	}
}

void GatorTree::printLevelCount(Node *_rootNode) {		//print out the treeHeight
	if (_rootNode != nullptr) {
		treeHeight = findLevelCount(_rootNode);
		cout << treeHeight << endl;
	}
}


void GatorTree::inOrder(Node *_rootNode, vector<string> &traversalVector) {		//recursion to traverse through all nodes
	if (_rootNode) {
		inOrder(_rootNode->left, traversalVector);
		traversalVector.push_back(_rootNode->studentName);
		inOrder(_rootNode->right, traversalVector);
	}
}

void GatorTree::inOrderNodes(Node *_rootNode, vector<Node *> &traversalVector) {		//recursion to traverse through all nodes
	if (_rootNode) {
		inOrderNodes(_rootNode->left, traversalVector);
		traversalVector.push_back(_rootNode);
		inOrderNodes(_rootNode->right, traversalVector);
	}
}

void GatorTree::postOrder(Node *_rootNode, vector<string> &traversalVector) {		//recursion to traverse through all nodes
	if (_rootNode) {
		postOrder(_rootNode->left, traversalVector);
		postOrder(_rootNode->right, traversalVector);
		traversalVector.push_back(_rootNode->studentName);
	}
}

void GatorTree::preOrder(Node *_rootNode, vector<string> &traversalVector) {		//recursion to traverse through all nodes
	if (_rootNode) {
		traversalVector.push_back(_rootNode->studentName);
		preOrder(_rootNode->left, traversalVector);
		preOrder(_rootNode->right, traversalVector);
	}
}

void GatorTree::printInOrder(Node *_rootNode) {
	if (_rootNode != nullptr) {
		vector<string> nodeVector;
		inOrder(_rootNode, nodeVector);
		for (int i = 0; i < nodeVector.size(); ++i) {
			if (i == nodeVector.size() - 1) {
				cout << nodeVector[i] << endl;
			} else {
				cout << nodeVector[i] << ", ";
			}
		}
	}
	

}

void GatorTree::printPreOrder(Node *_rootNode) {
	if (_rootNode != nullptr) {
		vector<string> nodeVector;
		preOrder(_rootNode, nodeVector);
		for (int i = 0; i < nodeVector.size(); ++i) {
			if (i == nodeVector.size() - 1) {
				cout << nodeVector[i] << endl;
			} else {
				cout << nodeVector[i] << ", ";
			}
		}
	}
}

void GatorTree::printPostOrder(Node *_rootNode) {
	if (_rootNode != nullptr) {
		vector<string> nodeVector;
		postOrder(_rootNode, nodeVector);
		for (int i = 0; i < nodeVector.size(); ++i) {
			if (i == nodeVector.size() - 1) {
				cout << nodeVector[i] << endl;
			} else {
				cout << nodeVector[i] << ", ";
			}
		}
	}
}

int GatorTree::searchName(Node *_rootNode, string name, int &isValid) {
	if (_rootNode == nullptr) {
		return 0;
	}
	if (_rootNode->studentName == name) {		//print out the ID of all students with that name
		cout << _rootNode->gatorId << endl;
		//isValid to check if the name exists, if not, it will return 0 (passed on to checker method)
		++isValid;
	}
	//recursively go through all the nodes
	if (_rootNode->left != nullptr)
	searchName(_rootNode->left, name, isValid);

	if (_rootNode->right != nullptr)
	searchName(_rootNode->right, name, isValid);

	return isValid;
}

int GatorTree::existChecker(int condition) {		//if condition is 0, then the name or id does not exist.
	if (condition == 0) {
		cout << "unsuccessful" << endl;
	}
	return 0;
}

int GatorTree::searchID(Node *_rootNode, int _id, int &isValid) {		//search for the name of the student with the given id and print it out
	if (_rootNode == nullptr) {
		return 0;
	}
	if (_rootNode->gatorId == _id) {
		cout << _rootNode->studentName << endl;
		++isValid;
	}
	//recursively go through all the node
	if (_rootNode->left != nullptr)
	searchID(_rootNode->left, _id, isValid);

	if (_rootNode->right != nullptr)
	searchID(_rootNode->right, _id, isValid);

	return isValid;
}

void GatorTree::removeInOrder(Node *_rootNode, int N) {
	vector<Node *> traversal;
	inOrderNodes(_rootNode, traversal);
	if (N < traversal.size()) {		//remove in order
		removeID(_rootNode, traversal[N]->gatorId);
	} else {
		cout << "unsuccessful\n";
	}

}

//left rotate
Node *GatorTree::rotateLeft(Node *_rootNode) {
	Node *right = _rootNode->right;
	_rootNode->right = right->left;
	right->left = _rootNode;
	return right;
}


//right rotate
Node *GatorTree::rotateRight(Node *_rootNode) {
	Node *left = _rootNode->left;
	_rootNode->left = left->right;
	left->right = _rootNode;
	return left;
}

//left right rotate
Node *GatorTree::rotateLeftRight(Node *_rootNode) {
	_rootNode->left = rotateLeft(_rootNode->left);
	_rootNode = rotateRight(_rootNode);
	return _rootNode;
}

//right left rotate
Node *GatorTree::rotateRightLeft(Node *_rootNode) {
	_rootNode->right = rotateRight(_rootNode->right);
	_rootNode = rotateLeft(_rootNode);
	return _rootNode;
}

//find the balance factor from two sides
int GatorTree::returnBalanceFactor(Node *_rootNode) {
	if (_rootNode == nullptr) {
		return 0;
	} else {
		return findLevelCount(_rootNode->left) - findLevelCount(_rootNode->right);
	}
}

//balance the tree
Node *GatorTree::balanceTree(Node *_rootNode) {
	int balanceFactor = returnBalanceFactor(_rootNode);
	int rightBalanceFactor = returnBalanceFactor(_rootNode->right);
	int leftBalanceFactor = returnBalanceFactor(_rootNode->left);
	//right heavy tree
	if (balanceFactor <= -2) {

		//right subtree heavy
		if (rightBalanceFactor >= 1) {
			//right left rotation
			_rootNode = rotateRightLeft(_rootNode);
		} else {
			//left rotation
			_rootNode = rotateLeft(_rootNode);
		}


	}
	//left heavy tree
	else if (balanceFactor >= 2) {
		//left subtree heavy
		if (leftBalanceFactor <= -1) {
			//left right rotation
			_rootNode = rotateLeftRight(_rootNode);

		} else {
			//right rotation
			_rootNode = rotateRight(_rootNode);
		}
	}
	return _rootNode;
}