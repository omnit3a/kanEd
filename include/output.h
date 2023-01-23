#ifndef OUTPUT_H_
#define OUTPUT_H_

#define COMMAND_MODE_PROMPT ": "

extern char commandStrings[8][16];

void writeBufferToFile();
void fixGapsInBuffer(int gap);

void execSystemCommand(char * command);

void insertLine(int lineNumber);

#endif
