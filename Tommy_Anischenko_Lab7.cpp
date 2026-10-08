#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    // TODO:score array
    // TODO: studentcourse array
    double score[3][3];
    string courseName[3] = {"Math", "C", "OS"};

    bool hasData = false;
    int choice;

    do {
        cout << "\n=== Student Grade System ===\n"
             << "1) Record grades (3x3)\n"
             << "2) One student's Total & Average\n"
             << "3) Display ALL (table + per-student stats)\n"
             << "4) Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            // TODO: input 3x3 grades (0..100) with re-prompt on invalid;
            // TODO: after successfully recording ALL 9 values, set hasData = true
            // hasData = true;  // (do NOT set this until after your input loops)
            for (int i = 0; i < 3; i++) {
                cout << "\nStudent " << i << ":\n";

                for (int j = 0; j < 3; j++) {
                    while (true) {
                        cout << courseName[j]
                             << " grade (0-100): ";

                        double grade;

                        if (!(cin >> grade)) {
                            cin.clear();
                            cin.ignore(
                                numeric_limits<streamsize>::max(),
                                '\n'
                            );

                            cout << "Invalid input. Enter a number.\n";
                            continue;
                        }

                        if (grade < 0 || grade > 100) {
                            cout << "Invalid grade. Enter 0-100.\n";
                            continue;
                        }

                        score[i][j] = grade;
                        break;
                    }
                }
            }

            hasData = true;
            cout << "\nAll grades recorded successfully.\n";

        }
        else if (choice == 2) {
            if (!hasData) { cout << "Please record grades first (option 1).\n"; continue; }
            // TODO: read idx (0..2); compute total = sum of 3 courses; avg = total/3.0; print
            int student;

            cout << "Enter student index (0-2): ";

            if (!(cin >> student)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid student index.\n";
                continue;
            }

            if (student < 0 || student > 2) {
                cout << "Invalid student index.\n";
                continue;
            }

            double total = 0;

            cout << "\nGrades for Student " << student << ":\n";

            for (int j = 0; j < 3; j++) {
                cout << courseName[j] << ": "
                     << score[student][j] << '\n';

                total += score[student][j];
            }

            cout << "Total: " << total << '\n';
            cout << "Average: " << total / 3.0 << '\n';
        }



        else if (choice == 3) {
            if (!hasData) { cout << "Please record grades first (option 1).\n"; continue; }
            // TODO: print 3x3 table; then for each student print total & average
            cout << "\nGrade Table\n";
            cout << "Student\tMath\tC\tOS\n";

            for (int i = 0; i < 3; i++) {
                cout << "S" << i;

                for (int j = 0; j < 3; j++) {
                    cout << "\t" << score[i][j];
                }

                cout << '\n';
            }


            cout << "\nStudent Statistics\n";

            for (int i = 0; i < 3; i++) {
                double total = 0;

                for (int j = 0; j < 3; j++) {
                    total += score[i][j];
                }

                cout << "Student " << i
                     << " Total: " << total
                     << " Average: " << total / 3.0 << '\n';
            }
        }
        else if (choice == 4) {
            cout << "Bye!\n";
        }
        else {
            cout << "Invalid choice. Enter 1, 2, 3, or 4.\n";
        }
    } while (choice != 4);

    return 0;
}
