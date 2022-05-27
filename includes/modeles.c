#include "projet.h"
#define DIM 50

MYSQL *sqlConnection = NULL;

int mainModeles(){
    
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



void creerTable(){
  executerSQL("DROP DATABASE IF EXISTS modeles");
  executerSQL("CREATE DATABASE modeles CHARACTER SET = 'utf8' COLLATE = 'utf8_general_cs'");
  executerSQL("USE modeles");
  executerSQL("CREATE TABLE modele(Id INT(11) NOT NULL AUTO_INCREMENT, NAME VARCHAR(20) NOT NULL, NiceName VARCHAR(20) NOT NULL, MakeId INT(11) NOT NULL, PRIMARY KEY(Id))");
}


struct marques{
  int Id;
  char Name[20];
  char NiceName[20];
  struct modeles{
    int Id;
    char Name[20];
    char NiceName[20];
    int MakeId;
};
};




void remplirTable(){

  int id, makeId, retour=1;
  char *inserer = (char *)malloc(1024), result, erreur [DIM], name, niceName;

  FILE *modeles=NULL;
  modeles=fopen("marques_modeles.txt","r+");
  struct marques marq;
  struct modeles mod;
  
    while(!feof(modeles)){
        
        fread(&mod, sizeof(struct modeles), 1, modeles);
        if(jsonPrimitive(&mod,mod.Id,result,DIM,erreur)){
          id=result;
        } else{
          retour=0;
        }
        if(jsonPrimitive(&mod,mod.Name,result,DIM,erreur)){
          name=result;
        }
        else{
          retour=0;
        }
        if(jsonPrimitive(&mod,mod.NiceName,result,DIM,erreur)){
         niceName=result;
        } else{
          retour=0;
        }
        if(jsonPrimitive(&marq,marq.Id,result,DIM,erreur)){
          makeId=result;
        } else {
          retour=0;
        }
        sprintf(inserer, "INSERT INTO MODELES (Id, Name, NiceName, MakeId) VALUES (id, name, niceName, makeId)");
        

    }
    
}



void listModeles(char * listModeles, char niceName, int nbElements, char * erreur){
  
   // tri de la table
    int i=0;
    char list[DIM], resultats[DIM][DIM], erreur[DIM];
    MYSQL_RES *sqlResult = SqlSelect("SELECT * FROM MODELES ORDER BY NAME ASC FOR JSON PATH, ROOT('Modeles')");

    if(jsonArray(sqlResult,niceName, resultats, nbElements, erreur)){
      for(i=0;i<nbElements;i++){
        listModeles[i]=resultats[i][1]; //garnit la liste avec le nom du modèle
      }
    } 
    

}