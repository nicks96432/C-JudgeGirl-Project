#ifndef BLOCKMOVER_H

#define BLOCKMOVER_H
#define uint64_t unsigned long long
void printBlock(uint64_t *block);
void initialize(uint64_t *block, int row, int column, int size);
int moveLeft(uint64_t *block);
int moveRight(uint64_t *block);
int moveUp(uint64_t *block);
int moveDown(uint64_t *block);
#undef uint64_t
#endif //BLOCKMOVER_H