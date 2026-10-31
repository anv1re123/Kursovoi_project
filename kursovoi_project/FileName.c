#include <stdio.h>
#include <locale.h>
#include <math.h>
#define COEFF_A 1.5
#define COEFF_B 5.0
#define COEFF_C 30.0
#define COEFF_D 0.6
#define COEFF_E 70.0
#define LIMIT_LOW 50
#define LIMIT_MAX 100

void print_titul(void);
void print_result(void);
double calc_Q(double X);
int control(double Q_i, double Q0);
void statistics(void); 

int main() {
    setlocale(LC_ALL, "RUS");
    print_titul();
    print_result();
    return 0;
}

double calc_Q(double X) {
    if (X < LIMIT_LOW) {
        return COEFF_A * X + COEFF_B;
    }
    else if (X >= LIMIT_LOW && X < LIMIT_MAX) {
        return X + COEFF_C;
    }
    else {
        return COEFF_D * X + COEFF_E;
    }
}

int control(double Q_i, double Q0) {
    if (Q_i < Q0) {
        return 1;
    }
    else {
        return 0; 
    }
}

void print_result(void){
    double X;
    printf("Введите значение расхода X: ");
    if (scanf("%lf", &X) != 1) {
        printf("Ошибка ввода!!!\n");
    }
    else {
        printf("Вывод Q: %.2lf\n", calc_Q(X));
    }
}

void print_titul(void) {
    printf("================================================================\n");
    printf("  ЛИНИЯ РОЗЛИВА — МОНИТОРИНГ РАСХОДА                            \n");
    printf("  Вариант 23                                                    \n");
    printf("  Вычисляет индикатор Q по значению X и контролирует отклонения.\n");
    printf("================================================================\n\n");
}

