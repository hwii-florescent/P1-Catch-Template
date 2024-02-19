#include "tree.h"


int main() {
    // GatorTree tree;   

    // // Inserting some nodes into the tree
    // tree.insertAllocatedRoot(45679999, "Brandon");
    // tree.insertAllocatedRoot(35459999, "Brian");
    // tree.insertAllocatedRoot(87879999, "Briana");
    // tree.insertAllocatedRoot(95469999, "Bella");


    // // Printing the inorder traversal of the tree
    // cout << "Inorder Traversal: ";
    // tree.printInOrder(tree.rootNode);

    // tree.removeAllocatedRoot(45679999);
    // tree.printInOrder(tree.rootNode);

    // tree.removeInOrder(tree.rootNode, 2);
    // tree.printInOrder(tree.rootNode);

    // int numCommands;
    // cin >> numCommands;
    // cin.ignore(); // Ignore the newline character after reading the number of commands

    // // Process each command
    // for (int i = 0; i < numCommands; ++i) {
    //     string command;
    //     getline(cin, command);

    //     // Parse the command
    //     stringstream ss(command);
    //     string operation;
    //     ss >> operation;

    //     if (operation == "insert") {
    //         string name;
    //         int id;
    //         ss.ignore(1); // Ignore the space after "insert"
    //         ss.ignore(1, '"'); // Ignore the opening double quote
    //         getline(ss, name, '"'); // Read the name
    //         ss >> id; // Read the ID
    //         tree.insertAllocatedRoot(id, name);
    //     } else if (operation == "remove") {
    //         int id;
    //         ss >> id;
    //         tree.removeAllocatedRoot(id);
    //     } else if (operation == "removeInorder") {
    //         int N;
    //         ss >> N;
    //         tree.removeInOrder(tree.rootNode, N);
    //     } else if (operation == "printInorder") {
    //         cout << "Inorder Traversal: ";
    //         tree.printInOrder(tree.rootNode);
    //     } else {
    //         cout << "Invalid command: " << operation << endl;
    //     }
    // }
	return 0;
}
