#include "projet.h"
#define DIM 50

MYSQL *sqlConnection = NULL;

int mainMarques(){
    
    // Creer les tables de la DB et les remplir avec le fichier
    char erreur;
    creerTables();
    if(remplirTables()==0){
      printf(erreur);
    }
    
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

  // Connexion à la db + contrôle du résultat
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
  char createTable="executerSQL(CREATE TABLE marques(Id INT(11) NOT NULL AUTO_INCREMENT, NAME VARCHAR(20) NOT NULL, NiceName VARCHAR(20) NOT NULL, PRIMARY KEY(Id)))";

  if (mysql_query(sqlConnection, createTable)){
    create=0; //La table n'a pas été créée
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    mysql_close(sqlConnection);
    exit(EXIT_FAILURE);
  }
  return create;
}

struct marques{
  int Id;
  char Name[20];
  char NiceName[20];
};

int remplirTable(){

  char *inserer = (char *)malloc(1024);
  int id,retour=1;
  char name, niceName,result,erreur;

  FILE *marques=NULL;

  struct marques marq;

    while(!feof(marques)){
        
        fread(&marq, sizeof(struct marques), 1, marques);
        if(jsonPrimitive(&marq,marq.Id,result,DIM,erreur)){
          id=result;
        } else{
          retour=0;
        }
        if(jsonPrimitive(&marq,marq.Name,result,DIM,erreur)){
          name=result;
        }
        else{
          retour=0;
        }
       if(jsonPrimitive(&marq,marq.NiceName,result,DIM,erreur)){
         niceName=result;
       } else{
          retour=0;
        }
        sprintf(inserer, "INSERT INTO MARQUES (Id, Name, NiceName) VALUES (id, name, niceName)");

    }

    return retour;
    
}

void listMarques(char * listMarques, int nbElements){
     // tri de la table
    int i=0;
    
    MYSQL_RES *sqlResult = SqlSelect("SELECT * FROM MARQUES ORDER BY NAME ASC");
    MYSQL_ROW sqlRow;
    while(sqlRow= mysql_fetch_row(sqlResult)){
      //Lecture ligne par ligne et remplissage de la liste
      strcpy(listMarques[i],sqlRow[1]);//remplissage de la cellule par la champ de la DB qui contient le nom de la marque
      i+=1;
    }
    nbElements=i;
    
}