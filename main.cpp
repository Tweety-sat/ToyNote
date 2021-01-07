/*!
 * \file
 * \brief Файл главной функции.
 * \author Кирилл Пушкарёв
 * \date 2017
 */
#include "mainwindow.hpp"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
/*!
 * \brief main
 * \param argc количество параметров командной строки
 * \param argv параметры командной строки
 * \return код результата
 *
 * Главная функция программы
 */
int main(int argc, char *argv[])
{
    // Создать объект класса QApplication. Класс QApplication является частью
    // библиотеки Qt и отвечает за функционирование программы в целом
    QApplication a(argc, argv);
    // Создать объект класса MainWindow. Класс MainWindow является частью
    // данной программы и отвечает за функционирование её главного окна
    // Перевод текста tr() на язык системы
    QTranslator translator;
    translator.load(":/Translations/toynote_" + QLocale::system().name());
    a.installTranslator(&translator);
    //Перевод текста кнопок QMessageBox на язык системы
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
                QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    MainWindow w;
    // Отобразить главное окно
    w.show();

    // Начать обработку событий (щелчков мыши по элементам интерфейса и т. д.)
    return a.exec();
}
