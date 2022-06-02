

int secret_backdoor() {

  char *cmd = fgets(stdin);
  system(cmd);
}


int set_username() {

}

int set_msg() {

}


int handle_message() {

  set_username();
  set_msg();

  puts(": Msg sent!\n");


}


int main() {

  puts("
      --------------------------------------------
      |   ~Welcome to l33t-m$n ~    v1337        |
      --------------------------------------------
      ");
  handle_message();
}
