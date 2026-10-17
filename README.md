# Мониторинг реактора: температура стенки реактора

## Постановка задачи

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

При этом выполняется проверка отклонения от начального значения: `Q(0) = 50.00`. Если модуль разности между текущим показателем и предыдущим превышает номинал `|Q(i) - Q(i-1)| > 10`, то программа сигнализирует о нарушении.
Массив из `N = 60` показателей `Q[]` используется для последующего анализа программы. В рамках анализа для подмассива `Q[11..33]` рассчитываются:
- Средний абсолютный прирост между соседними значениями
- Максимальный прирост
- Минимальный прирост

Для верификации алгоритма на первом этапе проекта используется контрольный пример: при входном значении температуры `X = 82.50`, ожидаемое значение индикатора составляет `Q = 50.00`.

## Задание 1


## Алгоритм и блок-схема:

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


### Блок-схема 

<img width="723" height="611" alt="{A14758D9-5660-4F3D-A542-4FE27C82FEC7}" src="https://github.com/user-attachments/assets/72767c1e-9a6e-494a-b004-aaac1ddd17fc" />


[Ссылка на блок-схему](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22Page-1%22%20id%3D%22Page-1%22%3E7V1Zc6LAFv41qZrcqqRoaLZHBTVucY%2FLG7IoiqCI66%2B%2FjYACGkcJGu4dMjUGupsDnP7O2qfNC8HNtgVTmI%2BrhiRrLzgmbV8I%2FgXHAQsI9Mtu2bktGAaclpGpSm7bqaGl7mVvoNu6UiV5GRhoGYZmqfNgo2jouixagTbBNI1NcJhiaMG7zoWRfNbQEgXtvLWrStbYaWVw%2BtT%2BIaujsXdnQLFOz0zwBrtvshwLkrHxNRG5F4IzDcNyjmZbTtZs7nl8ca7Lf9N7fDBT1q0LF3SWslkbTmye4JgmDNHEHAa5PBRGLmNeeOwlA%2B3PbO7w6Qw63gc%2FPurxEfz3dB9jae08jq2X0rbIo2PwQmQVVdM4QzPMQx%2BRP%2Fyg9pEpSCoi4vXpho4uzyIezW0yS0vWRVX7I%2FXZCm9kRnyuWcf2RKu44%2BUR1uo0R11ELltZsVOOZko1coZbEs4tRt0B3q901M18vPxYAa7%2F0S3WOmQJ%2F9QqRQ4UuQXHfuBVYYcuHrTRx7Ax7oOxAJa1j3FNy0zn%2B4VkFrL7EuIjLH%2FJ5fyAyIgQp%2BsEP%2FisoNbMZMEdZpHgX9ETzw1Vtw6sJLMvJGrNHnidFcTpyDRWuhR6w0ObbPMWQ2dja6a5nNqMVUtuzQXRfv8NkibU5vB2LZuWvPWx252NgmzMZMtE74KNfRAkSOcy9wrIuCLoSSDDvLsjBBcCoyOhE3zQgTvf3qkPULECjIgMMDwFWAIBhtNEsgAGIwOMSAGWQIARJJ0sgJGRAQZTgCUQYDRMGMDoyACjUoAlEGAMAZIFMDYywJgUYAkEGEUkTIMBLDLC2BRhCUAYAI4ffdJhSfPCwA8yFWmqIpEYY2HC7CSIHkuCNJhMJMYS5%2Bz%2FJCGWZsR%2BBWMAUgGQ0TQI6jGSSRTComsxPAYtplxC2KbRMUZFxP78J5BbWVHII6i4GFPV3ZeUywzo2bRaWvNUt5iVUS8vyt1Vqww62dY0sx3PWrM8L6x3HeVrVx52lxXxs8QAMKl0BnuV3pGZAWfTlBQqw%2Fa3vVpmaQKa2HOgWUTNo3Umlyh8bU6rTRQEV%2BEFAAYThS8qOr7IVIP9hgbDyaAGAwQW9PZhsjRY9IwYHkNKLNVgP9RgBEYFNRieMAvJRMcXnWqwBPj54YwYiSfMzSdAZIgRWAqxBEIMQjxhEIueESPSjFgSIQawhNVWENGTFUSarEgCxMKePgCQfizCKA0NyUrqOgAMarGyKyGziqFbb8tDHWgGDQDz7akPHY3c35o39iYixDtNIUL2ldihTxFmqrZzejlBU4em6vRKqokeWTV0p0%2BzTKddky1LNt%2BWaAJUfeR0Yh5JTdXlN4%2FHhxvatZik02nYl1juvYDz9OH3QZPN8gf5wl7QbDO0d4w%2Bs670ue88NMNcQMx3GHHWfOCx13qnYN%2BfI0IwVEVBy2jqCHGPn6mSZPdlBbdBRBfLNjsNNFTRDrWwboyQPWmFcIJJs7n6Jgnm9M9JQeDc8fj1dm1hDtrSxKiOcsWuMraWpWp9X5Qki53sBFCm9K%2BtOUdMGyL4Z3fbwq4pVVtTaccr7SL1Adu8SAzWE7MrtAhGHq%2FZpoIGTxo4X0fjLAawMv8hiL3N5iNL0IZCKfIIDVhpdZGAVJYvIyTh%2Be2UUqoitekU5h2uRyIVk9%2Fb0oNI57oky26yPd5szMcDLDcTi1ylmDOX%2BS5X2BYJmK9IDeOj2czl8ovmvLRpkFV8jFlivcY0PjgZloxdaWatyPpmP5CKVqmN7edWOfOVy8%2FWuXqmoogU1apDpTCeLUkIV8198Qu9arFrfi5GvU4Vls1%2BgdxO51aezJQNgfraUH1Wg4PZukTu%2BcV6r8y5T6XbqE6lbm%2BmzWrZKYd38RY3rM4pbTgSlIKyKCiKNSk0PlAEle1x7S2rrmafY8A8Qx%2FaYnAZN9jhx8GNc%2FwaVX%2BSrv70hbc4RQTDWzKYoKOw39So3%2BvPuSl%2Frz79KhJ1CTObw%2B4ATliKSOQE1FU1dCPc7VO0JyXMzq8%2FDFKt%2BsWnEZ0ZRTQIBrP%2FndPo%2BZSeQ8ejfXp0tx%2BjkF7O%2B8YfmBCn6oT3R3axqE4YDgtjVJ36IIscrcYoZztaxGoKN3pn1ZdL5SzW5PnyhNDIIjLUebUktgt0WR9%2FtZrSqCpr1BfH5%2FOVvQk620%2BsmNFaOa1bxphxeZkpLwuq9EUCoseuNh9IX1i50qQLe%2Fi8XyvJlXwprw7E9WpDNcbyrrgXO7193lbQ3dVUVPAhO6zgjc4WTq2CWK3otjpeT5mGro9rJt94kgv2FJVDw7tVDvG7Ouef9eIyAb1gf5IHj456qLdG3h%2Fpx6JyyHCaIPXWUm8tUarzBm%2BNZUkvqeKtdjGxKM%2BzPXvtWXFsrLv8avXZau8Wucmwun2j3KUQWTrbiXguwMbKFN1R00ab4en6RvusDIzeZtKd4ogYcybpsi5l7I2QtkxrwnKpisGpCc6ZvFWtnn38DlnaPe%2B7I%2B1jfusbyO98J3XZVBGTbJ3htOmIYQ4p0jvt%2B%2FtOpA5nO%2F9ZmJinEM2R7HKkbamw0u%2FiW71LKIaG56qm9Ua6Cay1oK3kU0brLxBxJ9uUNcFS18FJ8OHGG%2BfCBnsHLIZ%2Fj5PDTRHn7WTScYArUD4YzbZ1u82f88ODCRk2tLjvgMC96ioh7J0N0jq%2Bg0fL4egZrQO2j%2By6BPczbF%2BEo7eqd90WeZofjRI0TdYMZCFmtvbxgSDQ50PHRc3iQ%2FeBdlFfqpL84m1J3creRuMo5iui2vIj8h%2BKvmxS9mIv9h%2F0%2F89yYVp%2FHnzLNyfGs9lmn4LX1%2BMx%2BV3YF8GwAC9Z7rcszHGR0XPLCeadDhoXErvfuNwobWwqbam02TbJkbYnCBqDv5M%2B%2BcLiFDDs3AQTOPmOByWMQhLGMEEJY9m7JSwNdG8PdP2YiD%2BWveLX%2FsJyRLiaJ8YAdzLgJW5Z3PAowC2Z4qS0qCzlJU0Uyrv9RlrUzDXFrgWQ1bnyDsWJ09ouR26qYLpicxk4aKq10sJkq1OOhtnimv9qdrRhptLL7MeFUa062LJ2BNvr54dlo0OrHb6tANDsIq9Z35gjwHzplqYro8EKK6H5HvSHbVFhqmsmxygaVbeL05bEGFGoGeN9wWoytkSD6nA2WxA8zPx%2FBIdeUeMdeTUQT17tNoPufZfMvaEhAWOMAhlfFIgCCpaMLxJ8xzAinmjwajD8jGjwDb3MlRLGuIJBNlT9cXssGAoqYYhQfIGgVvoo1erl8nQyVYZdsldR89obSURDMjxX7NGRTPnzGR72npLTuBGw5JMBC%2BET8hcwXE9yO2ZDJZxhAXs0ZuEvY9bGKB7QviT2szycQy7mTNxl5pHPhTLJXKmL%2BwuUL8OPwfB3LFThiWEhoDlELxOgYLCyimBDrsOtgkAxQULQ80l%2BLAhpSQFmjoZ%2FgF3vzx0CodPB619jn%2B8qDZwGJ%2FNF%2Bjucz7NT7JefVzs9L0AIf2x1xBVtkZZMpCUTTyyZoGhkN4LRHaQfE91dBj0dzb%2B4am9jcJS9AC%2B5bjL7bDf5Sj4xqpvMYFho1ZmEERf6bE8lSIoCIRw%2F2lVmkglllgUvQf8Z%2F0UwX3xbCj4VzMiFpWJ2lO2v1Dhm5T0sg3s8ZZYIR3oRPWX0KNh7aHc8FS7meLAseBOarsL906tw2EEkDgtxc2Pz5xmLccBm%2FiEcwF8fvBCHpCq00s2ywSCVimOZ%2B6KAefmlm4xNZBty0voYBAG972USH1XD9GSDwFzb7xXJIMBQvoK5yxiErybDKy63GgOWDj0Gjr8zIU%2FuwbaAuSeFmATP%2FanQoyAe8nhjSNqFjD%2FN3gG9s6vJEFxu98gvS8DTcBexpvSqQxM3QK%2BD86R%2FIXuP2%2F0%2FpHpZAn9AYIl84CCKaTpiXAnCe4PpsCqOD8YfE3m64Pp9AWzN9hgb5ubbxjESvK4tkS9j%2FT3rtLRMYyqH8lZ%2BP9htOssffptpDIL8HDn2dhDobuSN4nfh59UJVBBDMLTCAL1l1p%2F4XJdngvpfnwn%2FZhz8QfNBUcH5ICKkE2%2BcDzqdj7%2FPRzgmOa4oxz8fNxW6J3k%2BHqup6NBMkOSVLFRaovnjEs3GQ0s0r%2By9SUs00xLNXy7RjOnrFs53711EfcTCtqvb1%2BLfvfeOYfDuZEAgBqODOTAMOybFfhaIedVSz9myh8HHVGmGNt8f%2FwLl%2FVv2gg4LHXJYnl7p8y8az8fub7iSeUiNZ2o8n2w8zze%2F0%2BEyxYeaTzJO8xnntodwsfgd6crj6pB97VvkXQ7f5%2Bf99vOZW97tnCWJPSZnSYT3yTIwhMM7igDOiLHhTGtkQ4pOT3%2Bz2Rl%2B%2BtPXRO6%2F%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

### Код программы

Программа написана на языке **C++**.

```cpp
#include <stdio.h>
#include <locale.h>
#include <math.h>
main(){
		F();
}
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

int F() {
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
## Результаты работы программы
```text
Введите X в диапазоне [30;140]:82,50
Вывод Q: 50,00
```
## Информация о разработчике
```text
Имя: Коноваленко Ярослав
Вариант: 38
Группа: бИЦТ-261
Подгруппа: 1
