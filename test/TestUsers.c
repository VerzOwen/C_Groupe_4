#include "../header/projet.h"
#include "../unity/unity.c"
#include "../src/users.c"


// Test connexion
/*void test_connexionUserInconnu(){
    struct user newUser = {"admintests5", "Adminpwd0"};
    TEST_ASSERT_EQUAL_INT(0, connexion(newUser));
}

void test_connexionPasswordIncorrect(){
    struct user newUser = {"adminlog", "Adminpwd0555"};
    TEST_ASSERT_EQUAL_INT(1, connexion(newUser));
}

void test_connexionUserCorrect(){
    struct user newUser = {"adminlog", "Adminpwd0"};
    TEST_ASSERT_EQUAL_INT(2, connexion(newUser));
}*/

// Test addUser
void test_addUserAdded(){
    struct user newUser = {"testuser10", "Testpwd10"};
    TEST_ASSERT_EQUAL_INT( 1, addUser(newUser));
}

// Test checkLogin --------------------------------------
void test_checkLoginCorrect(){
    struct user newUser = {"adminlog", "Adminpwd0"};
    TEST_ASSERT_EQUAL_INT( 1, checkLogin(newUser));
}

void test_checkLoginInferieur(){
    struct user newUser = {"admin", "Adminpwd0"};
    TEST_ASSERT_EQUAL_INT( 0, checkLogin(newUser));
}

void test_checkLoginSuperieur(){
    struct user newUser = {"adminggggggggggggggggggggggg", "Adminpwd0"};
    TEST_ASSERT_EQUAL_INT( 0, checkLogin(newUser));
}

// Test checkPassWord
void test_checkPWDCorrect(){
    struct user newUser = {"adminlog", "Adminpwd0"};
    TEST_ASSERT_EQUAL_INT( 1, checkLogin(newUser));
}

void test_checkPWDInferieur(){
    struct user newUser = {"adminlog", "admin"};
    TEST_ASSERT_EQUAL_INT( 0, checkPwd(newUser));
}

void test_checkPWDSuperieur(){
    struct user newUser = {"adminlog", "Adminpwd0GGGGGGGgggggggggg"};
    TEST_ASSERT_EQUAL_INT( 0, checkPwd(newUser));
}

// Test checkExistUser
void test_checkExistUserCorrect(){
    struct user newUser = {"adminlog", "Adminpwd0"};
    TEST_ASSERT_EQUAL_INT( 1, checkExistUser(newUser));
}

void test_checkExistUserIncorrect(){
    struct user newUser = {"adminlog4522", "Adminpwd0"};
    TEST_ASSERT_EQUAL_INT( 0, checkExistUser(newUser));
}

// Test CheckCorrectPassword
void test_checkCorrectPassWordCorrect(){
    struct user User = {"adminlog", "Adminpwd0"};
    TEST_ASSERT_EQUAL_INT( 1, checkCorrectPassWord(User));
}

void test_checkCorrectPassWordIncorrect(){
    struct user User = {"adminlog", "Adminpwd0testt"};
    TEST_ASSERT_EQUAL_INT( 0, checkCorrectPassWord(User));
}

// Test modifyUser
void test_modifyUserCorrect(){
    struct user User = {"testuser10", "Testpwd10"};
    struct user modifUser = {"testuser25", "Testpwd25"};
    TEST_ASSERT_EQUAL_INT( 1, modifyUser(User, modifUser));
}

void test_modifyUserInCorrect(){
    struct user User = {"testuser100", "Testpwd100"};
    struct user modifUser = {"testuser25", "Testpwd25"};
    TEST_ASSERT_EQUAL_INT( 0, modifyUser(User, modifUser));
}

// Test deleteUser
void test_deleteUserCorrect(){
    struct user DelUser = {"testuser2", "Testpwd2"};
    TEST_ASSERT_EQUAL_INT( 1, deleteUser(DelUser));
}

void test_deleteUserInCorrect(){
    struct user DelUser = {"testuser250", "Testpwd250"};
    TEST_ASSERT_EQUAL_INT( 0, deleteUser(DelUser));
}




int main()
{
    struct user admin= {"adminlog", "Adminpwd0"};
    struct user User1 = {"testuser1", "Testpwd1"};
    struct user User2 = {"testuser2", "Testpwd2"};
    FILE *users=NULL;
    users=fopen("users.txt","w+");

    fwrite(&admin, sizeof(admin), 1, users);    
    fwrite(&User1, sizeof(User1), 1, users); 
    fwrite(&User2, sizeof(User2), 1, users); 

    fclose(users);
    addUser(admin);
    addUser(User1);
    addUser(User2);
    printf("TEST UTILISATEURS\n=================\n\n");
    UNITY_BEGIN();
    
    /*RUN_TEST(test_connexionUserInconnu);
    RUN_TEST(test_connexionPasswordIncorrect);
    RUN_TEST(test_connexionUserCorrect);*/

    RUN_TEST(test_addUserAdded);

    RUN_TEST(test_checkLoginCorrect);
    RUN_TEST(test_checkLoginInferieur);
    RUN_TEST(test_checkLoginSuperieur);

    RUN_TEST(test_checkPWDCorrect);
    RUN_TEST(test_checkPWDInferieur);
    RUN_TEST(test_checkPWDSuperieur);
    
    RUN_TEST(test_checkExistUserCorrect);
    RUN_TEST(test_checkExistUserIncorrect);

    RUN_TEST(test_checkCorrectPassWordCorrect);
    RUN_TEST(test_checkCorrectPassWordIncorrect);

   RUN_TEST(test_modifyUserCorrect);
    RUN_TEST(test_modifyUserInCorrect);

    RUN_TEST(test_deleteUserCorrect);
    RUN_TEST(test_deleteUserInCorrect);

    sleep(1000);
    UNITY_END();
    return 0;
}