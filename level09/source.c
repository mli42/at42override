#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void secret_backdoor(void) {
  char cmd[0x80];

  fgets(cmd, 0x80, stdin);
  system(cmd);
}

void set_username(char *buffer) {
  char username[0x90 - 0x04]; // == 140
  int i;

  bzero(username, 0x10 * 8); // == 128
  puts(">: Enter your username");
  printf(">>: ");
  fgets(username, 0x80, stdin);

  i = 0;
  char *buffer_username = &buffer[0x8c]; // Actually not on the stack
  while(i <= 0x28 || username[i] != '\0')
  {
    buffer_username[i] = username[i];
    i++;
  }
  printf(">: Welcome, %s", buffer_username);
}

void set_msg(char *buffer) {
  char password[0x400];

  bzero(password, 0x80 * 8); // == 0x400 == 1024
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(password, 0x400, stdin);
  strncpy(buffer, password, buffer[0xb4]);
}

void handle_message(void) {
  char buffer[0xc0 - 0xc];
  int a = 0x8c;

  bzero(&buffer[0x8c], 0x28);
  set_username(buffer);
  set_msg(buffer);

  puts(">: Msg sent!\n");
}

int main(void) {
  puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
  handle_message();
}
