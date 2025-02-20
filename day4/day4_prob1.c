#include <stdio.h>

struct Student_t {
    int roll_no;
    char name[50];
    char course[50];
    int marks;
};

typedef struct Student_t Student;

void readStudents(Student students[], int n);
void displayStudents(Student students[], int n);
Student findHighestMarks(Student students[], int n);

int main() {
    int studentCount;
    printf("Enter number of students: ");
    scanf("%d", &studentCount);

    Student students[1000];
    readStudents(students, studentCount);
    displayStudents(students, studentCount);
    
    Student highestMarksStudent = findHighestMarks(students, studentCount);
    printf("Student with highest marks: %s, %d (%s)\n", 
           highestMarksStudent.name, highestMarksStudent.marks, 
           highestMarksStudent.course);
    
    return 0;
}


void readStudents(Student students[], int n) {
    printf("Enter details (Roll No, Name, Course, Marks):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %49s %49s %d", &students[i].roll_no, 
              students[i].name, students[i].course, 
              &students[i].marks);
    }
}


void displayStudents(Student students[], int n) {
    printf("Students:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s - %s - %d\n", students[i].roll_no, 
               students[i].name, students[i].course, 
               students[i].marks);
    }
}


Student findHighestMarks(Student students[], int n) {
    Student maxStudent = students[0];
    for (int i = 1; i < n; i++) {
        if (students[i].marks > maxStudent.marks) {
            maxStudent = students[i];
        }
    }
    return maxStudent;
}