#include <QVector>
#include "student.h"
#include "filehandler.h"
#include "printer.h"

int main() {
    QVector<Student> students = FileHandler::readStudentsFromFile("C:\\Users\\Krytiak\\Documents\\lab\\students.txt");
    Printer::printStudents(students);
    return 0;
}
