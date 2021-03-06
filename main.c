/*
 * Task: 
 *  Programming Assignment 1
 * 
 * Repository/Project name: 
 *  ENGG1003
 * 
 * Description of Task: 
 *  This program covers two different types of cipher algorithms; rotation cipher and substitution cipher. A menu has been created to distinguish between the different tasks.
 *  A switch statement is used to execute the user's input from the menu allowing for a certain task to be completed. Once the task is successfully completed, the program will quit 
 * 
 * Rotation cipher:
 *  Encryption: 
 *      The first task encrypts a message by shifting the alphabet a certain number of places. 
 *      "keyrot" is the number of letters the rotation cipher moves along the alphabet and its new corresponding value is given to the original letter, encrypting the message 
 *  
 *  Decryption:
 *      The second task decrypts a message by replaces the letters of the encrypted message with the inverse of the key/rotation amount. 
 *      "keyrot" is the number of letters the roation cipher moves along the alphabet and its original letter is given to the corresponding value. 
 *  
 *  Decryption WITHOUT KEY:                       
 *      The fifth task decrypts a rotation cipher is the key is ot known
 *      A for loop allows for all key options between 1-25 to be tested and printed to the screen along with the decrypted message.
 *      The user can then identify the successfully decrypted message by scrolling through the list. 
 * 
 * Substitution cipher:
 *  Encryption:
 *      The third task encrypts a message by substituting the 26 letters of the alphabet and encrypting them with a new set of letters.
 *      "keysub" is the new list of 26 encrypted letters and each letter of the message is given the new corresponding value.
 * 
 *  Decryption:
 *      The forth task decrypts a message by replacing the decryption key with the original 26 letters of the alphabet.
 *      "keysub" is the list of 26 letters for which the message is decrypted with the original 26 letters of the alphabet.
 * 
 * Program use:
 *  The program can be run by following these instructions:
 *      Open the "input.txt" file and make sure there is no text within.
 *      Press run.
 *      The user is then met by the Menu and is prompted to enter an option.
 *      Enter a number between 1-6 directly after the colon (no space should be between the colon and the number).
 *      Press run as stated.
 *      The user is prompted to provide input to the new commands directly after the colons (no space should be between the colon and the input).
 *      The program will successfully encrypt and decrypt the input
 *      The run the program again, clear the text from the input.txt file and press run.
 * 
 *  To run the program in the terminal remove the input file code and replace the "fprintf" and "fscanf" with "printf" and "scanf" respectively and follow the instructions below:
 *       Create an a.out file by pressing the run button in the main.c file.
 *      After this has been done, enter the terminal and type "cd ENGG1003/" to enter the project, then press enter.
 *      Type "ls" to reveal the list of files inside the project ENGG1003
 *      Type "./a.out" into the terminal to enter the output file.
 *      The user is then met by the Menu and is prompted to enter an option.
 *      After the program quits, the user can run the program again by completing the above tasks again in the terminal. 
 *
 *      The user can choose between 6 menu options prompting the user to choose either an encryption, decryption, rotation cipher or substitution cipher.         
 *      After following the prompts, the program will encrypt or decrypt the text inputted and print the final product in the input.txt file.    
 *          
 * Function definition:
 *  The function main is used for the program and a set of case functions are supplied by the switch statement. 
 *  Inputs are detailed within each case and include:
 *      char uppercase[26], lowercase[26], keysub[27], msg1[1000], msg2[1000], msg3[1500], msg4[1500], msg5[1000]
 *      int userin, keyrot, keysub, i, n, key=1 (used in the for statement in task 5)        
 * 
 */

#include <stdio.h>
#include <string.h> 

int main () {
    
    FILE *input;
    input = fopen ("input.txt", "r+");
   
    //Lowercase and uppercase chars are assigned an array value of 26 and the alphabet is initialised for both uppercase and lowercase letters.
    char uppercase[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char lowercase[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int userin; //Variable userin is declared as user input
    
    fprintf(input,"\nWELCOME TO THE ENCRYPTION AND DECRYPTION MENU\n\n"); // User friendly menu distinguishing the different tasks
    fprintf(input,"1. Rotation Cipher Encryption\n");
    fprintf(input,"2. Rotation Cipher Decryption\n");
    fprintf(input,"3. Substitution Cipher Encryption\n");
    fprintf(input,"4. Substitution Cipher Decryption\n");
    fprintf(input,"5. Rotation Cipher Decryption WITHOUT KEY\n");
    fprintf(input,"6. Quit\n");
    fprintf(input,"\nSelect an option and press run:"); //User asked to select an option within the menu
    fscanf(input,"%d", &userin); // User input is stored in the variable "userin" which is used in switch statement
    
    switch (userin) { //Switch statement takes user input from menu and executes the option selected
        
        case 1: //Rotation Cipher Encryption
            {
                fprintf(input, "\n\nRotation Cipher Encryption\n");
                char msg1[1000], ch; // Initialisation of msg1[1000] used as input and output message variable. Variable ch is used as character variable.
                int i, keyrot; //Initialisation of i used as the counter variable. Variable key is used as the rotation amount.
                
                fprintf(input,"\nEnter message to encrypt:"); //User is prompted to enter a message to encrypt in UPPERCASE letters.              
                fscanf(input," %[^\n]", msg1);

                fprintf(input, "\nEnter key/rotation amount:"); //User is prompted to enter the key/alphabet rotation amount.
                fscanf(input, "%d", &keyrot); //Stores rotation amount in variable keyrot.

                for(i=0; i<strlen(msg1); i++) { //For loop is used to shift each character in the message entered a set rotation amount. Initialises i to 0, while i is less than the string length.
    
                    ch=msg1[i]; //The character variable is stored as msg1 varable.
                    if(ch>=97 && ch<=122) { //If the charachter is between 97 and 122 ASCII values, add key/rotation amount to the character.
        
                        ch=ch+keyrot; //Key/rotation amount is added to the character as stated above.
                        if(ch<97) { //If the character variable is less than the ASCII value of 97, rotate back to z.
            
                            ch=ch-26; //value of 26 is subtracted to rotate back to z.
                        }
                    }
                    if(ch>=65 && ch<=90) { //If the character is between 65 and 90 ASCII values, add key/rotation amount to the character.

                        ch=ch+keyrot; //Key/rotation amount is added to the character as stated above.
                        if(ch<65) { //If the character is less than the ASCII value of 65 subtract 26, rotating the characters back to Z.

                            ch=ch-26; //value of 26 is subtracted to rotate back to Z.
                        }
                        if(ch>=91) { //If the character is greater than or equal to the special char ([), rotate back to A.
            
                            ch=ch-26; //Value of 26 is subtracted to rotate back to A.
                        }
                    }
                    if(ch>=0 && ch<=64) { //If the character is between 0 and 64 ASCII values, dont encrypt as these are special characters.
        
                        ch=ch; //Character variable is stored as unchanged character variable.
                    }

                    msg1[i]=ch; //The new encrypted message of size i has new character shift values for each letter in the message.
                }
                fprintf(input, "\nEncrypted message -  %s", msg1); //Prints encrypted message to screen.
                return 0; //Quits program.
            }
        
        case 2: //Rotation Cipher Decryption
            {
                fprintf(input, "\n\nRotation Cipher Decryption\n");
                char msg2[1000], ch; //initialisation of msg2[1000] used as input and output message variable. Variable ch is used as character variable
                int i, keyrot; //Initialisation of i used as the counter variable. Variable key is used as the rotation amount.
                             
                fprintf(input,"\nEnter messsage to decrypt:"); //User is prompted to enter a message to decrypt in UPPERCASE letters.
                fscanf(input," %[^\n]", msg2);
    
                fprintf(input,"\nEnter key/rotation amount:"); //User is prompted to enter the key/alphabet rotation amount.
                fscanf(input,"%d", &keyrot); //Stores rotation amount in variable keyrot.
    
                for(i=0; i<strlen(msg2); i++) { //For loop used to shift each character in the message entered a set rotation amount.
                    
                    ch=msg2[i]; //The character variable is stored as msg2 varable.
        
                    if(ch>=97 && ch<=122) { //If the character variable is between ASCII values of 97 and 122, add the key/rotation amount to the character.
        
                        ch=ch-keyrot;
                        if(ch<97) { //If the character variable is less than 97, rotate cipher back to "z".
                        
                            ch=ch+26; //value of 26 is added to rotate back to z.
                        }
                    }
                    if(ch>=65 && ch<=90) { //If the character is between 65 and 90 ASCII values, subtract key/rotation amount to the character.
        
                        ch=ch-keyrot; //Key/rotation amount is subtracted to the character as stated above.
                        if(ch<65) { //If the character is less than the ASCII value of 65 add 26, rotating the characters back to Z.
                
                            ch=ch+26; //Value of 26 is added to rotate back to Z.
                        }
    
                        if(ch>=91) { //If the character is greater than or equal to the special char ([), rotate back to A.
            
                            ch=ch+26; //Value of 26 is added to rotate back to A.
                        }                        
                    }
                    if(ch>=0 && ch<=64) { //If the character is between 0 and 64 ASCII values, dont encrypt as these are special characters.
            
                        ch=ch; //Character variable is stored as unchanged character variable.
                        }
    
                        msg2[i]=ch; //The new decrypted message of size i has new character shift values for each letter in the message.
                }          
                fprintf(input,"\nDecrypted message -  %s", msg2); //Prints decrypted message to screen.
                return 0; //Quits program.
            }
        
        case 3: //Substitution Cipher Encryption
            {
                fprintf(input, "\n\nSubstitution Cipher Encryption\n");
                char keysub[27], msg3[1500]; //Keysub value is assigned memory value of 27. Memory value of 1500 is given to the message input initialised as msg3. 
                          
                fprintf(input, "\nEnter message to encrypt:"); //User is prompted to enter a message to encrypt in UPPERCASE letters.
                fscanf(input, " %[^\n]",msg3); //User input is scanned for string msg3.

                int n,i; //Initialising counter variables n and i to use for array size.

                fprintf(input, "\nEnter key/26 characters:"); //26 characters are entered in uppercase when prompted. Each character can only be used once.
                fscanf(input, "%s",keysub); //Stores key input in keysub.

                for(n=0;n<strlen(msg3);n++) { //n is initialised to 0, while n is less than string length in text in "msg3", n is incremented by 1 each time.
                           
                    for(i=0;i<26;i++) { //i is initialised to 0, while i is less than 26, i is incremented by 1 each time.
                                
                        if(uppercase[i]==msg3[n]) { //if the message is uppercase, it will equal the key value of that letter.
                                  
                            msg3[n]=keysub[i]; //Each letter of msg3 is substituted for the keysub letters.
                            break;
                        }
                        if(lowercase[i]==msg3[n]) { //if the message lowercase, it will equal the key value of that letter.
                            
                            msg3[n]=keysub[i]; //Each letter of msg3 is substituted for the keysub letters.
                            break;
                        }
                    } //Loop is exited
                }
                fprintf(input, "\nEncrypted message -  %s",msg3); //Prints encrypted message to screen.
                return 0; //Quits program.
            }
        
        case 4: //Substitution Cipher Decryption
            {
                fprintf(input, "\n\nSubstitution Cipher Decryption\n");
                char keysub[27], msg4[1500]; //Keysub value is assigned memory value of 27. Memory value of 1500 is given to the message input initialised as msg4.
                          
                fprintf(input,"\nEnter message to decrypt:"); //User is prompted to enter a message to decrypt in UPPERCASE letters.
                fscanf(input," %[^\n]",msg4); //User input is scanned for string msg3.

                int n,i; //Initialising counter variables n and i for array size.

                fprintf(input,"\nEnter key/26 characters:"); //26 characters are entered in uppercase when prompted. Each character can only be used once.
                fscanf(input,"%s",keysub); //Stores key input in keysub.
                          
                for(n=0;n<strlen(msg4);n++) { //n is initialised to 0, while n is less than string length in text in "msg4", n is incremented by 1 each time
                            
                    for(i=0;i<26;i++) { //i is initialised to 0, while i is less than 26, i is incremented by 1 each time.
                                
                        if(msg4[n]==keysub[i]) { //If each letter of msg4 is substituted for the keysub letters, it will equal the corresponding letter.
                                    
                            msg4[n]=uppercase[i]; //The corresponding characters will be uppercase.
                            break;
                        }
                        if(msg4[n]==keysub[i]) { //If each letter of msg4 is substituted for the keysub letters, it will equal the corresponding letter.
                                    
                            msg4[n]=lowercase[i]; //The corresponding characters will be lowercase.
                            break;
                        }
                        else {
            
                            msg4[n]=msg4[n]; //Else the message input is stored as an unchanged message.
                        }
                    } //Loop is exited
                }
                fprintf(input,"\nDecrypted message -  %s",msg4); //Prints decrypted message to screen.
                return 0; //Quits program.
            }
        
        case 5: //Rotation Cipher Decryption WITHOUT KEY
            {
                fprintf(input, "\n\nRotation Cipher Decryption WITHOUT KEY\n");
                char msg5[1000], ch; // Initialisation of msg5[1000] used as input and output message variable. Variable ch used as character variable.
                int i, key=1; //Initialisation of variable i as the counter variable. The key is used as the rotation amount (set key shift to 0 to test all key shifts).
	
                fprintf(input,"\nEnter message to decrypt:\n"); //User is prompted to enter a message to decrypt in UPPERCASE letters.
                fscanf(input," %[^\n]", msg5);
	
	
	           for(key=1; key<=25; key++) { //Key is initialised to 1, while key is less than or equal to 25, key is incremented by 1 each time
	
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
    	           fprintf(input,"\n\n\nKey/rotation amount -  %d", key); //Prints key/rotation amount to terminal.
    	           fprintf(input,"\nDecrypted message   -  %s", msg5); //Prints list of decrypted messages between 1-25 to screen.
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
                break; //Quits program.
            }
    }
}
