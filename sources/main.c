#include "../includes/projet.h"
#include "../includes/users.h"

int main(){
    struct user newUser;
    struct user User;
    struct user ModUser;
    struct user ModifUser;
    struct user DelUser;
    int choix=0;
    int choixadmi=0;
    int logcorr=0, pwdcorr=0, idcorr=0;
    int add, connection, modif, delete;
    char crypt[20];


    while((choix != 1) || (choix !=2)){

        printf("\n\n1. Creer un compte \n2. Se connecter \n\nVotre choix : ");  scanf("%d", &choix);

        if(choix==1){
            
            while(idcorr!=1){

                printf("\n\nEntrer login : ");  scanf("%s", &newUser.login); 
                printf("Entrer mot de passe : ");   scanf("%s", &newUser.passWord);

                logcorr=checkLogin(newUser);
                pwdcorr=checkPwd(newUser);

                if(logcorr!=1){
                    printf("\nLe login doit faire entre 8 et 20 caracteres.");
                }   else if(pwdcorr!=1){
                    printf("\nLe mot de passe doit contenir un chiffre, une majuscule et faire entre 8 et 20 caracteres.");
                }   else{
                    idcorr=1;
                }
            
            }
            
            strcpy(newUser.passWord,encrypt(newUser.passWord));


            add=addUser(newUser);

            if(add==1){

                printf("Creation de compte effectuer");

            }

        }   else if (choix==2){
            
            printf("\n\nEntrer login : ");  scanf("%s", &User.login); 
            printf("Entrer mot de passe : ");   scanf("%s", &User.passWord);
            strcpy(User.passWord,encrypt(User.passWord));



            connection=connexion(User);

            if(connection==2){

                printf("\nConnexion réussie");

                if((strcmp("adminlog", User.login))==0){


                    while((choixadmi!=1) || (choixadmi!=2)){

                        printf("\n\nConnecter à un compte administrateur.");

                        printf("\n\n1. Modifier un utilisateur. \n2. Supprimer un utilisateur. \n\n Votre choix : ");   scanf("%d", &choixadmi);

                        if(choixadmi==1){
                            
                            printf("\n\nEntrer le login de l'utilisateur a modifier : ");  scanf("%s", &ModUser.login);
                            printf("Entrer le mot de passe de l'utilisateur a modifier : ");   scanf("%s", &ModUser.passWord);

                            while (idcorr!=1)
                            {
                                
                                printf("\n\nEntrer le nouveau login ( retaper le login actuel si pas besoin de changer) : ");  scanf("%s", &ModifUser.login); 
                                printf("Entrer mot de passe ( retaper le mot de passe si pas besoin de changer) : ");   scanf("%s", &ModifUser.passWord);

                                logcorr=checkLogin(ModifUser);
                                pwdcorr=checkPwd(ModifUser);

                                if(logcorr!=1){

                                    printf("\nLe login doit faire entre 8 et 20 caracteres.");
                            
                                }   else if(pwdcorr!=1){
                            
                                    printf("\nLe mot de passe doit contenir un chiffre, une majuscule et faire entre 8 et 20 caracteres.");
                            
                                }   else{
                            
                                    idcorr=1;
                            
                                }

                                    strcpy(ModifUser.passWord,encrypt(ModifUser.passWord));

                            }

                            modif=modifyUser(ModUser, ModifUser);            

                            if(modif==1){

                                printf("\n\nUtilisateur modifier.");

                            }                

                        }   else if(choixadmi==2){

                            printf("\n\nEntrer le login de l'utilisateur a supprimer : ");  scanf("%s", &DelUser.login);
 
                            delete=deleteUser(DelUser);
                        
                            if(delete==1){

                                printf("\n\nUtilisateur supprimer.");

                            }

                        }

                    }

                }   else{

                    printf("\nConnecter à un compte client.");

                }

            }   else if(connection==0){

                printf("\nLogin incorrect");

            }   else if(connection==1){

                printf("\nMot de passe incorrect");

            }

        }

    }


    sleep(1000);
    return 0;
}
