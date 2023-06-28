#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

void gameOverprint(int score) {
	Sleep(3000);
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);

	printf("Вы проиграли! Вы набрали %d очков!\n", score);
}

void gameLoop(char s[HEIGHT][(WIDTH + 1)], int* applecount, Point apples[5], Point tail[50]) {
	int score = 0;
	int speed = 500;
	int direct;
	int difficulty = 50;
	int gameover = 0;

	int tailLen = 0;
	struct Point snakeHead;
	snakeHead.x = WIDTH / 2;
	snakeHead.y = HEIGHT / 2;

	while (!gameover) {
		input(&direct, &gameover);
		tailmove(tail, tailLen, snakeHead);
		snakemove(direct, &snakeHead);
		drawFrame(s, *(applecount), apples, tailLen, tail, score, snakeHead);

		Sleep(speed);
		objColision(tail, tailLen, snakeHead, &gameover);
		appleColision(applecount, snakeHead, &tailLen, &score, &difficulty, apples, &speed);
	}

	gameOverprint(score);
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	srand(time(NULL));
	rand();

	char field[HEIGHT][(WIDTH + 1)];

	int applecount = 1;
	struct Point apples[5];
	spawnApples(applecount, apples);

	fillField(field);

	placeWalls(field);

	struct Point tail[50];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);

	gameLoop(field, &applecount, apples, tail);

	_getch();
	return 0;
}
