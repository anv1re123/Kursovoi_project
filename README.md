# Мониторинг реактора: температура стенки реактора

## 1. Постановка задачи

Датчик технологической установки работает непрерывно и формирует последовательность показаний температуры стенки реактора:
- `X(1),X(2)...X(n)`

Каждое полученное показание `X(i)` преобразуется по индивидуальной кусочной функции в индикатор технологического процесса `Q(i)`:
- `Q(i)=F(Xi)`

В соответствии с Вариантом 38, преобразование функции `Q(X)` имеет следующий вид:
- `Q(i) = 6*sqrt(X(i) - 65 + 1) + 5 — при X(i) < 65`
- `Q(i) = 2*(X(i) - 82.5) + 50 — при 65  <= X(i) <= 100`
- `Q(i) = 0.25*(X_i - 100)^2 + 55 — при X(i) > 100`

Rонтроль выполняется непосредственно при поступлении каждого нового значения `Qi` по схеме:
- `X(i)→Q(i)→Control(Q(i))`

При этом выполняется проверка отклонения от начального значения: `Q(0) = 50.00`. Если модуль разности между текущим показателем и предыдущим превышаетпорог `|Q(i) - Q(i-1)| > 10`, программа сигнализирует о нарушении. Названия процессов:...
Массив из `N = 60` показателей `Q[]` используется для последующего анализа программы. В рамках анализа для подмассива `Q[11..33]` рассчитываются:
- Средний абсолютный прирост между соседними значениями
- Максимальный прирост
- Минимальный прирост

Для верификации алгоритма на первом этапе проекта используется контрольный пример: при входном значении температуры `X = 82.50`, ожидаемое значение индикатора составляет `Q = 50.00`.

## 2. Задание 1


## 1.1. Алгоритм и блок-схема:

1. Функция расчета индикатора `Q(X)`:
- Принимает введенное число `X`.
- Если `X` меньше `65`, то считает по формуле: `6 * (sqrt(X - 65 + 1)) + 5`.
- Если `X` от `65` до `100` включительно, то считает по формуле: `2 * (X - 82.5) + 50`.
- В остальных случаях (когда `X` больше `100`) считает по формуле: `0.25 * (X - 100)^2 + 55`.
- Возвращает готовый ответ наружу в главную программу.

2. Главная программа `main`:
- Включает русский язык в консоли.
- Просит пользователя ввести число `X` и считывает его.
- Проверяет условие: если `X` находится в рамках от `30` до `140`, то программа вызывает функцию `Q(X)` и печатает результат на экран.
- Если число `X` не входит в этот промежуток, программа выводит на экран сообщение: `«ОШИБКА!!!! Заданное число не входит в диапазон [30;140]»`.


### 1.2. Блок-схема 

<img width="876" height="655" alt="{8DE3FDC9-C614-4CF7-9CA1-E6B5AE32FF20}" src="https://github.com/user-attachments/assets/3a6696db-7a4a-47b8-83a8-317a750b8835" />

[Ссылка на блок-схему](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22Page-1%22%20id%3D%22Page-1%22%3E7V1pl6Kw0v41fc7Me073ISRsHxXctd3advmGbKIIirj%2B%2BjcIKKDt2LTa3HudOUNDEopQeepJVSVMv0B%2BuinY4mxUs2TFeCEJefMChReSBJAk8A%2B3ZOuV0BzwCjRbl%2F1Gx4K2vlP8Qv8%2BbanLyiLS0LEsw9Fn0ULJMk1FciJlom1b62gz1TKiT52JmnJS0JZE47S0q8vOyCtlSeZYXlR0bRQ8GdCcVzMVg8b%2BmyxGomytQ0Uw9wJ527Ic72y64RXDVV6gF%2B%2B%2B%2FBe1h47ZiumcuaGzUOz6cOzqhCQMcYjHZd%2FI16Go%2BYp5EYiXDHKP2dz%2B6DU6PIc8dPXQhfAz%2FW4snG2gsdVC3pQEfA5eYFbVDYO3DMve18H8%2Fg8u12xR1rGQoM60THx7Futo5opZOIop6cYfuc9VBSujCblWg9jBdmkrKBrR7rS0LhaXrS65Cc%2Bw5To1JR2Z5Odad0D2qx19PRstikvA94vdUr1Dlcl3o1riQYmf81yRrIlbfPPgAx%2BGzVEfjESwqBdHdSMzme3msl3I7spYj6jyqVTyA5iREMk0oDB4r%2BLSzHjO70cRCn9xj2eWbjp7VVLZFwqXZve6zorSRLOtpSnH3nBfpri6JfDVyJkavqbWI91R2jNRct9%2FjY0Jl3m6XSm2o2xC6vZHo6BYU8Wx8bsQoxAEIeXd5t%2BBWOhd%2BwYIWPbNbyH6ENAOgo7wwSf%2BeAeXIUDdFGAwMcDIJ8BSCDCSgekCGEoMMPgEWAoBBikmXQCjEgMMPQGWQoAxKGUAYxIDjH4CLIUAYyFIF8C4xABjnwBLIcBomDIGA0RihHFPhKUAYQB4fvSRw9LmhYEfZCqeqYpUYoxDKZsnQfJYEjyDyVRiLHXO%2Fk8SYs%2BM2K9gDCA6AjKGAVEeo9hUISw5i5E3YDH1HMLWzY6llbD68%2B9AaWclMY%2Bh4mNM17efci4zYKaTWnkl0N1SVsG1gqR0l%2B0K6GTbk8xmNG1P84K42nbUz21l2F1UpfcyC8C42hnsdGZLZQa8K1NW6QzX3%2FTqmYUNGLjjQauEi7VVJpcqfK2Pq000AhfhBQCBUoUvOjm%2BqCeD%2FQaDkVSUwQAkot4%2BSheDJc%2BIkTdIiT0Z7IcMBgk6ymBkymZINjm%2BmCeDpcDPj2fEKDJlbj4EiSEGiSfEUggxhMiUQSx5Rgw%2BM2JphBggUra3AiZPVsBnsiINEIt7%2BgAg5r4Iow3cJCvrqwgw6PnS3QmZVS3TeV3s94FmcAMw2xzr8Jnm%2FzSCtlcJgW8MjQW5dxL7OlWc6sbWq%2BVFQx%2Faulcr6zbusm6ZXp3h2F65oTiOYr8u8ADopuZVEoFIQzeV10DH%2Bwe6ezEpr9Jyb3H8ZwGv9%2FH3wYPNCXv7Il7waLNMcI6PWd%2F6%2FHce2nEtYOV7ijgp3us4KP2mYX8%2FR4RhqEuikTF0DWtPmOqy7NZlRb9Awjcrrjot3FQ19nth%2FRghe2SFeILJcLX6Kov25M%2BRIEj%2BcP73erawBx%2Fy2KppuVJXHTmLcq2xK8myw423IqjQ5ufGnmGlDTH8s9tNYduSa%2B2JvBXUjxJdRB%2BCBAersd0V25BVRiuupeLG4yYpNHA7hwWcIhRFqbdeF7OQsVRaVTTcYGk0JIjorFDBSCLzmwmt1iR63SnMOnyPwhST37nWg0XnuhTHrbM9wW7ORgMiN5VKfLWUsxf5Ll%2FYlCDKV%2BWmVWy1crn8vDUrr5tUjRwRjtSos80ir6CytS1PnSXVWO8GcskpfxC7mVPJfOby01WukamqEk23G0gtjKYLCqFla1f6xK9a6trvc63XqaGK3S9Qm8nMyVOZiiXSn2u6zxloMF2VqZ0wX%2B3UGf%2Budpu1idztTY1pPTvhyS7Z5oe1GW0MNVEtqPOCqjrjQrOII6hsj%2F%2FYcPpy%2Bj4C7CP40DWD87gh9n883Hjnf5PyJ%2BXzZyi8JWkYDW%2BpWIIOwt%2Bk1K8JdGYrX%2FNnmCNxlTh1Vew34MWFhG1OxFU1y7Ti1SGmPbIwN7vcGcyt5tneSN6QYhmQJdy%2FpzJ6Idbz5ASyj1336wkaE3M%2B1H6vhFtyJ%2Fp%2BaHcT7kTxuPCG3GkOstjTamo519OCywlam51lXylXskRLECpjaFAlPFPn9bL0UWAq5uiz3ZK1mmLQn7yQz1d3Nuhs3olSxmjnjG6FYEeVRaayKOjyJwVgj1uui5gwnFx53EU9ctavl5VqvpzXB9JquaabI2Vb2kmd3i7vMnR3OZFUcsgNq2Szs0ETpyDVqqbLx6sJ2zTNUd0Wmg%2FywR7COQz6NudAmni6cb%2FgxmUivOAeqb1LR9%2FVXaO%2BH%2BrfhHKoeJ7g6a493bVUUecV7hrHUUFWJdgUwt2EPE8%2B2vuYlkbWqissl%2B%2Ftj%2B08Nx7WNq%2B0vxaiyCefIp4asLW0Jb%2FVpPnBCkxjbbxXB1ZvPe5OSCyMPbF0xZQz7peQrk0b4mKhS9GhiY6ZstGdnnv%2BhjjGv%2B77Ld1zYRNqKGxDFw3F1rGSXM7wykyssEAUCgpcWa%2FEG0HQQclR4v5qG76Kywx40dYUJ%2BxsYViIxlI5JrH%2BAQp%2FeG3FEB19FVV7CClBOx8ouN80A%2BmvobF%2FKla2m0A6NPBtKISc6abhloXzfGQ0YOBiC%2FreuPt3XRQE3hgQ9QRIxL1RXKzXngpPBO4xfVDaOZifYPosDIPlvMtzUMD4uJVoGIph4Zlh6rJOaNQjdSE4nGWUEKr3skvmQpeVl%2BBb1I0SfGGcZNpKSFdhXP4PRV2uKHeVl%2Fg%2F%2FO%2FPYm47f%2B78yFcvtnPV5l6Cv38P59RX4V6SzV5Bljw8o7CH1cXAHYfsGxOdVCji%2B5PKldbGPa3taW0EGVjbAwyNJd%2BokH0RtzQw4nQihiT1RkYtjMYWxrJRC%2BO4b1vYM8C9PsDt7Y2OaN41lL3g1v7CckR8N88N49vxQJD5RWkt4Pi2bEvj8ry6UBYMLFS2u7U8r9srmluJIGvylS0OEyf1bY5a18BkyeUyaNDS6%2BW5zdUmPIOypZXw2eoYw0y1l9mNClq9NthwbgDb6%2BeHFavD6B3hQwWg1XV0ZK5tDbCfpmOYqjZYEmU87IP%2B8ENS2dqKzbGqQTfczWkLOMIS6tZoV3BarGvYoDacTudQQJn%2Fjtgw2NT4jbTaISS4cWR4HvVcssgQohsGgWwoCCTecKz8k0CQCoeBbhQIbxMFXoyFHxQaEhe2MN4qMORiuz%2BujwtjASaKCbpdPGiUi%2BV6o1KZjCfqsEv1qnreeKVgMiSjU2JPjmQ6nM4IsHcbJP8DxVcClnowYBEi7w9ZFN9Pcj1mY1s44wZ2b8yiX8asi1Eywr4U8aM0HOWJuxa1V3LveeVRj4UyxV7YF%2FcPKJ%2BHH0uQb0RshydBxIDmCT0vgEbRnVUwnlS%2B1hBoNioIBT7Jjw3huaOAsLXhH%2BDu9%2Bf38dDx5O9XIdA%2FNxp4BV4CjApXeMeTS%2BKX%2B2sc%2Bwswwu%2B7OeICWzx3TDx3TDxwxwTN4HkjGt0h5j7R3XnQM8n8i4vz7Q0c5SDAS6%2BbzD3aTb6QVkzqJrMEEVt0plDCRT%2FXU4mKokEMx%2Fd2ldl0QpnjwEvUfyZ%2FEcxn35ZGDwUzIojk69fn4ef%2BlxqH5HyAZfAdT5mD8UgvoaeMu0K8xb6OP3jPD7KFYECfi3H%2F04txxN4k9utxM2v95xFrcsBV%2Fj4cIP%2FeeT0OW1VswZvjokEqfYvV7rMGFuSXrppsEs8hR9YnCBTh%2FTfKy4n%2FPHNCkY%2Flfpa88B1CIu5HsdQES36H9%2BN3U%2FE9y9fyPhUTBFA813Jn0me%2FkytMg4v%2BUODRNLq108HGIjea4b4BvJO7qZiHf73rfR7%2FD8Ndwr2jFz2XWwP0MjjDu0QjDvbrDdcHH8y03MlC3S1CRuzdRmHLMAkjRgDIGGFS8G7ALY6VyZzv90WwsT9GxDA32zQPQd5lfsRuivPvhNLCsa2JEktJhV1cv%2BgkNfhlEjEK61PouB96IP8b3SQuFXm68YCOggjFFg8Q9f1PCK8cCfo%2FfSTCn9mQdxoPmo6OB0yQKbxyPJjnePx7POLhxmGx%2BPbjcdVW9jSPx32ZiomNBEVd8PW%2BzqEffxGWN8Ucf50YzP0%2F%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

### 1.3. Код программы

Программа написана на языке **C++**.

```cpp
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
	// X = 82.50 °C → ожидается Q = 50.00.Проверить на первом этапе проекта.
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
```
## 1.4. Результаты работы программы
```text
Введите X в диапазоне [30;140]:82,50
Вывод Q: 50,00
```
## 3. Информация о разработчике
```text
Имя: Коноваленко Ярослав
Вариант: 38
Группа: бИЦТ-261
Подгруппа: 1
