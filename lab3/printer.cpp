#include "printer.h"
#include "studentprinter.h"

void Printer::printStudents(const QVector<Student>& students) {
    for (const Student &student : students) {
        StudentPrinter::print(student);
    }
}
