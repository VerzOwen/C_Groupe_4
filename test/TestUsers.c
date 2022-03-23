#include "../src/projet.h"


#define DIM 100

static char erreur[DIM];
static char expression[DIM];

void setUp(void)
{ // appel�e avant chaque test
    strcpy(erreur, "");
}



int main()
{
    printf("TEST UTILISATEURS\n=================\n\n");
    UNITY_BEGIN();

    UNITY_END();
    return 0;
}