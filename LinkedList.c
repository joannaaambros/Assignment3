#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ENGLISH
//#define FRENCH

#define DELIM " \n"

struct words
{
	char value[300];
	struct word *next;
};

typedef struct words linkedlist;

int main(){
	char input[300]; // getting user input
	char *tok;

	linkedlist *head = NULL;
	linkedlist *prev = NULL;
	linkedlist *curr;

	#ifdef ENGLISH 
	printf("Welcome to the infinite string storage program.\n");
	#else
	printf("Bonjour au programme");
	#endif

	while(1){

		#ifdef ENGLISH
		printf("Please enter a word: \n");
		#else
		printf("S'il vous plait un mot: \n");
		#endif
		
		//read user inputinto an array
		fgets(input, sizeof(input), stdin);

		tok = strtok(input, DELIM);
		
		//checking if token is end word
		if((strcmp(tok, "***END***")) == 0){
			curr=head; //starting from the beginning
			while(curr != NULL){
				printf("%s ", curr->value); //printf current word
				curr=curr->next;
				}
				printf("\n");
				break;
			}
			else{
				curr=(linkedlist *)malloc(sizeof(linkedlist)); //allocating memory for current word

				if(head == NULL) {
				head = curr;
				}
				if(tok != NULL) {
					strcpy(curr->value, tok); //copying token into value of current node
					}
				if(prev != NULL) {//if theres over a single word
					prev-> next = curr;
				}
				prev = curr;
				}
			}
		return 0;
		}

		

