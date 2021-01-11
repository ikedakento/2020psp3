#include <stdio.h>
#include <string.h>
#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int key_len, text_len, pos= 0, start;
    key_len=strlen(key);
    text_len=strlen(text);
    for(start =0;start<text_len;start++)
    {
         for(pos=0;pos<key_len;pos++)
          {
             if(text[start+pos]==key[pos])
             {
                 if(pos==key_len-1)
              {
                return &text[start];
              }
             else{
                continue;
                 }
            }
            else
            {
            break;
            }
            
        }
    }
    return NULL;
}



char* BMSearch(char text[], char key[])
{
    int i, n, text_len, key_len, index, index2,pos;
    int table[256];
    char *result;
    text_len = strlen(text);
    key_len = strlen(key);
    typedef unsigned char unchar;

    for(i= 0;i<256;i++)
    {
        table[i]=key_len;
    }
    for(i =0; i< key_len ; i++)
    {
        table[(unchar)key[i]] = key_len - i - 1;

    }
for(index = key_len -1;index<text_len;)
{
    n = 0;
    for(pos=key_len -1;pos>0;n++){
    
        if(text[index - n]== key[pos])
        {
            pos--;
        }
        else{
            index2 = index - n + table[(unchar)text[index - n]];
            if(index2 <= index)
            {
                index = index + 1;
            }else
            {
                
                    index = index2;
                }
            
            
            
            break;
        }
    }
    if(pos==0)
    {
        result = &text[index-n];
        break;
    }
}
return result;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}


