#include "maze.h"

void createStack(Stack &S)
{
    top(S) = NULL;
}

bool isEmpty(Stack S)
{
    return top(S) == NULL;
}

void push(Stack &S, int x, int y)
{
    address pointer_P = new element_stack;
    infotype_stack koordinat;
    koordinat.x = x;
    koordinat.y = y;
    info(pointer_P) = koordinat;
    next(pointer_P) = NULL;
    if (isEmpty(S))
    {
        top(S) = pointer_P;
    }
    else
    {
        next(pointer_P) = top(S);
        top(S) = pointer_P;
    }
}

void pop(Stack &S)
{
    if (isEmpty(S))
    {
        cout << "STACK KOSONG" << endl;
    }
    else if (next(top(S)) == NULL)
    // kasus 1 element
    {
        top(S) = NULL;
    }
    else
    {
        top(S) = next(top(S));
    }
}

Stack reverseStack(Stack S)
{
    Stack reverse_S;
    createStack(reverse_S);
    address pointer_P = top(S);
    while (pointer_P != NULL)
    {
        push(reverse_S, info(pointer_P).x, info(pointer_P).y);
        pointer_P = next(pointer_P);
    }
    return reverse_S;
}

void printStack(Stack S)
{
    address pointer_P = top(S);
    while (pointer_P != NULL)
    {
        cout << "(" << info(pointer_P).x << "," << info(pointer_P).y << ") ";
        pointer_P = next(pointer_P);
    }
    cout << endl;
    cout << endl;
}

void searchPath(int maze[51][51][2], Stack &S, int Dimensi_1, int Dimensi_2)
{
    // Kondisi untuk berhentinya adalah koordinat titik akhir (50,26)
    if (!(Dimensi_1 == 50 && Dimensi_2 == 26))
    {
        if ((maze[Dimensi_1][Dimensi_2 + 1][0] == 1) && (maze[Dimensi_1][Dimensi_2 + 1][1] == 0))
        // Prioritas pertama, bergerak ke kanan
        {
            Dimensi_2++;
            push(S, Dimensi_1, Dimensi_2);
            maze[Dimensi_1][Dimensi_2][1] = 1;
            searchPath(maze, S, Dimensi_1, Dimensi_2);
        }
        else if ((maze[Dimensi_1 + 1][Dimensi_2][0] == 1) && (maze[Dimensi_1 + 1][Dimensi_2][1] == 0))
        // Prioritas kedua, bergerak ke bawah
        {
            Dimensi_1++;
            push(S, Dimensi_1, Dimensi_2);
            maze[Dimensi_1][Dimensi_2][1] = 1;
            searchPath(maze, S, Dimensi_1, Dimensi_2);
        }
        else if ((maze[Dimensi_1][Dimensi_2 - 1][0] == 1) && (maze[Dimensi_1][Dimensi_2 - 1][1] == 0))
        // Prioritas ketiga, bergerak ke kiri
        {
            Dimensi_2--;
            push(S, Dimensi_1, Dimensi_2);
            maze[Dimensi_1][Dimensi_2][1] = 1;
            searchPath(maze, S, Dimensi_1, Dimensi_2);
        }
        else if ((maze[Dimensi_1 - 1][Dimensi_2][0] == 1) && (maze[Dimensi_1 - 1][Dimensi_2][1] == 0))
        // Prioritas keempat, bergerak ke atas
        {
            Dimensi_1--;
            push(S, Dimensi_1, Dimensi_2);
            maze[Dimensi_1][Dimensi_2][1] = 1;
            searchPath(maze, S, Dimensi_1, Dimensi_2);
        }
        else
        // Kasus buntu
        {
            pop(S);
            searchPath(maze, S, info(top(S)).x, info(top(S)).y);
        }
    }
}

void printArray(int maze[51][51][2])
{
    for (int iterator_i = 0; iterator_i < 51; iterator_i++)
    {
        for (int iterator_j = 0; iterator_j < 51; iterator_j++)
        {
            cout << maze[iterator_i][iterator_j][0] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printMaze(int maze[51][51][2])
{
    for (int iterator_i = 0; iterator_i < 51; iterator_i++)
    {
        for (int iterator_j = 0; iterator_j < 51; iterator_j++)
        {
            if (maze[iterator_i][iterator_j][0] == 1)
            {
                cout << "  ";
            }
            else
            {
                cout << maze[iterator_i][iterator_j][0] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void printPath(int maze[51][51][2], Stack S)
{
    address pointer_P;
    bool found;
    for (int iterator_i = 0; iterator_i < 51; iterator_i++)
    {
        for (int iterator_j = 0; iterator_j < 51; iterator_j++)
        {
            pointer_P = top(S);
            found = false;
            while (pointer_P != NULL && !found)
            {
                if ((info(pointer_P).x == iterator_i) && (info(pointer_P).y == iterator_j))
                {
                    cout << "  ";
                    found = true;
                }
                else
                {
                    pointer_P = next(pointer_P);
                }
            }
            if (!found)
            {
                if (maze[iterator_i][iterator_j][0] == 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "0 ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

int selectMenu()
{
    int userChoice = 0;
    cout << "============================== MENU ==============================\n";
    cout << "1. Menampilkan maze representasi array\n";
    cout << "2. Menampilkan maze yang belum di-solve\n";
    cout << "3. Menampilkan koordinat jalur setelah di-solve\n";
    cout << "4. Menampilkan maze yang sudah di-solve\n";
    cout << "0. Exit\n\n";
    cout << "Masukkan menu: ";
    cin >> userChoice;
    cout << endl;
    return userChoice;
}