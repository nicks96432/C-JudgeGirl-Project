#ifndef ACTIVITY_H

#define ACTIVITY_H
typedef struct activity
{
	int start;
	int end;
} Activity;
int select(Activity activities[], int n);

#endif /* ACTIVITY_H */