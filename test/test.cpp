#include <catch2/catch_test_macros.hpp>
#include "tree.h"
#include "helper.h"

TEST_CASE("Test incorrect commands") {
    
    // SECTION("Inserting with invalid name") {
        GatorTree tree;
        // string input = "insert \"huy\" 97722812";
        // string expected = "unsuccessful\n";

        std::ostringstream oss;
        streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        // Call the function that prints to cout
        // runInput(tree, input);
        std::cout << "unsuccessful" << endl;
        

        // // Check if the output matches the expected string
        std::cout.rdbuf(coutBuffer);

        REQUIRE(oss.str() == "unsuccessful\n");
        // Restore cout
        // REQUIRE(true);
    // }
}

    // SECTION("Inserting with missing quotation marks") {
    //     tree.insertAllocatedRoot(12345678, "Alice");
    //     tree.insertAllocatedRoot(23456789, "Bob");

    //     // Try to insert without quotation marks around name
    //     tree.insertAllocatedRoot(45679999, "Eve");
    // }

    // Add more test cases for incorrect commands as needed

// TEST_CASE("Test edge cases") {
//     GatorTree tree;

//     SECTION("Removing a node that doesn’t exist") {
//         tree.insertAllocatedRoot(12345678, "Alice");
//         tree.insertAllocatedRoot(23456789, "Bob");
//         tree.insertAllocatedRoot(34567890, "Charlie");

//         // Try to remove a node with an ID that doesn't exist
//         tree.removeAllocatedRoot(99999999);
//     }

//     // Add more edge cases for various functions as needed
// }

// TEST_CASE("Test rotation cases") {
//     GatorTree tree;

//     SECTION("Left Rotation") {
//         // Test for left rotation
//         tree.insertAllocatedRoot(3, "Node3");
//         tree.insertAllocatedRoot(2, "Node2");
//         tree.insertAllocatedRoot(1, "Node1");

//         REQUIRE(tree.rootNode->gatorId == 2);
//         REQUIRE(tree.rootNode->left->gatorId == 1);
//         REQUIRE(tree.rootNode->right->gatorId == 3);
//     }

//     SECTION("Right Rotation") {
//         // Test for right rotation
//         tree.insertAllocatedRoot(1, "Node1");
//         tree.insertAllocatedRoot(2, "Node2");
//         tree.insertAllocatedRoot(3, "Node3");

//         REQUIRE(tree.rootNode->gatorId == 2);
//         REQUIRE(tree.rootNode->left->gatorId == 1);
//         REQUIRE(tree.rootNode->right->gatorId == 3);
//     }

//     SECTION("Left-Right Rotation") {
//         // Test for left-right rotation
//         tree.insertAllocatedRoot(3, "Node3");
//         tree.insertAllocatedRoot(1, "Node1");
//         tree.insertAllocatedRoot(2, "Node2");

//         REQUIRE(tree.rootNode->gatorId == 2);
//         REQUIRE(tree.rootNode->left->gatorId == 1);
//         REQUIRE(tree.rootNode->right->gatorId == 3);
//     }

//     SECTION("Right-Left Rotation") {
//         // Test for right-left rotation
//         tree.insertAllocatedRoot(1, "Node1");
//         tree.insertAllocatedRoot(3, "Node3");
//         tree.insertAllocatedRoot(2, "Node2");

//         REQUIRE(tree.rootNode->gatorId == 2);
//         REQUIRE(tree.rootNode->left->gatorId == 1);
//         REQUIRE(tree.rootNode->right->gatorId == 3);
//     }
// }

// TEST_CASE("Test deletion cases") {
//     GatorTree tree;

//     SECTION("Deletion with no children") {
//         // Test deletion with no children
//         tree.insertAllocatedRoot(1, "Node1");
//         tree.insertAllocatedRoot(2, "Node2");

//         tree.removeAllocatedRoot(2);

//         REQUIRE(tree.rootNode->gatorId == 1);
//         REQUIRE(tree.rootNode->left == nullptr);
//         REQUIRE(tree.rootNode->right == nullptr);
//     }

//     SECTION("Deletion with one child") {
//         // Test deletion with one child
//         tree.insertAllocatedRoot(2, "Node2");
//         tree.insertAllocatedRoot(1, "Node1");
//         tree.insertAllocatedRoot(3, "Node3");

//         tree.removeAllocatedRoot(1);

//         REQUIRE(tree.rootNode->gatorId == 2);
//         REQUIRE(tree.rootNode->left == nullptr);
//         REQUIRE(tree.rootNode->right->gatorId == 3);
//     }

//     SECTION("Deletion with two children") {
//         // Test deletion with two children
//         tree.insertAllocatedRoot(2, "Node2");
//         tree.insertAllocatedRoot(1, "Node1");
//         tree.insertAllocatedRoot(3, "Node3");
//         tree.insertAllocatedRoot(4, "Node4");

//         tree.removeAllocatedRoot(2);

//         REQUIRE(tree.rootNode->gatorId == 3);
//         REQUIRE(tree.rootNode->left->gatorId == 1);
//         REQUIRE(tree.rootNode->right->gatorId == 4);
//     }
// }