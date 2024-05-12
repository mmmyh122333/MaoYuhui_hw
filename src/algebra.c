#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    // ToDo
    Matrix m;
    int i,k;
    if(a.rows == b.rows && a.cols == b.cols)
    {
        for(i = 0; i < a.rows; i++)
        {
            for(k = 0; k < a.cols; k++ )
            {
                m.data[i][k] = b.data[i][k] + a.data[i][k]; 
            }
        }
        return m;
    }
    else printf("Error: Matrix a and b must have the same rows and cols.\n");
    return create_matrix(0, 0);
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    // ToDo
    Matrix m;
    int i,k;
    if(a.rows == b.rows && a.cols == b.cols)
    {
        for(i = 0; i < a.rows; i++)
        {
            for(k = 0; k < a.cols; k++ )
            {
                m.data[i][k] = b.data[i][k] - a.data[i][k]; 
            }
        }
        return m;
    }
    else printf("Error: Matrix a and b must have the same rows and cols.\n");
    return create_matrix(0, 0);
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // ToDo
    Matrix m;//
    Matrix m2;//过渡矩阵
    int i , k ,j;
    if(a.cols == b.rows)
    {
        for(i = 0; i < a.rows ;i++)
        {
            for(j = 0; j < b.cols; j++)
            {
                for(k = 0; k < a.cols; k++)
                {
                    m2.data[i][j] = a.data[i][k] + b.data[k][j];
                    m.data[i][j] = m.data[i][j] + m2.data[i][j]; 
                }
            }
        }
        return m;
    }
    else{
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
    }
    return create_matrix(0, 0);
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    Matrix m;
    int i, j;
    for(i = 0; i < a.rows; i++){
        for(j = 0; j < a.cols; j++){
            m.data[i][j] = a.data[i][j] * k;
        }
    }
    return m;
}
//做到这里
Matrix transpose_matrix(Matrix a)
{
    // ToDo
    Matrix m;
    int i, j;
    for(i = 0; i < a.rows; i++){
        for(j = 0;j < a.cols; j++){
            m.data[j][i] = a.data[i][j];
        }
    }
    return m;
}

double det_matrix(Matrix a)
{
    // ToDo
    int det;
    int i,j,k;
    if(a.cols == a.rows)
    {

    }
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    int trace = 0;
    int i;
    if(a.cols == a.rows)
    {
        for(i = 0; i < a.rows;i++)
        {
            trace = trace + a.data[i][i];
        }
        return trace;
    }
    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}