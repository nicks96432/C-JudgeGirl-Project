int value(int type, int width, int height, int length)
{
	if (type != 79 && type != 47 && type != 29 && type != 82 && type != 26 && type != 22)
	{
		return -1;
	}
	if (width <= 0 || height <= 0 || length <= 0)
	{
		return -2;
	}
	int unit;
	switch (type)
	{
	case 79:
		unit = 30;
		break;
	case 47:
		unit = 10;
		break;
	case 29:
		unit = 4;
		break;
	case 82:
		unit = 5;
		break;
	case 26:
		unit = 3;
		break;
	case 22:
		unit = 9;
		break;
	default:
		break;
	}
	int volume = width * height * length;
	int Gcd = gcd(width, gcd(height, length));
	int price = volume * Gcd * Gcd * Gcd * unit;
	return price;
}
int gcd(int tmp1, int tmp2)
{
	int Gcd;
	while (tmp1 != 0 && tmp2 != 0)
	{
		if (tmp1 >= tmp2)
		{
			tmp1 %= tmp2;
		}
		else
		{
			tmp2 %= tmp1;
		}
	}
	Gcd = tmp1 >= tmp2 ? tmp1 : tmp2;
	return Gcd;
}