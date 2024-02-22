#include "tree.h"

// Destructor for the GatorTree
void GatorTree::deleteTree(Node *_rootNode) {
	// Calling recursive functions to delete each node of both subtrees
	//left
	if (_rootNode->right != nullptr) {
		deleteTree(_rootNode->right);
	}
	//right
	if (_rootNode->left != nullptr) {
		deleteTree(_rootNode->left);
	}
	delete _rootNode;
}

// Insertion method - based on lecture slides
Node *GatorTree::insert(Node *_rootNode, int _id, string _name) {
	// If there is no node there, insert and return
	// and for empty GatorTree
	if (_rootNode == nullptr) {
		cout << "successful\n";
		return new Node(_id, _name);
	}
		// If ID is bigger, go to right subtree
	else if (_id > _rootNode->gatorId) {
		_rootNode->right = insert(_rootNode->right, _id, _name);
		_rootNode = balanceTree(_rootNode);
	}
		// If ID is smaller, go to left subtree
	else if (_id < _rootNode->gatorId) {
		_rootNode->left = insert(_rootNode->left, _id, _name);
		_rootNode = balanceTree(_rootNode);
	}
		// If equal
	else if (_id == _rootNode->gatorId) {
		cout << "unsuccessful\n";
	}

	return _rootNode;

}

Node *GatorTree::getInorderSuccessor(Node *rightSubNode) {
	while (rightSubNode->left != nullptr) {
		rightSubNode = rightSubNode->left;
	}

	return rightSubNode;
}

// Method to remove node by ID
Node *GatorTree::removeID(Node *_rootNode, int _id) {
	if (_rootNode == nullptr) {
		cout << "unsuccessful\n";
		return _rootNode;
	} else if (_id > _rootNode->gatorId) {
		_rootNode->right = removeID(_rootNode->right, _id);
	} else if (_id < _rootNode->gatorId) {
		_rootNode->left = removeID(_rootNode->left, _id);
	}
		// If ID is found
	else if (_id == _rootNode->gatorId) {
		// Seperated into different cases for removal
		if (_rootNode->left == nullptr && _rootNode->right == nullptr) {
			cout << "successful\n";
			return nullptr;
		}
			// If there is only 1 right child
		else if (_rootNode->left == nullptr) {
			cout << "successful\n";
			Node *newNode = _rootNode->right;
			delete _rootNode;
			return newNode;
		}
			// If there is only 1 left child
		else if (_rootNode->right == nullptr) {
			cout << "successful\n";
			Node *newNode = _rootNode->left;
			delete _rootNode;
			return newNode;
		}
			// If there are 2 children
		else {
			// Find in order successor, set value then delete it
			Node *newNode = getInorderSuccessor(_rootNode->right);
			_rootNode->gatorId = newNode->gatorId;
			_rootNode->studentName = newNode->studentName;
			_rootNode->right = removeID(_rootNode->right, _rootNode->gatorId);
			// return
		}

	}


	return _rootNode;

};

// allocate root after inserting method
void GatorTree::insertAllocatedRoot(int _id, string _name) {
	rootNode = insert(rootNode, _id, _name);
	treeHeight = findLevelCount(rootNode);
}

void GatorTree::removeAllocatedRoot(int _id) {
	rootNode = removeID(rootNode, _id);
	treeHeight = findLevelCount(rootNode);
}


// find the level - based on lectures slides
int GatorTree::findLevelCount(Node *_rootNode) {
	if (_rootNode == nullptr) {
		return 0;
	} else {
		return 1 + max(findLevelCount(_rootNode->left), findLevelCount(_rootNode->right));
	}

}

// method to print level count
void GatorTree::printLevelCount(Node *_rootNode) {
	treeHeight = findLevelCount(_rootNode);
	cout << findLevelCount(_rootNode) << endl;
}


// method to inorder traverse through tree
void GatorTree::inOrder(Node *_rootNode, vector<string> &traversalVector) {
	if (_rootNode) {
		inOrder(_rootNode->left, traversalVector);
		traversalVector.push_back(_rootNode->studentName);
		inOrder(_rootNode->right, traversalVector);
	}
}

// method to inorder traverse through tree, but return a vector of nodes
void GatorTree::inOrderNodes(Node *_rootNode, vector<Node *> &traversalVector) {
	if (_rootNode == nullptr) {
		NULL;
	} else {
		inOrderNodes(_rootNode->left, traversalVector);
		traversalVector.push_back(_rootNode);
		inOrderNodes(_rootNode->right, traversalVector);
	}
}

// Post Order
void GatorTree::postOrder(Node *_rootNode, vector<string> &traversalVector) {
	if (_rootNode == nullptr) {
		NULL;
	} else {
		postOrder(_rootNode->left, traversalVector);
		postOrder(_rootNode->right, traversalVector);
		traversalVector.push_back(_rootNode->studentName);
	}
}

// Pre Order
void GatorTree::preOrder(Node *_rootNode, vector<string> &traversalVector) {
	if (_rootNode == nullptr) {
		NULL;
	} else {
		traversalVector.push_back(_rootNode->studentName);
		preOrder(_rootNode->left, traversalVector);
		preOrder(_rootNode->right, traversalVector);
	}
}

// Print Methods
void GatorTree::printInOrder(Node *_rootNode) {
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

// METHODS FOR PRINTING
void GatorTree::printPreOrder(Node *_rootNode) {
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

void GatorTree::printPostOrder(Node *_rootNode) {
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

// Method to search for student's name and print all IDs under the same name in preorder
int GatorTree::searchID(Node *_rootNode, string name, int &isValid) {
	// Use isValid to check if the name exists, if not, it will return 0 (passed on to checker method)
	if (_rootNode == nullptr) {
		return 0;
	}
	if (_rootNode->studentName == name) {
		cout << _rootNode->gatorId << endl;
		++isValid;
	}

	searchID(_rootNode->left, name, isValid);

	searchID(_rootNode->right, name, isValid);

	return isValid;
}

// checker: if condition is 0, then the name does not exist.
int GatorTree::existChecker(int condition) {
	if (condition == 0) {
		cout << "unsuccessful" << endl;
	}
	return 0;
}

// Method to search for name
int GatorTree::searchName(Node *_rootNode, int _id, int &isValid) {
	if (_rootNode == nullptr) {
		return 0;
	}
	if (_rootNode->gatorId == _id) {
		cout << _rootNode->studentName << endl;
		++isValid;
	}

	searchName(_rootNode->left, _id, isValid);

	searchName(_rootNode->right, _id, isValid);

	return isValid;
}

// Method to Remove In Order
void GatorTree::removeInOrder(Node *_rootNode, int N) {
	vector<Node *> traversal;
	inOrderNodes(_rootNode, traversal);
	if (N < traversal.size()) {
		removeID(_rootNode, traversal[N]->gatorId);
	} else {
		cout << "unsuccessful\n";
	}

}

// Rotate Left
Node *GatorTree::rotateLeft(Node *_rootNode) {
	Node *right = _rootNode->right;
	_rootNode->right = right->left;
	right->left = _rootNode;
	return right;
}


// Rotate Right
Node *GatorTree::rotateRight(Node *_rootNode) {
	Node *left = _rootNode->left;
	_rootNode->left = left->right;
	left->right = _rootNode;
	return left;
}

// Rotate left right
Node *GatorTree::rotateLeftRight(Node *_rootNode) {
	_rootNode->left = rotateLeft(_rootNode->left);
	_rootNode = rotateRight(_rootNode);
	return _rootNode;
}

// Rotate right left
Node *GatorTree::rotateRightLeft(Node *_rootNode) {
	_rootNode->right = rotateRight(_rootNode->right);
	_rootNode = rotateLeft(_rootNode);
	return _rootNode;
}

// Method to find the balance factor
int GatorTree::returnBalanceFactor(Node *_rootNode) {
	if (_rootNode == nullptr) {
		return 0;
	} else {
		return findLevelCount(_rootNode->left) - findLevelCount(_rootNode->right);
	}
}

// Balance GatorTree
Node *GatorTree::balanceTree(Node *_rootNode) {
	int balanceFactor = returnBalanceFactor(_rootNode);
	int rightBalanceFactor = returnBalanceFactor(_rootNode->right);
	int leftBalanceFactor = returnBalanceFactor(_rootNode->left);
	// If tree is right heavy
	if (balanceFactor <= -2) {

		// If right subtree is left heavy
		if (rightBalanceFactor >= 1) {
			// Perform RIGHT LEFT rotation
			_rootNode = rotateRightLeft(_rootNode);
		} else {
			// Perform LEFT rotation
			_rootNode = rotateLeft(_rootNode);
		}


	}
		// If tree is left heavy
	else if (balanceFactor >= 2) {
		// If left subtree is right heavy
		if (leftBalanceFactor <= -1) {
			// Perform LEFT RIGHT rotation
			_rootNode = rotateLeftRight(_rootNode);

		} else {
			// Perform RIGHT rotation
			_rootNode = rotateRight(_rootNode);
		}

	}
	return _rootNode;
}