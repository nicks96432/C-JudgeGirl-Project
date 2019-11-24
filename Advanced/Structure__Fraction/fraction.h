#ifndef FRACTION_H
#define FRACTION_H

typedef struct
{
	long long a, b;
} Frac;
Frac normal(long long, long long);
Frac add(Frac, Frac);
Frac subtract(Frac, Frac);
Frac multipy(Frac, Frac);
Frac divide(Frac, Frac);

#endif /* FRACTION_H */