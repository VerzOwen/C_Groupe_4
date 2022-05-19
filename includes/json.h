#ifndef JSON_H_INCLUDED
#define JSON_H_INCLUDED

short unsigned jsonPrimitive(char *chaineJson, char *nomAttribut, char *resultat, unsigned dim,char
*messageErreur);

short unsigned jsonArray(char *chaineJson, char *nomAttribut, char resultats[][], unsigned
*nbElements, char *messageErreur);


void lireJusqueCaractereAttendu(char *chaineJson, int *caractereCourant, int caractereAttendu,char *MessageErreur);

char *lectureChaine(char *chaineJson, int *caractereCourant,char *chaineLue,char *messageErreur);
#endif 
