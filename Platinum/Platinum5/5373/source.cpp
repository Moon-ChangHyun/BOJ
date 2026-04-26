// 4ms, 2028KB

#include<iostream>
#include<array>
using namespace std;

array<array<char, 3>, 3> faceB;
array<array<char, 3>, 3> faceU;
array<array<char, 3>, 3> faceF;
array<array<char, 3>, 3> faceD;
array<array<char, 3>, 3> faceL;
array<array<char, 3>, 3> faceR;

char* targetU[3];
char* targetD[3];
char* targetL[3];
char* targetR[3];
array<array<char, 3>, 3>* targetFace;

void resetCube() {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			faceU[i][j] = 'w';
			faceD[i][j] = 'y';
			faceF[i][j] = 'r';
			faceB[i][j] = 'o';
			faceL[i][j] = 'g';
			faceR[i][j] = 'b';
		}
}

void rotateTarget(bool isClockWise) {
	char tmp;
	if (isClockWise) {
		tmp = (*targetFace)[0][0];
		(*targetFace)[0][0] = (*targetFace)[2][0];
		(*targetFace)[2][0] = (*targetFace)[2][2];
		(*targetFace)[2][2] = (*targetFace)[0][2];
		(*targetFace)[0][2] = tmp;

		tmp = (*targetFace)[0][1];
		(*targetFace)[0][1] = (*targetFace)[1][0];
		(*targetFace)[1][0] = (*targetFace)[2][1];
		(*targetFace)[2][1] = (*targetFace)[1][2];
		(*targetFace)[1][2] = tmp;

		for (int k = 0; k < 3; ++k) {
			tmp = *(targetU[k]);
			*(targetU[k]) = *(targetL[k]);
			*(targetL[k]) = *(targetD[k]);
			*(targetD[k]) = *(targetR[k]);
			*(targetR[k]) = tmp;
		}
	}
	else {
		tmp = (*targetFace)[0][0];
		(*targetFace)[0][0] = (*targetFace)[0][2];
		(*targetFace)[0][2] = (*targetFace)[2][2];
		(*targetFace)[2][2] = (*targetFace)[2][0];
		(*targetFace)[2][0] = tmp;

		tmp = (*targetFace)[0][1];
		(*targetFace)[0][1] = (*targetFace)[1][2];
		(*targetFace)[1][2] = (*targetFace)[2][1];
		(*targetFace)[2][1] = (*targetFace)[1][0];
		(*targetFace)[1][0] = tmp;

		for (int k = 0; k < 3; ++k) {
			tmp = *(targetU[k]);
			*(targetU[k]) = *(targetR[k]);
			*(targetR[k]) = *(targetD[k]);
			*(targetD[k]) = *(targetL[k]);
			*(targetL[k]) = tmp;
		}
	}
}

void rotateF(bool isClockWise) {
	targetFace = &faceF;
	targetU[0] = &faceU[2][2];
	targetU[1] = &faceU[2][1];
	targetU[2] = &faceU[2][0];
	targetD[0] = &faceD[0][0];
	targetD[1] = &faceD[0][1];
	targetD[2] = &faceD[0][2];
	targetL[0] = &faceL[0][2];
	targetL[1] = &faceL[1][2];
	targetL[2] = &faceL[2][2];
	targetR[0] = &faceR[2][0];
	targetR[1] = &faceR[1][0];
	targetR[2] = &faceR[0][0];
	rotateTarget(isClockWise);
}

void rotateU(bool isClockWise) {
	targetFace = &faceU;
	targetU[0] = &faceB[2][2];
	targetU[1] = &faceB[2][1];
	targetU[2] = &faceB[2][0];
	targetD[0] = &faceF[0][0];
	targetD[1] = &faceF[0][1];
	targetD[2] = &faceF[0][2];
	targetL[0] = &faceL[0][0];
	targetL[1] = &faceL[0][1];
	targetL[2] = &faceL[0][2];
	targetR[0] = &faceR[0][0];
	targetR[1] = &faceR[0][1];
	targetR[2] = &faceR[0][2];
	rotateTarget(isClockWise);
}

void rotateD(bool isClockWise) {
	targetFace = &faceD;
	targetU[0] = &faceF[2][2];
	targetU[1] = &faceF[2][1];
	targetU[2] = &faceF[2][0];
	targetD[0] = &faceB[0][0];
	targetD[1] = &faceB[0][1];
	targetD[2] = &faceB[0][2];
	targetL[0] = &faceL[2][2];
	targetL[1] = &faceL[2][1];
	targetL[2] = &faceL[2][0];
	targetR[0] = &faceR[2][2];
	targetR[1] = &faceR[2][1];
	targetR[2] = &faceR[2][0];
	rotateTarget(isClockWise);
}

void rotateB(bool isClockWise) {
	targetFace = &faceB;
	targetU[0] = &faceD[2][2];
	targetU[1] = &faceD[2][1];
	targetU[2] = &faceD[2][0];
	targetD[0] = &faceU[0][0];
	targetD[1] = &faceU[0][1];
	targetD[2] = &faceU[0][2];
	targetL[0] = &faceL[2][0];
	targetL[1] = &faceL[1][0];
	targetL[2] = &faceL[0][0];
	targetR[0] = &faceR[0][2];
	targetR[1] = &faceR[1][2];
	targetR[2] = &faceR[2][2];
	rotateTarget(isClockWise);
}

void rotateL(bool isClockWise) {
	targetFace = &faceL;
	targetU[0] = &faceU[2][0];
	targetU[1] = &faceU[1][0];
	targetU[2] = &faceU[0][0];
	targetD[0] = &faceD[2][0];
	targetD[1] = &faceD[1][0];
	targetD[2] = &faceD[0][0];
	targetL[0] = &faceB[2][0];
	targetL[1] = &faceB[1][0];
	targetL[2] = &faceB[0][0];
	targetR[0] = &faceF[2][0];
	targetR[1] = &faceF[1][0];
	targetR[2] = &faceF[0][0];
	rotateTarget(isClockWise);
}

void rotateR(bool isClockWise) {
	targetFace = &faceR;
	targetU[0] = &faceU[0][2];
	targetU[1] = &faceU[1][2];
	targetU[2] = &faceU[2][2];
	targetD[0] = &faceD[0][2];
	targetD[1] = &faceD[1][2];
	targetD[2] = &faceD[2][2];
	targetL[0] = &faceF[0][2];
	targetL[1] = &faceF[1][2];
	targetL[2] = &faceF[2][2];
	targetR[0] = &faceB[0][2];
	targetR[1] = &faceB[1][2];
	targetR[2] = &faceB[2][2];
	rotateTarget(isClockWise);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	for (cin >> T; ~--T; ) {
		int n;
		cin >> n;
		resetCube();
		for (int i = 0; i < n; ++i) {
			string op;
			cin >> op;
			switch (op[0]) {
			case 'U':
				rotateU(op[1] == '+');
				break;
			case 'F':
				rotateF(op[1] == '+');
				break;
			case 'B':
				rotateB(op[1] == '+');
				break;
			case 'D':
				rotateD(op[1] == '+');
				break;
			case 'L':
				rotateL(op[1] == '+');
				break;
			case 'R':
				rotateR(op[1] == '+');
				break;
			}
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << faceU[i][j];
			}
			cout << '\n';
		}
	}
}