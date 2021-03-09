#include <iostream>
using namespace std;

typedef char String[9];
struct StudentRecord{
	String firstName;
	String lastName;
	int id;
	float gpa;
	// char gender;
	int currentHours;
	int totalHours;
};

int main() {
	StudentRecord student;
	StudentRecord students[100];
	cout << "Base Address         : " << &student;
	cout << ", Size of student      : " << sizeof(student) << endl;
	cout << "firstName Address    : " << &student.firstName;
	cout << ", Size of firstName    : " << sizeof(student.firstName) << endl;
	cout << "lastName Address     : " << &student.lastName;
	cout << ", Size of lastName     : " << sizeof(student.lastName) << endl;
	cout << "id Address           : " << &student.id;
	cout << ", Size of id           : " << sizeof(student.id) << endl;
	cout << "gpa Address          : " << &student.gpa;
	cout << ", Size of gpa          : " << sizeof(student.gpa) << endl;
	cout << "currentHours Address : " << &student.currentHours;
	cout << ", Size of currentHours : " << sizeof(student.currentHours) << endl;
	cout << "totalHours Address   : " << &student.totalHours;
	cout << ", Size of totalHours   : " << sizeof(student.totalHours) << endl;
	cout << endl;
	cout << "Size of students: " << sizeof(students) << endl;

	return 0;
}

