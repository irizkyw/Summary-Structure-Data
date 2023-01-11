#include <iostream>

typedef struct VertexT* AdrNodeT;

struct VertexT {
	AdrNodeT left;
	int info;
	AdrNodeT right;
};

void initT(AdrNodeT& root);
AdrNodeT allocNodeT(int data_baru);
void insertNodeT(AdrNodeT& root, AdrNodeT data_baru);
void deleteNodeT(AdrNodeT& root, int target_delete);

void preOrder(AdrNodeT root);
void inOrder(AdrNodeT root);
void postOrder(AdrNodeT root);

void descendantOfNode(AdrNodeT root, int target);
void ascendantOfNode(AdrNodeT root, int target);

AdrNodeT findNodeT(AdrNodeT root, int target);
int depthOfNode(AdrNodeT root, int target);
int levelOfNode(AdrNodeT root, int target);
int heightOfTree(AdrNodeT root);

int leaf(AdrNodeT root);