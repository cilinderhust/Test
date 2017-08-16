/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lin
 *
 * Created on March 2, 2017, 10:03 AM
 */

//#include <stdafx.h>
#include <cstdlib>
#include <iostream>

using namespace std;

void PrintMatrixInCircle (int** number, int rows, int columns, int start) {
    int startX = start;
    int startY = start;
    int endX = columns - start - 1;
    int endY = rows - start - 1;
    
    // determine if print the top row
    if (endX >= startX) {
        for (int i = startX; i <= endX; ++i)
            std::cout << number[startY][i] << " ";
    }
    // determine if print the right column
    if (endY > startY) {
        for (int i = startY + 1; i <= endY; ++i)
           std::cout << number[i][endX] << " "; 
    }
    // determine if print the bottom row
    if (endX > startX && endY > startY) {
        for (int i = endX-1; i >= startX; --i) 
            std::cout << number[endY][i] << " ";
    }
    // determine if print the left column
    if (endX > startX && endY > startY + 1) {
        for (int i = endY - 1; i > startY; --i)
            std::cout << number[i][startX] << " ";
    }
    
    return;
}

void PrintMatrixClockwisely (int** number, int rows, int columns) {

    // determine if inputs are right   
    if (number <= 0 || rows <= 0 || columns <= 0)
        return;
    
    int start = 0; // the left-top corner number index, for example (0,0) in first printed circle
    // print matrix in circle until all numbers all printed out
    while (rows > start*2 && columns > start*2) {
        PrintMatrixInCircle (number, rows, columns, start);
        start++;
    }
    
    return;
}

/*
 * 
 */
int main() {
    int arr1[4] = {1,2,3,4};
    int arr2[4] = {5,6,7,8};
    int arr3[4] = {9,10,11,12};
    int arr4[4] = {13,14,15,16};

    int (*rptr)[4] = &arr1;
    //int (*ptr)[4] = {arr1, arr2, arr3, arr4};
    //行指针
    /*int (*ptr)[4]         
     * ->ptr                a variable called ptr
     * -->*ptr              which is a pointer
     * --->(*ptr)[4]        which points to an array with length of 4
     * ---->int (*ptr)[4]   in which each element is of type int
     */
    //row pointer only takes 1 address, not 4; 指向包含4个元素的一行
    int j;
    std::cout<<"Using row pointer to print out the only row in arr1\n";
    for (j=0;j<=3;j++){
    	std::cout <<*(rptr[0]+j) << " ";
    }
    std::cout<<"\n";
    
    int *ptr[4] = {arr1, arr2, arr3, arr4};
    
    /*int *ptr[4]
     * ->ptr                a variable called ptr
     * -->ptr[4]            which is an array with length of 4;
     * --->*ptr[4]          in which each element is a pointer;
     * ---->int *ptr[4]     and each individual points to an int.
     */ 
     
    
    
    int** number;
    number= ptr;
    int rows = 4;
    int columns = 4;
    
    PrintMatrixClockwisely (number, rows, columns);

    return 0;
}
