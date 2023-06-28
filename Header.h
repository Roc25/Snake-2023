#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <wincon.h>
#include <time.h>


int const HEIGHT = 30, WIDTH = 30;

struct Point {
	int x;
	int y;
};

void drawFrame(char s[HEIGHT][(WIDTH + 1)], int count, Point* apples, int tailLen, Point tail[50], int score, Point snakeh);
void fillField(char s[HEIGHT][(WIDTH + 1)]);
void placeWalls(char s[HEIGHT][(WIDTH + 1)]);
void tailmove(Point tail[50], int tailLen, Point snakeh);
void spawnApples(int count, Point apples[5]);
void input(int* direct, int* gameover);
void snakemove(int direct, Point* snakeh);
void appleColision(int* applecount, Point snakeh, int* tailLen, int* score, int* difficulty, Point apples[5], int* speed);
void objColision(Point tail[50], int tailLen, Point snakeh, int* gameover);