#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
static int comp(const void *x, const void *y)
{
	int cmp;
	BookInfo *a = (BookInfo *)x, *b = (BookInfo *)y;
	if (!(cmp = strcmp(a->book_title, b->book_title)))
	{
		if (a->date > b->date)
		{
			return 1;
		}
		else if (a->date < b->date)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return cmp > 0 ? 1 : -1;
	}
}
BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[])
{
	BookInfoList answer;
	answer.num = 0;
	bool usedSelling[M];
	for (int i = 0; i < M; i++)
	{
		usedSelling[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!usedSelling[j] && !strcmp(authorArr[i].book_title, sellingArr[j].book_title))
			{
				answer.books[answer.num].selling = sellingArr[j].selling;
				answer.books[answer.num].date = sellingArr[j].date;
				strcpy(answer.books[answer.num].author, authorArr[i].author);
				strcpy(answer.books[answer.num].book_title, authorArr[i].book_title);
				answer.num++;
				usedSelling[j] = true;
			}
		}
	}
	qsort(answer.books, answer.num, sizeof(BookInfo), comp);
	return answer;
}