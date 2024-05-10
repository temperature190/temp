#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef void * GridElement;
typedef void (*PrintElem)(GridElement);
typedef struct Grid {
    size_t rows;
    size_t cols;
    GridElement *array;
    PrintElem print_func;
}Grid;
void printGrid(Grid *g);
Grid * create_grid(int rows, int cols, PrintElem print_func)
{
    if(print_func == NULL || rows < 1 || cols < 1){
        return NULL;
    }

    Grid *grid = (Grid *)malloc(sizeof(Grid));
    if(!grid){
        return NULL;
    }

    grid->rows = rows;
    grid->cols = cols;
    grid->print_func = print_func;

    grid->array = (GridElement *)calloc(rows * cols, sizeof(GridElement));
    if(!grid->array){
        free(grid);
        return NULL;
    }

    printf("grid:\n");
    printGrid(grid);

    return grid;
}

int add_to_grid(Grid *g, int row, int col, GridElement new_elem) {
    if(g->array[row * g->cols + col] == NULL){
        g->array[row * g->cols + col] = new_elem;

        printf("added: ");
        g->print_func(new_elem);
        printf("\n");
        return 0;
    }
    printf("not added: ");
    g->print_func(new_elem);
    printf("\n");
    return -1;
}

void free_grid(Grid **g) {
     free((*g)->array);
     free(*g);
     *g = NULL;
}

void printGrid(Grid *g) {
    for(size_t i = 0; i < g->rows * g->cols; i++){
        if(g->array[i]){
            g->print_func(g->array[i]);
            printf(",");
        }
    }
}
void printString(void *elem){
    printf("%s", (char *)elem);
}
int main(){

// twice same string - ok
//    Grid *g = create_grid(20, 12, printString);
//    char *str1 = "Exam";
//    char *str2 = "Exam2";
//    add_to_grid(g, 10, 1, str1);
//    add_to_grid(g, 12, 1, str2);
//    add_to_grid(g, 12, 3, str2);
//    printGrid(g);
//    free_grid(&g);

    int *x = NULL, *y = NULL;
    printf("%p, %p", x, y);
}