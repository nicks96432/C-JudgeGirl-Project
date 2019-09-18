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
	// 先用tmp1找到s最後一個字元
	while (*tmp)
	{
		tmp++;
	}
	tmp--;
	// 修剪末端空白
	while (isspace(*tmp))
	{
		*tmp = 0;
		tmp--;
	}
	//修剪前端空白
	while (isspace(*s))
	{
		s++;
	}
	return s;
}