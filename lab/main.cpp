#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDate>
#include <QDebug>
#include <QVector>

class Student {
public:
    QString name;
    QString topic;
    QDate date;

    // Конструктор по умолчанию для работы с QVector
    Student() {}

    // Конструктор для создания объекта Student
    Student(QString name, QString topic, QDate date) : name(name), topic(topic), date(date) {}

    // Функция для вывода информации о студенте
    void print() const {
        qDebug() << "Имя студента: " << name;
        qDebug() << "Название темы: " << topic;
        qDebug() << "Дата выдачи: " << date.toString("yyyy.MM.dd");
        qDebug() << "\n"; // Добавлен пробел после каждого студента
    }
};

// Функция для чтения файла и заполнения QVector студентами
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

        Student student(name, topic, date);
        students.append(student);
    }

    file.close();

    return students;
}

// Функция для вывода информации о всех студентах
void printStudents(const QVector<Student>& students) {
    for (const Student &student : students) {
        student.print();
    }
}

int main() {
    QVector<Student> students = readStudentsFromFile("C:\\Users\\Krytiak\\Documents\\lab\\students.txt");
    printStudents(students);
    return 0;
}
