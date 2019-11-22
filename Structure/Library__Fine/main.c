#include <stdio.h>
#include "book.h"
#include "date.h"
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned);
int main(void)
{
	struct Book book = {
		"Neon Genesis Evangelion",
		MANUAL,
		"978-159-116-400-5",
		"Yoshiyuki Sadamoto", //貞本 義行
		17};
	struct Date date_borrowed, date_returned;
	date_borrowed.year = 1900;
	date_borrowed.month = 1;
	date_borrowed.day = 1;
	date_returned.year = 2000;
	date_returned.month = 12;
	date_returned.day = 31;
	printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
	return 0;
}