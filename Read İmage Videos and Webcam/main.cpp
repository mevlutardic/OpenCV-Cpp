#include<iostream> 
using namespace std; 
int main() 
{ 
    cout<<"deneme";
    system("g++ -o Readimage Readimage.cpp `pkg-config opencv --cflags --libs`"); 
    system("./Readimage"); 

    return 0; 
} 