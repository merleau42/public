#include <stdio.h>

typedef struct B
{
	int x;
	int y;
} t_B;

typedef struct A
{
	int a;
	int b;
	int c;
	t_B B;

	int	(*x)(t_B*);
	int	(*y)(t_B*);
} t_A;

int getX(t_A *A)
{
	return A->B->x;
}

int getY(t_A *A)
{
	return A->B->y;
}

int main()
{
    t_A A;
	t_B *p;

    A.a = 1;
    A.b = 2;
	A.c = 3;
	A.B.x = 4;
	A.B.y = 5;

	A.x = getX;
	A.y = getY;

	//printf("%d, %d", (*p).x, (*p).y);
	printf("%d, %d", A.x(&A), A.y(&A));
}