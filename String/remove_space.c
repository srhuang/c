/*****************************************************************
Name    :remove_space
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190116 Initialization
*****************************************************************/
#include <stdio.h>
#include <string.h>

/*==============================================================*/
void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

/*==============================================================*/

int main(){
    char test[100]="a s d f g h j k l ";
    printf("Input String : %s\n", test);
    RemoveSpaces(test);
    printf("After remove space : %s\n", test);

    return 0;
}
/*==============================================================*/