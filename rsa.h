#ifndef rsa_h
#define rsa_h

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;



class rsa
{
    private:
   int x, y, n, t, i, flag;
    long int e[50], d[50], temp[50], j;
    char en[50], m[50];
    char msg[100];
    
public:
  int prime(long int); //function to check for prime number
    void encryption_key();
    long int cd(long int);
    void encrypt();
    void decrypt();
    rsa();
    ~rsa();
    
};

#endif
