# Holberton Shell 1.0

A simple UNIX command line interpreter developed for the Holberton School project.

## General Information

- **Editors:** vi, VScode
- **OS:** Ubuntu 20.04 LTS
- **Compiler:** gcc with options -Wall -Werror -Wextra -pedantic -std=gnu89
- **Code Style:** Betty style
- **Memory Management:** No memory leaks
- **Functions per File:** No more than 5 functions per file
- **Header Files:** Include guarded
- **System Calls:** Use only when necessary

## Features

- Displays a prompt and waits for the user to type a command.
- Displays the prompt again each time a command has been executed.
- Handles command lines with arguments.
- Handles the PATH.
- Does not call fork if the command doesn’t exist.
- Implements the exit built-in, which exits the shell.
- Implements the env built-in, which prints the current environment.

## Contributors

- Collin Ballard