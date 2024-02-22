#include "tree.h"
#include <limits>
#pragma once

//Support function to split the command to take in input and put in a vector
vector<string> split(const string& command, char delimiter) {
    vector<string> result;
    stringstream inp(command);
    string elm;
    while (getline(inp, elm, delimiter)) {
        result.push_back(elm);
    }
    return result;
}

void runInput(GatorTree& tree ,string command) {
    vector<string> inp = split(command, ' ');

    if (inp[0] == "insert" && inp.size() == 3) {
        // Insert command
        if (inp[1].size() > 2 && inp[1].front() == '"' && inp[1].back() == '"' && inp[2].find_first_not_of("0123456789") == string::npos) {
            // Valid format
            string name = inp[1].substr(1, inp[1].size() - 2); // Remove quotes
            if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) {
                int id = stoi(inp[2]);
                tree.insertAllocatedRoot(id, name);
            } else {
                cout << "unsuccessful" << endl;
            }
            
        } else {
            cout << "unsuccessful" << endl;
        }
    } else if (inp[0] == "remove" && inp.size() == 2) {
        // Remove command
        if (inp[1].find_first_not_of("0123456789") == string::npos) {
            int id = stoi(inp[1]);
            tree.removeAllocatedRoot(id);
        } else {
            cout << "unsuccessful" << endl;
        }
        
    } else if (inp[0] == "search" && inp.size() == 2) {
        // Search command
        if (inp[1].find_first_not_of("0123456789") == string::npos) {
            // Search by ID
            int id = stoi(inp[1]);
            int isValid = 0;
            tree.searchName(tree.rootNode, id, isValid);
            tree.existChecker(isValid);
        } else if (inp[1].size() > 2 && inp[1].front() == '"' && inp[1].back() == '"') {
            // Search by NAME
            string name = inp[1].substr(1, inp[1].size() - 2); // Remove quotes
            if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) {
                int isValid = 0;
                tree.searchID(tree.rootNode, name, isValid);
                tree.existChecker(isValid);
            } else {
                cout << "unsuccessful" << endl;
            }
        } else {
            cout << "unsuccessful" << endl;
        }
    } else if (inp[0] == "printInorder" && inp.size() == 1) {
        // Print inorder command
        tree.printInOrder(tree.rootNode);
    } else if (inp[0] == "printPreorder" && inp.size() == 1) {
        // Print preorder command
        tree.printPreOrder(tree.rootNode);
    } else if (inp[0] == "printPostorder" && inp.size() == 1) {
        // Print postorder command
        tree.printPostOrder(tree.rootNode);
    } else if (inp[0] == "printLevelCount" && inp.size() == 1) {
        // Print level count command
        tree.printLevelCount(tree.rootNode);
    } else if (inp[0] == "removeInorder" && inp.size() == 2) {
        // Remove by inorder traversal index
        if (inp[1].find_first_not_of("0123456789") == string::npos) {
            int N = stoi(inp[1]);
            tree.removeInOrder(tree.rootNode, N);
        } else {
            cout << "unsuccessful" << endl;
        }
    } else {
        cout << "unsuccessful" << endl;
    }
}