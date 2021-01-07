/*!
 * \file
 * \brief Заголовочный файл класса Note.
 * \author Кирилл Пушкарёв
 * \date 2017
 */
#ifndef NOTE_HPP
#define NOTE_HPP

#include <QDataStream>
#include <QTextStream>
#include <QString>

/*!
 * \brief Класс заметки.
 */
class Note
{
public:
    //! Конструктор по умолчанию
    Note();
    /*!
     * \brief Конструктор, устанавливающий заголовок и текст.
     * \param title Заголовок заметки.
     * \param text Текст заметки.
     *
     * Создаёт объект Note с заголовком \a title и текстом \a text.
     */
    Note(QString title, QString text);
    //! Возвращает заголовок заметки.
    const QString &title() const;
    //! Устанавливает заголовок заметки равным \a title.
    void setTitle(const QString &title);
    //! Возвращает текст заметки.
    const QString &text() const;
    //! Устанавливает заголовок заметки равным \a text.
    void setText(const QString &text);
    //! Сохраняет заметку в поток \a ost.
    void save(QDataStream &ost) const;
    //! Сохраняет заметку в текстовый поток \a ost.
    void savetext(QTextStream &ost) const;
    //! Загружает заметку из потока \a ist.
    void load(QDataStream &ist);
private:
    //! Заголовок заметки.
    QString mTitle;
    //! Текст заметки.
    QString mText;
};

/*!
 * \brief Реализация оператора << для вывода Note в QDataStream.
 * \param ost Поток для вывода.
 * \param note Заметка.
 * \return Поток \a ost после вывода.
 *
 * Данная функция объявлена \c inline, чтобы компилятор мог подставить её код
 * вместо полноценного вызова функции. В данном случае это оправданно, так как
 * функция всего лишь перенаправляет вызов методу save().
 */
inline QDataStream &operator<<(QDataStream &ost, const Note &note)
{
    note.save(ost);
    return ost;
}

/*!
 * \brief Реализация оператора << для вывода Note в QTextStream.
 * \param ost Текстовый поток для вывода.
 * \param note Заметка.
 * \return Поток \a ost после вывода.
 *
 * Данная функция объявлена \c inline, чтобы компилятор мог подставить её код
 * вместо полноценного вызова функции. В данном случае это оправданно, так как
 * функция всего лишь перенаправляет вызов методу save().
 */
inline QTextStream &operator<<(QTextStream &ost, const Note &note)
{
    note.savetext(ost);
    return ost;
}

/*!
 * \brief Реализация оператора >> для ввода Note из QDataStream.
 * \param ist Поток для ввода.
 * \param note Заметка.
 * \return Поток \a ist после ввода.
 */
inline QDataStream &operator>>(QDataStream &ist, Note &note)
{
    note.load(ist);
    return ist;
}

#endif // NOTE_HPP
