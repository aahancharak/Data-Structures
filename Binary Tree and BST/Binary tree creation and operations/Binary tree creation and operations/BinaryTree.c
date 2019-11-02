#include<stdio.h>
#include<stdlib.h>
# pragma warning(disable :4996);

typedef struct node {
	char data;
	struct node* lc;
	struct node* rc;
}NODE;

NODE *insert(char c[], int n) {
	NODE *tree = NULL;
	if (c[n] != '\0') {
		tree = (NODE*)malloc(sizeof(NODE));
		tree->lc = insert(c, 2 * n + 1);
		tree->data = c[n];
		tree->rc = insert(c, 2 * n + 2);
	}
	return tree;
}
void inorder(NODE *tree) {
	if (tree != NULL) {
		inorder(tree->lc);//In inorder left child is always displayed first,then parent,then right child
		printf("\n %c\n", tree->data);
		inorder(tree->rc);
	}

}
void postorder(NODE* tree) {
	if (tree != NULL) {
		postorder(tree->lc);//In postorder left child is always displayed first,then right,then parent node
		postorder(tree->rc);
		printf("\n %c\n", tree->data);
		
	}

}
void preorder(NODE* tree) {
	if (tree != NULL) {
		printf("\n %c\n", tree->data);
		preorder(tree->lc);//In preorder parent node is always displayed first
		preorder(tree->rc);
		

	}

}
void main() {
	printf("\n Welcome to the binary trees programme made by me\n");
	NODE *tree = NULL;
	char c[] = { 'A','B','C','D','E','\0', 'F','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	tree = insert(c, 0);
	int ch;
	printf("\nWelcome to the traverselvilla\n");
	printf("\n");
	while (1) {
		printf("\n Here are your choices \n");
		printf("\n 1> Inorder traversal\n");
		printf("\n 2> Post Order traversal \n");
		printf("\n 3> Pre Order traversal \n");
		printf("\n 4> Exit \n");
		scanf("%d", &ch);
		printf("\n");
		switch (ch) {
		case 1:
			printf("\n In order traversal\n");
			inorder(tree);
			printf("\n");
			break;
		case 2:
			printf("\n Post order traversal\n");
			postorder(tree);
			printf("\n");
			break;
		case 3:
			printf("\n Pre Order traversal\n");
			preorder(tree);
			printf("\n");
			break;
		case 4:
			exit(0);
		default:
			printf("\n Invalid choice please enter choice again\n");
			break;
			


		}
	}

 }