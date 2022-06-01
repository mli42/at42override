

unsigned int get_unum(void)
{
    unsigned int res = 0;
    fflush(stdout);
    scanf("%u", &res);
    clear_stdin();
    return res;
}

int read_number() {

  printf();
  get_unum();
  printf();
}


int store_number()
{
  printf();
  get_unum();
  printf();
  get_unum();

  puts();
  puts();
  puts();

}

int main() {

  while (--argc >= 0)
  memset(argv[argc], 0, size(argv[argc]));

  welcome_to_will_crappy_storage_machin_with_3command();
  command = fgets(stdin);
  execute(command);

}
