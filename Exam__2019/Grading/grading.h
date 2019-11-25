#ifndef GRADING_H
#define GRADING_H

#define maxL 1000
typedef struct Submission
{
	int subID;
	int studentID;
	char outputs[10][maxL];
} Submission;
void grading(char answer[10][maxL], Submission *sub, int num_of_submission);

#endif /* GRADING_H */