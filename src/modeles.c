#include "../header/projet.h"
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



struct modeles{
  int Id;
  char Name[20];
  char NiceName[20];
  int MakeId;
};



void remplirTable(){

  char *inserer = (char *)malloc(1024);

  FILE *modeles=NULL;

  struct modeles mod;

    while(!feof(modeles)){
        
        fread(&mod, sizeof(struct user), 1, modeles);
        sprintf(inserer, "INSERT INTO personne (Id, Name, NiceName, MakeId) VALUES (modeles.Id, modeles.Name, modeles.NiceName, modeles.MakeId)");

    }
    
}



void listModeles(char * listModeles, char niceName){

  char listJson[DIM],list[DIM];
  int i;
  unsigned *nbElements;
  FILE *modeles=NULL;

  struct modeles mod;
  listJson=jsonArray(char &modeles, char *mod.nom, char niceName, char resultats[][DIM], unsigned *nbElements, char erreur);
  
  for(i=0;i<nbElements;i++){
      if(niceName == mod.NiceName){

          list[i]=listJson[i][3];

      i=nbElements+1;
      }
  }

  for (i=0;i < nbElements;i++){

    listMarques[i]=list[i];

  }

  for (i=0;i < nbElements-1;i++){

    if (list[i]>list[i+1]){

      listModeles[i]=list[i+1];
      listModeles[i+1]=list[i];

    }
  }

}