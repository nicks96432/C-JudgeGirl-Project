#include <stdio.h>
#include <assert.h>
#define abs(x) ((x) > 0 ? (x) : (-(x)))
enum player
{
	DPS,
	HEALER,
	TANK
};
int main(void)
{
	int dps[5000] = {}, healer[5000] = {}, tank[5000] = {};
	short now__dps = 0, now__healer = 0, now__tank = 0;
	short first__dps = -1, first__healer = -1, first__tank = -1;
	int player;
	while (scanf("%d", &player) != EOF)
	{
		switch (player % 3)
		{
		case DPS:
			if (now__dps >= 5003)
			{
				now__dps %= 5000;
			}
			dps[now__dps % 5000] = player;
			now__dps++;
			break;
		case HEALER:
			if (now__healer >= 5000)
			{
				now__healer %= 5000;
			}
			healer[now__healer] = player;
			now__healer++;
			break;
		case TANK:
			if (now__tank >= 5000)
			{
				now__tank %= 5000;
			}
			tank[now__tank] = player;
			now__tank++;
			break;
		}
		if (abs(now__dps - first__dps) % 5000 > 3 && abs(now__healer - first__healer) % 5000 > 1 && abs(now__tank - first__tank) % 5000 > 1)
		{
			printf("%d %d %d %d %d\n", dps[(first__dps + 1) % 5000], dps[(first__dps + 2) % 5000], dps[(first__dps + 3) % 5000], healer[(first__healer + 1) % 5000], tank[(first__tank + 1) % 5000]);
			first__dps = (first__dps + 3) % 5000;
			first__healer = (first__healer + 1) % 5000;
			first__tank = (first__tank + 1) % 5000;
		}
	}
	return 0;
}