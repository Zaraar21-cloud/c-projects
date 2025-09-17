#include <stdio.h>

typedef char string[20];
char currency = '$';
typedef struct {
    string title;
    string author;
    int price;
    int stock;
} Book;

Book SomeBook = {"Some Book", "Some Author", 10,5};

Book Library[] = {};

int main(){
    
    return 0;
}