#include <stdio.h>
#include <locale.h>
#include <math.h>

double Q(double X);
int control(double Q_i, double Q_i1);
void vvesti_vivesty(void);

int main() {
    setlocale(LC_ALL, "RUS");
    printf("=== МОНИТОРИНГ РЕАКТОРА ===\n\n");
    vvesti_vivesty();
    return 0;

}

// 1. Функция расчета индикатора Q(X)
double Q(double X) {
    if ( X>= 30 && X <= 64) {
        printf("ОШИБКА: Значение X = % .2lf дает отрицательный корень!\n", X);
        return  0;
    }
    else if (X >= 65 && X <= 100) {
        return 2 * (X - 82.5) + 50;
    }
    else {
        return 0.25 * pow((X - 100), 2) + 55;
    }
}

// 2. Функция проверки отклонения
int control(double Q_i, double Q_i1) {
    if (fabs(Q_i - Q_i1) > 10.0) {
        return 1; // Нарушение
    }
    else {
        return 0; // Норма
    }
}


// 3. Функция считывания и обработки ввода
void vvesti_vivesty(void) {
    double X;
    printf("Введите значение температуры X в диапазоне [30; 140]: ");
    if (scanf("%lf", &X) != 1) {
        printf("Ошибка ввода!!!\n");
    }

    if (X >= 30 && X <= 140) {
        printf("Вывод Q: %.2lf\n", Q(X));
    }
    else {
        printf("ОШИБКА!!!! Заданное число %.2lf не входит в диапазон [30;140]\n", X);
    }
}
// 4. Функция расчета статистики (Заглушка)
void statistics(double Q_prikol, int start, int end) {
    // Будет реализова потом)))
    (void)Q_prikol;
    (void)start;
    (void)end;

}

