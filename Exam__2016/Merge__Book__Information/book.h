#ifndef BOOK_H

#define BOOK_H
#define MAXN 100
#define MAXL 25
typedef struct bookauthor
{
	char book_title[MAXL], author[MAXL];
} BookAuthor;
typedef struct bookselling
{
	char book_title[MAXL];
	int selling, date;
} BookSelling;
typedef struct bookinfo
{
	char book_title[MAXL], author[MAXL];
	int selling, date;
} BookInfo;
typedef struct bookinfolist
{
	int num; // the number of BookInfo
	BookInfo books[MAXN];
} BookInfoList;
BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[]);

#endif /* BOOK_H */