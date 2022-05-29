#ifndef MODELES_H_INCLUDED
#define MODELES_H_INCLUDED

int mainModeles();
void initialiserConnexion();
void cloturerConnexion();
int creerTables();
int remplirTables();
void executerSQL(char *instructionSQL);
int insererDonnee(char *instructionSQL);
void listModeles(char * listModeles, char niceName, int nbElements, char * erreur);
#endif 