#ifndef MEDICINE_H

#define MEDICINE_H
typedef struct _Ingredient
{
	char name[128];
	int weight;
} Ingredient;
typedef struct _Medicine
{
	Ingredient active[2];
	Ingredient inactive[5];
	int countActive;
	int countInactive;
	int total;
} Medicine;
void init(Medicine *medicine);
int addActive(Medicine *medicine, char *name, int weight);
int addInactive(Medicine *medicine, char *name, int weight);
void print(Medicine *medicine);
int totalWeight(Medicine *medicine);
char *maxIngredient(Medicine *medicine);

#endif /* MEDICINE_H */