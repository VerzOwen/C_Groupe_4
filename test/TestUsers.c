#include "../header/users.h"
#include "../unity/unity.h"

#define DIM 100

static char erreur[DIM];
static char expression[DIM];

void setUp(void)
{ // appel�e avant chaque test
    strcpy(erreur, "");
}


int main()
{
    UNITY_BEGIN();
    UNITY_END();
    return 0;
}