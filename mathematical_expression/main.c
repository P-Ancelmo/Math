#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXDIGIT 10

typedef struct{
    int x;
    int y;
}resultado;

int main(int argc, char* argv[]){
    char* str;
    int range = 10;

    if(argc > 2){
        str=argv[1];
        range = atoi(argv[2]);
    }
    else
        str = "5*2*2*5*2/2/10";    


    printf("%s\n", str);
    
    char** pilha;
    resultado* result = (resultado*) malloc(sizeof(resultado)*range+2+1);    
    //int cont, in;

    for(int i = -range; i <= range; i++){

        pilha = (char**) malloc(sizeof(char*)* strlen(str)+1);        
        for(int k = 0; k < strlen(str)+1; k++){
            pilha[k] = (char*) malloc(sizeof(char)*MAXDIGIT);
        }

        int cont = 0, in = 0;
        
        while(cont <= strlen(str)){
            
            if((str[cont] == '*' || str[cont] == '/' || str[cont] == '+' || str[cont] == '-' || str[cont] == '\0') && in >= 3){
                
                if(!strcmp(pilha[in-2], "*")){
                    //printf("%s * %s\n", pilha[in-1], pilha[in-3]);
                    sprintf(pilha[in-3], "%d", atoi(pilha[in-1])*atoi(pilha[in-3]));
                    in-=2;
                }
                else{                   
                    if(!strcmp(pilha[in-2], "/")){                        
                        sprintf(pilha[in-3], "%d", atoi(pilha[in-3])/atoi(pilha[in-1]));
                        in-=2;
                    }
                }
                if(str[cont] != '\0'){
                    sprintf(pilha[in], "%c", str[cont]);
                }                
               
            }
            else{
                if(str[cont] > '0' && str[cont] < '9'){
                    
                    sprintf(pilha[in], "%d", atoi(str+cont));
                    
                   
                }
                else{
                    
                    if(str[cont] == 'x')
                        sprintf(pilha[in], "%d", i);
                    else
                        sprintf(pilha[in], "%c", str[cont]);
                }
                
            }
            
            if(cont != strlen(str) && str[cont] != 'x')
                cont += strlen(pilha[in]);
            else
                cont++;            
            in++;
           
        }
        cont = 1;
        
        while(cont < in-1){
            if(!strcmp(pilha[1], "+")){
                //printf("%s + %s\n", pilha[0], pilha[2]);
                sprintf(pilha[0], "%d", atoi(pilha[0]) + atoi(pilha[2]));            
            }
            else{
                if(!strcmp(pilha[1], "-")){
                    //printf("%s - %s\n", pilha[0], pilha[2]);
                    sprintf(pilha[0], "%d", atoi(pilha[0]) - atoi(pilha[2]));
                }
            }
            for(int j = 1; j < in-cont+1; j++){
                
                if(j+2 < in){
                    pilha[j] = pilha[j+2];
                    
                }
                
            }            
            cont+=2;
        }
        result[i+range].x=i;
        result[i+range].y=atoi(pilha[0]);        
    }
    
    // cont = 1;
        
    // while(cont < in-1){
    //     if(!strcmp(pilha[1], "+")){
    //         printf("%s + %s\n", pilha[0], pilha[2]);
    //         sprintf(pilha[0], "%d", atoi(pilha[0]) + atoi(pilha[2]));            
    //     }
    //     else{
    //         if(!strcmp(pilha[1], "-")){
    //             printf("%s - %s\n", pilha[0], pilha[2]);
    //             sprintf(pilha[0], "%d", atoi(pilha[0]) - atoi(pilha[2]));
    //         }
    //     }
    //     for(int i = 1; i < in-cont; i++){
    //         pilha[i] = pilha[i+1];
    //     }
    //     cont++;
    // }
    for(int i=0;i <= range*2;i++){
        printf("[%d,%d]\n", result[i].x,result[i].y);
    }
    free(pilha);
    free(result);
}