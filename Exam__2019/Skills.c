#include <stdio.h>
#include <stdbool.h>
typedef struct Special
{
	int base;
	int extra;
	int cooldown;
} special;
int main(void)
{
	int round;
	scanf("%d", &round);
	int maxhealth, regent;
	scanf("%d%d", &maxhealth, &regent);
	special attack1, attack2, attack3;
	scanf("%d%d%d", &attack1.base, &attack1.extra, &attack1.cooldown);
	scanf("%d%d%d", &attack2.base, &attack2.extra, &attack2.cooldown);
	scanf("%d%d%d", &attack3.base, &attack3.extra, &attack3.cooldown);
	int normal;
	scanf("%d", &normal);
	bool used1 = false, used2 = false, used3 = false;
	bool cool1 = false, cool2 = false, cool3 = false;
	int i, health = maxhealth, use;
	int use1__time = -2147483647, use2__time = -2147483647, use3__time = -2147483647;
	int damage1, damage2, damage3;
	for (i = 0; i < round; i++)
	{
		if (i <= attack1.cooldown)
		{
			damage1 = attack1.base;
		}
		else
		{
			damage1 = attack1.base + attack1.extra * (i - attack1.cooldown);
		}
		if (i <= attack2.cooldown)
		{
			damage2 = attack2.base;
		}
		else
		{
			damage2 = attack2.base + attack2.extra * (i - attack2.cooldown);
		}
		if (i <= attack3.cooldown)
		{
			damage3 = attack3.base;
		}
		else
		{
			damage3 = attack3.base + attack3.extra * (i - attack3.cooldown);
		}
		if (used1 && use1__time + attack1.cooldown <= i)
		{
			damage1 = attack1.base + attack1.extra * (i - use1__time - attack1.cooldown);
		}
		if (used2 && use2__time + attack2.cooldown <= i)
		{
			damage2 = attack2.base + attack2.extra * (i - use2__time - attack2.cooldown);
		}
		if (used3 && use3__time + attack3.cooldown <= i)
		{
			damage3 = attack3.base + attack3.extra * (i - use3__time - attack3.cooldown);
		}
		cool1 = false;
		cool2 = false;
		cool3 = false;
		if (use1__time + attack1.cooldown <= i)
		{
			cool1 = true;
		}
		if (use2__time + attack2.cooldown <= i)
		{
			cool2 = true;
		}
		if (use3__time + attack3.cooldown <= i)
		{
			cool3 = true;
		}
		if (cool1 && cool2 && cool3)
		{
			if (damage1 >= damage2 && damage1 >= damage3 && damage1 >= normal)
			{
				use = damage1;
				use1__time = i;
				used1 = true;
			}
			else if (damage2 >= damage1 && damage2 >= damage3 && damage2 >= normal)
			{
				use = damage2;
				use2__time = i;
				used2 = true;
			}
			else if (damage3 >= damage1 && damage3 >= damage2 && damage3 >= normal)
			{
				use = damage3;
				use3__time = i;
				used3 = true;
			}
			else
			{
				use = normal;
			}
		}
		else if (cool1 && cool2 && !cool3)
		{
			if (damage1 >= damage2 && damage1 >= normal)
			{
				use = damage1;
				use1__time = i;
				used1 = true;
			}
			else if (damage2 >= damage1 && damage2 >= normal)
			{
				use = damage2;
				use2__time = i;
				used2 = true;
			}
			else
			{
				use = normal;
			}
		}
		else if (!cool1 && cool2 && cool3)
		{
			if (damage2 >= damage3 && damage2 >= normal)
			{
				use = damage2;
				use2__time = i;
				used2 = true;
			}
			else if (damage3 >= damage2 && damage3 >= normal)
			{
				use = damage3;
				use3__time = i;
				used3 = true;
			}
			else
			{
				use = normal;
			}
		}
		else if (cool1 && !cool2 && cool3)
		{
			if (damage1 >= damage3 && damage1 >= normal)
			{
				use = damage1;
				use1__time = i;
				used1 = true;
			}
			else if (damage3 >= damage1 && damage3 >= normal)
			{
				use = damage3;
				use3__time = i;
				used3 = true;
			}
			else
			{
				use = normal;
			}
		}
		else if (cool1 && !cool2 && !cool3)
		{
			if (damage1 >= normal)
			{
				use = damage1;
				use1__time = i;
				used1 = true;
			}
			else
			{
				use = normal;
			}
		}
		else if (!cool1 && cool2 && !cool3)
		{
			if (damage2 >= normal)
			{
				use = damage2;
				use2__time = i;
				used2 = true;
			}
			else
			{
				use = normal;
			}
		}
		else if (!cool1 && !cool2 && cool3)
		{
			if (damage3 >= normal)
			{
				use = damage3;
				use3__time = i;
				used3 = true;
			}
			else
			{
				use = normal;
			}
		}
		else
		{
			use = normal;
		}
		health -= use;
		printf("%d ", health);
		if (health <= 0)
		{
			break;
		}
		health += regent;
		if (health > maxhealth)
		{
			health = maxhealth;
		}
	}
	return 0;
}