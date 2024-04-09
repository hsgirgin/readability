#include <math.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(void){
int sentences = 0;
int words = 0;
int letters = 0;
string text = get_string("Text: ");
for(int i = 0,n = strlen(text); i < n;i++){
    if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
        sentences++;
        words++;
        i++;
    }
    else if((int) text[i] > 64 && (int) text[i] < 123){
        letters++;
    }
    else if(text[i] == ' '){
        words++;
    }


}
float adjust_value = 100/ (float) words;
float words_new = (float) words * adjust_value;
float letters_new = (float) letters * adjust_value;
float sentences_new = (float) sentences * adjust_value;
float level = round(0.0588*letters_new-0.296*sentences_new-15.8);
if (level >= 16){
    printf("Grade 16+\n");

}
else if(level < 1){
    printf("Before Grade 1\n");

}
else{
    printf("Grade %i\n",(int) level);
}
}
