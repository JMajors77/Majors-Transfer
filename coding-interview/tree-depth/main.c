#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 5

typedef struct Node {
	int val;
	int numChildren;
	struct Node** children;
} Node;

int maxDepth(Node* root);
Node* createNode(int val, int numChildren);

int main(int argc, char** argv){
	Node* root = createNode(1, 3);
	
	root->children[0] = createNode(3, 2);
	root->children[0]->children[0] = createNode(5, 0);
	root->children[0]->children[1] = createNode(6, 0);

	root->children[1] = createNode(2, 0);

	root->children[2] = createNode(4, 0);

	printf("%d\n", maxDepth(root));
}

int maxDepth(Node* root){
	if(root == NULL)
	{
		return 0;
	}

	int currMaxDepth = 1;
	for(int i = 0; i < root->numChildren; i++)
	{
		int depth = maxDepth(root->children[i]) + 1;	// +1 for the current node
		if(depth > currMaxDepth)
		{
			currMaxDepth = depth;
		}
	}
	return currMaxDepth;
}

Node* createNode(int val, int numChildren)
{
	Node* rtn = malloc(sizeof(Node));
	rtn->val = val;
	rtn->children = malloc(sizeof(Node*) * numChildren);
	rtn->numChildren = numChildren;

	return rtn;
}