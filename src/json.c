#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

short unsigned jsonPrimitive(char *chaineJson, char *nomAttribut, char *resultat, unsigned dim,char
*messageErreur){

    FILE *chaineJson = fopen("marques_modeles.txt");

    if (*nomAttribut == *resultat)
    {
        return 1;
    }
    while (((*nomAttribut = fgetc(marques_modeles)) != EOF) && (*nomAttribut != resultat) && ((*nomAttribut == ' ') || (*nomAttribut == '\t') || (*nomAttribut == '\n')))
    {
    }
    if (*nomAttribut != resultat)
    {
        return 0;
    }

     if (*nomAttribut != '\"')
    {
        printf("Erreur: ouvrant de chaine '\"' non trouv�");
    }
    char *buffer = (char *)malloc(100);
    int positionDansBuffer = 0;

    while (((*nomAttribut = fgetc(marques_modeles)) != EOF) && (*nomAttribut != '\"'))
    {
        buffer[positionDansBuffer] = (char)*nomAttribut;
        positionDansBuffer++;
    }
    // V�rifier qu'on est bien sur le " fermant
    if (*nomAttribut != '\"')
    {
        free(buffer);
        printf("Erreur: fermant de chaine '\"' non trouv�");
    }
    *nomAttribut = fgetc(marques_modeles);
    buffer[positionDansBuffer] = '\0';
    positionDansBuffer++;
    char *chaine = (char *)malloc(positionDansBuffer);
    strcpy(chaine, buffer);
    free(buffer);
        bool OK = !strcmp(buffer, "CarList");
        free(buffer);
        if (!OK)
        {
            return 0;
        }
}

short unsigned jsonArray(char *chaineJson, char *nomAttribut, char resultats[][DIM], unsigned
*nbElements, char *messageErreur){

}
