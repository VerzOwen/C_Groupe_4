#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

struct user{
    char login[20];
    char passWord[20];
};

unsigned addUser(struct user newUser);
unsigned checkLogin(struct user newUser);
unsigned checkPwd(struct user newUser);
unsigned checkExistUser(struct user newUser);


#endif // TEST_H_INCLUDED
