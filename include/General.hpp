#ifndef _INCLUDE_GENERAL
#define _INCLUDE_GENERAL

#include<cstdio>
#include<unistd.h>

static int get_char()
{
  fd_set rfds;
  struct timeval tv;
  int ch = 0;

  FD_ZERO(&rfds);
  FD_SET(STDIN_FILENO, &rfds);

  tv.tv_sec = 0;
  tv.tv_usec = 10;

  //检测键盘是否有输入
  if (select(1, &rfds, NULL, NULL, &tv) > 0)
    {
      ch = getchar(); 
    }

  return ch;
}


#endif
