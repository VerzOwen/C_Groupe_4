#include <stdio.h>
#include <stdlib.h>
#include "users.h"


// Vérifie si le login correspond à un login dans le fichier user
// Si c'est le cas, vérifie si le mot de passe entrer correspond 
// au mot de passe lié au login.
// Si tout est correct, la fonction renvoie 1 sinon 0
unsigned connexion(char login, char passWord; char erreur){
    
    int connexion=0;
    int i=0;

    while((!EOF) || (login==login)){
        if(login=login){
            if(passWord=passWD){
                connexion=1;
            } else strcpy(erreur, "Mot de passe incorrect");
        } else strcpy(erreur, "Login incorrect");

    return connexion;
}




// Vérifie si le login ne correspond à aucun déja crée puis
// Vérifie si le mot de passe mesure bien moins de 21 caractères
// Chiffre le mot de passe si c'est correct
// Renvoie 1 si tout est correct sinon 0
unsigned addUser(char login, char passWord, char erreur){

    int ajout=0;

    while((!EOF) || (login==login)){
        if(login!=login){
            strcpy(login, login);
            if(strlen(passWord)<21){
                chiffrement(passWord);
                ajout=1;
            } else strcpy(erreur, "Mot de passe trop court"); 
        }  else strcpy(erreur, "Login déja éxistant");
    }


    return ajout;
}




// Retourne 1 si le login est changé sinon 0
unsigned modifyLogin(char login, char newLog){

    int modif=0;

    while((!EOF) || (login==login)){
        if(login=login){
            login=newLog;
            modif=1;
        }
    }

    return modif;
}




// Retourne 1 si le mot de passe est changé sinon 0
unsigned modifyPassWord(char login, char newPassWord){
    
    int modif=0;

    while((!EOF) || (login==login)){
        if(login=login){
            passWord=newPassWord;
            modif=1;
        }
    }

    return modif;
}




// Retourne 1 si l'utilisateur est supprimé sinon 0
unsigned deleteUser(char login){

    int suppression=0;

    while((!EOF) || (login==login)){
        if(login=login){
            login=0;
            suppression=1;
        }
    }

    return suppression;
}





char chiffrement(char passWord){

}