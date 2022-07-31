//
//  VatTu.h
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 04/07/2022.
//

#ifndef VatTu_h
#define VatTu_h

#include "BaseHeader.h"


int amount = 0;

typedef struct {

	char maVT[10];
	char tenVT[20];
	char donViTinh[10];
	char soLuongTon[10];

	string toString() {
		string str = "";
		str.append(maVT);
		str.append(tenVT);
		str.append(donViTinh);
		str.append(soLuongTon);
		return str + "\n";
	}

	bool operator == (const VatTu& vatTu) const {
		return string(maVT) == string(vatTu.maVT);
	}
	bool operator > (const VatTu& vatTu)
	{
		return string(maVT) > string(vatTu.maVT);
	}
	bool operator < (const VatTu& vatTu)
	{
		return string(maVT) < string(vatTu.maVT);
	}
} VatTu;

struct VatTuNode {
	VatTu data;
	NodePtr left, * right;
};

typedef NodePtr NodePtr;


void initalize(NodePtr& root, int& amount)
{
	amount = 0;
	root = NULL;
}

// Create a node with data
NodePtr newNode(VatTu item) {
	NodePtr temp = (NodePtr)malloc(sizeof(NodePtr));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}


//Traverse and print data
void inorder(NodePtr& root) {
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
NodePtr insert(NodePtr& node, VatTu data) {
	// Return a new node if the tree is empty
	if (node == NULL) return newNode(data);

	// Traverse to the right place and insert the node
	if (data > node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	return node;
}

// Find min node
NodePtr minValueNode(NodePtr node) {
	NodePtr current = node;

	// Find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

// Find max node
NodePtr maxValueNode(NodePtr node) {
	NodePtr current = node;

	// Find the rightmost leaf
	while (current && current->right != NULL)
		current = current->right;

	return current;
}


NodePtr findNodeByMaVT(NodePtr root, char maVT[11])
{
	NodePtr node = root;
	while (node != NULL && strcmp(node->data.maVT, maVT) != 0)
	{
		if (strcmp(node->data.maVT, maVT) < 0)
			node = node->right;
		else if (strcmp(node->data.maVT, maVT) > 0)
			node = node->left;
	}
	return node;
}

// Deleting a node
NodePtr deleteNode(NodePtr& root, VatTu data) {
	// Return if the tree is empty
	if (root == NULL) return root;

	// Find the node to be deleted
	if (data < root)
		root->left = deleteNode(root->left, data);
	else if (data > root->data)
		root->right = deleteNode(root->right, data);
	else {
		// If the node is with only one child or no child
		if (root->left == NULL) {
			NodePtr temp = root->right;
			//giai phong bo nho da duoc cap phat bang malloc
			free(root);
			amount--;
			return temp;
		}
		else if (root->right == NULL) {
			NodePtr temp = root->left;
			free(root);
			amount--;
			return temp;
		}

		// If the node has two children
		NodePtr temp = minValueNode(root->right);

		// Place the inorder successor in position of the node to be deleted
		root->data = temp->data;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

void loadFile(NodePtr& root, int& amount)
{
	initalize(root, amount);
	ifstream vatTuData;
	vatTuData.open("VatTu.txt", ios::in);
	vatTuData >> amount;
	vatTuData.ignore();
	//logs << CountM << endl;
	for (int i = 0; i < amount; i++)
	{
		VatTu vatTu;
		vatTuData.getline(vatTu.maVT, sizeof(vatTu.maVT));
		vatTuData.getline(vatTu.tenVT, sizeof(vatTu.tenVT));
		vatTuData.getline(vatTu.donViTinh, sizeof(vatTu.donViTinh));
		vatTuData.getline(vatTu.soLuongTon, sizeof(vatTu.soLuongTon));
		root = insert(root, vatTu);
	}
	//logs << "finish" << endl;
	vatTuData.close();
}

#endif /* VatTu_h */
