# Виселица

## Демонстрация работы

https://github.com/user-attachments/assets/c3507766-7620-4ad7-8614-acd992fea675


## Правила игры
1. Один игрок загадывает слово.
2. Второй игрок пытается угадать слово, вводя буквы.
3. Если буква есть в загаданном слове:
   - Она открывается во всех местах, где встречается.
   - Игрок продолжает угадывать.
4. Если буквы нет — засчитывается ошибка, и добавляется на рисунке новая часть виселицы.
5. Игра заканчивается:
   - **Победой**, если слово угадано до того, как виселица полностью построена.
   - **Поражением**, если виселица полностью построена, а слово не угадано.

---

## Техническая реализация
- Логика игры включает:
  - Проверку ввода (буквы, повторы).
  - Отображение текущего состояния слова и виселицы.
  - Отображение использованных букв
  - Учёт ошибок (максимум 6 ошибок до поражения).
  - Вывод поздравлений/сообщений о проигрыше.
- Возможность играть через локальную сеть будет добавлена позже.

---

## Компоненты игры
### 1. Виселица
Графическое представление виселицы состоит из нескольких этапов:
- **Этап 0:** нарисована стойка.
- **Этап 1:** добавлена голова.
- **Этап 2:** добавлен торс.
- **Этап 3:** добавлена левая рука.
- **Этап 4:** добавлена правая рука.
- **Этап 5:** добавлена левая нога.
- **Этап 6:** добавлена правая нога + завершение игры.

Пример:
```
   +---+
   |   |
       |
       |
       |
       |
  =========
```

### 2. Логика слова
- Загаданное слово отображается как ряд символов `_` (по числу букв в слове).
- Угаданные буквы открываются, например:
  - Слово: `APPLE`
  - Угаданные: `A`, `P` → `A P P _ _`.

### 3. Пользовательский интерфейс
- Игровое поле отображается в консоли.
- Ввод команды/буквы игроком:
  - Если ввод неверный, игра выводит сообщение об ошибке и предлагает ввести букву снова.
  - Если игрок угадывает букву — обновляется состояние слова.
  - Если игрок ошибается — обновляется виселица и увеличивается счётчик ошибок.

Пример:
```
н
Неправильная буква, осталось попыток: 2
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
Сейчас слово выглядит так: ________
Угаданные буквы: 
Неправильные буквы: а к н о 
Уже было 4 попыток, осталось 2
```

### 4. Сетевой модуль
(Добавим позже, пока не умеем)
- Игроки смогут играть друг против друга через локальную сеть.
- Первый игрок загадывает слово, второй пытается его угадать.

---

## Логика игры
### a. Загадка слова
- Игрок вводит слово (другой игрок не видит).
- Игра проверяет, что слово состоит только из букв (без пробелов и цифр).
- Загаданное слово сохраняется в памяти.

### b. Процесс угадывания
- Игрок вводит букву.
- Если буква уже вводилась — игра сообщает об этом и предлагает ввести другую.
- Если буква есть в слове — она открывается.
- Если буквы нет — обновляется виселица и увеличивается количество ошибок.

### c. Конец игры
- Игра завершается, если:
  - Игрок угадал все буквы.
  - Виселица полностью построена (6 ошибок).

---

## Основные этапы разработки
### Этап 1. Подготовка рабочего окружения
- Настройка Git и структуры проекта.
- Настройка среды (Clion).

### Этап 2. Проектирование структуры игры
- Описание интерфейса и логики игры.
- Определение классов и их взаимодействия.
- Разработка схемы игры.

### Этап 3. Реализация игрового процесса
1. Ввод загаданного слова.
2. Отображение слова в виде `_ _ _ _`.
3. Проверка введённых букв:
   - Открытие угаданных букв.
   - Увеличение количества ошибок при неверном вводе.
4. Вывод виселицы и текущего состояния слова после каждого хода.

### Этап 4. Консольный интерфейс
- Вывод поля виселицы и текущего слова.
- Ввод команд/букв игроком.
- Обработка неверного ввода (например, цифры вместо букв).

### Этап 5. Обработка окончания игры
- Сообщение о победе/поражении.
- Предложение сыграть снова.

### Этап 6. Тестирование и отладка
- Проверка всех возможных случаев:
  - Угадано слово без ошибок.
  - Виселица полностью построена.
  - Повторы букв.
