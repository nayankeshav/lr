#include <stdio.h>
#define MAX 1000

typedef struct {
    double x[MAX];
    double y[MAX];
} xy_data;

int main(){
    int number_of_data = 0;

    printf("Vale Limit Set At : %d \n",MAX);

    printf("Reading Data\n");
    FILE *file;
    xy_data data;
    
    file = fopen("data.csv","r");

    if(file == NULL){
        printf("Error opening file\n");    
    }

    for(int i = 0;fscanf(file, "%lf,%lf",&data.x[i],&data.y[i]) == 2; i++){
        number_of_data++;
    }
    printf("All Data Read\n");

}