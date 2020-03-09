#ifndef TCT_H

#define TCT_H
typedef struct directory
{
	char name[256];
	struct directory *childDir;
	struct directory *silbingDir;
} Directory;
void tree(Directory *fs);
Directory *cd(Directory *fs, char path[]);

#endif /* TCT_H */