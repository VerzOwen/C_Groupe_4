#include "../header/users.h"

unsigned connexion(struct user connectUser){

    int exist;
    int pwd;
    int correct;

    if(exist=checkExistUser(connectUser)){
        if(pwd=checkCorrectPassWord(connectUser)){
            correct=2;
        } else correct=1;
    } else correct=0;

    return correct;
}



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

    if((strlen(newUser.login) < 21) && strlen(newUser.login) > 7){
        correct = 1;
    } else correct = 0;

    return correct;
}

unsigned checkPwd(struct user newUser){
    
    int correct;

    if((strlen(newUser.passWord) < 21) && strlen(newUser.passWord) > 7){
        correct = 1;
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

    struct user pwdUser;

    FILE *users=NULL;
    users=fopen("users.txt","r+");

    while(!feof(users) && correct==0){
        
        fread(&pwdUser, sizeof(struct user), 1, users);
        //fscanf(users,"%s %s \n",pwdUser.login,pwdUser.passWord);
        
        if((strcmp(pwdUser.passWord, User.passWord))==0) {
            
            correct=1;

        } 
    }
    fclose(users);
    return correct;
}



unsigned modification(struct user User, struct user modifUser){
    
    int modif; 
    int trouve=0;

    FILE *users=NULL;
    users=fopen("users.txt","a+");

    while(!feof(users) && trouve==0){
        printf("test2");
        fread(&User, sizeof(struct user), 1, users);
        //fscanf(users,"%s %s \n",User.login,User.passWord);
        
        if((strcmp(User.login, modifUser.login))==0) {
            printf("test1");
            trouve=checkExistUser(modifUser);
            
            if(trouve!=0){
                printf("testmodif1");
                /*fseek(users, -sizeof(&User), SEEK_CUR);
                fwrite(&modifUser, sizeof(modifUser), 1, users);*/
                strcpy(User.login, modifUser.login);
                strcpy(User.passWord, modifUser.passWord);
                fwrite(&User, sizeof(struct user), 1, users);
                modif=1;

            }   else modif=0;

        }
    }
    fclose(users);
    printf("%d", modif);
    return modif;
}



/*char * encrypt(char *passWord)
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
}*/



/*int main(){
    struct user User; //= {"testuser2","testpwd2"}; // = {"BenjaminP", "BenjaminPwD"};
    struct user newUser;
    struct user modifUser;
    int i, connexion;
    int ajoutUser;
    char erreur;
    int exist;
    int modif;

    printf("Entrer un login : ");
    scanf("%s", &User.login);
    printf("Entrer un mot de passe modif : ");
    scanf("%s", &User.passWord);


    printf("Entrer le nouveau login : ");
    scanf("%s", &modifUser.login);
    printf("Entrer le nouveau mot de passe modif : ");*/
    /*for(i = 0 ; (User.passWord[i] = getch()) != '\r'; i++){
        printf("*");
    }*/
    /*scanf("%s", &modifUser.passWord);


    // Test modif
    modif=modification(User, modifUser);

    if(modif==1){
        printf("Modification effectuee");
    }   else printf("Echec de la modification");*/
    
    
    // Test Connexion
    /*connexion=identification(newUser);

    printf("%d", connexion);

    if(connexion==2){
        printf("connexion réussie"); 
    } else if(connexion==0){
        printf("Login incorrect");
    } else if(connexion==1){
        printf("Mot de passe incorrect");
    }

    printf("\n%d", connexion);*/
    /*if(connexion=identification(User)){
        printf("Connexion réussie");
    } else printf("Connexion échouée");*/



    // Test ajout
    /*if((checkLogin(newUser))==1){
        printf("test1");
        if((checkPwd(newUser))==1){
            printf("test2");
            exist = checkExistUser(newUser);
            if(exist==0){
                ajoutUser=addUser(newUser);
                printf("Utilisateur cree");
            } else printf("Utilisateur existant");
        } else printf("Le mot de passe doit faire minimum 8 caractères et maximum 20");
    } else printf("Le login doit faire entre 8 et 20 caracteres");*/
   
    //ajoutUser=addUser(newUser);
    //printf("ajout effectue");
    //printf("%d", exist);
    /*sleep(1000);
}*/


/*main{

  Struct
  Appel checkLogin
  Appel checkPassWord

  Si c'est bon : Appel checkExistPlayer

  Si joueur n'éxiste pas : Appel addUser

}
*/