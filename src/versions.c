#include "../header/projet.h"
#define DIM 50
MYSQL *sqlConnection = NULL;

int mainVersions(){
    
    // Creer les tables de la DB et les remplir avec le fichier
    creerTables();
    remplirTables();
    
    return(0);
}
void initialiserConnexion()
{
  sqlConnection = mysql_init(NULL);
  if (sqlConnection == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    exit(EXIT_FAILURE);
  }

  // Connect the Database and check the result
  if (!mysql_real_connect(sqlConnection, "localhost", "root",
                          NULL, NULL, 3306, NULL, 0))
  {
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    exit(EXIT_FAILURE);
  }
}


void cloturerConnexion()
{
  if (sqlConnection != NULL)
  {
    mysql_close(sqlConnection);
  }
}

void executerSQL(char *instructionSQL)
{
  if (mysql_query(sqlConnection, instructionSQL))
  {
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    mysql_close(sqlConnection);
    exit(EXIT_FAILURE);
  }
}



int insererDonnee(char *instructionSQL)
{
  if (mysql_query(sqlConnection, instructionSQL))
  {
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    mysql_close(sqlConnection);
    exit(EXIT_FAILURE);
  }
  MYSQL_RES *sqlResult = mysql_store_result(sqlConnection);
  if (sqlResult == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    mysql_close(sqlConnection);
    exit(EXIT_FAILURE);
  }
  MYSQL_ROW sqlRow = mysql_fetch_row(sqlResult);
  if (sqlRow == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    mysql_close(sqlConnection);
    exit(EXIT_FAILURE);
  }
  int id = atoi(sqlRow[0]);
  return id;
}



int creerTable(){
  int create=1;
  executerSQL("DROP DATABASE IF EXISTS marques");
  executerSQL("CREATE DATABASE marques CHARACTER SET = 'utf8' COLLATE = 'utf8_general_cs'");
  executerSQL("USE marques");
  char createTable="executerSQL(CREATE TABLE marques(Id INT(11) NOT NULL AUTO_INCREMENT, NAME VARCHAR(20) NOT NULL, Powers VARCHAR(20) NOT NULL, ModelNiceName VARCHAR(20) NOT NULL, PRIMARY KEY(Id)))";

  if (mysql_query(sqlConnection, createTable)){
    create=0; //La table n'a pas été créée
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    mysql_close(sqlConnection);
    exit(EXIT_FAILURE);
  }
  return create;
}

struct versions{
  int Id;
  char Name[20];
  char Powers[20];
  char ModelNiceName[20];
};

int remplirTable(){

  char *inserer = (char *)malloc(1024);
  int id;
  char name, modelNiceName,result,erreur,retour=1;

  FILE *versions=NULL;

  struct versions vers;

    while(!feof(versions)){
        
        fread(&vers, sizeof(struct user), 1, versions);
        if(jsonPrimitive(&vers,vers.Id,result,DIM,erreur)){
          id=result;
        } else{
          retour=0;
        }
        if(jsonPrimitive(&vers,vers.Name,result,DIM,erreur)){
          name=result;
        }
        else{
          retour=0;
        }
       if(jsonPrimitive(&vers,vers.Powers,result,DIM,erreur)){
         powers=result;
       } else{
          retour=0;
        }
        if(jsonPrimitive(&vers,vers.ModelNiceName,result,DIM,erreur)){
         modelNiceName=result;
       } else{
          retour=0;
        }
        sprintf(inserer, "INSERT INTO personne (Id, Name, Powers, ModelNiceName) VALUES (id, name, powers, modelNiceName)");

    }

    return retour;
    
}
