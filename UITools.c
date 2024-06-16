#include "header.h"

VOID SetColor(UINT uFore, UINT uBack) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}

int KeyboardChoice(int userChoice, int choice_max) {
	char key = getch();
	if (key == -32) {
		key = getch();//上下左右是两个char，所以获取第二个get作为数据
		if (key == 72 || key == 75)
		{
			if (userChoice == 0) return 0;
			return --userChoice;
		}
		if (key == 80 || key == 77)
		{
			if (userChoice == choice_max) return choice_max;
			return ++userChoice;
		}
	}
	if (key == 27) {
		return 5;// EXIT的时候的user_choice;
	}

	if (key == 'w' || key == 'a') {
		if (userChoice == 0) return 0;
		return --userChoice;
	}
	if (key == 's' || key == 'd') {
		if (userChoice == choice_max) return choice_max;
		return ++userChoice;
	}
	if (key == '\r') 
		return 200;
	return userChoice;
}

int KeyboardChoice2(int userChoice) {
	char key = getch();
	if (key == -32) {
		key = getch();//上下左右是两个char，所以获取第二个get作为数据

		if (key == 75) {
			if (userChoice == 0) return 0;
			return --userChoice;
		}
		if (key == 77) {
			if (userChoice == 1) return 1;
			return ++userChoice;
		}

	}
	if (key == 27) {
		return 5;// EXIT的时候的user_choice;
	}

	
	if (key == '\r') return 200;
	return userChoice;
}