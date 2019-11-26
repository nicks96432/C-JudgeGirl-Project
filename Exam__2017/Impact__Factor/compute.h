#ifndef COMPUTE_H
#define COMPUTE_H
typedef struct
{
	char journalName[64];
	int numCitedPaper;
	int citedPaperIndex[1024];
} paper;
void compute(paper P[], int N);

#endif /* COMPUTE_H */