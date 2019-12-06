#include <stdio.h>
typedef struct Student
{
	char name[20];
	int id;
	char phone[10];
	float grade[4];
	int birth_year;
	int birth_month;
	int birth_day;
} student;
int main(void)
{
	FILE *fin, *fout;
	char namein[85], nameout[85];
	scanf("%s%s", namein, nameout);
	fin = fopen(namein, "rb");
	fout = fopen(nameout, "wb");
	student s;
	fprintf(fout, "<table border=\"1\">\n<tbody>\n");
	while (fread(&s, sizeof(student), 1, fin) == 1)
	{
		fprintf(fout, "<tr>\n<td>%s</td>\n", s.name);
		fprintf(fout, "<td>%d</td>\n", s.id);
		fprintf(fout, "<td>%s</td>\n", s.phone);
		fprintf(fout, "<td>%f, %f, %f, %f</td>\n", s.grade[0], s.grade[1], s.grade[2], s.grade[3]);
		fprintf(fout, "<td>%d, %d, %d</td>\n</tr>\n", s.birth_year, s.birth_month, s.birth_day);
	}
	fprintf(fout, "</tbody>\n</table>\n");
	fclose(fin);
	fclose(fout);
	return 0;
}