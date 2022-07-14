#include "rsa.h"

rsa::rsa() { 
   
   
   
   do{
   cout << "\nENTER FIRST PRIME NUMBER\n";
   cin >> x;
   cout<<"\n";
   flag = prime(x);
   }while(flag==0);
   do{
   cout << "\nENTER SECOND PRIME NUMBER\n";
   cin >> y;
   flag = prime(y);
   }while(flag==0 || x == y);


   cout << "\nENTER MESSAGE OR STRING TO ENCRYPT\n";
   cin >> msg;

   for(i = 0; msg[i] != '\0' ; i++)
      m[i] = msg[i];
   n = x * y;
   t = (x - 1) * (y - 1);

   encryption_key();
   cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";

   for(i = 0; i < j - 1; i++)
      cout << "\n" << e[i] << "\t" << d[i];

   
  }



int rsa::prime(long int pr)
{
   int j;
   int i;
   j = sqrt(pr);
   for(i = 2; i <= j; i++)
   {
      if(pr % i == 0)
         return 0;
   }
   return 1;
 }

//function to generate encryption key
void rsa::encryption_key()
{
   {
      int k;
      k = 0;
      for(i = 2; i < t; i++)
      {
         if(t % i == 0)
            continue;
         flag = prime(i);
         if(flag == 1 && i != x && i != y)
         {
            e[k] = i;
            flag = cd(e[k]);
            if(flag > 0)
            {
               d[k] = flag;
               k++;
            }
            if(k == 99)
            break;
         }
      }
   }
}

long int rsa::cd ( long int a)
{
   long int k = 1;
   while(1)
   {
      k = k + t;
      if(k % a == 0)
         return(k/a);
   }
}

//function to encrypt the message
void rsa::encrypt()
{
   long int pt, ct, key = e[0], k, len;
   i = 0;
   len = strlen(msg);

   while(i != len)
   {
      pt = m[i];
      pt = pt - 96;
      k = 1;
      for(j = 0; j < key; j++)
      {
         k = k * pt;
         k = k % n;
      }
      temp[i] = k;
      ct= k + 96;
      en[i] = ct;
      i++;
   }
   en[i] = -1;
   cout << "\n\nTHE ENCRYPTED MESSAGE IS\n";
   for(i=0; en[i] != -1; i++)
      cout << en[i];
   cout<<"\n";
}

//function to decrypt the message
void rsa::decrypt(){
   long int pt, ct, key = d[0], k;
   i = 0;
   while(en[i] != -1)
   {
      ct = temp[i];
      k = 1;
      for(j = 0; j < key; j++)
      {
         k = k * ct;
         k = k % n;
      }
      pt = k + 96;
      m[i] = pt;
      i++;
   }
   m[i] = -1;
   cout << "\n\nTHE DECRYPTED MESSAGE IS\n";
   for(i = 0; m[i] != -1; i++)
      cout << m[i];

  cout << endl;
}





rsa::~rsa(){
   cout <<"destructing"<<endl;
}