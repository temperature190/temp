//
// Created by aran on 05/08/22.
//
#include <stdlib.h>
#include <stdio.h>
/*!
 * "block" is an r-value, why does it produce a valid pointer for ch1
 * A: is it because "block" is in --q_ownership()'s stack frame?
 */
typedef struct chasm{
    char *s;
}Chasm;
Chasm *allocate_chasm(char *s){
    Chasm *ch1 = malloc(sizeof(Chasm));
    ch1->s = s;
    return ch1;
}
void q_ownership(){
    Chasm *ch_o = allocate_chasm("block");
    printf("%s\n", ch_o->s);
    printf("%p\n", ch_o->s);
}
/*!
 * This notation is very misleading - take note!
 */
void semi_dynamic_multidimensional_array(){
    int (*x)[16][4] = malloc(5*16*4*4);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 16; j++){
            for(int k = 0; k < 4; k++){
                x[i][j][k] = i * 100 + j * 10 + k;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 16; j++){
            for(int k = 0; k < 4; k++){
                printf(" %d",x[i][j][k]);
            }
            printf(" # ");
        }
        printf("\n");
    }
};
int main(){
    printf("radiology\n");
    return EXIT_SUCCESS;
}