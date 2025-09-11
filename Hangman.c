#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

typedef char string[15];
string words[] = {
    "awesome", "amazing", "wonderful", "beautiful", "gorgeous",
    "pretty", "hallucination", "classroom", "nightmare", "garden",
    "monitor", "projector", "keyboard", "mouse", "speaker",
    "headphone", "microphone", "printer", "scanner", "router",
    "modern", "website", "firewall", "antivirus", "software",
    "hardware", "algorithm", "database", "network", "server",
    "client", "cloud", "internet", "social", "browser",
    "search", "engine", "social", "media", "platform",
    "developer", "programmer", "paint", "debugging", "system",
    "variable", "function", "loop", "array", "string",
    "integer", "character", "pointer", "structure",
    "inheritance", "polygon", "medicine", "algebra", "python",
    "library", "module", "package", "movie", "terminal",
    "command", "line", "interface", "graphic", "design",
    "user", "experience", "interface", "mobile", "application",
    "desktop", "laptop", "tablet", "smartphone", "smartwatch",
    "television", "refrigerator", "microwave", "dishwasher", "washing",
    "dryer", "vacuum", "robot", "drone", "bicycle",
    "motorcycle", "car", "truck", "train", "airplane",
    "helicopter", "submarine", "spaceship", "planet", "galaxy",
    "universe", "constellation", "astrology", "telescope", "microscope",
    "laboratory", "experiment", "research", "science", "biology",
    "chemistry", "physics", "mathematics", "geometry", "calculus",
    "algebra", "statistics", "probability", "logic", "philosophy",
    "history", "geography", "literature", "language", "grammar",
    "spelling", "dictionary", "encyclopedia", "novel", "poetry",
    "biography", "memory", "journal", "diary", "letter",
    "postcard", "envelope", "stamp", "signature", "autograph",
    "document", "certificate", "license", "passport", "ticket",
    "receipt", "invoice", "bill", "money", "wallet","cash"
};

int numberofwords = sizeof(words)/sizeof(words[0]);

void startHangman();
void showHearts();
int chooseRandomWord();
int getnumberofletters(int index);
int chooseRandomIndex(int length);
void updateScreen(int showType);

const int maxLives = 5;
int lives = 0;
int allcorrect = 0;
int won =0;
int correctIndexes[15];
int guessIndexes[15];

int wordLength;
int wordIndex;

typedef enum {
 EASY,
 MEDIUM,
 HARD
} level;

level difficulty  = EASY;
/*
DIFFICULTY LEVELS:
0 --> EASY
1 --> MEDIUM
2 --> HARD
*/

int main(){
 startHangman();
 return 0;
}

int showLetters(int length){
int showLetters = 0;
switch(difficulty){
 case 0:
 showLetters = 2;
 break;
 case 1:
 showLetters = 1;
 break;
 case 2:
 showLetters = 0;
 break;
}
if(showLetters > 0){

for(int i=0;i<showLetters;i++){
int randomIndex;
int found = 0;
do{
randomIndex = chooseRandomIndex(length);
if (guessIndexes[randomIndex] != correctIndexes[randomIndex]){
 guessIndexes[randomIndex] = correctIndexes[randomIndex];
 found = 1;
}
}while(found == 0);
}
}
}

void setDifficulty(int length){
printf("CHOOSE YOUR DIFFICULTY\n");
printf("0 = EASY\n1 = MEDIUM\n2 = HARD\n");
do{
scanf("%d",&difficulty);
}while(difficulty > 2 || difficulty < 0);
switch(difficulty){
 case 0:
   difficulty = EASY;
   lives = 5;
   printf("DIFFICULTY CHOSEN: EASY\n");
   break;
 case 1:
 difficulty = MEDIUM;
 lives = 4;
 printf("DIFFICULTY CHOSEN: MEDIUM\n");
 break;
 case 2:
 difficulty = HARD;
 lives = 3;
 printf("DIFFICULTY CHOSEN: HARD\n");
 break;
}
showLetters(length);
}

void showHearts(){
for (int i=0;i<lives;i++){
printf("❤️ ");
}
}

int chooseRandomIndex(int k){
 srand(time(NULL));
 int randomIndex = rand() % k;
 return randomIndex;
}

int getnumberofletters(int index){
 int fakeLength = sizeof(words[index])/sizeof(words[index][0]);
 int originalLength = 0;
 for(int i=0;i<fakeLength;i++){
 if(words[index][i] != 0){
  originalLength++;
 }
 }
 return originalLength;
}

int updateWordGuess(string word,int length){
printf("\n");
for (int i=0;i<length;i++){
 if (guessIndexes[i] == 0){
   printf("_ ");
 }else{
  printf("%c ",word[i]);
 }
}
printf("\n");
}

void checkAllCorrect(){
int checkAll = 1;
for (int i=0; i< wordLength; i++){
if(correctIndexes[i] != guessIndexes[i]){
checkAll = 0;
}
}
if(checkAll == 1){
allcorrect = 1;
}
}

void checkGuessAndEnroll(int guess){
int atleastOne = 0;
 for (int i=0;i < wordLength;i++){
  if (correctIndexes[i] == guess){
  atleastOne++;
  guessIndexes[i] = correctIndexes[i];
  }
 }
 if (atleastOne == 0){
 lives--;
 }
 
 checkAllCorrect();
 
}

void startGuessing(){
while (lives > 0 && allcorrect != 1){
char theirGuess;
printf("ENTER YOUR GUESS:");
scanf(" %c",&theirGuess);
checkGuessAndEnroll(theirGuess);
updateScreen(0);
}
}

void updateScreen(int showType){
// clrscr();
printf("Guess the word in %d chances! \n\n",lives);
showHearts();
updateWordGuess(words[wordIndex],wordLength);
}

void startHangman(){
 lives = maxLives;
 allcorrect = 0;
 int randomIndex = chooseRandomIndex(numberofwords);
 int num_letters = getnumberofletters(randomIndex);
 wordIndex = randomIndex;
 wordLength = num_letters;
 for (int i=0;i<num_letters;i++){
 correctIndexes[i] = words[randomIndex][i];
 }
 printf("******HANGMAN******* \n\n");
 setDifficulty(num_letters);
 
 printf("Guess the word in %d chances! \n", lives);
 showHearts();
 updateWordGuess(words[randomIndex],num_letters);
 startGuessing();
 if (allcorrect==0){
 printf("You lost!\n");
 }else{
 printf("YOU WON!! \n");
 }
 printf("THE WORD WAS: %s \n",words[wordIndex]);
}
    