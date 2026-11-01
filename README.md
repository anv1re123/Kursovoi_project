
# Мониторинг: Линия розлива — расход жидкости 

> Учебный проект для автоматизированного контроля расхода жидкости и анализа статистических данных.


## Описание входных данных
- **$X(i)$** — непрерывная последовательность показаний датчика расхода жидкости на технологической линии розлива(мл/c).


## Индивидуальная формула варианта
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
    * Если да: то программа вызывает функцию $calc _ Q(X)$ и выводит результат на экран.
    * Если нет: то программа выводит сообщение об ошибке $"Ошибка  ввода!!!"$.
4. Конец

### Блок-схема 

<img width="349" height="802" alt="{00C54B72-E58C-41DB-BB59-2F9D7CD0FA00}" src="https://github.com/user-attachments/assets/df38137e-d2b2-4b91-b339-65d9919278ca" />


[Ссылка на блок-схему 1](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22goGTumh30XNIcFfH6rBE%22%3E7ZpbU6MwFMc%2FDTP64A6Q3ni0N3XGXbVVVx8jRMiYkk6a2nY%2F%2FSYklJvVylKmO0MfMOfk5EBO%2FvxKiQYYzNYXDM6Dn9RDxLBNb22AoWHblmMB8Ud6Ntpjmpby%2BAx72pc4pvgPigO1d4k9tMgEckoJx%2FOs06VhiFye8UHG6Cob9kpJ9qxz6KOCY%2BpCUvT%2Bxh4PlLdndxP%2FJcJ%2BEJ%2FZ6jiqZwbjYD2TRQA9ukq5wMgAA0YpV63ZeoCIrF5cFzVuvKN3e2EMhXyfAQ%2BXV5MNcWd37uTR7z2MJ49LfvZBFu1a8E1cA5FHlFsY%2FVWAOZrOoSt7VmLJhS%2FgMyIsSzTFFOfoKlyIJdOeV0zIgBLKhE1kmc48yN5ODBuMo49hD7btUxlPQ%2F5xvBl9VLxqy3ifQQ%2BjZExIQ3mdC87oG%2FpOIjXpd0iWetLG0DScoTz2TUPMpdeN2%2BLYj44jw%2B4QUbW%2Bh99F0%2BdRHuV6YXmPWJlMXHQ%2BxDhap%2Bqul%2B4C0RnibCNCgpS6OlpKq0SJW3npLCC2N9khUN8H%2FjZzIhXR0Gr5hnJslRd5hfunKCW6ZC76WoVpyYXeubx7heUSuFhgN6s0Rpehh%2BT1mbL%2B6BUuCb%2BGL4j0ofvmR93x8qtbvI%2FWmD%2FJAT%2Fa2nrWyWR7uNa5ImMTG6EoVWqQNJ%2FTfcmwyIrHldUfh8xH%2FJNKgaJOv1RNW0uAIQI5fs8uV0pK7U%2Bkos9wS7FY263YWrYj6pKWm2Xlkqi11%2BPSdPo6VS%2BXShWnkCpS73bq5QUN9kFhRLhIUwwSgggVAJqJ5ZsjhsUFIJbvu006ytBzjeLvxP%2Bbpk9V8c7q5njXyqnGORTwWhUCDzTA2xN4tn3kxCt8w5YnHgD1Ei%2BubYO8QyBvfPJ0Whf1QOtgj3mgQuzFgjs%2B7lXxg%2BGosNSq7kGsVfODmN1usHQ4LN3VxaSCbKpjUqdKJrUbJtXEpHY%2BSXkmdeyamdTdrbCGSf8q08HNr%2FvJzXVdZCqIpzoy9aokU7chU01k6uTfGpQnUzf%2Fe%2FDQZHIaMh2OTNP78%2FtRXVwqSKcyLsUvFqrhktNwqSYu9fJvhMpzyTFrfp3ebC3u1lhx21DuNp7rXUV5VDuP7WjnsbNrC%2FHodx8LotuDaMJMNsWVGpP%2FLQCjvw%3D%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)


<img width="428" height="715" alt="{BA5AF915-7128-4DA1-9CF4-5E62578EDECE}" src="https://github.com/user-attachments/assets/2c79f811-c820-4c02-b670-4085399951fb" />


[Ссылка на блок-схему 2](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22goGTumh30XNIcFfH6rBE%22%3E7VjbbqMwEP0apN2HVmBDGh5DkraRdqW2abvbRxdcQDU4Mk5D9uvXxibc0ltEo1QKD8QznhnwzOHYGQOOk%2FyCoUX0mwaYGMAMcgNODAAsxzXFj9SslWYIoVKELA60UaWYx%2F%2BwVmq%2FcBkHOGsYckoJjxdNpU%2FTFPu8oUOM0VXT7ImS5lMXKMQdxdxHpKv9Ewc80qsAZ5X%2BEsdhVD7ZGrhqJkGlsV5JFqGArmoqODXgmFHK1SjJx5jI5JV5UX7nr8xuXozhlH%2FE4e5ydrMmfnLt39yHw7vzm%2FslP9kSRasyvi5zIOKIdAvBW0Uxx%2FMF8uXMSlRc6CKeECFZYiiWuMCzNBMl05qnmJAxJZQJmcg0nQSIPf8wADwvLgOMN%2BOf0p6mfLu9WVzKXo2lfcYZfcbbPSxvZE2B8gAQQtuVHmp1L4gs9eqMiWm4E3n3TEO89PCsHIu7V9ynBhgQkR4viF%2FEMORFHKV6ZG2NKEHDrngeZhzntQTrGl1gmmDO1sIkqsFooDGzqiC3wZGOAkt53XRBGvDhJnKFCTHQsPgERICKi4POh9LFDF0yH78Ptzq20mAkP1Mh%2BQRlWew3IcXoMg2wfD9T5h8%2FoSXhv9AjJh7yn8Niuiy%2F%2BpY9nMf8r3Q4dbT0oIPJ8STXsQphXQqpSFXNSYoP9bnKrZBKv7fwtx2xmsMQCzF%2FI1Owi9N3UeNoCDBMEI9fmuWqQcl5Ayr6CVc0FrXdgM0GrshLHW6W1Qqiaq%2F96jT0fqhhK5RKTidUgd7N0ncHNPwI5xVUVmCKIUIwoSFDiSjfArNYvABm7bmramIXmsxxufl9E9q8NhzPcCZ90Zt11qI3uwUS96v4ze6R3%2BCR3w6ctzr75Id5Czb3W2jvl7WAc6Stnmjr9HSPxNXBSX8Hs%2BEnmOvgGOm7M0uLDmyzt%2FOQvefzEHCPzNLH%2F0gwQIlcWPqYyZ%2F57eh2Nr%2Bdjef7opoOcHqjGnjsE4BtPQDZOhjpFoG8qzaCU7QRBq%2F1Aw6%2FlQC%2BDEefaSYct6yv3bKc9slk9y2rg5idtywhVi1RZV41luH0Pw%3D%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

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
