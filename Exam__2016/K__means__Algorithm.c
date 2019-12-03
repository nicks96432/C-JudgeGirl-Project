#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 50
#define MAX_L 20
#define GROUPS 3
char names[MAX_N][MAX_L];
int n, l, r;
int dist(char *str1, char *str2)
{
	int i, ans = 0;
	for (i = 0; i < l; i++)
	{
		ans += abs(str1[i] - str2[i]);
	}
	return ans;
}
int comp(const void *x, const void *y)
{
	return strcmp(names[*(int *)x], names[*(int *)y]);
}
int pick(char name[MAX_L], int pickid[], int count)
{
	int i;
	int mindistance = dist(name, names[pickid[0]]), mindistanceid = 0, newdistance;
	for (i = 0; i < count; i++)
	{
		newdistance = dist(name, names[pickid[i]]);
		if (newdistance < mindistance || newdistance == mindistance && strcmp(names[pickid[mindistanceid]], names[pickid[i]]) > 0)
		{
			mindistance = newdistance;
			mindistanceid = i;
		}
	}
	return mindistanceid;
}
int newleader(int memberid[MAX_N], int countmember)
{
	int i, j, sum[MAX_L + 5] = {0};
	char average[MAX_L + 5] = {0};
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < countmember; j++)
		{
			sum[i] += names[memberid[j]][i];
		}
		average[i] = sum[i] / countmember;
	}
	return memberid[pick(average, memberid, countmember)];
}
void kmeans(int leaderid[GROUPS], int memberid[GROUPS][MAX_N], int countmember[GROUPS])
{
	int i;
	/* 初始化 */
	for (i = 0; i < GROUPS; i++)
	{
		leaderid[i] = i;
	}
	int round, groupid;
	for (round = 0; round < r; round++)
	{
		/* 歸零 */
		for (i = 0; i < GROUPS; i++)
		{
			countmember[i] = 0;
		}
		/* 挑組員 */
		for (i = 0; i < n; i++)
		{
			groupid = pick(names[i], leaderid, GROUPS);
			memberid[groupid][countmember[groupid]] = i;
			countmember[groupid]++;
		}
		/* 選新隊長 */
		for (i = 0; i < GROUPS; i++)
		{
			leaderid[i] = newleader(memberid[i], countmember[i]);
		}
	}
	return;
}
int main(void)
{
	scanf("%d%d%d", &n, &l, &r);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%s", names[i]);
	}
	int leaderid[GROUPS], memberid[GROUPS][MAX_N], countmember[GROUPS];
	kmeans(leaderid, memberid, countmember);
	qsort((void *)leaderid, GROUPS, sizeof(leaderid[0]), comp);
	for (i = 0; i < GROUPS; i++)
	{
		printf("%s\n", names[leaderid[i]]);
	}
}