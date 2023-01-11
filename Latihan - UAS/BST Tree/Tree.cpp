#include "Tree.h"

using namespace std;

void initT(AdrNodeT& root) {
	root = NULL;
}
AdrNodeT allocNodeT(int data_baru) {
	AdrNodeT allocT = new VertexT;
	allocT->left = NULL;
	allocT->info = data_baru;
	allocT->right = NULL;
	return allocT;
}

void insertNodeT(AdrNodeT& root, AdrNodeT data_baru) {
	if (root == NULL) root = data_baru;
	else {
		if (data_baru->info < root->info)
			insertNodeT(root->left, data_baru);
		else
			insertNodeT(root->right, data_baru);
	}
}
void deleteNodeT(AdrNodeT& root, int target_delete) {
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			root = NULL;
		}
		else if (root->left == NULL) {
			AdrNodeT temp = root;
			root = root->right;
			temp = NULL;
		}
		else if (root->right == NULL) {
			AdrNodeT temp = root;
			root = root->left;
			temp = NULL;
		}
		else {
			AdrNodeT temp = root;
			while (temp->left != NULL) temp = temp->left;
			root->info = temp->info;
			deleteNodeT(root->right, temp->info);
		}
	}
}

void preOrder(AdrNodeT root) {
	if (root != NULL) {
		cout << root->info << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(AdrNodeT root) {
	if (root != NULL) {
		inOrder(root->left);
		cout << root->info << " ";
		inOrder(root->right);
	}
}
void postOrder(AdrNodeT root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->info << " ";
	}
}

void descendantOfNode(AdrNodeT root, int target) {
	if (root != NULL) {
		AdrNodeT find = findNodeT(root, target);
		if (find != NULL) {
			preOrder(find->left);
			preOrder(find->right);
		}
	}
}

void ascendantOfNode(AdrNodeT root, int target) {
	if (root != NULL) {
		if (target < root->info) {
			cout << root->info << " ";
			ascendantOfNode(root, target);
		}
		else {
			cout << root->info << " ";
			ascendantOfNode(root, target);
		}
	}
}

AdrNodeT findNodeT(AdrNodeT root, int target) {
	if (root == NULL) return NULL;
	if (root->info == target) return root;

	AdrNodeT left = findNodeT(root->left, target);
	if (left != NULL) return left;

	AdrNodeT right = findNodeT(root->right, target);
	if (right != NULL) return right;

	return NULL;
}

int depthOfNode(AdrNodeT root, int target) {
	if (root != NULL) {
		if (target < root->info)
			return 1 + depthOfNode(root->left, target);
		else
			return 1 + depthOfNode(root->left, target);
	}
	return 0;
}

int levelOfNode(AdrNodeT root, int target) {
	return depthOfNode(root,target) + 1;
}
int heightOfTree(AdrNodeT root) {
	if (root != NULL) {
		int left = heightOfTree(root->left);
		int right = heightOfTree(root->right);

		if (left < right)
			return left + 1;
		else
			return right + 1;
	}
	return 0;
}

int leaf(AdrNodeT root) {
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			return leaf(root) + 1;
		}
	}
	return 0;
}