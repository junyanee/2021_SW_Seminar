#include <stdio.h>

void setIdentityMatrix(double (*matrix)[4]);

int main(void) {

	double matrix[4][4] = { 0.0, };
	
	setIdentityMatrix(matrix, 4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%.1f  ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void setIdentityMatrix(double (*matrix)[4]) {
	for (int i = 0; i < 4; i ++) {
		matrix[i][i] = 1.0;
	}
}