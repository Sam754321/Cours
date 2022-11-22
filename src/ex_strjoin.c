#include "libtam.h"
#include<stdio.h>
static char *malostr(const char *s1, const char *s2)
{
    char * retstr;

    retstr =NULL;
    if(s1 && s2)
      {
          if(!(retstr = (char *)malloc(sizeof(char) * (ex_strlen((char*)s1) + ex_strlen((char*)s2) + 1))))
                return NULL;
      }
      else if(s1 && !s2)
      {
          if(!(retstr = (char *)malloc(sizeof(char) * (ex_strlen((char*)s1) + 1))))
                return NULL;
      }
      else if(!s1 && s2)
      {
          if(!(retstr = (char *)malloc(sizeof(char) * (ex_strlen((char*)s2) + 1))))
                return NULL;
      }
      return retstr;
}

char *ex_strjoin(const char *s1, const char *s2)
{
  char * retstr;
  int j;
  int i;

  retstr = NULL;
  i = 0;
  j = 0;
  if(s1 || s2)
  { 
      retstr = malostr(s1, s2);
      if(s1)
      {
           while(s1[i] != 0)
           {
               retstr[i] = s1[i];
               i ++;
           }
      }
      if(s2)
      {
           while(s2[j] != 0)
           {
                retstr[i] = s2[j];
                i ++;
                j++;
           }
      }
      retstr[i] = 0;
  }
    return retstr;
}