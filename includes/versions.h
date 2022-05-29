#ifndef VERSIONS_H_INCLUDED
#define VERSIONS_H_INCLUDED
#define DIM 50
int mainVersions();
void initialiserConnexion();
void cloturerConnexion();
int creerTables();
int remplirTables();
void listVersions(char **listVersions, char NiceName, int nbElements, char * erreur);
//void executerSQL(char *instructionSQL);
//int insererDonnee(char *instructionSQL)
#endif 