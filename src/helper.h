#include "tree.h"
#include <limits>
#pragma once

//Separate the first command and check if there are anything left after it
pair<string, bool> getFirstWord(const string& str) {
    // Find the position of the first space character
    size_t pos = str.find(' ');

    // If no space is found, return the whole string
    if (pos == string::npos) {
        return make_pair(str, false);
    }

    // Return the first word and indicate there's something left in the string
    return make_pair(str.substr(0, pos), true);
}

//Run the command
void runInput(GatorTree& tree ,string command) {
    auto check = getFirstWord(command);
    string method = check.first;
    bool notEmpty = check.second;

    if (method == "insert" && notEmpty) {
        // Insert command
        string restCommand = command.substr(method.length() + 1);
        size_t firstQuotePos = restCommand.find('"');
        size_t secondQuotePos = restCommand.find('"', firstQuotePos + 1);
        bool valid = true;
        if (firstQuotePos == std::string::npos) {
            cout << "unsuccessful" << endl;
            valid = false;
        } else if (secondQuotePos == std::string::npos) {
            cout << "unsuccessful" << endl;
            valid = false;
        }
        if (valid) {
            string name = restCommand.substr(firstQuotePos + 1, secondQuotePos - firstQuotePos - 1);
            string id = restCommand.substr(secondQuotePos + 2, restCommand.length() - 1);
            if (id.find_first_not_of("0123456789") == string::npos) {
                // Valid format
                int temp = 0;
                int temp2 = 0;
                for (char ch : name) {
                    if (isalpha(ch) == 0) {
                        temp++;
                    }
                } 
                for (char ch : name) {
                    if (isspace(ch) == 0) {
                        temp2++;
                    }
                }
                if (temp != 0 && temp2 != 0) {
                    cout << "unsuccessful" << endl;

                } else {
                    int gatorId = stoi(id);
                    tree.insertAllocatedRoot(gatorId, name);
                }
            }  
        }
    } else if (method == "remove" && notEmpty) {
        string restCommand = command.substr(method.length() + 1);
        // Remove command
        if (restCommand.find_first_not_of("0123456789") == string::npos) {
            int id = stoi(restCommand);
            tree.removeAllocatedRoot(id);
        } else {
            cout << "unsuccessful" << endl;
        }
        
    } else if (method == "search") {      // Search command
        string restCommand = command.substr(method.length() + 1);

        //Check if search by name or ID
        if (restCommand.find_first_not_of("0123456789") == string::npos) {
            // Search by ID
            int id = stoi(restCommand);
            int isValid = 0;
            tree.searchID(tree.rootNode, id, isValid);
            tree.existChecker(isValid);
        } else if (restCommand.front() == '"' && restCommand.back() == '"') {
            // Search by NAME
            string name = restCommand.substr(1, restCommand.size() - 2); // Remove quotes
            int temp = 0;
            int temp2 = 0;
            for (char ch : name) {
                if (isalpha(ch) == 0) {
                    temp++;
                }
            } 
            for (char ch : name) {
                if (isspace(ch) == 0) {
                    temp2++;
                }
            }
            if (temp != 0 && temp2 != 0) {
                cout << "unsuccessful" << endl;

            } else {
                int isValid = 0;
                tree.searchName(tree.rootNode, name, isValid);
                tree.existChecker(isValid);
            }
            
        } else {
            cout << "unsuccessful" << endl;
        }
    } else if (method == "printInorder" && !notEmpty) {
        // Print inorder command
        tree.printInOrder(tree.rootNode);
    } else if (method == "printPreorder" && !notEmpty) {
        // Print preorder command
        tree.printPreOrder(tree.rootNode);
    } else if (method == "printPostorder" && !notEmpty) {
        // Print postorder command
        tree.printPostOrder(tree.rootNode);
    } else if (method == "printLevelCount" && !notEmpty) {
        // Print level count command
        tree.printLevelCount(tree.rootNode);
    } else if (method == "removeInorder") {
        // Remove by inorder traversal index
        string restCommand = command.substr(method.length() + 1);
        if (restCommand.find_first_not_of("0123456789") == string::npos) {
            int N = stoi(restCommand);
            tree.removeInOrder(tree.rootNode, N);
        } else {
            cout << "unsuccessful" << endl;
        }
    } else {
        cout << "unsuccessful" << endl;
    }
}