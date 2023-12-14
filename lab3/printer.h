#ifndef PRINTER_H
#define PRINTER_H

#include <QVector>
#include "student.h"

class Printer {
public:
    static void printStudents(const QVector<Student>& students);
};

#endif // PRINTER_H
