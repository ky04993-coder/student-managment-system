include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
    float marks;
    char grade;
};

// Calculate grade
char calculateGrade(float marks) {
    if (marks >= 90)
        return 'A';
    else if (marks >= 80)
        return 'B';
    else if (marks >= 70)
        return 'C';
    else if (marks >= 60)
        return 'D';
    else
        return 'F';
}

// Check if ID already exists
bool idExists(Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id)
            return true;
    }
    return false;
}

// Add student
void addStudent(Student students[], int &count) {

    if (count >= 100) {
        cout << "\nStudent limit reached!\n";
        return;
    }

    int id;

    cout << "\nEnter Student ID: ";
    cin >> id;

    if (idExists(students, count, id)) {
        cout << "This ID already exists!\n";
        return;
    }

    students[count].id = id;

    cout << "Enter Name: ";
    cin >> students[count].name;

    cout << "Enter Age: ";
    cin >> students[count].age;

    cout << "Enter Course: ";
    cin >> students[count].course;

    do {
        cout << "Enter Marks (0-100): ";
        cin >> students[count].marks;

        if (students[count].marks < 0 || students[count].marks > 100)
            cout << "Invalid marks! Enter between 0 and 100.\n";

    } while (students[count].marks < 0 || students[count].marks > 100);

    students[count].grade = calculateGrade(students[count].marks);

    count++;

    cout << "\nStudent added successfully!\n";
}

// Display students
void displayStudents(Student students[], int count) {

    if (count == 0) {
        cout << "\nNo students available.\n";
        return;
    }

    cout << "\n========== ALL STUDENTS ==========\n";

    for (int i = 0; i < count; i++) {

        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "Marks: " << students[i].marks << endl;
        cout << "Grade: " << students[i].grade << endl;
    }
}

// Search student
void searchStudent(Student students[], int count) {

    int id;
    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {

        if (students[i].id == id) {

            cout << "\n===== STUDENT FOUND =====\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Marks: " << students[i].marks << endl;
            cout << "Grade: " << students[i].grade << endl;

            return;
        }
    }

    cout << "\nStudent not found!\n";
}

// Update student
void updateStudent(Student students[], int count) {

    int id;
    cout << "\nEnter Student ID to update: ";
    cin >> id;

    for (int i = 0; i < count; i++) {

        if (students[i].id == id) {

            cout << "\nEnter New Name: ";
            cin >> students[i].name;

            cout << "Enter New Age: ";
            cin >> students[i].age;

            cout << "Enter New Course: ";
            cin >> students[i].course;

            do {
                cout << "Enter New Marks (0-100): ";
                cin >> students[i].marks;

                if (students[i].marks < 0 || students[i].marks > 100)
                    cout << "Invalid marks!\n";

            } while (students[i].marks < 0 || students[i].marks > 100);

            students[i].grade = calculateGrade(students[i].marks);

            cout << "\nStudent updated successfully!\n";

            return;
        }
    }

    cout << "\nStudent not found!\n";
}

// Delete student
void deleteStudent(Student students[], int &count) {

    int id;
    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < count; i++) {

        if (students[i].id == id) {

            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;

            cout << "\nStudent deleted successfully!\n";

            return;
        }
    }

    cout << "\nStudent not found!\n";
}

// Save data to file
void saveData(Student students[], int count) {

    ofstream file("students.txt");

    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    file << count << endl;

    for (int i = 0; i < count; i++) {
        file << students[i].id << endl;
        file << students[i].name << endl;
        file << students[i].age << endl;
        file << students[i].course << endl;
        file << students[i].marks << endl;
        file << students[i].grade << endl;
    }

    file.close();

    cout << "\nData saved successfully!\n";
}

// Load data from file
void loadData(Student students[], int &count) {

    ifstream file("students.txt");

    if (!file) {
        return;
    }

    file >> count;
    file.ignore();

    for (int i = 0; i < count; i++) {

        file >> students[i].id;
        file.ignore();

        getline(file, students[i].name);

        file >> students[i].age;
        file.ignore();

        getline(file, students[i].course);

        file >> students[i].marks;
        file >> students[i].grade;
        file.ignore();
    }

    file.close();
}

int main() {

    Student students[100];
    int count = 0;
    int choice;

    // Load previous data
    loadData(students, count);

    do {

        cout << "\n\n====================================\n";
        cout << "       STUDENT MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Save Data\n";
        cout << "7. Exit\n";

        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addStudent(students, count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                updateStudent(students, count);
                break;

            case 5:
                deleteStudent(students, count);
                break;

            case 6:
                saveData(students, count);
                break;

            case 7:
                saveData(students, count);
                cout << "\nThank you for using Student Management System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
