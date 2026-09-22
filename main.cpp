#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> // #1 ifstream
#include <random>
#include <algorithm>
#include <vector>


void parseString(std::string &line, std::string &field);

struct Employee {
    std::string name;
    std::string empNum;
    double rate;
    double hours;
    double grossPay;
};

int main() {
    std::vector<Employee> employees;

    std::ifstream csvFile; // instantiated a ifstream object
    std::string name;
    std::string empNum;
    std::string rate;
    std::string hours;
    double grossPay;

    //csvFile.open("./EmployeeData.csv");
    csvFile.open("../EmployeeData.csv");

    if (!csvFile.is_open()) {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(csvFile, line);  // read header and ignore
    std::cout << "\nTable 1 (Orginal Order)\n";
    std::cout <<std::left;
    std::cout << std::setw(15) << "Name";
    std::cout << std::setw(15) << "EmpNum";
    std::cout << std::setw(15) << "Rate";
    std::cout << std::setw(15) << "Hours";
    std::cout << std::setw(15) << "Gross Pay";
    std::cout << "\n---------------------------------------------------------------------------";
    std::cout << std::endl;
    while (std::getline(csvFile, line)) {
        parseString(line, name);
        parseString(line,  empNum);
        parseString(line,  rate);
        parseString(line, hours);

        grossPay = stod(rate) * stod(hours);

        Employee emp;
        emp.name = name;
        emp.empNum = empNum;
        emp.rate = stod(rate);
        emp.hours = stod(hours);
        emp.grossPay = grossPay;

        employees.push_back(emp);


        std::cout << std::setw(15) << std::left << name;
        std::cout << std::setw(15) << std::right << empNum;
        std::cout << std::setw(15) << rate;
        std::cout << std::setw(15) << hours;
        std::cout << std::setw(15) << grossPay;
        std::cout << std::endl;

    }

    csvFile.close(); // #6 close the file

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(employees.begin(), employees.end(), gen);
    std::cout << "\nTable 2 (Random Order)\n";
    std::cout <<std::left;
    std::cout << std::setw(15) << "Name";
    std::cout << std::setw(15) << "EmpNum";
    std::cout << std::setw(15) << "Rate";
    std::cout << std::setw(15) << "Hours";
    std::cout << std::setw(15) << "Gross Pay";
    std::cout << "\n---------------------------------------------------------------------------";
    std::cout << std::endl;
    for (const Employee &employee : employees) {
        std::cout << std::setw(15) << employee.name;
        std::cout << std::setw(15) << employee.empNum;
        std::cout << std::setw(15) << employee.rate;
        std::cout << std::setw(15) << employee.hours;
        std::cout << std::setw(15) << employee.grossPay;
        std::cout << std::endl;
    }
    // table 3
    std::sort(employees.begin(), employees.end() , [](const Employee& a, const Employee& b) {
        return a.grossPay > b.grossPay;


        }
     );
    std::cout << "\nTable 3 (Gross Pay in Descending Order)\n";
    std::cout <<std::left;
    std::cout << std::setw(15) << "Name";
    std::cout << std::setw(15) << "EmpNum";
    std::cout << std::setw(15) << "Rate";
    std::cout << std::setw(15) << "Hours";
    std::cout << std::setw(15) << "Gross Pay";
    std::cout << "\n---------------------------------------------------------------------------";
    std::cout << std::endl;

    for (const Employee &employee : employees) {
        std::cout << std::setw(15) << employee.name;
        std::cout << std::setw(15) << employee.empNum;
        std::cout << std::setw(15) << employee.rate;
        std::cout << std::setw(15) << employee.hours;
        std::cout << std::setw(15) << employee.grossPay;
        std::cout << std::endl;
    }

    /*location = line.find(',');
    name = line.substr(0, location);
    line = line.substr(location+1, line.length());


    location = line.find(',');
    empNum = line.substr(0, location);
    line = line.substr(location+1, line.length());

    location = line.find(',');
    rate = line.substr(0, location);
    line = line.substr(location+1, line.length());

    location = line.find(',');
    hours = line.substr(0, location);
    line = line.substr(location+1, line.length());*/

    return 0;
}

void parseString(std::string &line, std::string &field) {
    int location;
    location = line.find(',');
    field = line.substr(0, location);
    line = line.substr(location+1, line.length());

}


