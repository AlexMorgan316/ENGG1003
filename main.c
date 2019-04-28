

#include <stdio.h>
#include <string.h> 

int main () {
   
    char uppercase[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char lowercase[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int userin;
    
    printf("\nWELCOME TO THE ENCRYPTION AND DECRYPTION MENU\n"); // User friendly menu distinguishing the different tasks
    printf("1. Rotation Cipher Encryption\n");
    printf("2. Rotation Cipher Decryption\n");
    printf("3. Substitution Cipher Encryption\n");
    printf("4. Substitution Cipher Decryption\n");
    printf("5. Rotation Cipher Decryption WITHOUT KEY\n");
    printf("6. Quit\n");
    printf("\nSelect an option and press enter:  "); //User asked to select an option within the menu
    scanf("%d",&userin); // User input is stored in the variable "userin" which is used in switch statement
    
    switch (userin) { //Switch statement takes user input from menu and executes the option selected
        
        case 1:
            {
                char msg1[1000], ch; // Initialisation of msg1[1000] used as input and output message variable. Variable ch is used as character variable.
                int i, keyrot; //Initialisation of i used as the counter variable. Variable key is used as the rotation amount.
                
                printf("\nEnter message to encrypt: "); //User is prompted to enter a message to encrypt in UPPERCASE letters.              
                scanf(" %[^\n]", msg1);

                printf("\nEnter key/rotation amount: "); //User is prompted to enter the key/alphabet rotation amount.
                scanf("%d", &keyrot); //Stores rotation amount in variable keyrot.

                for(i=0; i<strlen(msg1); i++) { //For loop is used to shift each character in the message entered a set rotation amount.
    
                    ch=msg1[i]; //The character variable is stored as msg1 varable.
                    if(ch>=97 && ch<=122) {
        
                        ch=ch+keyrot;
                        if(ch<97) {
            
                            ch=ch-26;
                        }
                    }
                    if(ch>=65 && ch<=90) {

                        ch=ch+keyrot;
                        if(ch<65) {

                            ch=ch-26;
                        }
                        if(ch>=91) {
            
                            ch=ch-26;
                        }
                    }
                    if(ch>=0 && ch<=64) {
        
                        ch=ch;
                    }

                    msg1[i]=ch; //The new encrypted message of size i has new character shift values for each letter in the message.
                }
                printf("\nEncrypted message: %s", msg1); //Prints encrypted message to screen.
                return 0; //Quits program.
            }
        
        case 2:
            {
                char msg2[1000], ch; //initialisation of msg2[1000] used as input and output message variable. Variable ch is used as character variable
                int i, keyrot; //Initialisation of i used as the counter variable. Variable key is used as the rotation amount.
                             
                printf("Enter messsage to decrypt: "); //User is prompted to enter a message to decrypt in UPPERCASE letters.
                scanf(" %[^\n]", msg2);
    
                printf("\nEnter key/rotation amount: "); //User is prompted to enter the key/alphabet rotation amount.
                scanf("%d", &keyrot); //Stores rotation amount in variable keyrot.
    
                for(i=0; i<strlen(msg2); i++) { //For loop used to shift each character in the message entered a set rotation amount.
                    
                    ch=msg2[i]; //The character variable is stored as msg2 varable.
        
                    if(ch>=97 && ch<=122) {
        
                        ch=ch-keyrot;
                        if(ch<97) {
                        
                            ch=ch+26;
                        }
                    }
                    if(ch>=65 && ch<=90) {
        
                        ch=ch-keyrot;
                        if(ch<65) {
                
                            ch=ch+26;
                        }
    
                        if(ch>=91) {
            
                            ch=ch+26;
                        }                        
                    }
                    if(ch>=0 && ch<=64) {
            
                        ch=ch;
                        }
    
                        msg2[i]=ch; //The new decrypted message of size i has new character shift values for each letter in the message.
                }          
                printf("\nDecrypted message: %s", msg2); //Prints decrypted message to screen.
                return 0; //Quits program.
            }
        
        case 3:
            {
                char keysub[27], msg3[1500];
                          
                printf("\nEnter message to encrypt: ");
                scanf(" %[^\n]",msg3);

                int n,i;

                printf("\nEnter key/26 characters: ");
                scanf("%s",keysub);

                for(n=0;n<strlen(msg3);n++) {
                           
                    for(i=0;i<26;i++) {
                                
                        if(uppercase[i]==msg3[n]) { 
                                  
                            msg3[n]=keysub[i];
                            break;
                        }
                        if(lowercase[i]==msg3[n]) {
                            
                            msg3[n]=keysub[i];
                            break;
                        }
                    }
                }
                printf("\nEncrypted message: %s",msg3);
                return 0;
            }
        
        case 4:
            {
                char keysub[27], msg4[1500];
                          
                printf("\nEnter message to decrypt: ");
                scanf(" %[^\n]",msg4);

                int n,i;

                printf("\nEnter key/26 characters: ");
                scanf("%s",keysub);
                          
                for(n=0;n<strlen(msg4);n++) {
                            
                    for(i=0;i<26;i++) {
                                
                        if(msg4[n]==keysub[i]) {
                                    
                            msg4[n]=uppercase[i];
                            break;
                        }
                        if(msg4[n]==keysub[i]) {
                                    
                            msg4[n]=lowercase[i];
                            break;
                        }
                        else {
            
                            msg4[n]=msg4[n];
                        }
                    }
                }
                printf("\nDecrypted message: %s",msg4);
                return 0;
            }
        
        case 5:
            {
                char msg5[1000], ch;
                int i, key=1;
	
                printf("Enter message to decrypt: ");
                scanf(" %[^\n]", msg5);
	
	
	           for(key=1; key<=25; key++) {
	
    	           for(i=0; msg5[i] != '\0'; ++i) {
    
    		          ch=msg5[i];
    		
    		          if(ch>='A' && ch<='Z') { 
    		
    			         ch=ch-1; 
    			
    			         if(ch<'A') {
    			             
    			             ch=ch+'Z'-'A'+1;
    			         }
    			         msg5[i]=ch; 
    		          }
    	           }
    	           printf("\nKey/rotation amount: %d", key);
    	           printf("\nDecrypted message: %s", msg5);
                }
                return 0;
            }
        
        case 6:
            {
                return 0;
            }
 
        default:
            {
                printf("Invalid option, select number between 1-6\n");
                return 0;
            }
    }
}

