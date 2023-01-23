#include <stdio.h>
#include <input.h>
#include <string.h>
#include <main.h>
#include <ctype.h>

char fileBuffer[BUFFER_LINE_AMOUNT * BUFFER_LINE_SIZE];
char lineBuffer[BUFFER_LINE_AMOUNT][BUFFER_LINE_SIZE];
char inputBuffer[BUFFER_LINE_SIZE];
char commandBuffer[BUFFER_LINE_SIZE];
int currentLineNumber = 0;
int amountOfLines = 0;

void readToFileBuffer(){
  int currentPosition = 0;
  char currentChar;

  fseek(sourceFile, 0, SEEK_END);
  int size = ftell(sourceFile);

  if (size == 0){
    fprintf(sourceFile, "(filled empty file)\n"); 
  }
  rewind(sourceFile);

  while ((currentChar = getc(sourceFile)) != EOF){
    fileBuffer[currentPosition++] = currentChar;
  }
}

void readToLineBuffer(){
  readToFileBuffer();
  
  int currentLine = 0;
  char * tempToken;
  char currentToken[BUFFER_LINE_SIZE];
  strcpy(currentToken, strtok(fileBuffer, DELIM));
  strcat(currentToken, "\n");
  strcpy(lineBuffer[currentLine++], currentToken);
  
  while(currentLine < BUFFER_LINE_AMOUNT){
    char * tempToken = strtok(NULL, DELIM);
    if (tempToken != NULL){
      strcpy(currentToken, tempToken);
      if (currentToken != NULL){
	strcat(currentToken, "\n");
	strcpy(lineBuffer[currentLine++], currentToken);
      }
    } else {
      strcpy(lineBuffer[currentLine++], "");
    }
  }

  amountOfLines = currentLine;
}

char * getCurrentLineText(){
  char * returnValue = lineBuffer[currentLineNumber];
  return returnValue;
}

char * getLineText(int lineNumber){
  char * returnValue = lineBuffer[lineNumber];
  return returnValue;
}

void getStringFromUser(){
  fgets(inputBuffer, sizeof(inputBuffer), stdin);
}

void promptUser(char * prompt){
  printf("%s", prompt);
  fgets(inputBuffer, sizeof(inputBuffer), stdin);
}

int isInputNumber(){
  inputBuffer[strcspn(inputBuffer, "\n")] = 0;
  for (int i = 0 ; i < strlen(inputBuffer) ; i++){
    if (!isdigit(inputBuffer[i])){
      return 0;
    }
  }
  return 1;
}
