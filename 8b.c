#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

char buf1[]="abcdefghijklmnop";
char buf2[]="ABCDEFGHIJKLMNOP";

int main(int argc, char const *argv[]) {
  int fd;
  fd=creat("file.txt",S_IRWXU);
  if (fd<0)
  {
    printf("\nError in creating file\n");
    exit(1);
  }
  write(fd,buf1,16);
  lseek(fd,48,SEEK_SET);
  write(fd,buf2,16);
  system("gedit file.txt");
  return 0;
}
