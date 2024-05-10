#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

#include <string.h>

//void print_stacktrace()
//{
//    int size = 16;
//    void * array[16];
//    int stack_num = backtrace(array, size);
//    char ** stacktrace = backtrace_symbols(array, stack_num);
//    for (int i = 0; i < stack_num; ++i)
//    {
//        printf("array[i]: %d\n", *(int *)array[i]);
//        printf("%s\n", stacktrace[i]);
//    }
//    free(stacktrace);
//}
//
//typedef struct {
//    int a, b, c;
//}Triangle;
//
//#define SIDE_COUNT 3
//#define STR_COUNT 19
//#define ASCII_OF_ZERO 48
//#define NUMBER_BASE 10
//#define SEPARATOR ','
//#define LINE_SEPARATOR '\n'
//
//int get_triangle(Triangle* ptr){
//    char str[STR_COUNT] = {0};
//    if(fgets(str, STR_COUNT, stdin) == NULL)
//        return EXIT_FAILURE;
//    int sides[SIDE_COUNT] = {0};
//
//    for(int i = 0, j = 0; i < SIDE_COUNT; i++, j++){
//
//        // add digit
//        while(str[j] != SEPARATOR && str[j] != LINE_SEPARATOR){
//            sides[i] *= NUMBER_BASE;
//            sides[i] += (int)(str[j++] - ASCII_OF_ZERO);
//        }
//        // next number
//    }
//    ptr->a = sides[0];
//    ptr->b = sides[1];
//    ptr->c = sides[2];
//    return EXIT_SUCCESS;
//}
//
//int get_trs(){
//
//    // list of triangles on heap
//    Triangle *tr_list = malloc(sizeof(Triangle));
//
//    // check malloc success
//    if(tr_list == NULL)
//        return EXIT_FAILURE;
//
//    // get unlimited triangles from input
//    int i = 0;
//    while(!get_triangle(&tr_list[i++])) {
//        tr_list = realloc(tr_list, (i+1) * sizeof(Triangle));
//
//        // check realloc success
//        if(tr_list == NULL)
//            return EXIT_FAILURE;
//        if(i == 4)
//            break;
//    }
//
//    tr_list = realloc(tr_list, (i-2) * sizeof(Triangle));
//
//    // check realloc success
//    if(tr_list == NULL)
//        return EXIT_FAILURE;
//    i-=2;
//    // print out triangles in reverse order
//    for(; i > -1; i--){
//        printf("%d,%d,%d\n", tr_list[i].a, tr_list[i].b, tr_list[i].c);
//    }
//
//    return EXIT_SUCCESS;
//}
//
#include <stdio.h>
#include <stdlib.h>
//
//#define BASE 10
//#define ZERO_CHR '0'
//
//int main()
//{
//    char buffer[10];
//    char *ptr;
//    size_t digit_count;
//
//    char *digit_chr = NULL;
//    size_t input_B = 0;
//
//    scanf("%s", buffer);
//    digit_count = strtol(buffer, &ptr, BASE);
//    for(size_t i = 0; i < digit_count; i++){
//        scanf("%c", digit_chr);
//        input_B +=  *digit_chr - ZERO_CHR;
//    }
//
//    printf("%zu\n", input_B);
//}

