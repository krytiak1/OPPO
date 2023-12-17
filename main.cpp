#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDate>
#include <QDebug>
#include <QVector>
#include "student.h"  // Подключение заголовочного файла student.h

// Функция для чтения информации о студентах из файла
QVector<Student> readStudentsFromFile(const QString& filePath) {
    QFile file(filePath); 
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  
        return QVector<Student>();  

    QTextStream in(&file);  
    QVector<Student> students;  
    while (!in.atEnd()) { 
        QString line = in.readLine();  
        QStringList fields = line.split('\"'); 
        QString name = fields[1];  
        QString topic = fields[3];  
        QDate date = QDate::fromString(fields[4].trimmed(), "yyyy.MM.dd");  

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
