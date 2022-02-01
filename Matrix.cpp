#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));
    for (int i = 0;i < rowsNum;++i ){
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }
    for (int i = 0 ; i < rowsNum ; ++i )
        for (int j = 0 ; j < colsNum ; ++j )
            matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){
    int num = 3;
    if (row<=0)
    {
        rowsNum=num;
    }
    else
    {
        rowsNum=row;
    }
    if (col<=0)
    {
        colsNum=num;
    }
    else
    {
        colsNum=col;
    }
     matrixData=NULL;
     matrixData = (int**)malloc(rowsNum*sizeof(int*));
        for (int i = 0 ; i < rowsNum ; ++i ){
           matrixData[i] = (int*) malloc(colsNum*sizeof(int));
        }

        for (int i = 0 ; i < rowsNum ; ++i )
            for (int j = 0 ; j < colsNum ; ++j ) //makes an empty matrix
                matrixData[i][j]=0;}

Matrix::Matrix(int row, int col, int** table){
    rowsNum=row;
    colsNum=col;
     matrixData=NULL;
     matrixData = (int**)malloc(rowsNum*sizeof(int*));
        for (int i = 0 ; i < rowsNum ; ++i ){
           matrixData[i] = (int*) malloc(colsNum*sizeof(int));}

        for (int i = 0 ; i < rowsNum ; ++i )
            for (int j = 0 ; j < colsNum ; ++j )
                matrixData[i][j]=table[i][j]; //copies table onto the matrix
}

int Matrix::getElement(int i, int j){
    if (i<0 || i>=rowsNum || j<0 || j>=colsNum){  //checks to see if input is invalid
        throw out_of_range("Invalid indexes.");}
        return matrixData[i][j];
}


bool Matrix::setElement(int x, int i, int j){
    if (i<0 || i>=rowsNum || j<0 || j>=colsNum){ //checks to see if input is invalid
        return false;}
    else{
        matrixData[i][j] = x;   // sets the value at specifying indexes
        return true;
        }
}

Matrix Matrix::copy()
{
    Matrix copy=  Matrix(rowsNum,colsNum,matrixData);
    return  copy;
}

void Matrix::addTo( Matrix m ){
    int i,j;
    if (m.rowsNum!=rowsNum || m.colsNum!=colsNum){   //checks to see if input is invalid
        throw invalid_argument("Invalid operation");
    }
     for (int i = 0 ; i < rowsNum ; ++i )
                for (int j = 0 ; j < colsNum ; ++j )
                    matrixData[i][j]+=m.matrixData[i][j];  //updates the matrix

}

Matrix Matrix::subMatrix(int i, int j){
    if (i>=rowsNum|| j>=colsNum){
        throw out_of_range("Submatrix not defined"); //creates a submatrix
    }
    Matrix subM = Matrix (i+1,j+1,matrixData);

    return  subM;
}

int Matrix::getsizeofrows(){
    return rowsNum;
}
int Matrix::getsizeofcols(){
    return colsNum;
}

bool Matrix::isUpperTr()
{
    for (int i = 0 ; i < (rowsNum-1) ; i++ )
        for (int j = 0 ; j <= i ; j++ )
            if(matrixData[i+1][j] != 0){ //finds the upper trace of the matrix
                return false;
            }
    return true;
}

string Matrix::toString()
{
    int i, j;
    string output="";
    for (i=0;i<rowsNum;i++){
        for (j=0;j<colsNum;j++){
            output+=to_string(matrixData[i][j])+" ";  //converts matrix into string form
        }
        output+="\n";
    }
     return output;
}
