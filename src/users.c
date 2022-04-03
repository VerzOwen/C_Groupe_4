#include "../header/projet.h"

/*unsigned connexion(struct user connectUser){

    int exist;
    int pwd;
    int correct;

    if(exist=checkExistUser(connectUser)){
        if(pwd=checkCorrectPassWord(connectUser)){
            correct=2;
        } else correct=1;
    } else correct=0;

    return correct;
}*/



unsigned addUser(struct user newUser){

    int ajout;
    //int exist;

    //exist=checkExistPlayer( addNewUser.login);

    FILE *users=NULL;
    users=fopen("users.txt","a+");

        fwrite(&newUser, sizeof(newUser), 1, users);    
        ajout = 1;

    fclose(users);

    return ajout;
}


// Vérifie si le login et mot de passe respecte les critères
unsigned checkLogin(struct user newUser){

    int correct;

    if((strlen(newUser.login) < 20) && strlen(newUser.login) > 7){
        correct = 1;
    } else correct = 0;

    return correct;
}



unsigned checkPwd(struct user newUser){
    
    int correctNb=0,correctMaj=0,correct,i;
    
    if((strlen(newUser.passWord) < 21) && strlen(newUser.passWord) > 7){
        for(i=0;i<strlen(newUser.passWord);i++){
            if(isdigit(newUser.passWord[i])){
                correctNb = 1;
            }
            if(isupper(newUser.passWord[i])){
                correctMaj=1;
            }
            if(correctNb==1 && correctMaj==1){
                correct=1;
                i=strlen(newUser.passWord);
            }
        }
        
    } else correct = 0;

    return correct;
}


//Vérifie si le Login éxiste déja. Retourne 1 si c'est le cas, sinon retourne 0
unsigned checkExistUser(struct user newUser){

    int trouve=0;
    struct user User;

    FILE *users=NULL;
    users=fopen("users.txt","r+");
    if(!users){users=fopen("users.txt","w+");}
    
    while(!feof(users) && trouve==0){
        
        fread(&User, sizeof(struct user), 1, users);
        //fscanf(users,"%s %s \n",User.login,User.passWord);
        
        if((strcmp(User.login, newUser.login))==0) {
            
            trouve=1;

        }
    }
    fclose(users);
    return trouve;
}

// Vérifie si le MDP donné correspond au login. Retourne 1 si c'est le cas, sinon retourne 0
unsigned checkCorrectPassWord(struct user User){

    int correct=0;
    int egal;
    struct user pwdUser;

    FILE *users=NULL;
    users=fopen("users.txt","r+");

    while(!feof(users) && correct==0){

        fread(&pwdUser, sizeof(struct user), 1, users);

        if((strcmp(pwdUser.login, User.login))==0){
            printf("test1");
            if((strcmp(pwdUser.passWord, User.passWord))==0) {
                correct=1;
            } 
        }
        //fscanf(users,"%s %s \n",pwdUser.login,pwdUser.passWord);
         
    }
    fclose(users);
    return correct;
}



unsigned modifyUser(struct user User, struct user modifUser){
    
    int modif=0; 
    int trouve=0;
    struct user modifyUser;

    FILE *users=NULL;
    FILE *modifFile=NULL;
    users=fopen("users.txt","r");
    modifFile=fopen("delete.txt", "a+");
    fread(&modifyUser, sizeof(struct user), 1, users);
    while(!feof(users)){


        //fscanf(users,"%s %s \n",User.login,User.passWord);
        
        if((strcmp(modifyUser.login, User.login))==0) {
            trouve=checkExistUser(modifUser);
            
            if(trouve==0){
                strcpy(modifyUser.login, modifUser.login);
                strcpy(modifyUser.passWord, modifUser.passWord);
                fwrite(&modifyUser, sizeof(modifyUser), 1, modifFile);
                modif=1;

            }   else {

                }

        }   else {
            fwrite(&modifyUser, sizeof(modifyUser), 1, modifFile);
        }
        fread(&modifyUser, sizeof(struct user), 1, users);
    }

    fclose(users);
    fclose(modifFile);
    remove("users.txt");
    rename("delete.txt","users.txt");

    return modif;
}

unsigned deleteUser(struct user User){
    
    int delete=0; 
    int trouve=0;
    struct user delUser;

    FILE *users=NULL;
    FILE *delFile=NULL;
    users=fopen("users.txt","r");
    delFile=fopen("delete.txt", "a+");

    fread(&delUser, sizeof(struct user), 1, users);

    while(!feof(users)){
        //fscanf(users,"%s %s \n",User.login,User.passWord);
        
        if((strcmp(delUser.login, User.login))==0) {
            delete=1;
        }   else {
            fwrite(&delUser, sizeof(delUser), 1, delFile);
        }
        fread(&delUser, sizeof(struct user), 1, users);
    }

    fclose(users);
    fclose(delFile);
    remove("users.txt");
    rename("delete.txt","users.txt");
    return delete;
}



char * encrypt(char *passWord)
{
    int k;
    int limit;
    unsigned char swap;
    limit=strlen(passWord);

    for(k=0;k<limit;k++)
    {
        swap=(unsigned char)passWord[k]<<5;
        passWord[k]=(unsigned char)passWord[k]>>3;
        passWord[k]=(unsigned char)passWord[k]|swap;
    }
    return(passWord);
}



char *decrypt(char *passWord)
{
    int k;
    int limit;
    unsigned char swap;
        limit=strlen(passWord);
        for(k=0;k<limit;k++)
        {
                swap=(unsigned char)passWord[k]>>5;
                passWord[k]=(unsigned char)passWord[k]<<3;
                passWord[k]=(unsigned char)passWord[k]|swap;
        }

    return(passWord);
}
