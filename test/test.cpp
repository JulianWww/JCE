#include <iostream>
#include <jce/binarySearchTree.hpp>

int main(int argc, char **argv) {
    jce::BinarySearchTree<size_t> tree({});
    tree.insert(100);
    std::cout << tree.contains(99) << std::endl;
    return 1;
}