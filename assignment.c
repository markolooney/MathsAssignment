#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//declaring Encypt and Decrypt functions
void Encrypt(char* name,char* cipher);
void Decrypt(char* cipher,char* name);

main()
{
    //initilizing name to a empty string 
    char* name = {""};
    
    //printing to screen
    printf("Input an eight letter word that you want Encrypted: ");
    
    //user inputting string for name
    scanf("%s",name);
    
    //if user types in lowercase they will be converted to uppercase
    for(int i = 0; i<8; i++)
    {
        name[i]= toupper(name[i]);
    }
    
    //initilizing name2 to a empty string 
    char* name2 ={""};
    
    //initilizing cipher and allocating memory for it then calling Encrypt function passing in name and cipher
    char* cipher = (char*)malloc(4*sizeof(char*));
    Encrypt(name,cipher);
    
    //same as before but new variables are used for second half of string
    char* cipher2 = (char*)malloc(4*sizeof(char*));
    Encrypt((name+4),cipher2);  
    
    //joining both strings together in cipher so that they can be printed to screen 
    cipher = strcat(cipher,cipher2);
    
    //printing name to screen 
    printf("\nInput string (plaintext): %s\n",name);
    
    //printing cipher to screen
    printf("\nEncrypted (ciphertext)  : %s\n",cipher);
    
    //calling Decrypt function passing in name and cipher
    Decrypt(cipher,name);
    //calling Decrypt function passing in name2 and cipher2
    Decrypt(cipher2,name2);
    
    //joining both strings together in name so that they can be printed to screen 
    name = strcat(name,name2);
    
    //printing name to screen 
    printf("\nDecrypted (plaintext)   : %s\n",name);
    
    //getchars so the program stays open
    getchar();   
    getchar();       
}

//function for encrypting
void Encrypt(char* name,char* cipher)
{
    
    //array of character that can be searched through for encryption
    char letter[29] = {'*','A','B','C','D','E','F','G','H','I','J','K','L',
    'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',']','%'};
    
    //Encryption matrix
    int E[4][4]= {{9, 12, 23, 1}  
                ,{24, 5, 24, 19}
                ,{13, 2, 21, 13}
                ,{1, 3, 25, 15}};
                
    //used to take converted numbers from name
    int plain[4];
    //mod
    int n = 29;
                
    int k = 0;
    int j;
    //used for holding numbers after multiplication and mod is done          
    int sum[4] = {0,0,0,0};
    
    //for loop that goes through name compares it to the letter array and put approiate number into plain 
    for (j = 0;j<4;j++)
    {
        for (int i = 0;i<29;i++)
        {
            if (name [j] == letter[i])
            {
                
                plain [k] = i;
                k++;
                
            }
        }
    }
    //for loop that goes through plain multiplys by d then mods by n and puts answer into sum
    for(int i = 0;i<4;i++)
    {
        for (k = 0;k<4;k++)
        {
            //matrix multiplication
            sum[i] = sum[i] + (plain [k] * E[i][k]) ;
        }
        //mod matrix multiplication by n
        sum[i]=sum[i]%n;
    }
    //for loop to go through letter array and put approiate letters in cipher depending on the number in sum hence giving encrypted text
    for (j = 0;j<4;j++)
    {
        cipher[j] = letter[sum[j]];
    }
    cipher[4] = '\0';
}
  
  
  
//function for decrypting
void Decrypt(char* cipher,char* name)
{
    //array of character that can be searched through for decryption
   char letter[29] = {'*','A','B','C','D','E','F','G','H','I','J','K','L',
    'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',']','%'}; 
    
    //decrytion matrix
    int D[4][4]= {{10, 12, 8, 12}  
                ,{6, 21, 23, 13}
                ,{20, 11, 19, 5}
                ,{17, 25, 27, 27}}; 
    
    //used to take converted numbers from name
    int Decrypted[4];
    //mod
    int n = 29;    
    int k = 0;
    int j;
    //used for holding numbers after multiplication and mod is done 
    int sum[4] = {0,0,0,0};
    
    //for loop that goes through cipher compares it to the letter array and put appropriate number into decryted 
    for (j = 0;j<4;j++)
    {
        for (int i = 0;i<29;i++)
        {
            if (cipher [j] == letter[i])
            {
                
                Decrypted [k] = i;
                k++;
                
            }
        }
    }
    //for loop that goes through decrypted multiplys by e then mods by n and puts answer into sum
    for(int i = 0;i<4;i++)
    {
        for (k = 0;k<4;k++)
        {
            //matrix multiplication
            sum[i] = sum[i] + (Decrypted [k] * D[i][k]) ;
        }
        //mod matrix multiplication by n
        sum[i]=sum[i]%n;   
    }
    //for loop to go through letter array and put appropriate letters in cipher depending on the number in sum hence giving encrypted text
    for (j = 0;j<4;j++)
    {
        name[j] = letter[sum[j]];
    }
    name[4] = '\0';
}