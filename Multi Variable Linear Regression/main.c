#include <stdio.h>

typedef struct { // Creating a Structure For Storing the Read CSV file
    int *datastream;
    int row;
    int col;
    int initialcol;
}data_matrix;

double csv_reader(data_matrix *matrix, const char *file_location){
    FILE *file = fopen(file_location,"r");

    if(file == NULL){ //Checking If File Has Been Loaded Succesfully
        printf("Error Opening The File\n");
    }
    else{
        printf("Man let that begin !\n");
    }
}

int main(){
    char fileLocation[300];
    printf("Enter name of file : ");
    scanf("%s", fileLocation);
    
    data_matrix data;
    data.col = 2
    data.row = 0;
    data.row_cap= 2;

    data.datastream = malloc(data.col * data.row_cap * sizeof(double));

    csv_reader(&data,fileLocation);
}