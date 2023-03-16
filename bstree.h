
#ifndef BST_H
#define BST_H

#include <fstream>
#include <sstream>
#include <iostream>
#include "movie.h"

using namespace std;


class BSTree {

public:
    ~BSTree();  // Destructor

    // declares a friend function that allows the BSTree class to output its
    // contents using the output stream operator <<
    friend ostream& operator<<(ostream& stream, const BSTree& bst);

    // declares a nested struct called Node that represents a node in the binary search tree.
    struct Node{
        Movie* data;
        Node* left = nullptr;
        Node* right = nullptr;
        bool visited = false;

        Node(Movie* d, Node* l, Node* r) : data(d), left(l), right(r){};
    };

    // Inserts a Movie object into the BSTree according to the Movie's "year" field value.
    void insert(Movie* source);

    // Function searches the BSTree for a node whose Movie's last_mame matches the last_mame of the input Movie. If a
    // match is found, the result parameter is updated to point to that Movie, and the function returns true. Otherwise,
    // the function returns false.
    bool retrieve(Movie* query, Movie*& result) const;

    // function goes through the BSTree and deletes every Movie object and sets the subtree to NULL.
    void make_empty();

    // prints out the BSTree in in-order traversal.
    string print_inorder() const;

private:
    // used to keep track of the first Node object that is inserted into the tree, which will serve as the root of BST.
    Node* root = nullptr;

    // Helper for insert. Recursively inserts a Movie object into the BSTree according to the Movie's "year" field value.
    Node* insert(Node* current, Movie* source);

    // Helper function for the public retrieve function. It recursively searches a subtree of the BSTree for a node
    // with a matching last_mame, and updates the result parameter and returns true if a match is found. Otherwise,
    // it returns false.
    bool retrieve(Node* current, Movie* query, Movie*& result) const;

    // Helper for the public make_empty function. It recursively goes through the binary search tree and deletes every
    // movie object and sets the subtree to NULL.
    void make_empty(Node* current);

    // Helper for the print_inorder. It recursively prints out the binary search tree in in-order traversal.
    string print_inorder(Node* current) const;

    // Declares a private helper function that finds all stock of a movie in the current.
    int find_stock(Node* current, Movie*& movie) const;

    // Declares a private helper function that resets the visited flag of all nodes in the current.
    void crear_visited_flags(Node* current) const;
};

#endif
