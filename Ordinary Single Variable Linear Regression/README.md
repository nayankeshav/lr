# Simple Linear Regression in C (Least Mean Square)
 
A lightweight C implementation of **Simple Linear Regression** using the **Least Mean Square (LMS) / Ordinary Least Squares (OLS)** method. The program reads paired feature data from a CSV file, calculates the line of best fit, evaluates accuracy using **Root Mean Squared Error (RMSE)**, and lets you make predictions interactively.
 
## Model Mathematical Formulation
 
The linear relationship between the independent predictor *X* and the dependent target variable *Y* is modeled as:
 
```text
Y = B·X + A
```
 
Where:
 
* **Y**: Predicted output variable (e.g., wine quality rating)
* **X**: Input feature variable (e.g., alcohol percentage)
* **B**: Slope coefficient
* **A**: Y-intercept coefficient
### 1. Closed-Form Parameter Calculations
 
The parameters **B** and **A** are calculated by minimizing the sum of squared residuals. Here *N* is the number of data points and each sum runs from *i* = 1 to *N*.
 
**Slope (B):**
 
```text
        N·Σ(Xᵢ·Yᵢ) − (ΣXᵢ)·(ΣYᵢ)
B  =  ───────────────────────────
          N·Σ(Xᵢ²) − (ΣXᵢ)²
```
 
**Intercept (A):**
 
```text
        ΣYᵢ − B·ΣXᵢ
A  =  ───────────────
              N
```
 
### 2. Root Mean Squared Error (RMSE)
 
The overall prediction error across the dataset is measured using RMSE:
 
```text
RMSE = √( (1/N) · Σ( Yᵢ − (B·Xᵢ + A) )² )
```
 
## Dataset & Memory Allocation
 
The implementation relies on a pre-allocated fixed array size via a macro definition:
 
```c
#define MAX 2000
```
 
### Allocation Rationale
 
* The standard **Red Wine Quality dataset** (`winequality-red.csv`) contains **1,599 data rows**.
* Setting `MAX` to `2000` provides a sufficient memory buffer for the dataset without dynamic re-allocation overhead.
* **Note on manual sizing**: If you process datasets larger than 2,000 records, the `MAX` macro must be increased manually.
## Code Architecture
 
```text
├── main.c           # Dataset loading, OLS math, and prediction loop
└── data.csv         # Input dataset (header in 1st row, followed by paired X and Y values)
```
 
### Key Functions & Logic
 
1. **`xy_data` struct**: Holds parallel static arrays `x[MAX]` and `y[MAX]` inside a single structure instance.
2. **`RMSE`**: Iterates through the stored data points to compute the residual error between actual *Y* and predicted *Ŷ = B·X + A*.
3. **File parsing (`fgets` & `fscanf`)**: Skips the CSV header line and increments the dataset count (`number_of_data`) while parsing each row.
4. **Prediction loop**: Keeps running after model fitting, so you can enter any value of *X* and get the predicted *Y* on demand.
## How to Build & Run
 
### Prerequisites
 
* GCC or any standard C compiler
### 1. Compilation
 
Compile the program and link the math library with the `-lm` flag:
 
```bash
gcc main.c -o main -lm
```
 
### 2. Execution
 
Make sure `data.csv` is in the same directory as the compiled binary:
 
```bash
./main
```
