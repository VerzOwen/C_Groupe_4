#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

unsigned connexion(char login, char passWord);
unsigned addUser(char login, char passWord);
unsigned modifyLogin(char login);
unsigned modifyPassWord(char login, char passWord);
unsigned deleteUser(char login);
char chiffrement(char passWord);

#endif // TEST_H_INCLUDED
