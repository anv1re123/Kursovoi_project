## Постановка задачи

# Мониторинг: Линия розлива — расход жидкости

## Постановка задачи

Датчик технологической установки работает непрерывно и формирует последовательность показаний расхода жидкости в **мл/с**:
- $X(1), X(2), \dots, X(n)$

Каждое полученное показание $X(i)$ преобразуется по кусочной функции в индикатор технологического процесса $Q(i)$:
- $Q(i) = F(X(i))$

Преобразование функции **$Q(X)$** имеет следующий вид:

$$
Q(X) = \begin{cases}
1.5X + 5, & \text{при } X < 50 \\
X + 30, & \text{при } 50 \le X < 100 \\
0.6X + 70, & \text{при } X \ge 100
\end{cases}
$$

Контроль выполняется непосредственно при поступлении каждого нового значения $Q(i)$ по схеме:
- $X(i) \rightarrow Q(i) \rightarrow \text{Control}(Q(i))$

В соответствии с **Типом В**, требуется найти максимальную серию последовательных значений, которые находятся ниже заданного порогового уровня $Q_0$.


Массив из $N  показателей $Q[]$ используется для последующего вычисления:
- Средний абсолютный прирост между соседними значениями;
- Максимальный прирост;
- Минимальный прирост.

## Задание 

## Алгоритм и блок-схема:

1. Главная программа `main`:
- Включает русский язык в консоли.
- Просит пользователя ввести число `X` и считывает его.
- Проверяет условие: если `X` находится в рамках от `30` до `140`, то программа вызывает функцию `Q(X)` и печатает результат на экран.
- Если число `X` не входит в этот промежуток, программа выводит на экран сообщение: `«ОШИБКА!!!! Заданное число не входит в диапазон [30;140]»`.

2. Формула расчета индикатора Q(X):

Q(X) = \begin{cases}
6\sqrt{X - 64} + 5, & X < 65 \\
2(X - 82.5) + 50, & 65 \le X \le 100 \\
0.25(X - 100)^2 + 55, & X > 100
\end{cases}

3. Ручной расчет

| X   | Расчёт Q                | Результат |
|----:|-------------------------|----------:|
| 70  | 2(70 - 82,5) + 50       | 25        |
| 90  | 2(90 - 82,5) + 50       | 65        |
| 110 | 0,25(110 - 100)² + 55   | 80        |

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

double Q(double X);
int control(double Q_i, double Q_i1);
void vvesti_vivesty(void);

int main() {
    setlocale(LC_ALL, "RUS");
    printf("=== МОНИТОРИНГ РЕАКТОРА ===\n\n");
    vvesti_vivesty();
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
```
## Результаты работы программы
```text
=== МОНИТОРИНГ РЕАКТОРА ===

Введите значение температуры X в диапазоне [30; 140]: 82,50
Вывод Q: 50,00

```
## Информация о разработчике
```text
Имя: Коноваленко Ярослав
Вариант: 38
Группа: бИЦТ-261
```
