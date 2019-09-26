/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  char * pch1;

  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  pch1 = strtok (str," ");

  printf("%s\n", pch); 
  printf("%s", pch1); 
//   while (pch != NULL)
//   {
//     printf ("%s\n",pch);
//     pch = strtok (NULL, " ,.-");
//   }
  return 0;
}
