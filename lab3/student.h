#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QDate>

class Student {
public:
    QString name;
    QString topic;
    QDate date;

    Student() {}
    Student(QString name, QString topic, QDate date);
};

#endif // STUDENT_H
