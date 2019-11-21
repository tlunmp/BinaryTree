#include "stdio.h"
#include "stdlib.h"
#include "node.h"
#include "string.h"
#include "tree.h"

struct node *newNode(char item[]) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->counts=0;
	strcpy(temp->word[(temp->counts)++],item);
	temp->left = temp->right = NULL;
	return temp;
}

struct node *buildTree(char *word[], int count){

	struct node *root = NULL;		
	int j;
	for(j=0; j < count; j++) {
		if(!word[j][0] == '\0') {
			if(root == NULL) {
				root = insertToTree(root, word[j]);
			} else {
				insertToTree(root, word[j]);

			}
		}
	}
	return root;
}

void traverseInorder(struct node *root,int level,FILE *f) {

	if (root != NULL) {
		traverseInorder(root->left,level+1,f);	
		int i;
	
		int j;
		for(j=0; j < level*2; j++) {
			fprintf(f," ");
		}
		
		for(i=0;i<root->counts;i++) {
			fprintf(f,"%s ", root->word[i]);
		}	

		fprintf(f,"\n");

		traverseInorder(root->right,level+1,f);
	}
}

void traversePreorder(struct node *root,int level,FILE *f) {

if (root != NULL) {

	int j;
	for(j=0; j < level*2; j++) {
		fprintf(f, " ");
	}

	int i;
	for(i=0;i<root->counts;i++) {
    		fprintf(f,"%s ",root->word[i]);
    	}

	fprintf(f,"\n");

	traversePreorder(root->left,level+1,f);

	traversePreorder(root->right,level+1,f);

	}
}

void traversePostorder(struct node *root,int level, FILE *f) {

	if (root != NULL) {

		traversePostorder(root->left,level+1,f);

		traversePostorder(root->right,level+1,f);

		int j;
		for(j=0; j < level*2; j++) {
			fprintf(f, " ");
		}
	
		int i;
		for(i=0;i<root->counts;i++) {
			fprintf(f, "%s ", root->word[i]);
		}

		fprintf(f, "\n");
	}

}

int insertTheSame(struct node *root,char key[]) {

	if (root != NULL) {

		insertTheSame(root->left,key);	

		int asciiConvertRoot = (int)root->word[0][0];
		int asciiConvertKey  = (int)key[0];
		
/*
		if(root->word[0][0] == key[0]) {
			strcpy(root->word[(root->counts)++],key);
			return 0;
		}
*/		if(asciiConvertRoot == asciiConvertKey) {
			strcpy(root->word[(root->counts)++],key);
			return 0;
		}

		insertTheSame(root->right,key);

	}

	return -1;

}

struct node* insertNotTheSame(struct node* node, char key[]) {

	if (node == NULL) {
		return newNode(key);
	}

	int asciiConvertNode = (int)node->word[0][0];
	int asciiConvertKey  = (int)key[0];

/*
	if (key[0] < node->word[0][0]) {

		node->left = insertNotTheSame(node->left, key);

	} else if (key[0] > node->word[0][0]){
	
	
		node->right = insertNotTheSame(node->right, key);

	}
*/	
	if (asciiConvertKey < asciiConvertNode) {

		node->left = insertNotTheSame(node->left, key);

	} else if (asciiConvertKey > asciiConvertNode){

		node->right = insertNotTheSame(node->right, key);

	}
	return node;

}

struct node* insertToTree(struct node* node, char key[]) {

	if(insertTheSame(node,key)==0) {
		return NULL;
	}
	else {

		return insertNotTheSame(node,key);
	}
}
