#include "Header.h"

void spawnApples(int count, Point apples[5]) {
	for (int i = 0; i < count; i++) {
		apples[i].x = (rand() % (WIDTH - 3)) + 1;
		apples[i].y = (rand() % (HEIGHT - 2)) + 1;
	}
}

void levelUp(int* applecount, int score, int* speed) {
	*(applecount) += 1;
	if (*speed > 50) {
		*speed -= 50;
	}
	if ((score / 50) % 2 == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
	}
}

void input(int* direct, int* gameover) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			*direct = 1;
			break;
		case 's':
			*direct = 2;
			break;
		case 'd':
			*direct = 3;
			break;
		case 'w':
			*direct = 4;
			break;
		case 'x':
			*gameover = 1;
			break;
		}
	}
}

void snakemove(int direct, Point* snakeh) {
	switch (direct) {
	case 1:
		snakeh->x -= 1;
		break;
	case 2:
		snakeh->y += 1;
		break;
	case 3:
		snakeh->x += 1;
		break;
	case 4:
		snakeh->y -= 1;
		break;
	default:
		break;
	}
}

void objColision(Point tail[50], int tailLen, Point snakeh, int* gameover) {
	__asm {
		cmp snakeh.x, 0
		jle go
		mov eax, WIDTH
		sub eax, 1
		cmp snakeh.x, eax
		jae go
		cmp snakeh.y, 0
		jle go
		mov eax, HEIGHT
		sub eax, 1
		cmp snakeh.y, eax
		jae go

		jmp ex
	go:
		mov eax, gameover
		mov [eax], 1
	ex:
	}

	for (int i = 0; i < tailLen; i++) {
		if (tail[i].x == snakeh.x && tail[i].y == snakeh.y) {
			*gameover = 1;
		}
	}
}

void appleColision(int* applecount, Point snakeh, int* tailLen, int* score, int* difficulty, Point apples[5], int* speed) {
	for (int i = 0; i < *(applecount); i++) {
		if ((snakeh.x == (apples[i].x)) && (snakeh.y == (apples[i].y))) {
			(*tailLen)++;
			*score += 10;
			if (*score % *difficulty == 0) {
				levelUp(applecount, *score, speed);
			}
			spawnApples(*(applecount), apples);
		}
	}
}