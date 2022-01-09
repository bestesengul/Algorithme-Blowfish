
#include <stdio.h>
#include "blowfish.h"
#include <string.h>
#include <stdint.h>

char plaintext[];

int main (int argc, const char* argv[])
{
// ***************************************************************************
// ********************* CONSOLE APPLICATION FOR TESTING *********************
// ***************************************************************************
   BLOWFISH_CTX ctx;

   /* must be less than 56 bytes */
   char *key = "5432361636545212456402842121500";
   int keylen = strlen(key);
   printf("************************* APPLICATION CONSOLE DE TESTE *************************\nEntrer votre message:\n > ");

   scanf("%[^\n]s", plaintext);

   uint8_t *plaintext_string = (uint8_t*) plaintext;
   int plaintext_len = strlen(plaintext_string);

   uint8_t ciphertext_buffer[256];
   uint8_t *ciphertext_string = &ciphertext_buffer[0];
   int ciphertext_len = 0;

   uint32_t message_left;
   uint32_t message_right;
   int block_len;

   Blowfish_Init(&ctx, key, keylen);

   printf("Message original: %s\n\n", plaintext_string);

   /* encrypt the plaintext message string */
   printf("Message crypte: ");

   while (plaintext_len)
   {
     message_left = message_right = 0UL;

   /* crack the message string into a 64-bit block (ok, really two 32-bit blocks); pad with zeros if necessary */
     for (block_len = 0; block_len < 4; block_len++)
     {
       message_left = message_left << 8;
       if (plaintext_len)
       {
           message_left += *plaintext_string++;
           plaintext_len--;
       }
       else message_left += 0;
     }
     for (block_len = 0; block_len < 4; block_len++)
     {
       message_right = message_right << 8;
       if (plaintext_len)
       {
           message_right += *plaintext_string++;
           plaintext_len--;
       }
       else message_right += 0;
     }
   /* encrypt and print the results */
     Blowfish_Encrypt(&ctx, &message_left, &message_right);
     printf("%lx%lx", message_left, message_right);

   /* save the results for decryption below */
     *ciphertext_string++ = (uint8_t)(message_left >> 24);
     *ciphertext_string++ = (uint8_t)(message_left >> 16);
     *ciphertext_string++ = (uint8_t)(message_left >> 8);
     *ciphertext_string++ = (uint8_t)message_left;
     *ciphertext_string++ = (uint8_t)(message_right >> 24);
     *ciphertext_string++ = (uint8_t)(message_right >> 16);
     *ciphertext_string++ = (uint8_t)(message_right >> 8);
     *ciphertext_string++ = (uint8_t)message_right;
     ciphertext_len += 8;
    }
    printf("\n\n");

   /* reverse the process */
     printf("Message decrypte: ");

     ciphertext_string = &ciphertext_buffer[0];
    while(ciphertext_len)
    {
        message_left = message_right = 0UL;

        for (block_len = 0; block_len < 4; block_len++)
        {
          message_left = message_left << 8;
          message_left += *ciphertext_string++;
          if (ciphertext_len)
           ciphertext_len--;
        }
        for (block_len = 0; block_len < 4; block_len++)
        {
           message_right = message_right << 8;
           message_right += *ciphertext_string++;
           if (ciphertext_len)
           ciphertext_len--;
        }

        Blowfish_Decrypt(&ctx, &message_left, &message_right);

   /* if plaintext message string padded, extra zeros here */

        printf("%c%c%c%c%c%c%c%c",
        (int)(message_left >> 24), (int)(message_left >> 16),
        (int)(message_left >> 8), (int)(message_left),
        (int)(message_right >> 24), (int)(message_right >> 16),
        (int)(message_right >> 8), (int)(message_right));
    }

    printf("\n********************************************************************************\n\n");


// ***************************************************************************
// ******* REAL APPLICATION: MESSAGE DIGESTION (WITH A SAMPLE DATASET) *******
// ***************************************************************************
    FILE *fOriginal = fopen("messages.txt", "r");
    FILE *fEncryted = fopen("messages-cryptes.txt", "w");
    FILE *fDecryted = fopen("messages-decryptes.txt", "w");

    printf("*****  APPLICATION DU MONDE REEL: CHIFFREMENT DE MESSAGE (AVEC UN DATASET) *****\nChiffre les messages dans le jeu de donnee...: messages.txt\n");

    fprintf(fEncryted, "*************** STATUS - Encrypted ***************\n\n");
    fprintf(fDecryted, "*************** STATUS - Decrypted ***************\n\n");

    if(fOriginal && fEncryted && fDecryted) {
        char tmp[500];
        BLOWFISH_CTX ctxM;
        while(fgets(tmp, sizeof(tmp), fOriginal) != NULL) {
           uint8_t *message_string = (uint8_t*) tmp;
           uint8_t message_len = strlen(message_string);

           uint8_t ciphermessage_buffer[256];
           uint8_t *ciphermessage_string = &ciphermessage_buffer[0];
           int ciphermessage_len = 0;

           uint32_t Message_left;
           uint32_t Message_right;
           int Block_len;

           Blowfish_Init(&ctxM, key, keylen);

           while (message_len)
           {
             Message_left = Message_right = 0UL;

           /* crack the message string into a 64-bit block (ok, really two 32-bit blocks); pad with zeros if necessary */
             for (Block_len = 0; Block_len < 4; Block_len++)
             {
               Message_left = Message_left << 8;
               if (message_len)
               {
                   Message_left += *message_string++;
                   message_len--;
               }
               else Message_left += 0;
             }
             for (Block_len = 0; Block_len < 4; Block_len++)
             {
               Message_right = Message_right << 8;
               if (message_len)
               {
                   Message_right += *message_string++;
                   message_len--;
               }
               else Message_right += 0;
             }
           /* encrypt and print the results */
             Blowfish_Encrypt(&ctxM, &Message_left, &Message_right);
             fprintf(fEncryted, "%lx%lx", Message_left, Message_right);

           /* save the results for decryption below */
             *ciphermessage_string++ = (uint8_t)(Message_left >> 24);
             *ciphermessage_string++ = (uint8_t)(Message_left >> 16);
             *ciphermessage_string++ = (uint8_t)(Message_left >> 8);
             *ciphermessage_string++ = (uint8_t)Message_left;
             *ciphermessage_string++ = (uint8_t)(Message_right >> 24);
             *ciphermessage_string++ = (uint8_t)(Message_right >> 16);
             *ciphermessage_string++ = (uint8_t)(Message_right >> 8);
             *ciphermessage_string++ = (uint8_t)Message_right;
             ciphermessage_len += 8;
            }
            fprintf(fEncryted, "\n");

           /* reverse the process */
            ciphermessage_string = &ciphermessage_buffer[0];
            while(ciphermessage_len)
            {
                Message_left = Message_right = 0UL;

                for (Block_len = 0; Block_len < 4; Block_len++)
                {
                  Message_left = Message_left << 8;
                  Message_left += *ciphermessage_string++;
                  if (ciphermessage_len)
                   ciphermessage_len--;
                }
                for (Block_len = 0; Block_len < 4; Block_len++)
                {
                   Message_right = Message_right << 8;
                   Message_right += *ciphermessage_string++;
                   if (ciphermessage_len)
                   ciphermessage_len--;
                }

                Blowfish_Decrypt(&ctxM, &Message_left, &Message_right);

           /* if plaintext message string padded, extra zeros here */

                fprintf(fDecryted, "%c%c%c%c%c%c%c%c",
                (int)(Message_left >> 24), (int)(Message_left >> 16),
                (int)(Message_left >> 8), (int)(Message_left),
                (int)(Message_right >> 24), (int)(Message_right >> 16),
                (int)(Message_right >> 8), (int)(Message_right));
            }

           fprintf(fDecryted,"\n");

        }
    }

    fclose(fOriginal);
    fclose(fEncryted);
    fclose(fDecryted);

    printf("******** Consultez messages-cryptes.txt pour voir les messages cryptes! ********\n");
    printf("***** Consultez messages-decryptes.txt pour voir les messages decryptes! *******\n");
    printf("********************************************************************************\n\n");
    
    return 0;
}