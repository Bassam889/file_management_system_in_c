# File Management System

This project is a file management system written in C. It allows users to perform various file operations such as creating, reading, writing, appending, and deleting files. The system also supports listing all files in a specified directory.

## Features

- **Create a File**: Allows users to create a new file.

- **Write to a File**: Overwrites content in a file.

- **Append to a File**: Adds content to the end of an existing file.

- **Read a File**: Reads and displays the content of a file.

- **Delete a File**: Deletes a specified file.

- **List Files**: Lists all files in a given directory.

- **Exit**: Exits the program.

## How It Works

The program displays a menu with options for each file operation. Users can select an option by entering the corresponding number. Based on the user’s input, the program performs the requested operation.

## Example menu

```bash
File Management System
1. Create a file
2. Write to a file
3. Read from a file
4. Edit a file
5. Delete a file
6. List files
7. Exit
Enter your choice: 
```

## Instructions

### Prerequisites

- A C compiler (e.g., GCC)

- Basic knowledge of the command line

### Compilation

To compile the program, run the following command in your terminal:

```bash
gcc -o file_management file_management.c
```

### Running the program

After compiling, you can run the program using:

```bash
./file_management
```

### Example Usage

1. Create a File

- Select option 1 from the menu.

- Enter the filename when prompted.

2. Write to a File

- Select option 2.

- Enter the filename and the content to write.

3. Read from a File

- Select option 3.

- Enter the filename to view its content.

4. Append to a File

- Select option 4.

- Enter the filename and the content to append.

5. Delete a File

- Select option 5.

- Enter the filename to delete it.

6. List Files

- Select option 6.

- Enter the directory path to list all files within.

7. Exit

- Select option 7 to exit the program.

## Code Overview

The program uses standard C libraries like stdio.h and stdlib.h for input/output operations and file handling. Each operation is implemented as a function for modularity and clarity. Error handling is included to ensure robust behavior.

## Example Output

```bash
File Management System
1. Create a file
2. Write to a file
3. Read from a file
4. Edit a file
5. Delete a file
6. List files
7. Exit
Enter your choice: 6
Enter directory path: /home/user/project
Files in directory '/home/user/project':
- file1.txt
- file2.c
- file3.log
```

## Future Improvements

- Add support for subdirectories.

- Include search functionality to find specific files.

- Improve error messages for better user experience.

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute it as per the terms of the license.

