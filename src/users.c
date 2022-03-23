#include "projet.h"

unsigned addUser(struct user newUser){

    int ajout;
    int exist;

    //exist=checkExistPlayer( addNewUser.login);
    
    //strcpy(addNewUser.login, "AdminLog");
    //strcpy(addNewUser.passWord, "AdminPWD");

    FILE *users=NULL;
    users=fopen("users.txt","a+");

        fwrite(&newUser, sizeof(newUser), 1, users);    
        ajout = 1;

    fclose(users);
    /*switch (exist)
    {
    case 0:
        
        if(strlen(addNewUser.passWord)<21){

            //if(chiffrement(newPassWord)==1){}
                ajout=1;
                fwrite(&addNewUser, sizeof(addNewUser), 1, users);
                //Si ajout = 1 alors "Le mot de passe doit faire au moins 8 caractères, ne doit pas dépasser les 20, doit avoir un chiffre et une maj"
        }   //else(strcpy(erreur, "Mot de passe trop court"));
        break;

    case 1:
        printf("test");
        ajout=0;
        //strcpy(erreur, "Login déja éxistant");
        // Login déja éxistant 
        break;

    }*/

    return ajout;
}

// Vérifie si le login et mot de passe respecte les critères

unsigned checkLogin(struct user newUser){
    
    int correct;

    if((strlen(newUser.login) < 21) && strlen(newUser.login) > 8){
        correct = 1;
    } else correct = 0;

    return correct;
}

unsigned checkPwd(struct user newUser){
    
    int correct;

    if((strlen(newUser.passWord) < 21) && strlen(newUser.passWord) > 8){
        correct = 1;
    } else correct = 0;

    return correct;
}

//Vérifie si le Login éxiste déja. Retourne 1 si c'est le cas, sinon retourne 0

unsigned checkExistUser(struct user newUser){

    int trouve=0;
    struct user User;

    FILE *users=NULL;
    users=fopen("users.txt","r");
    fseek(users, 0, SEEK_SET);

    while((!feof(users)) || (trouve!=1)){
        fread(&User, sizeof(struct user), 1, users);
        
        if((strcmp(User.login, newUser.login))==0) {

            trouve=1;

        } 
    }

    return trouve;
}

/*unsigned test();

unsigned test(){
     FILE *outfile;
     
    // open file for writing
    outfile = fopen ("users.txt", "a+");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }
 
    struct user input1 = {"test", "sharma"};
    struct user input2 = {"mahendra", "dhoni"};
     
    // write struct to file
    fwrite (&input1, sizeof(struct user), 1, outfile);
    fwrite (&input2, sizeof(struct user), 1, outfile);

    return 1;
     
}*/

int main(){
    struct user newUser = {"AdminLog", "AdminPwD"};
    int ajoutUser;
    char erreur;
    int exist;
    exist = checkExistUser(newUser);
    //ajoutUser=addUser(newUser);
    printf("%d", exist);
    sleep(1000);
}


/*main{

  Struct
  Appel checkLogin
  Appel checkPassWord

  Si c'est bon : Appel checkExistPlayer

  Si joueur n'éxiste pas : Appel addUser

}
*/