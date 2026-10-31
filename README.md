
# Мониторинг: Линия розлива — расход жидкости 

> Учебный проект для автоматизированного контроля расхода жидкости и анализа статистических данных.

## Цель проекта
Показать, что задача понята, исходные данные и математическая модель определены, а структура программы на языке Си спланирована и реализована.

## Описание входных данных
- **$X(i)$** — непрерывная последовательность показаний датчика расхода жидкости на технологической линии розлива(мл/c).


## Индивидуальная формула варианта (Вариант 23)
Каждое полученное показание $X(i)$ преобразуется по кусочной функции в индикатор технологического процесса $Q(i) = f(X)$:

$$
Q(X) = \begin{cases}
1.5X + 5, & \text{при } X < 50 \\
X + 30, & \text{при } 50 \le X < 100 \\
0.6X + 70, & \text{при } X \ge 100
\end{cases}
$$

Контроль выполняется по схеме Типа B (поиск максимальной серии последовательных значений ниже заданного уровня $Q_0$).

## Ручной счет (контрольные примеры)

| № | Входное значение $X(i)$ | Условие выбора формулы | Расчет индикатора $Q(i)$ | Ожидаемое значение $Q(i)$ |
|---|---|---|---|---|
| 1 | $X = 40.00$ | $X < 50$| $1.5 \cdot 40.00 + 5$ | **$65.00$** |
| 2 | $X = 75.00$ | $50 \le X < 100$ | $75.00 + 30$ | **$105.00$** |
| 3 | $X = 120.00$ | $X \ge 100$ | $0.6 \cdot 120.00 + 70$ | **$142.00$** |

## Схема преобразования данных
- $X(i) \rightarrow f(X) \rightarrow Q \rightarrow \text{CONTROL} \rightarrow \text{STATE}$
- $Q[] \rightarrow \text{заданный интервал } \rightarrow \text{STATISTICS}$

## Структура программы (Каркас)
Программа на языке Си разбита на логические функции:
- Чтение и вывод данных (`vvesti_vivesty`)
- Расчет индикатора $Q$ (`calc_Q`)
- Контроль отклонений / поиск серии (`control`)
- Статистический анализ для подмассива $Q[]$ (cреднее, размах, дисперсия, количество смен направления изменения последовательности) (`statistics`)



## Алгоритм и блок-схема:

1. Начало
2. Функция $calc_Q(X)$ для вычисления значения индикатора, которая принимает число $X$:

* Если $X < 50$, то возвращает значение, вычисленное по формуле: $1.5 * X + 5.0$.
* Если $50 <= X < 100$, то возвращает значение, вычисленное по формуле: $X + 30.0$.
* Если $X >= 100$, то возвращает значение, вычисленное по формуле: $0.6 * X + 70.0$.

3. Главная программа:

* Объявление переменной $X$ типа $double$.
* Просит пользователя ввести значение расхода $X$.
* Считывание введенного значения.
* Проверка корректности ввода (было ли введено число):
    * Если да: то программа вызывает функцию $calc_Q(X)$ и выводит результат на экран.
    * Если нет: то программа выводит сообщение об ошибке $"Ошибка ввода!!!"$.
4. Конец

### Блок-схема 

<img width="328" height="807" alt="{4230887A-422A-4847-9242-595F067C495A}" src="https://github.com/user-attachments/assets/b85de36b-75ad-4265-8999-34006cc10af9" />


[Ссылка на блок-схему 1](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22goGTumh30XNIcFfH6rBE%22%3E7ZlbU6MwFMc%2FDTP64A6QFsqjvakz7qqt18cIERgD6aSppfvpNyGh3Lwtg2xnLQ805yQ5hHP%2B%2FRUaDYyi5ITCRfCTeAhrpu4lGhhrJj9si38Iz0Z6DMMxpMenoad8uWMe%2FkbKqSvvKvTQsjSQEYJZuCg7XRLHyGUlH6SUrMvDngguX3UBfVRzzF2I69670GOB9A5MO%2FefotAPsisbliN7IpgNVneyDKBH1gUXmGhgRAlhshUlI4RF9rK8yHnTN3q3C6MoZp%2BZcHN6NttgN7pyZ7f%2B4GY6u12xo1eiKNeSbbIc8Dg83dwYroOQofkCuqJnzUvOfQGLMLcM3uS3uEBn8ZKXTHmeQoxHBBPKbSzSdORB%2BnygmWCaHpo52rYPxXgSs9fH6%2Bkhx8u2GC%2FX%2BgLxSq1VG%2BuaMxbnoa7xJQzsrM3Pw%2FQ80UwL85sdeuELb%2FosjSNdj7Tq4QktjUuvhyhDSSFdKuMniESI0Q0fEhREYSkFrHMBbVWhooDM3pSnQCVffxs5rzBvqCL%2FRcFNGRd5NdnXFUBW1EUfi6eolNg7Fl86brkYLpehWxYIJavYQ2J9usg%2FeoIrzM7hI8JD6D77aXdWfvnNHKIkZPdiwo%2B%2Bsh5UMNEeJypWamwyI%2BapKkwS5kOxL5%2BWWtk8xRdIfcTeuW9QV92HGuirglKEIQtfyskvCKP%2FTuHVFS5JyCu1lU7PdPhdFsVjGJUgspJqXhERH4caVELJ5NRCpVrc3npzeYLP8CjFTKoQCjFGmPgURrx8C0RDvgBEq32XeUcThCUo%2B2H6J0i7bws6hl2BTq9SbOerqNNrkTrgm1LHNHccO7UfrebYAaBb7GS53XOnoK7pwf1hV%2BgBvS974AEtsifTye7BZ8fZ0GvvkaTX8SOJ2d%2Bzoaauq67AUKt2e2Cw2gRDfw%2BGRmDoV4M0B4NldgwG%2B229fFswjC5%2BXc8uzrvCQ63m7eFh0CYe7D0eGuHBqr6SNseDXX09%2BWo8OHs81NQ1vz6%2BnnQFh1rFW4ND9nraDhycPRwawWFQ%2FZegORwcveP%2FOf%2B%2FjZdXNlXEXsyx2nMRZ7kv00%2F3Zay3Nlh2fm%2BmppVPYIWb%2BU6fFFG%2BYQomfwA%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

<img width="460" height="750" alt="{1D0B6602-20D2-43AB-BC1E-6E19B91CE4D1}" src="https://github.com/user-attachments/assets/d1ba847d-3a64-4014-9b6c-2e013e6944b6" />


[Ссылка на блок-схему 2](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22goGTumh30XNIcFfH6rBE%22%3E7VjbbqMwEP0apN2HVmCHNHkMSS%2BRdqW26WX76IILVg2OjNOQ%2Ffq1sbmnl0RpNqrKA3jGM4M9c3yMseA4zs45mke%2FWYCpBewgs%2BDEAsCBwJYPpVlpTX%2FoaEXISWCMKsWM%2FMVGafzCBQlw2jAUjFFB5k2lz5IE%2B6KhQ5yzZdPsidHmW%2BcoxB3FzEe0q70ngYi0dgBOKv0FJmFUvNnpD3VPjApjM5M0QgFb1lTw1IJjzpjQrTgbY6qSV%2BRF%2B5290lsOjONEfMTh9mJ6vaJ%2BfOVf34WD27Pru4U4WhPFqFKxKnIg48h0S8FbRkTg2Rz5qmcpKy51kYiplBzZlFOc42mSypIZzROhdMwo41KmKk1HAeLPPywAz%2FLLAuOy%2FVPZs0Sst7fzS9vrtrLXY31BdGHGak1sazhRd8%2B25BAGJ0Vb3r38fmqBPpWT9QLyIpuhyONo1SNva2RCG3b5%2BzAXOKuly2T8HLMYC76SJlENFH2DgGUFoBIVJkq5TlZNF2TgG5aRqwrLhinyBgUHOi4OOrDvIoAtuI%2FfB08dKUkwUotOSj5FaUr8JkA4WyQBVuOzVf7xE1pQ8Qs9Yuoh%2FznMu4vy65Xp4YyIP8rh2DXSgwmm2pPMxMqFVSEkMlU1JyU%2B1Psqt1wq%2FAy%2FIB5i8ca8YRd172LANQXlmCJBXprJrwHDfaPw5g2XjMhKldDpgaGcZR08jtMKoitp%2FOoU8X6oQSuUTk4nVI7FcurbwxN%2BhI9ymskRwhGlmLKQo1iWb445kQPAvN13WXVsQ2EZLjam%2F0JpV5brWe5kV9TjnLSop9cq%2BfCzuKe3Q%2B6BX5N7DpZTOjvShzkFNnc22NsvowD3m1LWUsrx8R5JpVP13X3QDDZglYNji8Na9a2l2rN39h3R2%2FN3BBh%2Br%2Fo12OqjWA0zeUzVY3YzupnObqbj2b5ooAODndEA%2FHon2TWnVHW4HZlDrLrrg66bH3T7r51YD%2F%2BwCz4NFZscd783h002B7e9o2%2B%2FOXTqv%2FXmIMXqh5o2r35LwtN%2F%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

### Код программы

Программа написана на языке **C++**.

```cpp
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

void print_titul();
void print_result();
double calc_Q(double X);
int control(double Q_i, double Q0);


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

void print_result(){
    double X;
    printf("Введите значение расхода X: ");
    if (scanf("%lf", &X) != 1) {
        printf("Ошибка ввода!!!\n");
    }
    else {
        printf("Вывод Q: %.2lf\n", calc_Q(X));
    }
}

void print_titul() {
    printf("================================================================\n");
    printf("  ЛИНИЯ РОЗЛИВА — МОНИТОРИНГ РАСХОДА                            \n");
    printf("  Вариант 23                                                    \n");
    printf("  Вычисляет индикатор Q по значению X и контролирует отклонения.\n");
    printf("================================================================\n\n");
}




```
## Результаты работы программы
```text
================================================================
  ЛИНИЯ РОЗЛИВА - МОНИТОРИНГ РАСХОДА
  Вариант 23
  Вычисляет индикатор Q по значению X и контролирует отклонения.
================================================================

Введите значение расхода X: 43
Вывод Q: 69,50
```
## Информация о разработчике
```text
Имя: Коноваленко Ярослав
Вариант: А23
Группа: бИЦТ-261
```
