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
    xy_data data; // Declaring a Single Instance
    
    file = fopen("data.csv","r");

    if(file == NULL){
        printf("Error opening file\n");    
    }

    //Reading CSV file to struct 
    for(int i = 0;fscanf(file, "%lf,%lf",&data.x[i],&data.y[i]) == 2; i++){
        number_of_data++;
    }

    //Least Mean Square
    double xy = 0; 
    double x = 0;
    double y = 0; 
    double x2 = 0;
    for(int i = 0; i < number_of_data; i++){
        xy = xy + (data.x[i]*data.y[i]); //sum of all xy
        x = x + data.x[i]; //sum of all x
        y = y + data.y[i]; //sum of all y
        x2 = x2 + (data.x[i]*data.x[i]); //sum of all x^2
    }

    double b = ((number_of_data*(xy)) - (x*y))/( (number_of_data * x2) - (x*x));
    double a = (y - (b*x))/number_of_data;

    printf("Y = BX + A\n");
    printf("Y = %lfX + %lf\n",b,a);

}