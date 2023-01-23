#include <modes.h>
#include <stdio.h>
#include <input.h>
#include <stdlib.h>
#include <unistd.h>
#include <output.h>
#include <string.h>
#include <commands.h>

#define MINIMUM_ARGS 2
#define MAXIMUM_ARGS 3

FILE * sourceFile;
char * sourceFilename;

int main(int argc, char ** argv){

  int tempLine = 0;
  
  if (argc < MINIMUM_ARGS){
    fprintf(stderr, "kanEd: must provide a working filename\n");
    exit(1);
  } else if (argc >= MAXIMUM_ARGS){
    fprintf(stderr, "kanEd: only one file may be edited at once\n");
    exit(1);
  } else {
    sourceFilename = argv[1];
    if (access(sourceFilename, F_OK) == 0){
      sourceFile = fopen(sourceFilename, "r+");
      if (sourceFile == NULL){
	perror("kanEd");
	exit(1);
      }
      // read contents of file
      readToLineBuffer();
    } else {
      perror("kanEd");
      exit(1);
    }
  }

  int currentCommand = 0;
  int catStart = 0;
  int catEnd = 0;
  
  while (strcmp(commandBuffer, QUIT_CMD) != 0){
    if (strcmp(currentMode, COMMAND_MODE) == 0){
      promptUser(COMMAND_MODE_PROMPT);
      strcpy(commandBuffer, inputBuffer);

      if (strcmp(commandBuffer, APPEND_CMD) == 0){
	setMode(APPEND_MODE);
	continue;
      } else if (strcmp(commandBuffer, EDIT_CMD) == 0){
	setMode(EDIT_MODE);
	continue;
      } else if (strcmp(commandBuffer, DELETE_CMD) == 0){
	setMode(DELETE_MODE);
	continue;
      } else if (strcmp(commandBuffer, LIST_CMD) == 0){
	tempLine = 0;
	while (strcmp(lineBuffer[tempLine], "") != 0){
	  printf("%d | %s", tempLine, lineBuffer[tempLine++]);
	}
	
      } else if (strcmp(commandBuffer, CAT_CMD) == 0){

	strcpy(inputBuffer, "test");
	while (!isInputNumber()){
	  promptUser("starting line: ");
	}
	catStart = (atoi(inputBuffer) - 1) % BUFFER_LINE_AMOUNT;
	strcpy(inputBuffer, "test");
	while (!isInputNumber()){
	  promptUser("ending line: ");
	}
	catEnd = (atoi(inputBuffer) - 1) % BUFFER_LINE_AMOUNT;
	tempLine = catStart;
	
	while (strcmp(lineBuffer[tempLine], "") != 0 && tempLine <= catEnd){
	  printf("%d | %s", tempLine, lineBuffer[tempLine++]);
	}
	
      } else if (strcmp(commandBuffer, QUIT_CMD) == 0){
	break;
      } else {
	printf("?\n");
      }
    } else if (strcmp(currentMode, APPEND_MODE) == 0){
      getStringFromUser();
      if (strcmp(inputBuffer, COMMAND_CMD) == 0){
	setMode(COMMAND_MODE);
	readToLineBuffer();
	continue;
      }
      fprintf(sourceFile, "%s", inputBuffer);
      readToLineBuffer();
    } else if (strcmp(currentMode, EDIT_MODE) == 0){
      getStringFromUser();
      if (strcmp(inputBuffer, COMMAND_CMD) == 0){
	setMode(COMMAND_MODE);
	writeBufferToFile();
	continue;
      }
      strcpy(lineBuffer[currentLineNumber++], inputBuffer);
    } else if (strcmp(currentMode, DELETE_MODE) == 0){
      strcpy(inputBuffer, "test");
      while (!isInputNumber()){
	promptUser("line to delete: ");
	if (strcmp(inputBuffer, COMMAND_CMD) == 0){
	  setMode(COMMAND_MODE);
	  break;
	}
      }
      if (strcmp(inputBuffer, COMMAND_CMD) == 0){
	continue;
      }
      tempLine = (atoi(inputBuffer)-1) % BUFFER_LINE_AMOUNT;
      strcpy(lineBuffer[tempLine], "");
      fixGapsInBuffer(tempLine);
    }
  }
  
  fclose(sourceFile);
  
  return 0;
}
