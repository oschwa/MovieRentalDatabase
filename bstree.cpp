

#include <iomanip>
#include "bstree.h"

BSTree::~BSTree() {
    // Recursively delete all nodes and info within them.
    make_empty(root);
    // Set root pointer to null.
    root = nullptr;
}


void BSTree::make_empty() {
    // Call the private make_empty function with the root of the BST as a parameter.
    return make_empty(root);
}


void BSTree::make_empty(BSTree::Node *current) {

    // If the current node is not null
    if (current != nullptr) {

        // Recursively call the make_empty function for the right and left
        // children of the current node to ensure that all nodes are deleted.
        make_empty(current->right);
        make_empty(current->left);

        // Delete the info held in the current node.
        delete current->data;
        current->data = nullptr;

        // Delete the current node.
        delete current;
    }
}


void BSTree::insert(Movie* source) {
    // Calls the private helper function insert() passing the root node of the BSTree and the new Movie object to be inserted.
    // The root node will be updated as needed by the insert() function.
    root = insert(root, source);
}

BSTree::Node* BSTree::insert(BSTree::Node* current, Movie* source) {

    // If the current node is null, we've reached a leaf node and can insert the new node here.
    if (current == nullptr) {
        // Create a new node with the source info and no children.
        current = new Node(source, nullptr, nullptr);
    }
    // If the source info is less than the current node's info, traverse the left subtree.
    else if (*source < *current->data) {
        // Recursively insert the new node into the left subtree.
        current->left = insert(current->left, source);
    }
    // If the source info is greater than the current node's info, traverse the right subtree.
    else if (*source > *current->data) {
        // Recursively insert the new node into the right subtree.
        current->right = insert(current->right, source);
    }
    // If the source info is equal to the current node's info, increment the stock of the current movie
    // and delete the source info.
    else if(*source == *current->data){
        // Add the stock of the source movie to the current movie.
        current->data->set_stock(current->data->get_stock() + source->get_stock());
        // Delete the source movie to avoid memory leaks.
        delete source;
    }else{
        // This code should never be executed, but if it does, print an error message.
        cout << "ERROR: " << source->get_title() << " cannot be added." << endl;
    }

    // Return the current node.
    return current;
}


bool BSTree::retrieve(Movie* query, Movie*& result) const {
    // Calls the private helper function "retrieve" starting from the root of the binary search tree.
    return retrieve(root, query, result);
}


bool BSTree::retrieve(BSTree::Node* current, Movie* query, Movie*& result) const {

    // If current node is nullptr, the movie has not been found and the function returns false.
    if (current == nullptr) {
        return false;
    }
    // If we found a movie whose info matches the query movie, then the function returns true
    // and updates the result pointer to point to the found movie's info.
    if (*current->data == *query) {
        result = current->data;
        return true;
    }
    // If the query movie's info is greater than the current movie's info, then we search the right subtree.
    else if (*query > *current->data) {
        return retrieve(current->right, query, result);
    }
    // If the query movie's info is less than the current movie's info, then we search the left subtree.
    else {
        return retrieve(current->left, query, result);
    }
}


string BSTree::print_inorder() const{
    // Calls the private helper function print_inorder and saves the returned string.
    string inorder = print_inorder(root);
    // Calls the private helper function crear_visited_flags to reset the visited flags of all nodes in the tree.
    crear_visited_flags(root);
    // Returns the string of the BSTree printed in order.
    return inorder;
}


string BSTree::print_inorder(BSTree::Node* current) const {
    // Creates a stringstream object.
    stringstream stream;
    // If current node is not nullptr, continue to traverse.
    if (current != nullptr) {
        // Recursively call print_inorder on the left subtree and append the result to the stringstream.
        stream << print_inorder(current->left);
        // If the current node has not been visited yet.
        if(!current->visited) {
            stream.setf(ios::left);  // Set the output format flag to left-justified.
            stream << " ";  // Add initial legth spaces to the stringstream.
            stream << setw(37) << current->data->get_title();  // Add TITLELENGTH characters of
                                                                       // the movie title to the stringstream.
            stream << find_stock(root, current->data);  // Add the stock of the current movie to the stringstream.
            stream << endl;  // Add a newline character to the stringstream.
        }
        // Recursively call print_inorder on the right subtree and append the result to the stringstream.
        stream << print_inorder(current->right);
    }

    // Convert the stringstream object to a string and return it.
    return stream.str();
}


ostream& operator<<(ostream &stream, const BSTree& bst) {
    // Calls the print_inorder function to get a string representation of the BSTree in-order traversal.
    stream << bst.print_inorder();
    // Returns the output stream.
    return stream;
}


int BSTree::find_stock(Node* current, Movie*& movie) const {
    // If current node is null, the movie was not found in the BST.
    if(current == nullptr) {
        return 0;
        // If current node's info is the same as the movie's and it has not been visited before, mark it as visited
        // and return the sum of its stock plus the stock of its left and right subtrees.
    }else if((current->data->get_title() == movie->get_title()) &&
             !current->visited){

        current->visited = true;

        return current->data->get_stock() +
               (find_stock(current->left, movie) +
                find_stock(current->right, movie));
        // If current node's info is not the same as the movie's, continue searching in its left and right subtrees.
    }else {
        return (find_stock(current->left, movie) +
                find_stock(current->right, movie));

    }
}


void BSTree::crear_visited_flags(Node* current) const {
    // If this is not a leaf node.
    if(current != nullptr) {
        // Reset the "visited" flag to false for the current node.
        current->visited = false;
        // Recursively call this method on the right and left subtrees of the current node.
        crear_visited_flags(current->right);
        crear_visited_flags(current->left);
    }
}
