## Полученное задание

Написать программу, использующую три библиотеки: zlib, libpng и freetype. Программа должна создавать PNG-файл с нарисованным текстовым сообщением с помощью шрифта, загруженного из файла `*.ttf`.

При написании программы должны быть выполнены следующие условия:
1.  Программа должна компилироваться с помощью `gcc` и системы `makefile` в ОС Linux или WSL.
2.  Программа должна быть выполнена в трех версиях:
    * `static` - статическая компоновка всех трех библиотек.
    * `dynamic` - динамическая загрузка всех трех библиотек в начале работы с помощью `dlload`.
    * `blob` - реализация всего функционала в виде блоба и загрузка его с диска с помощью загрузчика `elf-loader`, который должен быть включен в состав проекта.
3.  Система Makefile должна поддерживать команды: `make static`, `make dynamic`, `make blob`, `make clean`, `make all`.
4.  Программа, независимо от типа сборки, должна генерировать PNG-файл и печатать на экран общее время своей работы, а также время, затраченное на загрузку системы (от начала `main` до конца работы).
5.  Файл со шрифтом, имя PNG-файла и печатаемый текст должны поступать в программу из аргументов командной строки.
6.  Программа не должна генерировать исключения или преждевременно завершать свою работу, независимо от аргументов командной строки.

## Реализация

Описание реализации представлено в [отчете](отчет.pdf).
