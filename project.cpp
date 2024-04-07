#include <iostream>
#include <string>
#include <vector>

class Record {
public:
    std::string name;
    int age;
};

class Record_Management {
public:
    std::vector<Record> records;

    void add_Record(std::string const name, const int age) {
        Record new_Record;
        new_Record.name = name;
        new_Record.age = age;
        records.push_back(new_Record);
    }

    Record fetch_Record(const int id) {
        if (id < 0 || id >= records.size()) {
            std::cout << "Invalid ID\n";
            return Record(); 
        }
        return records[id];
    }
};

enum class Option {
    ADD_RECORD,
    FETCH_RECORD,
    QUIT,
};

class Menu {
public:
    void show_Menu() {
        std::cout << "Please select an option: \n";
        std::cout << "1- Add Record.\n";
        std::cout << "2- Fetch Record.\n";
        std::cout << "3- Quit.\n";
    }

    Option select_Option() {
        int option_Number = 0;
        Option option_Selected = Option::ADD_RECORD;

        std::cout << "Enter option: ";
        std::cin >> option_Number;

        switch (option_Number) {
            case 1:
                option_Selected = Option::ADD_RECORD;
                break;
            case 2:
                option_Selected = Option::FETCH_RECORD;
                break;
            case 3:
                option_Selected = Option::QUIT;
                break;
            default:
                break;
        }

        return option_Selected;
    }

    void take_Action(Option opt, Record_Management &records) {
        Record record;
        std::string name;
        int age = 0;
        int id = 0;

        switch (opt) {
            case Option::ADD_RECORD:
                std::cout << "Add User. Please enter the name and the age: \n";
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Age: ";
                std::cin >> age;

                records.add_Record(name, age);
                std::cout << "\nUser has been added.\n\n";
                break;
            case Option::FETCH_RECORD:
                std::cout << "\nEnter ID: ";
                std::cin >> id;

                record = records.fetch_Record(id);

                if (record.name.empty()) { 
                    std::cout << "Record not found.\n";
                } else {
                    name = record.name;
                    age = record.age;
                    std::cout << "ID: " << id << "\n";
                    std::cout << "Name: " << name << "\n";
                    std::cout << "Age: " << age << "\n";
                }
                break;
            default:
                break;
        }
    }
};

int main() {
    Menu menu;
    Option option_Selected = Option::ADD_RECORD;

    Record_Management records;

    while (Option::QUIT != option_Selected) {
        menu.show_Menu();
        option_Selected = menu.select_Option();
        menu.take_Action(option_Selected, records);
    }

    return 0;
}
