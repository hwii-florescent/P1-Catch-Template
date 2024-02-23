#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#pragma once

using namespace std;

struct Node {       //create Struct for Nodes
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

    GatorTree() : rootNode(nullptr) {}      //constructor
    ~GatorTree() {      //default destructor
        if (rootNode != nullptr) {
            deleteTree(rootNode);    
        }
    }
    void deleteTree(Node *_rootNode);       //destructor

    Node *insert(Node *_rootNode, int _id, string _name);       //insert method and balance the tree
    Node *getInorderSuccessor(Node *rightSubNode);          //go through the bottom left from a node
    Node *removeID(Node *_rootNode, int _id);       //remove a node through the id
    void insertAllocatedRoot(int _id, string _name);        //call the insert method and the findLevelCount to store the tree height
    void removeAllocatedRoot(int _id);      //call the remove method and the findLevelCount to store the tree height
    int findLevelCount(Node *_rootNode);    //traverse through the tree to find the level of the tree
    void printLevelCount(Node *_rootNode);      //print out the tree's height
    void inOrder(Node *_rootNode, vector<string> &traversalVector);     //traverse through all the nodes and store the name in inorder traversal
    void inOrderNodes(Node *_rootNode, vector<Node *> &traversalVector);        //traverse through all the nodes and store the Node object in inorder traversal
    void postOrder(Node *_rootNode, vector<string> &traversalVector);       //traverse through all the nodes and store the name in postorder traversal
    void preOrder(Node *_rootNode, vector<string> &traversalVector);        //traverse through all the nodes and store the name in preorder traversal
    void printInOrder(Node *_rootNode);     //print the node in in order traversal
    void printPreOrder(Node *_rootNode);    //print the node in pre order traversal
    void printPostOrder(Node *_rootNode);   //print the node in post order traversal
    int searchName(Node *_rootNode, string name, int &isValid);     //search the node by name and print out the id
    int existChecker(int condition);    //check if search method find anything, print out unsuccessful otherwise
    int searchID(Node *_rootNode, int _id, int &isValid);   //search the node by ID and print out the name
    void removeInOrder(Node *_rootNode, int N);     //remove the Nth ID from in order traversal
    Node *rotateLeft(Node *_rootNode);      //tree left rotation
    Node *rotateRight(Node *_rootNode);     //right rotation
    Node *rotateLeftRight(Node *_rootNode);     //left-right rotation
    Node *rotateRightLeft(Node *_rootNode);     //right-left rotation
    int returnBalanceFactor(Node *_rootNode);       //check the level to find balance factor
    Node *balanceTree(Node *_rootNode);     //balance the tree
};