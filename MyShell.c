#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 1024
#define SPACES " \n"

int main(int argc, char *argv[]) {
	char line[MAX_LENGTH];
	char *cmd;
	char *prompt = "SUPER SHELL! ";

		while(1){
			printf(prompt);
			if (!fgets(line, MAX_LENGTH, stdin)) break;
			
			//parse and execute commands
			
			if((cmd = strtok(line, SPACES))){
			// clean errors
			errno =0;
	
			if (strcasecmp(cmd, "quit") == 0) {
			break;
			}
			
			else if((strcasecmp(cmd, "Set") == 0)) {
			cmd = strtok(NULL, SPACES);
			if (strcasecmp(cmd, "Prompt") == 0) {
			char *arg = strtok(NULL, SPACES);
			if (!arg)
			 fprintf(stderr, "You were missing a prompt.\n");
			
			else prompt= arg;
			}
			}
			else system(line);
	
			}

			}	
	
return 0;
}

