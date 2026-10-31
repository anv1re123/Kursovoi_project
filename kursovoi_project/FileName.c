#include <stdio.h>
#include <locale.h>
#include <math.h>

double calc_Q(double X);
int control(double Q_i, double Q0);
int vvesti_vivesty();
void statistics(void); 

int main() {
    setlocale(LC_ALL, "RUS");
    printf("=== ЛИНИЯ РОЗЛИВА - РАСХОД ЖИДКОСТИ ===\n\n");
    vvesti_vivesty();
    return 0;
}
// 1. Функция расчета индикатора Q(X)
double calc_Q(double X) {
    if (X < 50) {
        return 1.5 * X + 5;
    }
    else if (X >= 50 && X < 100) {
        return X + 30;
    }
    else {
        return 0.6 * X + 70;
    }
}
// 2. Функция проверки отклонения
int control(double Q_i, double Q0) {
    if (Q_i < Q0) {
        return 1; // Отклонение
    }
    else {
        return 0; // Норма
    }
}
// 3. Функция считывания и обработки ввода
int vvesti_vivesty(){
    double X;
    printf("Введите значение расхода X: ");
    if (scanf("%lf", &X) != 1) {
        printf("Ошибка ввода!!!\n");
    }
    else {
        printf("Вывод Q: %.2lf\n", calc_Q(X));
    }
}
// 4. Функция расчета статистики (Заглушка)
void statistics(void)
{
}