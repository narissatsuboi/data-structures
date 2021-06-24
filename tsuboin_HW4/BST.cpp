/* @file BST.cpp
 * @author Narissa Tsuboi */
#include "BST.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
 * Constructor, CopyConstructor, AssignmentOp, Destructor
 */

template<class ItemType>
BST<ItemType>::BST() {
	root = nullptr;
}

template<class ItemType>
BST<ItemType>::BST(const BST<ItemType>& otherBST) {
    copyTree(otherBST.root);
}

template<class ItemType>
BST<ItemType>* BST<ItemType>::copyTree(Node*& ptr)
 {
    if (ptr != nullptr) {
        ItemType data = ptr->data;
        insert(new Node(data, nullptr, nullptr));
    }
}

template<class ItemType>
BST<ItemType>& BST<ItemType>::operator=(const BST<ItemType> &otherBST) {
    // TODO:: IF THE  SAME DONT COPY THIS
    destroyTree(root);
    copy(otherBST->root);
}

template<class ItemType>
BST<ItemType>::~BST() {
	destroyTree(root);
}

/* Node Constructors */

template<class ItemType>
BST<ItemType>::Node::Node() = default;

template<class ItemType>
BST<ItemType>::Node::Node( ItemType &item, BST::Node * left, BST::Node *
right) {
    this->data = item;
    this->left = left;
    this->right = right;
}

/*
 * Methods
 */

template<class ItemType>
bool BST<ItemType>::insert(ItemType item) {
    Node * newNode = new Node;
    newNode->data = item;
    newNode->left = newNode->right = nullptr;

    if(insertHelper(root, newNode))
        return true;
    else
        return false;
}

template<class ItemType>
bool BST<ItemType>::insertHelper(Node *& ptr, Node *& newNode) {
    if (ptr == nullptr) // root empty
        ptr = newNode;
    else if (ptr->data > newNode->data) //recur insert left branch
        insertHelper(ptr->left, newNode);
    else // recur insert right branch
        insertHelper(ptr->right, newNode);
    return true;
}

template<class ItemType>
bool BST<ItemType>::contains(const ItemType& key) {
    return containsHelper(root, key);
}

template<class ItemType>
bool BST<ItemType>::containsHelper(const BST::Node * ptr, const ItemType &key)
const {
    if (ptr == nullptr) // empty
        return false;
    if (ptr->data == key) // found
        return true;
    if (ptr->data > key)
        // search left subtree if the current data is in the rhs of the tree
        return containsHelper((ptr->left), key);
    else
        // search right subtree if the current data is in the lhs of the tree
        return containsHelper(ptr->right, key);
}

template<class ItemType>
bool BST<ItemType>::remove(const ItemType& item) {
    if (removeHelper(root, item))
        return true;
    else
        return false;
}

template<class ItemType>
bool BST<ItemType>::removeHelper(Node *& ptr, const ItemType& item) {
    if (ptr != nullptr) {
        if (ptr->data > item)
            removeHelper(ptr->left, item);
        else if (ptr->data < item)
            removeHelper(ptr->right, item);
        else {
            makeDeletion(ptr);
        }
        return true;
    }
    return false;
}

//template<class ItemType>
//bool BST<ItemType>::remove(const ItemType& item) {
//    if (removeHelper(root, item))
//        return true;
//    else
//        return false;
//}
//
//template<class ItemType>
//bool BST<ItemType>::removeHelper(Node *& ptr, const ItemType& item) {
//    if (ptr != nullptr) {
//        if (ptr->data > item)
//            removeHelper(ptr->left, item);
//        else if (ptr->data < item)
//            removeHelper(ptr->right, item);
//        else {
//            makeDeletion(ptr);
//        }
//        return true;
//    }
//    return false;
//}

template<class ItemType>
bool BST<ItemType>::empty() const {
    return root == nullptr;
}

template<class ItemType>
int BST<ItemType>::size() const{
    return sizeHelper(root);
}
template<class ItemType>
int BST<ItemType>::sizeHelper(const BST::Node *ptr) const {
    int leftSum, rightSum;
    if (ptr != nullptr)
    {
        leftSum = sizeHelper(ptr->left);
        rightSum = sizeHelper(ptr->right);
        return leftSum + rightSum + 1;
    }
    return 0;
}

template<class ItemType>
int BST<ItemType>::getLeafCount() const {
    return getLeafCountHelper(root);
}

template<class ItemType>
int BST<ItemType>::getLeafCountHelper(const BST::Node * ptr) const {
    if (ptr == nullptr)
        return 0;
    else if (ptr->left == nullptr && ptr->right == nullptr)
        return 1;
    return getLeafCountHelper(ptr->left) + getLeafCountHelper(ptr->right);
}

template<class ItemType>
int BST<ItemType>::getHeight() const {
    return getHeightHelper(root);
}

template<class ItemType>
int BST<ItemType>::getHeightHelper(const Node * subTreePtr) const {
    if (subTreePtr == nullptr)
        return 0;
    else
    {
        return 1 + max((getHeightHelper(subTreePtr->left)),
                       getHeightHelper(subTreePtr->right));
    }
}

template<class ItemType>
int BST<ItemType>::getLevel(const ItemType& key) const {
    int level = 1;
    return getLevelHelper(root, key, level);
}

template<class ItemType>
int BST<ItemType>::getLevelHelper(const BST::Node * ptr, const ItemType &key,
                                  int& level) const {
    const int NOT_FOUND = -1;
    if (ptr == nullptr)
        return NOT_FOUND;
    else if (ptr->data == key) // when key is found
        return level;
    else if (ptr->data > key)
    {
        // search left subtree if the current data is in the rhs of the tree
        level++;
        return getLevelHelper(ptr->left, key, level);
    }
    else
    {
        // search right subtree if the current data is in the lhs of the tree
        level++;
        return getLevelHelper(ptr->right, key, level);
    }
}

template<class ItemType>
string BST<ItemType>::getAncestors(const ItemType& key) const
{
    stringstream sso;
    getAncestorsHelper(root, key, sso);
    return sso.str();
}

template<class ItemType>
bool BST<ItemType>::getAncestorsHelper(const Node * ptr, const ItemType& key,
       stringstream& sso) const {
        if (ptr == nullptr)
            return false;
        if (ptr->data == key) // base case 2 found key
            return true;
        else if (getAncestorsHelper(ptr->left, key, sso) ||
                getAncestorsHelper(ptr->right, key, sso)) {
            sso << ptr->data << " ";
            return true;
        }
        return false;
}

/*
 * Transversals
 */

template<class ItemType>
string BST<ItemType>::getpreorderTransversal() const{
    stringstream sso;
    preorderTraversalHelper(root, sso);
    return sso.str();
}

template<class ItemType>
void BST<ItemType>::preorderTraversalHelper(BST::Node *ptr, stringstream& sso)
const {
    if (ptr != nullptr) {
        sso << ptr->data << " ";
        preorderTraversalHelper(ptr->left, sso);
        preorderTraversalHelper(ptr->right, sso);
    }
}

template<class ItemType>
string BST<ItemType>::getinorderTransversal() const {
    stringstream sso;
    inorderTraversalHelper(root, sso);
    return sso.str();
}

template<class ItemType>
void BST<ItemType>::inorderTraversalHelper(BST::Node *ptr, stringstream& sso)
const {
    if (ptr != nullptr) {
        inorderTraversalHelper(ptr->left, sso);
        sso << ptr->data << " ";
        inorderTraversalHelper(ptr->right, sso);
    }
}

template<class ItemType>
string BST<ItemType>::getpostOrderTransversal() const {
    stringstream sso;
    postorderTraversalHelper(root, sso);
    return sso.str();
}

template<class ItemType>
void BST<ItemType>::postorderTraversalHelper(BST::Node *ptr, stringstream& sso)
const {
    if (ptr != nullptr) {
        postorderTraversalHelper(ptr->left, sso);
        postorderTraversalHelper(ptr->right, sso);
        sso << ptr->data << " ";
    }
}

template<class ItemType>
void BST<ItemType>::makeDeletion(Node *& ptr) {
    Node * curr = nullptr;
    if (ptr != nullptr) {
        if (ptr->left == nullptr) {
            curr = ptr;
            ptr = ptr->right;
            delete curr;
        } else if (ptr->right == nullptr) {
            curr = ptr;
            ptr = ptr->left;
            delete curr;
        } else {
            curr = ptr->right;
            while (curr->left != nullptr)
                curr = curr->left;
            ptr->data = curr->data;
            removeHelper(ptr->right, curr->data);
        }
    }
}

template<class ItemType>
void BST<ItemType>::destroyTree(Node *&ptr) {
    if (ptr != nullptr) {
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }
    ptr = nullptr;
}











