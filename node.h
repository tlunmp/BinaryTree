#ifndef NODE_H
#define NODE_H

#define STRSIZE 50
#define CHARSIZE 300

struct node {

	char word[STRSIZE][CHARSIZE];
	struct node *left, *right;
	int counts;
};

#endif 

