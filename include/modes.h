#ifndef MODES_H_
#define MODES_H_

#define COMMAND_MODE "command mode"
#define APPEND_MODE "append mode"
#define EDIT_MODE "edit mode"
#define LIST_MODE "list mode"
#define DELETE_MODE "delete mode"
#define INSERT_MODE "insert mode"

extern char * currentMode;

char * getCurrentMode();
void setMode(char * newMode);

#endif
