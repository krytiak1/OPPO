#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDate>
#include <QDebug>
#include <QVector>
#include "student.h"

class FileHandler {
public:
    static QVector<Student> readStudentsFromFile(const QString& filePath);
};

#endif // FILEHANDLER_H
