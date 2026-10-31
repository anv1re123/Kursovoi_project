## Постановка задачи

# Мониторинг: Линия розлива — расход жидкости

## Цель проекта
Показать, что задача понята, исходные данные и математическая модель определены, а структура программы на языке Си спланирована и реализована в виде каркаса.

## Описание входных данных
- **$X(i)$** — непрерывная последовательность показаний датчика расхода жидкости на технологической линии розлива в мл/c.


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

1. 

2. Ручной расчет

### Блок-схема 

<img width="328" height="807" alt="{4230887A-422A-4847-9242-595F067C495A}" src="https://github.com/user-attachments/assets/b85de36b-75ad-4265-8999-34006cc10af9" />


[Ссылка на блок-схему 1](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22goGTumh30XNIcFfH6rBE%22%3E7ZlbU6MwFMc%2FDTP64A6QFsqjvakz7qqt18cIERgD6aSppfvpNyGh3Lwtg2xnLQ805yQ5hHP%2B%2FRUaDYyi5ITCRfCTeAhrpu4lGhhrJj9si38Iz0Z6DMMxpMenoad8uWMe%2FkbKqSvvKvTQsjSQEYJZuCg7XRLHyGUlH6SUrMvDngguX3UBfVRzzF2I69670GOB9A5MO%2FefotAPsisbliN7IpgNVneyDKBH1gUXmGhgRAlhshUlI4RF9rK8yHnTN3q3C6MoZp%2BZcHN6NttgN7pyZ7f%2B4GY6u12xo1eiKNeSbbIc8Dg83dwYroOQofkCuqJnzUvOfQGLMLcM3uS3uEBn8ZKXTHmeQoxHBBPKbSzSdORB%2BnygmWCaHpo52rYPxXgSs9fH6%2Bkhx8u2GC%2FX%2BgLxSq1VG%2BuaMxbnoa7xJQzsrM3Pw%2FQ80UwL85sdeuELb%2FosjSNdj7Tq4QktjUuvhyhDSSFdKuMniESI0Q0fEhREYSkFrHMBbVWhooDM3pSnQCVffxs5rzBvqCL%2FRcFNGRd5NdnXFUBW1EUfi6eolNg7Fl86brkYLpehWxYIJavYQ2J9usg%2FeoIrzM7hI8JD6D77aXdWfvnNHKIkZPdiwo%2B%2Bsh5UMNEeJypWamwyI%2BapKkwS5kOxL5%2BWWtk8xRdIfcTeuW9QV92HGuirglKEIQtfyskvCKP%2FTuHVFS5JyCu1lU7PdPhdFsVjGJUgspJqXhERH4caVELJ5NRCpVrc3npzeYLP8CjFTKoQCjFGmPgURrx8C0RDvgBEq32XeUcThCUo%2B2H6J0i7bws6hl2BTq9SbOerqNNrkTrgm1LHNHccO7UfrebYAaBb7GS53XOnoK7pwf1hV%2BgBvS974AEtsifTye7BZ8fZ0GvvkaTX8SOJ2d%2Bzoaauq67AUKt2e2Cw2gRDfw%2BGRmDoV4M0B4NldgwG%2B229fFswjC5%2BXc8uzrvCQ63m7eFh0CYe7D0eGuHBqr6SNseDXX09%2BWo8OHs81NQ1vz6%2BnnQFh1rFW4ND9nraDhycPRwawWFQ%2FZegORwcveP%2FOf%2B%2FjZdXNlXEXsyx2nMRZ7kv00%2F3Zay3Nlh2fm%2BmppVPYIWb%2BU6fFFG%2BYQomfwA%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

<img width="422" height="697" alt="{E6224367-D37F-42A6-873E-04D5663B1FC0}" src="https://github.com/user-attachments/assets/2c87d4cd-acdc-40b4-abaf-0c98741d8e6f" />


[Ссылка на блок-схему 2](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22goGTumh30XNIcFfH6rBE%22%3E7VjbbqMwEP0apN2HRmCHNHksSS%2BRdqW26WX76IILVg2OjNOQ%2Ffq1sbmnl0RpNqrKA3jGM4M9c3yMseA4zs45mke%2FWYCpBewgs%2BDEAsCBwJYPpVlpzWDkaEXISWCMKsWM%2FMVGafzCBQlw2jAUjFFB5k2lz5IE%2B6KhQ5yzZdPsidHmW%2BcoxB3FzEe0q70ngYi0dgiOK%2F0FJmFUvNkZjHRPjApjM5M0QgFb1lTw1IJjzpjQrTgbY6qSV%2BRF%2B5290lsOjONEfMTh9mJ6vaJ%2BfOVf34XD27Pru4U4WhPFqFKxKnIg48h0S8FbRkTg2Rz5qmcpKy51kYiplBzZlFOc42mSypIZzROhdMwo41KmKk1HAeLPPywAz%2FLLAuOy%2FVPZs0Sst7fzS9vrtrLXY31BdGHGak1sazRRd8%2B25BCGx0Vb3r38fmqBAZWT9QLyIpuhyONo1SNva2RCG3b5%2BzAXOKuly2T8HLMYC76SJlENFAODgGUFoBIVJkq5TlZNF2TgG5aRqwrLhinyBgUHOi4OOrDvIoAtuI%2FfB08dKUlwohadlHyK0pT4TYBwtkgCrMZnq%2FzjJ7Sg4hd6xNRD%2FnOYdxfl1yvTwxkRf5RDzzXSgwmm2pPMxMqFVSEkMlU1JyU%2B1Psqt1wq%2FAy%2FIB5i8ca8YRd172LANQXlmCJBXprJrwHDfaPw5g2XjMhKldDpg5GcZR08jtMKoitp%2FOoU8X6oYSuUTk4nVI7FcurbwxN%2BhI9ymskRwhGlmLKQo1iWb445kQPAvN13WXVsQ2EZLjam%2F0JpV5brWe5kV9TjHLeop98q%2BeizuKe%2FQ%2B6BX5N7DpZTOjvShzkFNnc22N8vowD3m1LWUorj9Ho9CPfILJ3S7%2B6rZrgBtRwcZRzW0m%2Bt1769s4%2BJ%2Fp4%2FJsDoe%2BmvwdYAxWqYyWOqHrObk5vp7GY6nu2LBjow2BkNwK93nF1zVFUn3BNzklV3fdp189Pu4LVj6%2BGfeMGnoWKTM%2B%2F35rDJ5uC2d%2FTtN4dO%2FbfeHKRY%2FVXT5tW%2FSXj6Dw%3D%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

### Код программы

Программа написана на языке **C++**.

```cpp
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
```
## Результаты работы программы
```text
=== ЛИНИЯ РОЗЛИВА - РАСХОД ЖИДКОСТИ ===

Введите значение расхода X: 40
Вывод Q: 65,00

```
## Информация о разработчике
```text
Имя: Коноваленко Ярослав
Вариант: А23
Группа: бИЦТ-261
```
