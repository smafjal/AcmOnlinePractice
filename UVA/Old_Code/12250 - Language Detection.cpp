#include<stdio.h>
#include<string.h>
        /**HELLO
HOLA
HALLO
BONJOUR
CIAO
ZDRAVSTVUJTE

Case 1: ENGLISH
Case 2: SPANISH
Case 3: GERMAN
Case 4: FRENCH
Case 5: ITALIAN
Case 6: RUSSIAN
 **/

int main()
{
    char arr[100];
    int i=1;
    while(scanf(" %s",arr)==1)
    {
        if(!(strcmp(arr,"#")))break;
        else if(!(strcmp(arr,"HELLO")))printf("Case %d: ENGLISH\n",i);
        else if(!(strcmp(arr,"HOLA")))printf("Case %d: SPANISH\n",i);
        else if(!(strcmp(arr,"HALLO")))printf("Case %d: GERMAN\n",i);
        else if(!(strcmp(arr,"BONJOUR")))printf("Case %d: FRENCH\n",i);
        else if(!(strcmp(arr,"CIAO")))printf("Case %d: ITALIAN\n",i);
        else if(!(strcmp(arr,"ZDRAVSTVUJTE")))printf("Case %d: RUSSIAN\n",i);
        else printf("Case %d: UNKNOWN\n",i);
        i++;
    }
    return 0;
}
