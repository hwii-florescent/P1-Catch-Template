// #include <catch2/catch_test_macros.hpp>
// #include "tree.h"
// #include "helper.h"

// TEST_CASE("Test incorrect commands") {
//     GatorTree tree;
//     SECTION("Inserting with invalid name") {
//         string input = "insert \"b0b\" 12345678";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "unsuccessful\n");
//     }

//     SECTION("Use invalid command") {
//         string input = "unknown command";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "unsuccessful\n");
//     }

//     SECTION("Remove with name but not id") {
//         string input = "remove \"Mike\"";
//         runInput(tree, "insert \"Mike\" 12345678");
//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "unsuccessful\n");
//     }

//     SECTION("Print but has value behind it") {
//         string input = "printPostorder 123456";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "unsuccessful\n");
//     }

//     SECTION("Insert but no names no id") {
//         string input = "insert";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "unsuccessful\n");
//     }
// }
// TEST_CASE("Test edge cases") {
//     GatorTree tree;

//     SECTION("Search when the tree is empty") {
//         string input = "search 97722812";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "unsuccessful\n");
//     }

//     SECTION("Print traversal when tree is empty") {
//         string input = "printPreorder";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "");
//     }

//     SECTION("Remove Inorder when tree is empty") {
//         string input = "removeInorder 2";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "unsuccessful\n");
//     }
// }

// TEST_CASE("Test rotation cases") {
//     GatorTree tree;

//     SECTION("Left Rotation") {
//         // Test for left rotation
//         runInput(tree, "insert \"Mark\" 10000000");
//         runInput(tree, "insert \"Hexto\" 10000001");
//         runInput(tree, "insert \"Lily\" 10000002");

//         REQUIRE(tree.rootNode->gatorId == 10000001);
//         REQUIRE(tree.rootNode->left->gatorId == 10000000);
//         REQUIRE(tree.rootNode->right->gatorId == 10000002);
//     }

//     SECTION("Right Rotation") {
//         // Test for right rotation
//         runInput(tree, "insert \"Mark\" 10000002");
//         runInput(tree, "insert \"Hexto\" 10000001");
//         runInput(tree, "insert \"Lily\" 10000000");

//         REQUIRE(tree.rootNode->gatorId == 10000001);
//         REQUIRE(tree.rootNode->left->gatorId == 10000000);
//         REQUIRE(tree.rootNode->right->gatorId == 10000002);
//     }

//     SECTION("Left-Right Rotation") {
//         // Test for left-right rotation
//         runInput(tree, "insert \"Mark\" 10000002");
//         runInput(tree, "insert \"Hexto\" 10000000");
//         runInput(tree, "insert \"Lily\" 10000001");

//         REQUIRE(tree.rootNode->gatorId == 10000001);
//         REQUIRE(tree.rootNode->left->gatorId == 10000000);
//         REQUIRE(tree.rootNode->right->gatorId == 10000002);
//     }

//     SECTION("Right-Left Rotation") {
//         // Test for right-left rotation
//         runInput(tree, "insert \"Mark\" 10000000");
//         runInput(tree, "insert \"Hexto\" 10000002");
//         runInput(tree, "insert \"Lily\" 10000001");

//         REQUIRE(tree.rootNode->gatorId == 10000001);
//         REQUIRE(tree.rootNode->left->gatorId == 10000000);
//         REQUIRE(tree.rootNode->right->gatorId == 10000002);
//     }
// }

// TEST_CASE("Test deletion cases") {
//     GatorTree tree;

//     SECTION("Deletion with no children") {
//         runInput(tree, "insert \"Her\" 123456789");
//         string input = "remove 123456789";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "successful\n");
//     }

//     SECTION("Deletion with one child") {
//         runInput(tree, "insert \"Her\" 123456789");
//         runInput(tree, "insert \"Hism\" 234567890");

//         string input = "remove 123456789";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "successful\n");
//     }

//     SECTION("Deletion with two children") {
//         runInput(tree, "insert \"Her\" 123456789");
//         runInput(tree, "insert \"Hism\" 234567890");
//         runInput(tree, "insert \"Hassan\" 334567890");


//         string input = "remove 234567890";

//         std::ostringstream buffer;
//         std::streambuf* coutBuffer = std::cout.rdbuf();
//         std::cout.rdbuf(buffer.rdbuf());

//         // Print something to std::cout
//         runInput(tree, input);

//         // Get the captured string
//         std::string capturedOutput = buffer.str();

//         // Restore cout
//         std::cout.rdbuf(coutBuffer);

//         // Call the function that prints to cout
//         REQUIRE(capturedOutput == "successful\n");
//     }
// }

// TEST_CASE("Insert and Remove Multiple Nodes", "[Tree]") {
//     Tree tree;
//     std::srand(std::time(nullptr)); // Seed for random generation
//     std::vector<int> ids(100);
//     std::iota(ids.begin(), ids.end(), 1); // Fill ids with 1 to 100

//     // Insert nodes
//     for (int id : ids) {
//         tree.insertAllocatedRoot(id, "Student" + std::to_string(id));
//     }

//     // Shuffle ids and remove 10 random nodes
//     std::random_shuffle(ids.begin(), ids.end());
//     for (int i = 0; i < 10; ++i) {
//         tree.removeAllocatedRoot(ids[i]);
//     }

//     // Check in order - assuming inOrder function correctly fills traversalVector
//     std::vector<std::string> traversalVector;
//     tree.inOrder(tree.root, traversalVector);
//     REQUIRE(traversalVector.size() == 90);
//     std::cout << "Insert and Remove Multiple Nodes passed.\n";
//     // More detailed checks can be added here, such as verifying the contents of traversalVector
// }
