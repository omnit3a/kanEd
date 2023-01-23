#ifndef INPUT_H_
#define INPUT_H_

#define BUFFER_LINE_AMOUNT 26000
#define BUFFER_LINE_SIZE 80
#define DELIM "\n"

extern char fileBuffer[BUFFER_LINE_AMOUNT * BUFFER_LINE_SIZE];
extern char lineBuffer[BUFFER_LINE_AMOUNT][BUFFER_LINE_SIZE];
extern char inputBuffer[BUFFER_LINE_SIZE];
extern char commandBuffer[BUFFER_LINE_SIZE];
extern int currentLineNumber;
extern int amountOfLines;

void readToFileBuffer();
void readToLineBuffer();
char * getCurrentLineText();
char * getLineText(int lineNumber);

void getStringFromUser();
void promptUser(char * prompt);

int isInputNumber();

#endif
