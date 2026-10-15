#include <stdio.h>
#include <locale.h>
#include <math.h>
double Q(double X) {
	if (X < 65) {
		X = 6 * (sqrt(X - 65 + 1)) + 5;
	}
	else if (X >= 65 && X <= 100) {
		X = 2 * (X - 82.5) + 50;
	}
	else {
		X = 0.25 * pow((X - 100), 2);
	}
	return X;
}

int main() {
	// X = 82.50 °C ? ожидается Q = 50.00.Проверить на первом этапе проекта.
	setlocale(LC_ALL, "RUS");

	double X;
	printf("Введите X в диапазоне [30;140]:");
	scanf("%lf", &X);
	if (X >= 30 && X <= 140) {
		printf("Вывод Q: %.2lf", Q(X));
	}
	else {
		printf("ОШИБКА!!!! Заданное число %.2lf не входит в диапазон [30;140]", X);
	}


}