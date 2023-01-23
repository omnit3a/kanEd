* kanEd Documentation
# kanEd is licensed under the BSD 2-clause license

kanEd is a line-based text editor, similar to the unix text editor 'ed(1)'.

* Basic functionality
kanEd is modal in nature, having five modes. The modes available to the user are:
- Command Mode:
  Enter other modes and write current file/quit kanEd
- Append Mode:
  Add text to the end of the current file
- Edit Mode:
  Edit specific lines in the current file
- Delete mode:
  Remove specifc lines from the current file
- Insert mode:
  Insert lines between already written lines in the current file

There are also several commands that do not enter modes, but still have functionality, those being:
- `list`
  List off all lines in the current file
- `cat`
  List off all lines in the current file within a specific range
- `quit`
  Exit kanEd
- `shell`
  Allow for the execution of commands in the current user's shell

To enter Append, Edit, Delete mode or Insert mode, type "append", "edit", "delete" or "insert" respectively while within Command mode.
To exit Edit mode or Delete mode, type "." when prompted for a line number.
To exit Append mode or Insert mode, type "." on its own while entering text.
