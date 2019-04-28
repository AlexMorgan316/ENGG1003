

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
        
        case 1: //Rotation Cipher Encryption
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
        
        case 2: //Rotation Cipher Decryption
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
        
        case 3: //Substitution Cipher Encryption
            {
                char keysub[27], msg3[1500];
                          
                printf("\nEnter message to encrypt: "); //User is prompted to enter a message to encrypt in UPPERCASE letters.
                scanf(" %[^\n]",msg3);

                int n,i; //Initialising counter variables n and i to use for array size.

                printf("\nEnter key/26 characters: "); //26 characters are entered in uppercase when prompted. Each character can only be used once.
                scanf("%s",keysub); //Stores key input in keysub.

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
                printf("\nEncrypted message: %s",msg3); //Prints encrypted message to screen.
                return 0; //Quits program.
            }
        
        case 4: //Substitution Cipher Decryption
            {
                char keysub[27], msg4[1500];
                          
                printf("\nEnter message to decrypt: "); //User is prompted to enter a message to decrypt in UPPERCASE letters.
                scanf(" %[^\n]",msg4); //Stores key input in keysub.

                int n,i; //Initialising counter variables n and i for array size.

                printf("\nEnter key/26 characters: "); //26 characters are entered in uppercase when prompted. Each character can only be used once.
                scanf("%s",keysub); //Stores key input in keysub.
                          
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
                printf("\nDecrypted message: %s",msg4); //Prints decrypted message to screen.
                return 0; //Quits program.
            }
        
        case 5: //Rotation Cipher Decryption WITHOUT KEY
            {
                char msg5[1000], ch; // Initialisation of msg5[1000] used as input and output message variable. Variable ch used as character variable.
                int i, key=1; //Initialisation of variable i as the counter variable. The key is used as the rotation amount (set key shift to 0 to test all key shifts).
	
                printf("Enter message to decrypt: "); //User is prompted to enter a message to decrypt in UPPERCASE letters.
                scanf(" %[^\n]", msg5);
	
	
	           for(key=1; key<=25; key++) {
	
    	           for(i=0; msg5[i] != '\0'; ++i) { //For loop used to shift each character in the message entered a set amount of key shifts. 
    
    		          ch=msg5[i]; //Character variable is stored as msg5 varable.
    		
    		          if(ch>='A' && ch<='Z') { //If statement applies to the characters A-Z in the alphabet or the ASCII values between 65-90.
    		
    			         ch=ch-1; //New decrypted character is equal to the character ASCII value -1. 
    			
    			         if(ch<'A') { //If character is less than 'A' after ASCII value rotation
    			             
    			             ch=ch+'Z'-'A'+1; //Loops character to A-Z by adding 'Z' value and substracting 'A' value +1 so the char is A-Z on completion.
    			         }
    			         msg5[i]=ch; //The new decrypted message of size i has new character shift values for each letter in the message.
    		          }
    	           }
    	           printf("\nKey/rotation amount: %d", key); //Prints key/rotation amount to terminal.
    	           printf("\nDecrypted message: %s", msg5); //Prints list of decrypted messages between 1-25 to screen.
                }
                return 0; //Quits program.
            }
        
        case 6: //Quit
            {
                return 0; //Quits program.
            }
 
        default:
            {
                printf("Invalid option, select number between 1-6\n"); //Prints "Invalid option" to terminal.
                return 0; //Quits program.
            }
    }
}

