#include "../includes/projet.h"
#include "../includes/users.h"
#define DIM 20
int main(){
    //DECLARATION
    struct user newUser;
    struct user User;
    struct user ModUser;
    struct user ModifUser;
    struct user DelUser;
    int choix;
    int choixadmi, choixutili;
    int logcorr, pwdcorr, idcorr;
    int i, add, connection, modif, delete;
    char crypt[DIM],RepeatPassword[DIM];
    //DEFINITION
    debut: //Permet la réinitialisation des données lors d'une déconnexion
    choixadmi=0;
    choixutili=0;
    choix=0;
    logcorr=0;
    pwdcorr=0;
    idcorr=0;
    while((choix != 1) || (choix !=2)){

        printf("\n\n1. Creer un compte \n2. Se connecter \n\nVotre choix : ");  scanf("%d", &choix);

        if(choix==1){ //inscription
            
            while(idcorr!=1){

                printf("\n\nEntrer login : ");  scanf("%s", &newUser.login); 
                printf("Entrer mot de passe : ");       
                for(i = 0 ; (newUser.passWord[i] = getch()) != '\r'; i++){
                     printf("*");
                }
                printf("Répéter mot de passe : "); 
                for(i = 0 ; (RepeatPassword[i] = getch()) != '\r'; i++){
                     printf("*");
                }
                logcorr=checkLogin(newUser);
                pwdcorr=checkPwd(newUser);
                if(strcmp(RepeatPassword,newUser.passWord)!=0){
                    printf("Les 2 mots de passes doivent être identiques");
                } else if(logcorr!=1){
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

        }   else if (choix==2){//Connexion
            
            printf("\n\nEntrer login : ");  scanf("%s", &User.login); 
            printf("Entrer mot de passe : ");   scanf("%s", &User.passWord);
            for(i = 0 ; (User.passWord[i] = getch()) != '\r'; i++){
                printf("*");
            }
            strcpy(User.passWord,encrypt(User.passWord));



            connection=connexion(User);

            if(connection==2){

                printf("\nConnexion réussie");

                if((strcmp("adminlog", User.login))==0){


                    while((choixadmi!=1) || (choixadmi!=2)){

                        printf("\n\nConnecter à un compte administrateur.");

                        printf("\n\n1. Ajouter un utilisateur. \n2. Modifier un utilisateur. \n3. Supprimer un utilisateur. \n4. Deconnexion. \n\n Votre choix : ");   scanf("%d", &choixadmi);

                        switch(choixadmi){
                            case(1): //ajout d'un utilisateur
                            while(idcorr!=1){

                                printf("\n\nEntrer login : ");  scanf("%s", &newUser.login); 
                                printf("Entrer mot de passe : ");       
                                for(i = 0 ; (newUser.passWord[i] = getch()) != '\r'; i++){
                                    printf("*");
                                }
                                printf("Répéter mot de passe : "); 
                                for(i = 0 ; (RepeatPassword[i] = getch()) != '\r'; i++){
                                    printf("*");
                                }
                                logcorr=checkLogin(newUser);
                                pwdcorr=checkPwd(newUser);
                                if(strcmp(RepeatPassword,newUser.passWord)!=0){
                                    printf("Les 2 mots de passes doivent être identiques");
                                } else if(logcorr!=1){
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
                        break;
                        case(2): //modification d'un utilisateur
                            
                            printf("\n\nEntrer le login de l'utilisateur a modifier : ");  scanf("%s", &ModUser.login);
                            printf("Entrer le mot de passe de l'utilisateur a modifier : ");   
                            for(i = 0 ; (ModUser.passWord[i] = getch()) != '\r'; i++){
                                printf("*");
                            }

                            while (idcorr!=1)
                            {
                                
                                printf("\n\nEntrer le nouveau login ( retaper le login actuel si pas besoin de changer) : ");  scanf("%s", &ModifUser.login); 
                                printf("Entrer mot de passe ( retaper le mot de passe si pas besoin de changer) : ");   
                                for(i = 0 ; (ModifUser.passWord[i] = getch()) != '\r'; i++){
                                    printf("*");
                                }
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
                        break;
                        case(3): //suppresion d'un utilisateur

                            printf("\n\nEntrer le login de l'utilisateur a supprimer : ");  scanf("%s", &DelUser.login);
 
                            delete=deleteUser(DelUser);
                        
                            if(delete==1){

                                printf("\n\nUtilisateur supprimer.");

                            }
                        break;
                        case(4): //deconnexion
                        goto debut;
                        break;
                        }

                    }

                }   else{

                    printf("\nConnecter à un compte client.");

                     printf("\n\n1. Voir la liste des marques. \n2. Voir la liste des modèles d'une marque. \n3. Voir la liste des versions. \n4. Deconnexion. \n\n Votre choix : ");   scanf("%d", &choixutili);

                    switch(choixutili){
                        case(1): //liste des marques

                        break;
                        case(2): //liste des modèles d'une marque

                        break;
                        case(3): //liste des versions

                        break;
                        case(4): //deconnexion
                        goto debut;
                        break;
                    }
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
