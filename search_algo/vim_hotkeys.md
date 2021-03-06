#Vim Hotkeys

##Общее

**Режим поиска**
```
/ - поиск от курсора до конца документа
? - поиск от курсора до начала документа
```

**Визуальный режим**
`v`

**Операции с файлами**
```
:w            - сохраняет файл с существующим именем
:w filename   - сохраняет файл с новым именем
```

##Перемещение по файлу

- `0` («ноль») — в начало текущей строки;
- `$` — в конец текущей строки
- `w` — на слово вправо
- `b` — на слово влево

- `gg` — перейти в начало файла
- `G` — перейти в конец файла

##Редактирование файла

**Ввод текста**

- `i` — перейти в режим ввода с текущей позиции
- `a` — перейти в режим ввода после курсора
- `I` — переместиться в начало строки и перейти в режим ввода
- `А` — переместиться в конец строки и перейти в режим ввода
- `o` — перейти в режим ввода с новой строки под курсором
- `S` - удаляет всю текущую строку и переходит в режим ввода
- `R` — перейти в режим ввода с заменой текста (аналог insert)
- `r` — заменить один символ

**Удаление**

- `x` — удалить символ под курсором
- `dd` — удалить текущую строку (вырезать)
- `d<число>d` или `<число>dd` — стирание числа строк начиная с текущей
- `d0` - удаление символов с начала строки до текущего положения курсора
- `d$` или `D` - удаление символов с текущего положения курсора до конца строки

- `yy` (также `Y`) — копирование текущей строки в неименованный буфер
- `y<число>y` — копирование числа строк начиная с текущей в неименованный буфер
- `p` — вставка содержимого неименнованного буфера под курсором

**Отмена изменений**

- `u` — отмена последней команды
`Команды u и U могут отменять друг друга.`

- `<Ctrl-r>` или `:redo` вперёд по изменениям
- `.` — повтор последней команды, включая ввод текста.
- `~` - тильда меняет символы под курсором на противоположный регистр

##Запись/выход

`ZQ - выйти без сохранения`
`:q! - выйти без сохранения`
`ZZ - записать файл и выйти(Если файл не изменяли, то записываться он не будет)`
`:wq - записать файл и выйти`
`:x - записать файл и выйти`
`:sav filename<CR> - "Сохранить как"`
`:w filename<CR> - "Сохранить как"`
`:sh<CR> - переход в командную оболочку.` Чтобы из командной оболочки вернуться в редактор нажмите CTRL-D или введите exit.

##Дополнительные возможности
`^G - показать информацию о файле`
`:set number - отобразить слева нумерацию строк (:set nonumber - спрятать нумерацию)`
`:set wrap - переносить длинные строки(:set nowrap - не переносить)`
`:sy[ntax] on/off - включить/выключить подсветку синтаксиса`
`:set tabstop=4`

**Конвертация кодировки файла**
```
:set fenc=cp1251<CR>
:set fenc=koi8-r<CR>
:set fenc=ibm866<CR>
:set fenc=utf-8<CR>
```

##Вставка форматированного текста с отступами

`:set paste`
.вставляем форматированный текст с отступами в режиме редактирования (например, средней кнопкой мыши) и строки «съезжать» вправо не будут. После этого режим «вставки» можно отключить командой:
`:set nopaste`


