#ifndef MODELES_H_INCLUDED
#define MODELES_H_INCLUDED

int mainModeles();
void initialiserConnexion();
void cloturerConnexion();
void creerTables();
void remplirTables();
void executerSQL(char *instructionSQL);
int insererDonnee(char *instructionSQL)
#endif 