#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    TWO RANDOM MATRIX where created from user specified rows and columns and matrix multiplication
    for both are done in two different threads.
    
*/

mutex m;

vector<vector<int>> matrixmultiplication(vector<vector<int>> matrix_1,vector<vector<int>> matrix_2){
    
    
    vector<vector<int>> res_matrix(matrix_1.size(),vector<int>(matrix_2[0].size(),0));
   
  
  /*
  matrix multiplication.
  */
  for(int l1=0;l1<matrix_1.size();l1++){
      for(int l2=0;l2<matrix_2[0].size();l2++){
          for(int c=0;c<matrix_2.size();c++){
             
              res_matrix[l1][l2]+=(matrix_1[l1][c]*matrix_2[c][l2]);
          }
      }
  }
  
  return res_matrix;
}

int main()
{
    int m1_row,m1_col,m2_row,m2_col;
   cout<<"Enter Rows for Matrix 1"<<endl;      cin>>m1_row;
   cout<<"\nEnter Columns for Matrix 1"<<endl; cin>>m1_col;
   cout<<"\nEnter Rows for Matrix 2"<<endl;    cin>>m2_row;
   cout<<"\nEnter Columns for Matrix 2"<<endl; cin>>m2_col;
   
    if(m1_col!=m2_row){
      cout<<"Matrix multiplication cannot be done"<<endl;
      return 0;
  }
   
    /*
        two vectors are created according to user specified rows and columns
    */
   vector<vector<int>> mat1(m1_row,vector<int>(m1_col,0));
   vector<vector<int>> mat2(m2_row,vector<int>(m2_col,0));
   
   vector<vector<int>> res_matrix1(mat1.size(),vector<int>(mat2[0].size(),0));
   vector<vector<int>> res_matrix2(mat1.size(),vector<int>(mat2[0].size(),0));
   
   
      
 /*
    random values are assigned to the two vectors
 */
  for(int row=0;row<m1_row;row++){
      for(int col=0;col<m1_col;col++){
          mat1[row][col]=rand()%10;
      }
  }
   
  for(int row=0;row<m2_row;row++){
      for(int col=0;col<m2_col;col++){
          mat2[row][col]=rand()%10;
      }
  }
  
/*
    two threads for matrix multiplication are called.
*/
 
    future<vector<vector<int>>> fut1=async(matrixmultiplication,mat1,mat2);
    future<vector<vector<int>>> fut2=async(matrixmultiplication,mat1,mat2);
  
  
  
   cout<<"MATRIX 1 :"<<endl;
   for(auto &r:mat1){
      for(int c:r){
          cout<<c<<" ";
      }
      cout<<endl;
  }
  cout<<"MATRIX 2 :"<<endl;
  for(auto &r:mat2){
      for(int c:r){
          cout<<c<<" ";
      }
      cout<<endl;
  }
  
  
  /*
  resultant matrix are returned back
  */
  res_matrix1=fut1.get();
  res_matrix2=fut2.get();
  
   cout<<"RESULTANT MATRIX FROM THREAD 1 :"<<endl;
   for(auto &r:res_matrix1){
      for(int c:r){
          cout<<c<<" ";
      }
      cout<<endl;
  }
  
   cout<<"RESULTANT MATRIX FROM THREAD 2 :"<<endl;
   for(auto &r:res_matrix2){
      for(int c:r){
          cout<<c<<" ";
      }
      cout<<endl;
  }

    return 0;
}
