#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void log_wrapper(FILE* file, char *a, char *b) {

}

int main(int argc, char **argv)
{
  FILE *logfile;
  FILE *file;
  char *path;
  int fd;
  char read;

  if (argc == 2)
    printf("Usage: %s filename\n", argv[0]);
  if ((logfile = fopen("./backups/.log", "w")) == NULL) {
    printf("ERROR: Failed to open %s\n", "./backups/.log");
    exit(1);
  }

  log_wrapper(logfile, "Starting back up: ", argv[1]);
  if ((file = fopen(argv[1], "r")) == NULL) {
    printf("ERROR: Failed to open %s\n", argv[1]);
    exit(1);
  }

  path = "./backups/";
  strncat(path, argv[1], strlen(path));

  if ((fd = open(path, 0xc1, 0x1b0)) == 0) {
    printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
    exit(1);
  }

  /*  fgetc() reads the next character from stream and returns it as an
      unsigned char cast to an int, or EOF on end of file or error.
  */
  while ((read = fgetc(file)) != EOF)
    write(fd, &read, 1);

  log_wrapper(logfile, "Finished back up ", argv[1]);
  fclose(file);
  close(fd);
  // Canary
  return (0);
}
