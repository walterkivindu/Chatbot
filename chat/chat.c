#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
void chat(char * y){
    FILE* stream = fopen("data.csv", "r");
    char line[1024];
    
    time_t rawtime;
    struct tm * timeinfo;
    if(!strcmp(y,"What is the time"))
        {
            time ( &rawtime );
            timeinfo = localtime ( &rawtime );
            printf("\033[42m The time is %s\n",asctime (timeinfo));
        }
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        char* bb =strdup(line);
        char* se=getfield(tmp, 1);
        if(!strcmp(se,y)){
            printf("\033[42m%s\n\n",getfield(bb, 2));
        } 
        
    }
    printf("\033[0m");
}

int main()
{
    printf("\033[34mListening....type something >");
        const char  y[1024];
        gets(y);
        while(strcmp(y,"exit")!=0){
            chat(y);
            printf("\033[34mListening....type something >");
            gets(y);
        }
        system("clear");
        printf("Bye!\n");
}