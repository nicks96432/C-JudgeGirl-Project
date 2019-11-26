#ifndef COMPONENTPART_H
#define COMPONENTPART_H

#define MAXLENGTH 16
#define MAXCOMPONENT 64
typedef struct
{
	char name[MAXLENGTH];
	int numComponent;
	int componentPartList[MAXCOMPONENT];
	int price;
} ComponentPart;
void findPrice(int N, ComponentPart list[]);

#endif /* COMPONENT_H */