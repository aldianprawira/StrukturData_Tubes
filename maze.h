#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include <iostream>
#define top(S) S.top
#define info(P) P->info
#define next(P) P->next

using namespace std;

struct infotype_stack
{
    int x, y;
};

typedef struct element_stack *address;

struct element_stack
{
    infotype_stack info;
    address next;
};

struct Stack
{
    address top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
void push(Stack &S, int x, int y);
void pop(Stack &S);
Stack reverseStack(Stack S);
void printStack(Stack S);

void searchPath(int maze[21][21][2], Stack &S, int Dimensi_1, int Dimensi_2);
void printArray(int maze[21][21][2]);
void printMaze(int maze[21][21][2]);
void printPath(int maze[21][21][2], Stack S);

int selectMenu();

#endif // MAZE_H_INCLUDED