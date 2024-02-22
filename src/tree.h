#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#pragma once

using namespace std;
struct Node {
    int gatorId;
    string studentName;
    Node* left;
    Node* right;
    int height;

    Node(int id, const string& name) : gatorId(id), studentName(name), left(nullptr), right(nullptr), height(1) {}
};

class GatorTree {
public:
    Node *rootNode;
    int treeHeight;

    GatorTree() : rootNode(nullptr) {}

    ~GatorTree() {
        deleteTree(rootNode);
    }

    // Destructor for the GatorTree
    void deleteTree(Node *_rootNode);

    // Insertion method - based on lecture slides
    Node *insert(Node *_rootNode, int _id, string _name);
    Node *getInorderSuccessor(Node *rightSubNode);
    Node *removeID(Node *_rootNode, int _id);
    void insertAllocatedRoot(int _id, string _name);
    void removeAllocatedRoot(int _id);
    int findLevelCount(Node *_rootNode);
    void printLevelCount(Node *_rootNode);
    void inOrder(Node *_rootNode, vector<string> &traversalVector);
    void inOrderNodes(Node *_rootNode, vector<Node *> &traversalVector);
    void postOrder(Node *_rootNode, vector<string> &traversalVector);
    void preOrder(Node *_rootNode, vector<string> &traversalVector);
    void printInOrder(Node *_rootNode);
    void printPreOrder(Node *_rootNode);
    void printPostOrder(Node *_rootNode);
    int searchID(Node *_rootNode, string name, int &isValid);
    int existChecker(int condition);
    int searchName(Node *_rootNode, int _id, int &isValid);
    void removeInOrder(Node *_rootNode, int N);
    Node *rotateLeft(Node *_rootNode);
    Node *rotateRight(Node *_rootNode);
    Node *rotateLeftRight(Node *_rootNode);
    Node *rotateRightLeft(Node *_rootNode);
    int returnBalanceFactor(Node *_rootNode);
    Node *balanceTree(Node *_rootNode);
};