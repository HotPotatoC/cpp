#include <iostream>
#include <memory>
#include <string>

class Person {
   public:
    Person(const std::string &name);
    std::string get_name();
    void set_name(const std::string &name);
    friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Person> &person);

   private:
    std::string name;
};

Person::Person(const std::string &name) { this->name = name; }
std::string Person::get_name() { return this->name; }
void Person::set_name(const std::string &name) { this->name = name; }
std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Person> &person) {
    out << "- Person Details" << std::endl;
    out << "Address: " << &person << std::endl;
    out << "Name: " << person->name << std::endl;

    return out;
}

auto main() -> int {
    int *ptr_int = new int(5);
    std::cout << "- ptr_int" << std::endl;
    std::cout << "Address: " << &ptr_int << std::endl;
    std::cout << "Value: " << *ptr_int << std::endl;
    // explicitly call delete to deallocate memory to
    // avoid memory leakage
    delete ptr_int;

    // Smart pointer deallocates memory automatically without
    // explicitly calling the delete operator using unique_ptr
    std::cout << "- smart_ptr_int" << std::endl;
    std::unique_ptr<int> smart_ptr_int = std::make_unique<int>(12);
    std::cout << "Address: " << &smart_ptr_int << std::endl;
    std::cout << "Value: " << *smart_ptr_int << std::endl;

    std::cout << "- person" << std::endl;
    std::unique_ptr<Person> person = std::make_unique<Person>("Juan");

    std::cout << person->get_name() << std::endl;
    person->set_name("John");
    std::cout << person->get_name() << std::endl;

    std::cout << person << std::endl;

    return EXIT_SUCCESS;
}