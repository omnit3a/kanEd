#include <stdio.h>
#include <output.h>
#include <string.h>
#include <commands.h>
#include <main.h>
#include <input.h>

char commandStrings[8][16] = {
  COMMAND_CMD,
  APPEND_CMD,
  EDIT_CMD,
  LIST_CMD,
  DELETE_CMD,
  CAT_CMD,
  WRITE_CMD,
  QUIT_CMD
};

void writeBufferToFile(){
  int currentLine = 0;
  char tempBuffer[BUFFER_LINE_AMOUNT * BUFFER_LINE_SIZE] = "";

  sourceFile = freopen(sourceFilename, "w", sourceFile);
  
  for (int i = 0 ; i < BUFFER_LINE_AMOUNT; i++){
    if (strcmp(lineBuffer[i], "") == 0 ){
      break;
    }
    strcat(tempBuffer, lineBuffer[i]);
  }
  
  fprintf(sourceFile, "%s", tempBuffer);
  
}

void fixGapsInBuffer(int gap){
  
  for (int i = gap ; i < BUFFER_LINE_AMOUNT ; i++){
    strcpy(lineBuffer[i], lineBuffer[i+1]);
  }
  writeBufferToFile();
}
