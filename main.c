#include <stdio.h>
#include <string.h>

int main () {
   
    char uppercase[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char lowercase[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int userin;
    
    printf("\nWELCOME TO THE ENCRYPTION AND DECRYPTION MENU\n");
    printf("1. Rotation Cipher Encryption\n");
    printf("2. Rotation Cipher Decryption\n");
    printf("3. Substitution Cipher Encryption\n");
    printf("4. Substitution Cipher Decryption\n");
    printf("5. Rotation Cipher Decryption WITHOUT KEY\n");
    printf("6. Quit\n");
    printf("\nSelect an option and press enter:  ");
    scanf("%d",&userin);
    
    switch (userin) {
        
        case 1:
            {
                char msg1[1000], ch;
                int i, keyrot;
                
                printf("\nEnter message to encrypt: ");               
                scanf(" %[^\n]", msg1);

                printf("\nEnter key/rotation amount: ");
                scanf("%d", &keyrot);

                for(i=0; i<strlen(msg1); i++) {
    
                    ch=msg1[i];
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

                    msg1[i]=ch;
                }
                printf("\nEncrypted message: %s", msg1);
                return 0; 
            }
        
        case 2:
            {
                char msg2[1000], ch;
                int i, keyrot;
                             
                printf("Enter messsage to decrypt: ");
                scanf(" %[^\n]", msg2);
    
                printf("\nEnter key/rotation amount: ");
                scanf("%d", &keyrot);
    
                for(i=0; i<strlen(msg2); i++) {
                    
                    ch=msg2[i];
        
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
    
                        msg2[i]=ch;
                }          
                printf("\nDecrypted message: %s", msg2);
                return 0;
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

