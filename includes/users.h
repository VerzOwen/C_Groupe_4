#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

#include "projet.h"

struct user{
    char login[20];
    char passWord[20];
};

unsigned connexion(struct user User);
unsigned modifyUser(struct user User, struct user modifUser);
unsigned deleteUser(struct user newUser);
unsigned addUser(struct user newUser);
unsigned checkLogin(struct user newUser);
unsigned checkPwd(struct user newUser);
unsigned checkExistUser(struct user newUser);
unsigned checkCorrectPassWord(struct user User);
char * encrypt(char passWord[]);
char *decrypt(char passWord[]);

#endif 
