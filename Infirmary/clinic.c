#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void trim_text(char *str){
    // get string length
    size_t len = 0;
    for(; str[len] != '\0'; len++){}

    char *word = (char *)calloc(len, 1);
    char *new_str = (char *)calloc(len, 1);

    size_t i = 0;
    size_t n = 0;
    for(size_t j = 0; i < len + 1; i++){
        if(!isspace(str[i]) && str[i] != '\0'){
            word[j++] = str[i];
        }
        else{
            for(size_t k = 1; k < j - 1; k++, n++){
                new_str[n] = word[k];
            }

            // forward string to next word
            for(;isspace(str[i]); i++){}

            if(str[i] == '\0') {break;}
            else {
                i--;
                new_str[n++] = ' ';
                j = 0;
            }
        }
    }

    // copy new string back to string
    for(i = 0; i < n; i++){
        str[i] = new_str[i];
    }
    str[i] = '\0';

    free(word);
    free(new_str);
}

int main(){
    char str[12] = "Hello World!";
    trim_text(str);
    printf("%s", str);
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void trim_text(char *str){
    // get string length
    size_t len = 0;
    for(; str[len] != '\0'; len++){}

    char *word = (char *)calloc(len, 1);
    char *new_str = (char *)calloc(len + 1, 1);

    size_t i = 0;
    size_t n = 0;
    for(size_t j = 0; i < len + 1; i++){
        if(!isspace(str[i]) && str[i] != '\0'){
            word[j++] = str[i];
        }
        else if(j){
            for(size_t k = 1; k < j - 1; k++, n++){
                new_str[n] = word[k];
            }

            if(str[i] == '\0') {
                new_str[n] = '\0';
                break;
            }
            else {
                i--;
                if(new_str[n - 1] != ' ' && n){
                    new_str[n++] = ' ';
                }
                j = 0;
            }
        }
    }
    printf("%s", new_str);

    free(word);
    free(new_str);
}

int main(){
//    char str[60] = "        .....space, the   final    frontier.......        ";
//    trim_text(str);
    char word[] =  "";
    if(*word){
        printf("true");
    }
}