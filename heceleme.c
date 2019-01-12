#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//bu fonksyion eger harf sesli ise 1 degil ise 0 dondurur
int isVowel(char);

int main()
{
    //word kullanicinin girecegi kelime
    //wordHype hecelenmis hali
    char word [50] = "", wordHyp [100] = "";
    int i,j = 0;
    char word2 [60] = "";
    char word3 [60] = "";

    printf("Hecelemek istediginiz kelimeyi giriniz:\n");
    scanf("%s", word);

    for (i=0; i < strlen(word) ;i++)
     {
         if(isVowel(word[i]) == 1)
          {
              if(isVowel(word[i+1]) == 1 || isVowel(word[i+2]) == 1)
               {
                   if(i>0)
                   {
                       strncat(word2,&word[j],2);
                       strncat(word3,&word[j],2);
                   }
                  else
                   {
                       strncat(word2,&word[j],i+1);
                       strncat(word3,&word[j],i+1);
                   }

                 j = strlen(word3);
                 strcat(word2,"-");

               }

              else if(isVowel(word[i+3]) == 1)
               {
                   if(j>0)
                   {
                       strncat(word2,&word[j],3);
                       strncat(word3,&word[j],3);
                   }
                  else if(i>1 && j == 0)
                   {
                       strncat(word2,&word[j],4);
                       strncat(word3,&word[j],4);
                   }
                  else
                   {
                       strncat(word2,&word[j],3);
                       strncat(word3,&word[j],3);
                   }

                  j = strlen(word3);
                  strcat(word2,"-");
                  i++;

               }
              else if(isVowel(word[i+4]) == 1)
               {
                  strncat(word2,&word[0],i+3);
                  strncat(word3,&word[0],i+3);
                  j = strlen(word3);
                  strcat(word2,"-");
                  i+=2;

               }

          }

     }

strcat(word2,&word[j]);
strcpy(wordHyp,word2);


    printf("%s\n", wordHyp);
    return 0;
}

int isVowel(char c)
{

  switch(c)
  {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return 1;
      break;
    default:
      return 0;
      break;
  }
}
