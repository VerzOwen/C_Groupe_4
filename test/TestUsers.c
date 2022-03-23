#include "../src/projet.h"

#define DIM 100

/*static char erreur[DIM];
static char expression[DIM];

void setUp(void)
{ // appel�e avant chaque test
    strcpy(erreur, "");
}*/

void test_checkLoginCorrect(){
    char *login = "adminlog";
    TEST_ASSERT_EQUAL_INT( 1, checkLogin(login));
}

/*int main()
{
    printf("TEST UTILISATEURS\n=================\n\n");
    UNITY_BEGIN();
    RUN_TEST(test_checkLoginCorrect);
    UNITY_END();
    return 0;
}*/

void testUsers(){
    printf("TEST UTILISATEURS\n=================\n\n");
    UNITY_BEGIN();
    RUN_TEST(test_checkLoginCorrect);
    UNITY_END();
}