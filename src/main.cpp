#include "tree.h"
#include <limits>

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    GatorTree tree;   

    int numCommands;
    cin >> numCommands;
    cin.ignore(); // Ignore the newline character after reading the number of commands

    // Process each command
    for (int i = 0; i < numCommands; ++i) {
        string command;
        getline(cin, command);

        vector<string> tokens = split(command, ' ');

        if (tokens[0] == "insert" && tokens.size() == 3) {
            // Insert command: insert NAME ID
            if (tokens[1].size() > 2 && tokens[1].front() == '"' && tokens[1].back() == '"' && tokens[2].find_first_not_of("0123456789") == string::npos) {
                // Valid format
                string name = tokens[1].substr(1, tokens[1].size() - 2); // Remove quotes
                int id = stoi(tokens[2]);
                tree.insertAllocatedRoot(id, name);
            } else {
                cout << "unsuccessful" << endl;
            }
        } else if (tokens[0] == "remove" && tokens.size() == 2) {
            // Remove command: remove ID
            int id = stoi(tokens[1]);
            tree.removeAllocatedRoot(id);
        } else if (tokens[0] == "search" && tokens.size() == 2) {
            // Search command: search ID/NAME
            if (tokens[1].find_first_not_of("0123456789") == string::npos) {
                // Search by ID
                int id = stoi(tokens[1]);
                int isValid = 0;
                tree.searchName(tree.rootNode, id, isValid);
                if (isValid == 0) {
                    cout << "unsuccessful" << endl;
                }
            } else if (tokens[1].size() > 2 && tokens[1].front() == '"' && tokens[1].back() == '"') {
                // Search by NAME
                string name = tokens[1].substr(1, tokens[1].size() - 2); // Remove quotes
                int isValid = 0;
                tree.searchID(tree.rootNode, name, isValid);
                if (isValid == 0) {
                    cout << "unsuccessful" << endl;
                }
            } else {
                cout << "unsuccessful" << endl;
            }
        } else if (tokens[0] == "printInorder" && tokens.size() == 1) {
            // Print inorder command
            tree.printInOrder(tree.rootNode);
        } else if (tokens[0] == "printPreorder" && tokens.size() == 1) {
            // Print preorder command
            tree.printPreOrder(tree.rootNode);
        } else if (tokens[0] == "printPostorder" && tokens.size() == 1) {
            // Print postorder command
            tree.printPostOrder(tree.rootNode);
        } else if (tokens[0] == "printLevelCount" && tokens.size() == 1) {
            // Print level count command
            tree.printLevelCount(tree.rootNode);
        } else if (tokens[0] == "removeInorder" && tokens.size() == 2) {
            // Remove by inorder traversal index: removeInorder N
            int N = stoi(tokens[1]);
            tree.removeInOrder(tree.rootNode, N);
        } else {
            cout << "unsuccessful" << endl;
        }
    }
	return 0;
}
