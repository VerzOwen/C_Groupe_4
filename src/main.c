#include "../header/projet.h"

int main(){
    // Initialise la connexion à la DB
    initialiserConnexion();

    mainMarques();
    mainModeles();
    mainVersions();

    // Ferme la connexion à la DB
    cloturerConnexion();
    return(0);
}