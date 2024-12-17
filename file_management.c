#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

void create_file(const char *filename);
void write_file(const char *filename, const char *content);
void read_file(const char *filename);
void append_file(const char *filename, const char *content);
void delete_file(const char *filename);
void list_files(const char *directory);

int main() {

  int choice;
  char filename[100], content[256], directory[100];

  while (1) {
    printf("\nFile management System\n");
    printf("1. Create a file\n");
    printf("2. Write to a file\n");
    printf("3. Read from a file\n");
    printf("4. Edit a file\n");
    printf("5. Delete a file\n");
    printf("6. List files\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter filename: ");
      scanf("%99s", filename);
      create_file(filename);
      break;
    case 2:
      printf("Enter your filename: ");
      scanf("%99s", filename);
      getchar(); // Clear newline
      printf("Enter content: ");
      fgets(content, sizeof(content), stdin);
      write_file(filename, content);
      break;
    case 3:
      printf("Enter your filename: ");
      scanf("%99s", filename);
      read_file(filename);
      break;
    case 4:
      printf("Enter your filename: ");
      scanf("%99s", filename);
      getchar();
      printf("Enter content: ");
      fgets(content, sizeof(content), stdin);
      append_file(filename, content);
      break;
    case 5:
      printf("Enter your filename : ");
      scanf("%99s", filename);
      delete_file(filename);
      break;
    case 6:
      printf("Enter directory path: ");
      scanf("%99s", directory);
      list_files(directory);
      break;
    case 7:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice, Try again.\n");
    }
  }
  return 0;
}

void create_file(const char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error creating a file");
    return;
  }
  printf("File %s created successfully.\n", filename);
  fclose(file);
}

void write_file(const char *filename, const char *content) {

  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error opening file");
    return;
  }
  fprintf(file, "%s\n", content);
  printf("content written to %s.\n", filename);
  fclose(file);
}

void read_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  char buffer[8000];

  if (file == NULL) {
    printf("Error finding file");
  } else {
    printf("File %s was found.\n", filename);
    while (fgets(buffer, 8000, file) != NULL) {
      printf("%s", buffer);
    }
  }
  fclose(file);
}

void delete_file(const char *filename) {
  if (remove(filename) == 0) {
    printf("File %s was deleted successfully.\n", filename);
  } else {
    printf("File was not deleted because it's not found.\n");
  }
}

void list_files(const char *directory) {
  DIR *dir = opendir(directory);
  if (dir == NULL) {
    printf("Error opening directory");
    return;
  }

  struct dirent *entry;
  printf("FIles in directory '%s':\n", directory);
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) {
      printf("- %s\n", entry->d_name);
    }
  }

  closedir(dir);
}

void append_file(const char *filename, const char *content) {
  FILE *file = fopen(filename, "a");
  if (file == NULL) {
    printf("Error opening file '%s' for appending.\n", filename);
    return;
  }

  fprintf(file, "%s\n", content);
  printf("Content appended to file '%s'.\n", filename);
  fclose(file);
}
