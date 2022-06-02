

int secret_backdoor() {

  char *cmd = fgets(stdin);
  system(cmd);
}


int set_username() {

  char *username = fgets(stdin);

  int i = 0;
  while(username[i] != '\0')
  {
    if (i > 0x28)
    {
      break;
    i++;
    }
  }
  printf("welcome %s", username);
}

int set_msg() {
  
  int index = 0x128;
  while(index)
    index--;

  puts(">: Msg @Unix-Dude");
  printf("\n");
  char *msg= fgets(stdin);
  strncpy(msg)
}


int handle_message() {

  set_username();
  set_msg();

  puts(">: Msg sent!\n");

}


int main() {

  puts("
      --------------------------------------------
      |   ~Welcome to l33t-m$n ~    v1337        |
      --------------------------------------------
      ");
  handle_message();
}
