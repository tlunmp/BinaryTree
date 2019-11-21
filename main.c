#include "stdio.h"
#include "errno.h"
#include "ctype.h"
#include "node.h"
#include "tree.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
	
	const int SIZE = 1000;
	char input[SIZE];
	char *inputList[SIZE];
	int indexList = 0;
	int counter = 0;

	FILE *fInorder;
	FILE *fPreorder;
	FILE *fPostorder;

	inputList[0] = malloc(sizeof(char));
		
	if (argc > 2) {
		fprintf(stderr, "Error too much argument\n");
		return 0;
	} 
	
	if (argc == 2) {

		int size = 0;

		char *fileNameInorder;
		fileNameInorder = malloc(strlen(argv[1]) + 1);
		strcpy(fileNameInorder, argv[1]);
		strcat(fileNameInorder, ".inorder");		
	

		char *fileNamePreorder;
		fileNamePreorder = malloc(strlen(argv[1]) + 1);
		strcpy(fileNamePreorder, argv[1]);
		strcat(fileNamePreorder, ".preorder");		
	

		char *fileNamePostorder;
		fileNamePostorder = malloc(strlen(argv[1]) + 1);
		strcpy(fileNamePostorder, argv[1]);
		strcat(fileNamePostorder, ".postorder");		
		
		size_t len = strlen(argv[1]);
		FILE *file = fopen(strcat(argv[1], ".fs182"), "r");
		argv[len] = '\0';
	
		if (file == NULL) {
		
			perror("Error opening file");
			return 0;		
		}else {
	 		fseek (file, 0, SEEK_END);

	         	size = ftell (file);
		         rewind(file);
			 if(size == 0) {
				
				fprintf(stderr, "Error: The File is Empty\n");
				return 0;
			}

		}
		
		while(fgets(input, sizeof(input), file)){
		
			size_t len1;
			len1 = strlen(input);
			int m;
				
				for (m = 0; m < len1; m++) {
					if(isspace(input[m])) {		
						if(isalpha(input[m+1]) && isupper(input[m+1])) {
							input[m+1] = tolower(input[m+1]);
						}
						inputList[indexList][counter] = '\0';
						counter = 0;
						indexList++;
						inputList[indexList] = malloc(sizeof(char));
					} else {
						inputList[indexList][counter] = input[m];
						counter++;
					}
	
				}
		}
	
		fInorder = fopen(fileNameInorder, "w+");
		fPreorder = fopen(fileNamePreorder, "w+");
		fPostorder = fopen(fileNamePostorder, "w+");
		
		fclose(file);

	} 
	
	if (argc == 1){
	
		while(fgets(input, sizeof(input), stdin))
		{
			size_t len = strlen(input);
			int i;
			for(i=0; i < len; i++) {	

					if(isspace(input[i]) && !isspace(input[i+1])) {			
						if(isalpha(input[i+1]) && isupper(input[i+1])) {
							input[i+1] = tolower(input[i+1]);
						}
						inputList[indexList][counter] = '\0';
						counter = 0;
						indexList++;
						inputList[indexList] = malloc(sizeof(char));
					}	 

					if(!isspace(input[i])){
						inputList[indexList][counter] = input[i];
						counter++;
					}
			}			
		}

		fInorder = fopen("out.inorder", "w+");
		fPreorder = fopen("out.preorder", "w+");
		fPostorder = fopen("out.postorder", "w+");
	}


	//check if there is duplicates and remove it.
	int m;
	for(m=0; m < indexList; m++)
	{
		int n;
		for(n=m+1; n < indexList; n++ ){
			if(strcmp(inputList[m],inputList[n]) == 0) {
				inputList[n][0] = '\0';
			}
		}	

	}

	//build the binary search tree
	struct node *root = buildTree(inputList,indexList);


	traverseInorder(root,0,fInorder);
	traversePreorder(root,0,fPreorder);
	traversePostorder(root,0,fPostorder);


	//freeing the malloc
	int j;
	for(j=0; j < indexList; j++) {
		free(inputList[j]);
	}

	fclose(fInorder);
	fclose(fPreorder);
	//fclose(fPostorder);
	
	return 0;
}
