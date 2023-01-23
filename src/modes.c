#include <stdio.h>
#include <modes.h>
#include <string.h>
#include <main.h>
#include <input.h>
#include <stdlib.h>

char * currentMode = COMMAND_MODE;

char * getCurrentMode(){
  return currentMode;
}

void setMode(char * newMode){
  currentMode = newMode;
  if (strcmp(currentMode, COMMAND_MODE) == 0){
    printf("now in command mode\n");
    sourceFile = freopen(sourceFilename, "r", sourceFile);
    
  } else if (strcmp(currentMode, APPEND_MODE) == 0){
    printf("now appending lines\n");
    sourceFile = freopen(sourceFilename, "a", sourceFile);
    
  } else if (strcmp(currentMode, EDIT_MODE) == 0){
    printf("now editing lines\n");
    sourceFile = freopen(sourceFilename, "r+", sourceFile);
    strcpy(inputBuffer, "test");
    while (!isInputNumber()){
      promptUser("start line: ");
    }
    currentLineNumber = (atoi(inputBuffer)-1) % BUFFER_LINE_AMOUNT;
    
  } else if (strcmp(currentMode, DELETE_MODE) == 0){
    printf("now in delete mode\n");
    sourceFile = freopen(sourceFilename, "r+", sourceFile);

  } else if (strcmp(currentMode, INSERT_MODE) == 0){
    printf("now inserting lines\n");
    sourceFile = freopen(sourceFilename, "r+", sourceFile);
    
  } else {
    currentMode = COMMAND_MODE;
    printf("tried to switch to non-valid mode\n");
    
  }
}
