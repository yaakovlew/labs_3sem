
class Person {
private:
    int age;
    int mark;
public:
    Person();

    explicit Person(int age);

    Person(int age, int mark);

    int getAge();

    int getMark();

    void setAge(int age);

    void setMark(int mark);

    ~Person() = default;
};

Person::Person() {
    this->age = 0;
    this->mark = 0;
}

Person::Person(int age) {
    this->age = age;
    this->mark = 0;
}

Person::Person(int age, int mark) {
    this->age = age;
    this->mark = mark;
}

int Person::getAge() {
    return this->age;
}

int Person::getMark() {
    return this->mark;
}

void Person::setAge(int new_age) {
    this->age = new_age;
}

void Person::setMark(int new_mark) {
    this->mark = new_mark;
}

