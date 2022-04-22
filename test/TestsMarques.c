#include "../header/projet.h"

#define DIM 100

static char erreur[DIM];
static char expression[DIM];

void setUp(void)
{ // appel�e avant chaque test
    strcpy(erreur, "");
}

void test_creerTable(){
    TEST_ASSERT_EQUAL_INT(1, creerTables());
}

void test_remplirTable(){
    TEST_ASSERT_EQUAL_INT( 1, remplirTables());
}



int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_creerTable);
    RUN_TEST(test_remplirTable);
    UNITY_END();
    return 0;
}