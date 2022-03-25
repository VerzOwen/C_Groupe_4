//#include "../src/projet.h"
/*#include "main_test.h"
#include "../header/users.h"
#define DIM 100*/
#include <unistd.h>
#include "../header/users.h"
#include "../unity/unity.c"
/*static char erreur[DIM];
static char expression[DIM];

void setUp(void)
{ // appel�e avant chaque test
    strcpy(erreur, "");
}*/

/*void test_checkLoginCorrect(){
    struct user newUser = {"adminlog", "adminpwd"};
    //char *login = "adminlog";
    TEST_ASSERT_EQUAL_INT( 1, checkLogin(newUser));
}*/

void test_multiplication(){
    int resultat = 2*3;
    TEST_ASSERT_EQUAL_INT32(6, resultat);
}

int main()
{
    printf("TEST UTILISATEURS\n=================\n\n");
    UNITY_BEGIN();
    //RUN_TEST(test_checkLoginCorrect);
    RUN_TEST(test_multiplication);
    sleep(1000);
    UNITY_END();
    return 0;
}

/*void testUsers(){
  
    printf("TEST UTILISATEURS\n=================\n\n");
    UNITY_BEGIN();
    RUN_TEST(test_checkLoginCorrect);
    UNITY_END();
      
}
*/