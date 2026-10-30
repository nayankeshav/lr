#include<stdio.h>

#define COL 4
#define ROW 4

typedef struct{
    double mat[ROW][COL];
}matrix_data;

int main(){
    matrix_data data;
    printf("Value Limit Set @ : %d\n", ROW);

    FILE *file = fopen("data_t.csv","r");
    if(file == NULL){
        printf("error opening file\n");
        return 0;
    }

    char dump[300];
    fgets(dump,sizeof(dump),file);

    //reading CSV file to struct
    for(int i = 0; fscanf(file,"%lf %*[,;] %lf %*[,;] %lf %*[,;] %lf", &data.mat[i][0],&data.mat[i][1],&data.mat[i][2],&data.mat[i][3]) == 4;i++){
    }

    double y[ROW]; // building the y matrix
    for(int i = 0; i<ROW; i++){
        y[i] = data.mat[i][COL-1];
    }

    double x[ROW][COL]; // building the x matrix
    for(int i = 0; i<ROW; i++){
        for(int j = 1; j < COL; j++){
            x[i][0] = 1;
            x[i][j] = data.mat[i][j-1];
        }
    }    

    double xt[COL][ROW];
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j < COL; j++){
            xt[j][i] = x[i][j];
        }
    }
    
    double xtx[COL][ROW];
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j < COL; j++){
            xtx[i][j] = 0;
            for(int k = 0; k < ROW; k++){
                xtx[i][j] = xtx[i][j] + (xt[i][k] * x[k][j]);
            }
        }
    }

    double xty[ROW];
    for(int i = 0; i< ROW; i++){
        xty[i] = 0;
        for(int j = 0; j < ROW; j++){
            xty[i] = xty[i] + (y[j] * xt[i][j]);
        }
    }

}