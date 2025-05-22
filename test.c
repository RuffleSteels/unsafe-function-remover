// test3.c
#include <stdio.h>
#include <stdlib.h>
int main() {
  char buf[128];
  const char *src = "a.txt", *dst = "b.txt";
  snprintf(buf, sizeof(buf), "cp %s %s", src, dst);
  system(buf);

  char *cmd = malloc(64);
  sprintf(cmd, "date +\"%%Y-%%m-%%d\"");
  system(cmd);
  free(cmd);

  char buf2[128];
  snprintf(buf2, sizeof(buf2), "echo “Hello %s”", "World");
  system(buf2);

  system("ls -l /tmp");

  const char *p = "uname -a";
  system(p);

  return 0;
}

// ./build/clang_execv_rewriter.exe test.c -- -IC:\Program Files\LLVM\lib\clang\20\include