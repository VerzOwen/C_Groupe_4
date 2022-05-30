#include "users.h"

//Ajoute l'utilisateur dans le fichier s'il n'existe pas déjà
unsigned addUser(struct user newUser){

    int ajout=0; //Valeur de retour: si vaut 1, l'utilisateur a été ajouté 

    if(checkExistPlayer(newUser.login)==0){ //Verification que l'utilisateur qu'on souhaite ajouter n'existe pas

        FILE *users=NULL;
        users=fopen("users.txt","a+");

            fwrite(&newUser, sizeof(newUser), 1, users);    
            ajout = 1;

        fclose(users);
    }

    return ajout;
}


// Vérifie si le login  respecte les critères
unsigned checkLogin(struct user newUser){

    int correct=0; //Valeur de retour: si vaut 1, le login respecte les critères

    if((strlen(newUser.login) < 21) && strlen(newUser.login) > 7){ //Vérifie que le login fait entre 8 et 20 caractères
        correct = 1;
    } 

    return correct;
}

//Vérifie si le mdp respecte les critères
unsigned checkPwd(struct user newUser){
    
    int correctNb=0,correctMaj=0,correct,i;
    
    if((strlen(newUser.passWord) < 21) && strlen(newUser.passWord) > 7){ //Vérifie que le mdp fait entre 8 et 20 caractères
        for(i=0;i<strlen(newUser.passWord);i++){
            if(isdigit(newUser.passWord[i])){ //Vérifie qu'il y a au moins un chiffre dans le mdp
                correctNb = 1;
            }
            if(isupper(newUser.passWord[i])){ //Vérifie qu'il y a au moins une majuscule dans le mdp
                correctMaj=1;
            }
            if(correctNb==1 && correctMaj==1){ //S'il y a le bon nombre de caractères, un chiffre et une majuscule le mdp est valide
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
            if((strcmp(pwdUser.passWord, User.passWord))==0) {
                correct=1;
            } 
        }
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
    modifFile=fopen("modif.txt", "a+"); //Crée un nouveau fichier dans lequel on inscrira les données du 1er fichier avec les modifications souhaitées
    fread(&modifyUser, sizeof(struct user), 1, users);
    while(!feof(users)){

        if((strcmp(modifyUser.login, User.login))==0) {
            trouve=checkExistUser(modifUser);
            
            if(trouve==0){//l'utilisateur lu par le flux est l'utilisateur qu'on souhaite modifié
                //on ajoute les données modifiés selon les paramètres de la fonction dans le fichier modif
                strcpy(modifyUser.login, modifUser.login);
                strcpy(modifyUser.passWord, modifUser.passWord);
                fwrite(&modifyUser, sizeof(modifyUser), 1, modifFile);
                modif=1;

            }   

        }   else {//l'utilisateur lu par le flux ne correspond pas à l'utilisateur qu'on souhaite modifié
            fwrite(&modifyUser, sizeof(modifyUser), 1, modifFile); //on écrit les données de l'utilisateur dans le nouveau fichier
        }
        fread(&modifyUser, sizeof(struct user), 1, users);
    }

    fclose(users);
    fclose(modifFile);
    remove("users.txt"); //suppression du 1er fichier sans les modifications
    rename("modif.txt","users.txt"); //modification du nom du 2ème fichier pour qu'il corresponde au nom du 1er fichier

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
        
        if((strcmp(delUser.login, User.login))==0) {//l'utilisateur lu par le flux est l'utilisateur qu'on souhaite supprimé
                //on ignore l'utilisateur qu'on souhaite supprimer afin de ne pas le recopier dans le nouveau fichier
            delete=1;
        }   else {//l'utilisateur lu par le flux ne correspond pas à l'utilisateur qu'on souhaite supprimer
            fwrite(&delUser, sizeof(delUser), 1, delFile);//on écrit les données de l'utilisateur dans le nouveau fichier
        }
        fread(&delUser, sizeof(struct user), 1, users);
    }

    fclose(users);
    fclose(delFile);
    remove("users.txt");  //suppression du 1er fichier sans les suppressions
    rename("delete.txt","users.txt");//modification du nom du 2ème fichier pour qu'il corresponde au nom du 1er fichier
    return delete;
}

//Cryptage d'un mdp par décalage de bits
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

//Decryptage d'un mdp par décalage de bits
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
