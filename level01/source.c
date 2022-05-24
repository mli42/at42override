#include <stdio.h>
#include <string.h>

char username[0x100] = { 0 };

int verify_user_name(char *username) {
  puts("verifying username....\n");

  return strncmp(username, "dat_wil", 7);
}

int verify_user_pass(char *password) {
  return strncmp(password, "admin", 5);
}

int main(void) {
  char s[0x60 - 0x1c] = { 0 };

  puts("********* ADMIN LOGIN PROMPT *********");
  printf("Enter Username: ");

  fgets(username, 0x100, stdin);
  if (verify_user_name(username) != 0) {
    puts("nope, incorrect username...\n");
    return 1;
  }

  puts("Enter Password: ");
  fgets(s, 0x64, stdin);
  int good_password = verify_user_pass(s);

  if (good_password == 0 || good_password != 0) {
    puts("nope, incorrect password...\n");
    return 1;
  }

  return 0;
}
