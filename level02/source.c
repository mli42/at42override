#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
  char **argv_bis = argv; // 0x120 - 0x114 => 12
  int argc_bis = argc; // 0x114 - 0x110 => 4
  char password[0x110 - 0xa0] = { 0 };
  char true_password[0xa0 - 0x70] = { 0 };
  char username[0x70 - 0xc];
  int size; // 0xc - 0x8 => 4
  FILE *file = NULL; // 0x8 => 8

  file = fopen("/home/users/level03/.pass", "r");
  if (file == NULL) {
    fwrite("ERROR: failed to open password file\n", 1, 0x24, stderr);
    exit(1);
  }

  size = fread(true_password, 1, 0x29, file);
  true_password[strcspn(true_password, "\n")] = '\0'; // Put \0 at first \n

  if (size != 0x29) {
    fwrite("ERROR: failed to read password file\n", 1, 0x24, stderr);
    fwrite("ERROR: failed to read password file\n", 1, 0x24, stderr);
    exit(1);
  }
  fclose(file);

  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\***************************************/");

  printf("--[ Username: ");
  fgets(username, 0x64, stdin);
  username[strcspn(username, "\n")] = '\0';

  printf("--[ Password: ");
  fgets(password, 0x64, stdin);
  password[strcspn(password, "\n")] = '\0';

  puts("*****************************************");

  if (strncmp(true_password, password, 0x29) != 0) {
    printf(username);
    puts(" does not have access!");
    exit(1);
  }
  printf("Greetings, %s!\n", username);
  system("/bin/sh");

  return (0);
}
