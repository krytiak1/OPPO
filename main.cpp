#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDate>
#include <QDebug>
#include <QVector>
#include "student.h"  // Подключение заголовочного файла student.h

// Функция для чтения информации о студентах из файла
QVector<Student> readStudentsFromFile(const QString& filePath) {
    QFile file(filePath);  // Создание объекта QFile
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  // Попытка открыть файл для чтения
        return QVector<Student>();  // Возврат пустого QVector, если файл не удалось открыть

    QTextStream in(&file);  // Создание QTextStream для чтения из файла
    QVector<Student> students;  // Создание QVector для хранения студентов
    while (!in.atEnd()) {  // Чтение файла до конца
        QString line = in.readLine();  // Чтение одной строки из файла
        QStringList fields = line.split('\"');  // Разделение строки на поля
        QString name = fields[1];  // Получение имени студента
        QString topic = fields[3];  // Получение темы
        QDate date = QDate::fromString(fields[4].trimmed(), "yyyy.MM.dd");  // Получение даты

        Student student(name, topic, date);  // Создание объекта Student
        students.append(student);  // Добавление студента в QVector
    }

    file.close();

    return students;  // Возврат QVector со студентами
}

// Функция для вывода информации о студентах
void printStudents(const QVector<Student>& students) {
    for (const Student &student : students) {  // Обход всех студентов в QVector
        student.print();  // Вывод информации о студенте
    }
}

int main() {
    QVector<Student> students = readStudentsFromFile("C:\\Users\\Krytiak\\Documents\\lab\\students.txt");
    printStudents(students);
    return 0;
}
