#include <stdio.h>
#include <ctype.h>
char *erase(char *s);
int main(void)
{
	char s[1048576];
	while (fgets(s, 1048576, stdin))
	{
		char *q = erase(s);
		puts(q);
	}
	return 0;
}
char *erase(char *s)
{
	char *tmp = s;
	// ����tmp1���s�̫�@�Ӧr��
	while (*tmp)
	{
		tmp++;
	}
	tmp--;
	// �װť��ݪť�
	while (isspace(*tmp))
	{
		*tmp = 0;
		tmp--;
	}
	//�װūe�ݪť�
	while (isspace(*s))
	{
		s++;
	}
	return s;
}