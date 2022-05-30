#include "projet.h"

#define DIM 5
#define DIMERROR 50

short unsigned jsonPrimitive(char *chaineJson, char *nomAttribut, char *resultat, unsigned dim,char
*messageErreur){

   
    int trouve=1, caractereCourant=0;
    char messageErreurCarAttendu[DIMERROR];
    char messageErreurLectureChaine[DIMERROR];
    char chaineLue,nomAttri;
    //Cherche l'attribut dont le nom est entré en paramètre
    while(strcmp(nomAttri,nomAttribut)!=0){//l'attribut ne correspond pas à l'attribut recherché
        lireJusqueCaractereAttendu(chaineJson,&caractereCourant,'\"',messageErreurCarAttendu);
         lectureChaine(chaineJson, caractereCourant,nomAttri,messageErreurLectureChaine);
        lireJusqueCaractereAttendu(chaineJson,&caractereCourant,':',messageErreurCarAttendu);
    }
    if(messageErreurCarAttendu[0]!=NULL){//Erreur lors de la recherche de caractères
        strcpy(messageErreur,messageErreurCarAttendu); //Affichage du message d'erreur
        trouve=0;
    } else {
        //Lis la chaine de caractère 
        lectureChaine(chaineJson,caractereCourant,chaineLue,messageErreurLectureChaine);
        if(messageErreurLectureChaine[0]!=NULL){//Erreur lors de la lecture de la chaine
            strcpy(messageErreur,messageErreurLectureChaine); //Affichage du message d'erreur
            trouve=0;
        } else {
            strcpy(resultat,chaineLue); 
        }
    }

    return trouve;
}

short unsigned jsonArray(char *chaineJson, char *nomAttribut, char resultats[][DIM], unsigned
*nbElements, char *messageErreur){

    int i,j=0, continuer=1, trouve=1, caractereCourant=0;
    char messageErreurCarAttendu[DIMERROR];
    char messageErreurLectureChaine[DIMERROR];
    char chaineLue,nomAttri; 
    
    //Cherche l'attribut dont le nom est entré en paramètre
     while(strcmp(nomAttri,nomAttribut)!=0){//l'attribut ne correspond pas à l'attribut recherché
        lireJusqueCaractereAttendu(chaineJson,&caractereCourant,'\"',messageErreurCarAttendu);
        lireJusqueCaractereAttendu(chaineJson,&caractereCourant,':',messageErreurCarAttendu);
        lectureChaine(chaineJson, caractereCourant,nomAttri,messageErreurLectureChaine);
    }
    lireJusqueCaractereAttendu(chaineJson,&caractereCourant,'[',messageErreurCarAttendu);
    lireJusqueCaractereAttendu(chaineJson,&caractereCourant,':',messageErreurCarAttendu);
    while(continuer==1){
        for(i=0;i<DIM;i++){
            lireJusqueCaractereAttendu(chaineJson,&caractereCourant,':',messageErreurCarAttendu);
            if(messageErreurCarAttendu[0]!=NULL){ //Erreur lors de la recherche de caractère
                strcpy(messageErreur,messageErreurCarAttendu); //Affichage du message d'erreur
                trouve=0;
            } else {
                lectureChaine(chaineJson,caractereCourant,chaineLue,messageErreurLectureChaine);
                if(messageErreurLectureChaine[0]!=NULL){ //Erreur lors de la lecture de chaine
                    strcpy(messageErreur,messageErreurLectureChaine); //Affichage du message d'erreur
                    trouve=0;
                } else {
                    strcpy(resultats[j][i],chaineLue);
                }
        }
        }
        //Parcour le fichier pour controler si d'autre lignes doivent être rajoutées
        while(((caractereCourant = fgetc(chaineJson)) != EOF) && (caractereCourant != "{") && (caractereCourant != "]")){
        }
        if(caractereCourant=="]"){
            continuer=0;
        }
        j+=1;
    }

    nbElements=j;
    return trouve;
}


void lireJusqueCaractereAttendu(char *chaineJson, int *caractereCourant, int caractereAttendu,char *MessageErreur)
{
    if (*caractereCourant == caractereAttendu)
    {
        return;
    }
    while (((*caractereCourant = fgetc(chaineJson)) != EOF) && (*caractereCourant != caractereAttendu) && ((*caractereCourant == ' ') || (*caractereCourant == '\t') || (*caractereCourant == '\n')))
    {
    }
    if (*caractereCourant != caractereAttendu)
    {
        
        strcpy(MessageErreur,"Erreur: caractere attendu non trouve");
    }
}

char *lectureChaine(char *chaineJson, int *caractereCourant,char *chaineLue,char *messageErreur)
{
    char *buffer;
    // Verifier qu'on est bien sur le " ouvrant
    if (*caractereCourant != '\"')
    {
        strcpy(messageErreur,"Erreur: ouvrant de chaine non trouver");
        
    }
    buffer = (char *)malloc(100);
    int positionDansBuffer = 0;
    // Lire les caracteres et les mettre dans la zone de travail jusqu'au " fermant
    while (((*caractereCourant = fgetc(chaineJson)) != EOF) && (*caractereCourant != '\"'))
    {
        buffer[positionDansBuffer] = (char)*caractereCourant;
        positionDansBuffer++;
    }
    // Verification qu'on est bien sur le " fermant
    if (*caractereCourant != '\"')
    {
        free(buffer);
        strcpy(messageErreur,"Erreur: fermant de chaine non trouver");
    }
    // Passe au caractere suivant et terminer le buffer avec un 0
    *caractereCourant = fgetc(chaineJson);
    buffer[positionDansBuffer] = '\0';
    positionDansBuffer++;
    // Allouer une zone de memoire et y copier la chaine
    char *chaine = (char *)malloc(positionDansBuffer);
    strcpy(chaine, buffer);
    free(buffer);
    chaineLue=chaine;
}