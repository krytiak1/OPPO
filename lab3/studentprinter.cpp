#include "studentprinter.h"

void StudentPrinter::print(const Student& student) {
    qDebug() << "Имя студента: " << student.name;
    qDebug() << "Название темы: " << student.topic;
    qDebug() << "Дата выдачи: " << student.date.toString("yyyy.MM.dd");
    qDebug() << "\n";
}
