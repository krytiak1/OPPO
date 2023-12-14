#include "student.h"
#include <stdexcept>

Student::Student(QString name, QString topic, QDate date) : name(name), topic(topic), date(date) {
    if (!date.isValid()) {
        throw std::invalid_argument("Invalid date");
    }
}
