#include "filehandler.h"
#include <stdexcept>

QVector<Student> FileHandler::readStudentsFromFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QVector<Student>();

    QTextStream in(&file);
    QVector<Student> students;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split('\"');
        if (fields.size() < 5) {
            qDebug() << "Некорректная строка: " << line;
            break;
        }
        QString name = fields[1];
        QString topic = fields[3];
        QDate date = QDate::fromString(fields[4].trimmed(), "yyyy.MM.dd");
        if (!date.isValid()) {
            qDebug() << "Некорректная дата: " << fields[4];
            break;
        }

        Student student(name, topic, date);
        students.append(student);
    }

    file.close();

    return students;
}
