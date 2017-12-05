#include "Rotate.h"

struct data gendata() {
	struct data x;
	//srand((unsigned)time(NULL));
	x.n = rand() % 1000 + 1;
	x.d = (rand() % (2*x.n) -x.n);

	x.str = (char*)malloc(x.n);
	for (int i = 0; i < x.n; i++) {
		x.str[i] = rand() % 24 + 65;
	}
	return x;
}

int main() {
	double time;
	struct data x = gendata();
	printf("STRLength\t ROTATEdistance\t T.trivial\t T.juggle\t T.bw\t\t T.reverse\n");
	printf("%d\t\t %d\t\t ",x.n, x.d);
	
	time = clock();
	for (int i = 0; i < 10000;i++)
	trivialrotation(x.str, x.d, x.n);
	printf("%.3f\t\t ", (clock() - time) / CLOCKS_PER_SEC);

	time = clock();
	for (int i = 0; i < 10000; i++)
	leftRotate(x.str, x.d, x.n);
	printf("%.3f\t\t ", (clock() - time) / CLOCKS_PER_SEC);

	time = clock();
	for (int i = 0; i < 10000; i++)
	Blockswap(x.str, x.d, x.n);
	printf("%.3f\t\t ", (clock() - time) / CLOCKS_PER_SEC);

	time = clock();
	for (int i = 0; i < 10000; i++)
	reverse(x.str, x.n, x.d);
	printf("%.3f\t\t ", (clock() - time) / CLOCKS_PER_SEC);

	return 0;
}
