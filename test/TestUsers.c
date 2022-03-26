#include "../header/users.h"
#include "../unity/unity.c"
#include "../src/users.c"

/*void test_multiplication(){
    int resultat = 2*3;
    TEST_ASSERT_EQUAL_INT32(6, resultat);
}*/


// Test connexion
void test_connexionUserInconnu(){
    struct user newUser = {"admintests5", "adminpwd"};
    TEST_ASSERT_EQUAL_INT(0, connexion(newUser));
}

void test_connexionPasswordIncorrect(){
    struct user newUser = {"adminlog", "adminpwd555"};
    TEST_ASSERT_EQUAL_INT(1, connexion(newUser));
}

void test_connexionUserCorrect(){
    struct user newUser = {"adminlog", "adminpwd"};
    TEST_ASSERT_EQUAL_INT(2, connexion(newUser));
}

// Test checkLogin --------------------------------------
void test_checkLoginCorrect(){
    struct user newUser = {"adminlog", "adminpwd"};
    TEST_ASSERT_EQUAL_INT( 1, checkLogin(newUser));
}

void test_checkLoginInferieur(){
    struct user newUser = {"admin", "adminpwd"};
    TEST_ASSERT_EQUAL_INT( 0, checkLogin(newUser));
}

void test_checkLoginSuperieur(){
    struct user newUser = {"admingggggggggggggggggggggggg", "adminpwd"};
    TEST_ASSERT_EQUAL_INT( 0, checkLogin(newUser));
}

// Test checkPassWord
void test_checkPWDCorrect(){
    struct user newUser = {"adminlog", "adminpwd"};
    TEST_ASSERT_EQUAL_INT( 1, checkLogin(newUser));
}

void test_checkPWDInferieur(){
    struct user newUser = {"adminlog", "admin"};
    TEST_ASSERT_EQUAL_INT( 0, checkPwd(newUser));
}

void test_checkPWDSuperieur(){
    struct user newUser = {"adminlog", "adminpwdGGGGGGGgggggggggg"};
    TEST_ASSERT_EQUAL_INT( 0, checkPwd(newUser));
}

int main()
{
    printf("TEST UTILISATEURS\n=================\n\n");
    UNITY_BEGIN();
    
    RUN_TEST(test_connexionUserInconnu);
    RUN_TEST(test_connexionPasswordIncorrect);
    RUN_TEST(test_connexionUserCorrect);

    RUN_TEST(test_checkLoginCorrect);
    RUN_TEST(test_checkLoginInferieur);
    RUN_TEST(test_checkLoginSuperieur);

    RUN_TEST(test_checkPWDCorrect);
    RUN_TEST(test_checkPWDInferieur);
    RUN_TEST(test_checkPWDSuperieur);
    //RUN_TEST(test_multiplication);
    sleep(1000);
    UNITY_END();
    return 0;
}