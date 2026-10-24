#include <stdio.h>
#include <math.h>
#define MAX 2000

typedef struct {
    double x[MAX];
    double y[MAX];
} xy_data;

double rmse(double a, double b, int number_of_data, double x_array[], double y_array[]){
    double result;
    double intermidate = 0;
    for(int j = 0; j < number_of_data; j++){
        intermidate = intermidate + (y_array[j] - ((b*x_array[j]) + a)) * (y_array[j] - ((b*x_array[j]) + a));
    }
    result = sqrt(intermidate/number_of_data);
    return result;
}

int main(){
    int number_of_data = 0;

    printf("Vale Limit Set At : %d \n",MAX);

    FILE *file;
    xy_data data; // Declaring a Single Instance
    
    file = fopen("data.csv","r");
    if(file == NULL){
        printf("Error opening file\n");    
    }

    char dump[300];
    fgets(dump,sizeof(dump),file);

    //Reading CSV file to struct 
    for(int i = 0;fscanf(file, "%lf %*[,;] %lf",&data.x[i],&data.y[i]) == 2; i++){
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

    //Root Mean Squaed Error, actual output and Predicted value
    double rmse_value = rmse(a,b,number_of_data,data.x,data.y);

    printf("Y = BX + A\n");
    printf("Y = %lfX + %lf\n",b,a);
    printf("RMS Error : %lf\n",rmse_value);

    

}