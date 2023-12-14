#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QDate>
#include <QDebug>

// Определение класса Student
class Student {
public:
    QString name;   // Имя студента
    QString topic;  // Тема, которую изучает студент
    QDate date;     // Дата выдачи темы

    // Конструктор по умолчанию
    Student() {}

    // Конструктор для создания объекта Student
    Student(QString name, QString topic, QDate date) : name(name), topic(topic), date(date) {}

    // Функция для вывода информации о студенте
    void print() const;
};

#endif // STUDENT_H  // Конец условной компиляции
