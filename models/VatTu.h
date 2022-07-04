//
//  VatTu.h
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 04/07/2022.
//

#ifndef VatTu_h
#define VatTu_h

#include <stdio.h>
#include <string>
#include <iostream>

#define MA_VAT_TU_SIZE 10
#define MA_VAT_TU "Ma Vat Tu"
#define TEN_VAT_TU "Ten Vat Tu"
#define DON_VI_TINH "Don Vi Tinh"
#define SO_LUONG_TON "So Luong Ton"

using namespace std;

class VatTu{
    
public:
    string maVT;
    string tenVT;
    string donViTinh;
    int soLuongTon;
    
    VatTu(){}
    
    string toString(){
        return "Ma Vat Tu: " + this->maVT + "\n" +
                "Ten Vat Tu: " + this->tenVT + "\n" +
                "Don Vi Tinh: " + this->donViTinh + "\n" +
                "So Luong Ton: " + to_string(this->soLuongTon) + "\n";
    }
};

struct VatTuNode {
    VatTu data;
    struct VatTuNode *left, *right;
};

// Create a node with data
struct VatTuNode *newNode(VatTu item) {
    struct VatTuNode *temp = (struct VatTuNode *)malloc(sizeof(struct VatTuNode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

//Traverse and print data
void inorder(struct VatTuNode *root) {
    if (root != NULL) {
        // Traverse left
        inorder(root->left);
        
        // Traverse root
        cout << root->data.toString() << " -> ";
        
        // Traverse right
        inorder(root->right);
    }
}

// Insert a node
struct VatTuNode *insert(struct VatTuNode *node, VatTu data) {
    // Return a new node if the tree is empty
    if (node == NULL) return newNode(data);
    
    // Traverse to the right place and insert the node
    if (data.maVT.compare(node->data.maVT) < 0)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    
    return node;
}

// Find min node
struct VatTuNode *minValueNode(struct VatTuNode *node) {
    struct VatTuNode *current = node;
    
    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
    
    return current;
}

// Find max node
struct VatTuNode *maxValueNode(struct VatTuNode *node) {
    struct VatTuNode *current = node;
    
    // Find the rightmost leaf
    while (current && current->right != NULL)
        current = current->right;
    
    return current;
}

// Deleting a node
struct VatTuNode *deleteNode(struct VatTuNode *root, VatTu data) {
    // Return if the tree is empty
    if (root == NULL) return root;
    
    // Find the node to be deleted
    if (data.maVT.compare(root->data.maVT) < 0)
        root->left = deleteNode(root->left, data);
    else if (data.maVT.compare(root->data.maVT) > 0)
        root->right = deleteNode(root->right, data);
    else {
        // If the node is with only one child or no child
        if (root->left == NULL) {
            struct VatTuNode *temp = root->right;
            //giai phong bo nho da duoc cap phat bang malloc
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct VatTuNode *temp = root->left;
            free(root);
            return temp;
        }
        
        // If the node has two children
        struct VatTuNode *temp = minValueNode(root->right);
        
        // Place the inorder successor in position of the node to be deleted
        root->data = temp->data;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

#endif /* VatTu_h */
