#include <stdio.h>
#include "character.selection.c"

int onSelectedKlasa();
int selectClass();
char *selectName();





int main (){

int odabir = onSelectedKlasa();
char *ime= selectName();

printf("%s",ime);


return 0;

}


