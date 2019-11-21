#ifndef TREE_H
#define TREE_H
#include <stdio.h>

struct node *newNode(char item[]);
struct node *buildTree(char *word[], int count);

void traverseInorder(struct node *root,int level, FILE *f);
void traversePreorder(struct node *root,int level, FILE *f);
void traversePostorder(struct node *root,int level, FILE *f);

int insertTheSame(struct node *root,char key[]);
struct node* insertNotTheSame(struct node* node, char key[]);
struct node* insertToTree(struct node* node, char key[]);

#endif
