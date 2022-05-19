#include "../includes/json.h"
#include "../unity/unity.h"
#include "../includes/projet.h"

#define DIM 100

static char erreur[DIM];
static char expression[DIM];
static char expressionMatrice[][DIM];

void setUp(void)
{ // appel�e avant chaque test
    strcpy(erreur, "");
}

void test_jsonPrimitive(){
    FILE *fichJson=NULL;
    struct fichJson *json;
    char NomAttribut="name";
    TEST_ASSERT_EQUAL_INT(1,jsonPrimitive(json,NomAttribut,expression,DIM,erreur));
}

void test_jsonArray(){
    FILE *fichJson=NULL;
    struct fichJson *json;
    char NomAttribut="Acura";
    int nbElement=0;
    TEST_ASSERT_EQUAL_INT(1,jsonArray(json,NomAttribut,expressionMatrice,nbElement,erreur));
}

int testJson()
{
    UNITY_BEGIN();
    RUN_TEST(test_jsonPrimitive);
    RUN_TEST(test_jsonArray);
    UNITY_END();
    return 0;
}