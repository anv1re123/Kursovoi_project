# Курсовой проект

## Постановка задачи

Датчик технологической установки работает непрерывно и формирует последовательность показаний температуры стенки реактора:
- `X(1),X(2)...X(n)`

Каждое полученное показание `X(i)` преобразуется по индивидуальной кусочной функции в индикатор технологического процесса `Q(i)`:
- `Q(i)=F(Xi)`

В соответствии с Вариантом 38, математическое преобразование функции `Q(X)` имеет следующий вид:
- `Q(i) = 6*sqrt(X(i) - 65 + 1) + 5 — при X(i) < 65`
- `Q(i) = 2*(X(i) - 82.5) + 50 — при 65  <= X(i) <= 100`
- `Q(i) = 0.25*(X_i - 100)^2 + 55 — при X(i) > 100`

Оперативный контроль выполняется непосредственно при поступлении каждого нового значения по схеме:
- `X(i)→Q(i)→Control(Q(i))`

При этом выполняется проверка отклонения значения от номинала. Базовое (начальное) значение `Q(0) = 50.00`. Если модуль разности между текущим показателем и предыдущим превышает критический порог `|Q(i) - Q(i-1)| > 10`, программа сигнализирует о нарушении режима. Названия состояний процесса определяются алгоритмом.
Накопленный массив из `N = 60` показателей `Q[]` используется исключительно для последующего статистического анализа. В рамках статистического анализа для подмассива `Q[11..33]` рассчитываются:
- Средний абсолютный прирост между соседними значениями
- Максимальный прирост
- Минимальный прирост

Для верификации алгоритма на первом этапе проекта используется контрольный пример: при входном значении температуры `X = 82.50`, ожидаемое значение индикатора составляет `Q = 50.00`.


## 1. Алгоритм и блок-схема

1. Начало алгоритма.
2. Ввести номера команд \(A\) и \(B\).
3. Проверить условие: номер команды \(A\) чётный, а номер команды \(B\) нечётный, или наоборот.
   - Если условие выполняется, присвоить переменной res значение 1.
   - Если условие не выполняется, присвоить переменной res значение 0.
4. Вывести значение переменной res на экран.
5. Конец алгоритма.

### Блок-схема

<img width="523" height="700" alt="{D07ACF12-45B9-4621-B004-1E6B20A1DA5A}" src="https://github.com/user-attachments/assets/42d65db5-b163-415e-8d07-c4cfe9d18377" />


[Ссылка на блок-схему](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22_iuYZesH0EMXVjER_gjp%22%3E3Zjdb5swEMD%2FGqR2Uic%2BQ3hsPtq9TJqUh22PLjhg1eDImCbZX78zNt%2FpmlIWKc2DY5%2FvjLnf%2BTgwnGV6eORol3xnEaaGbUYHw1kZtm05tgl%2FUnJUkllgKUHMSaSVGsGG%2FMFaqO3igkQ47ygKxqggu64wZFmGQ9GRIc7Zvqu2ZbR71R2K8UCwCREdSn%2BSSCRKOrf9Rv4NkziprmzNAjWTokpZ30meoIjtWyJnbThLzphQvfSwxFQ6r%2FKLsnt4ZbbeGMeZOMcgF4iLoZFeJxfH6pbBDLwLg8U%2BIQJvdiiUM3sADLJEpBRGFnRjjiICCy0ZZRxkGcuk1ZZQWomodM1dhPjzjWE7D%2BXPsJd1%2F1bqs2aJrr5Z%2FpS%2B6kt9teEXRAu9YWNlGsFKtgvTgJ3N%2FaoP7aJs19oIc4EPrRvXrnrELMWCH0EladH0NLp9Q96qcOpVHEePdXwHeoh03MX1yg0a6Gg6p0mRbFecRQpmEaWYMiCRXhmvsl3Ymo5sXdDKRnGaneDk9jjZXU7WFKAg6UREEJadA4snLH0q8uvBRGBorG1jHhj3mo1pOA%2BjCAXvJ%2BSYUxBCNDwLDiuyCEsj83oA5UVaIlnJe1F9G7RMq%2BzB9cybG2nyRTqkmb3VopNzt6Pw%2BkO89ryLt06mGq%2FrTpIpPy9dUrMlbbITPcbeOHyeNwEdVojP%2FSArD91Ez6vecamzX1U3TwEEZ9HnLQDvW6WEKga9shicXar08%2F0pEGkcOBq8lwyRsYKHVSg21X2bJKyy0UPGRcJiliG6bqSLbmpssYVYuZfvTzB8oix8rv0OF4qx6FWqQ2dyTJEgL92b%2BJBnnHGeaVXT%2F80z%2BEDEL6n51dOj35Uy9FcHvUg5OOrB0JudcvIDHtWmPxgBtzThGnTDtc5C1RLKadqqx6Xexnmo3HGoevX0BQO5qRP7acXV75IXCnJvpOfq%2FV%2F09IeXcsts7Nm%2FvFcmPcVwOXRsKezk6cxfP%2BRW75B7vtf285v6juv1uKgdjM4E%2FrVlgnbRevobkyor7Hfg1c6%2BM7%2Faju%2BenbgrFbbd5riTk98bFjPvn5jf1J%2FNzWnDYj4uLNpwLhgTum6ePtHBsPkArPzYfEZ31n8B%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

Программа написана на языке **C++**.

```cpp
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    int n;
    double sum = 0;

    printf("Введите число n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        sum = sum + 1.0 / ((2 * i + 1) * (2 * i + 1));
    }

    printf("Ответ: %.3lf", sum);

    return 0;
}
```
## 3. Результаты работы программы
```text
Введите число n: 5
Ответ: 0,192
```
## 4. Информация о разработчике
```text
Имя: Коноваленко Ярослав
Вариант: 13
Группа: бИЦТ-261
Подгруппа: 1
