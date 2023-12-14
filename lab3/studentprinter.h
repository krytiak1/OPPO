#ifndef STUDENTPRINTER_H
#define STUDENTPRINTER_H

#include <QDebug>
#include "student.h"

class StudentPrinter {
public:
    static void print(const Student& student);
};

#endif // STUDENTPRINTER_H
