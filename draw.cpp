#include "Header.h"

void clearGameField(char s[HEIGHT][(WIDTH + 1)]) {
	for (int i = 1; i < HEIGHT - 1; i++) {
		for (int j = 1; j < WIDTH - 2; j++) {
			s[i][j] = ' ';
		}
	}
}

void drawSnake(char s[HEIGHT][(WIDTH + 1)], int len, Point tail[50], Point snakeh) {
	s[snakeh.y][snakeh.x] = '0';

	for (int k = 0; k < len; k++) {
		s[tail[k].y][tail[k].x] = 'o';
	}
}

void drawApples(char s[HEIGHT][(WIDTH + 1)], int count, Point* apples) {
	for (int i = 0; i < count; i++) {
		s[apples[i].y][apples[i].x] = '@';
	}

	s[0][0] = '#';
}

void drawStrings(char s[HEIGHT][(WIDTH + 1)]) {
	for (int i = 0; i < HEIGHT; i++) {
		printf("%s\n", s[i]);
	}

	printf("\n");
}

void placeWalls(char s[HEIGHT][(WIDTH + 1)]) {
	for (int i = 0; i < WIDTH; i++) {
		s[0][i] = '#';
		s[(HEIGHT - 1)][i] = '#';
	}
	for (int i = 0; i < HEIGHT; i++) {
		s[i][0] = '#';
		s[i][WIDTH - 1] = '#';
		s[i][WIDTH] = '\0';
	}
}

void fillField(char s[HEIGHT][(WIDTH + 1)]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			s[i][j] = ' ';
		}
	}
}

void tailmove(Point tail[50], int tailLen, Point snakeh) {
	int preX = tail[0].x;
	int preY = tail[0].y;
	int pre2X, pre2Y;
	tail[0].x = snakeh.x;
	tail[0].y = snakeh.y;
	for (int i = 1; i < tailLen; i++) {
		pre2X = tail[i].x;
		pre2Y = tail[i].y;
		tail[i].x = preX;
		tail[i].y = preY;
		preX = pre2X;
		preY = pre2Y;
	}
}

void drawFrame(char s[HEIGHT][(WIDTH + 1)], int count, Point* apples, int tailLen, Point tail[50], int score, Point snakeh) {
	system("cls");
	printf(" \n");

	clearGameField(s);
	drawApples(s, count, apples);
	drawSnake(s, tailLen, tail, snakeh);
	drawStrings(s);

	printf("Очки: % d\n", score);
	printf("\n");
}