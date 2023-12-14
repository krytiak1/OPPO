#include "student.h"  // Подключение заголовочного файла student.h

// Реализация функции print() класса Student
void Student::print() const {
    qDebug() << "Имя студента: " << name;
    qDebug() << "Название темы: " << topic;
    qDebug() << "Дата выдачи: " << date.toString("yyyy.MM.dd");
    qDebug() << "\n";
}
