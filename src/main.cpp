#include "tree.h"
#include "helper.h"
int main() {
    //Create the AVL tree
    GatorTree tree;   

    //Take in the number that determine the number of commands
    int num;
    cin >> num;
    cin.ignore(); // Ignore the newline character after reading the number of commands

    // Process each command
    for (int i = 0; i < num; ++i) {
        string command;
        getline(cin, command);
        runInput(tree, command);
    }
	return 0;
}
