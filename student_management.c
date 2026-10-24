
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int roll;
    char name[NAME_LENGTH];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int count = 0;

void addStudent(void) {
    if (count >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }

    Student s;

    printf("Enter roll number: ");
    if (scanf("%d", &s.roll) != 1) {
        printf("Invalid roll number.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].roll == s.roll) {
            printf("Roll number already exists!\n");
            return;
        }
    }

    printf("Enter name (one word): ");
    scanf("%49s", s.name);

    printf("Enter marks (0-100): ");
    if (scanf("%f", &s.marks) != 1 ||
        s.marks < 0 || s.marks > 100) {
        printf("Invalid marks.\n");
        while (getchar() != '\n');
        return;
    }

    students[count++] = s;
    printf("Student added successfully!\n");
}

void viewStudents(void) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\nRoll No.   Name                 Marks\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %.2f\n",
               students[i].roll,
               students[i].name,
               students[i].marks);
    }
}

void searchStudent(void) {
    int roll;

    printf("Enter roll number to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Found: %s, Marks: %.2f\n",
                   students[i].name,
                   students[i].marks);
            return;
        }
    }

    printf("Student not found.\n");
}

void calculateAverage(void) {
    if (count == 0) {
        printf("No marks available.\n");
        return;
    }

    float total = 0;

    for (int i = 0; i < count; i++) {
        total += students[i].marks;
    }

    printf("Average marks: %.2f\n", total / count);
}

int main(void) {
    int choice;

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Calculate Average Marks\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: calculateAverage(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
