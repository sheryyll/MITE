/*`3. Hospital Patient Management System`  
`Scenario:`  
A `hospital` maintains patient records using a `doubly linked list`. The system should:  
- Add `new patients`  
- Allow `forward and backward navigation`  
- Remove `discharged patients`  

`Operations Example:`  
```
New Patient Admitted: John (ID 201)  
New Patient Admitted: Mary (ID 202)  
New Patient Admitted: David (ID 203)  

Discharging: Mary  
Remaining Patients: John ↔ David  
```*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient {
    int id;
    char name[50];
    struct Patient* prev;
    struct Patient* next;
} Patient;

typedef struct {
    Patient* head;
    Patient* tail;
} Hospital;

void InitHospital(Hospital* hospital);
void AdmitPatient(Hospital* hospital, int id, char* name);
void ShowPatients(Hospital* hospital);
void DischargePatient(Hospital* hospital, int id);

int main() {
    Hospital hospital;
    InitHospital(&hospital);

    AdmitPatient(&hospital, 201, "John");
    AdmitPatient(&hospital, 202, "Mary");
    AdmitPatient(&hospital, 203, "David");

    ShowPatients(&hospital);

    printf("\nDischarging: Mary (ID 202)\n");
    DischargePatient(&hospital, 202);

    ShowPatients(&hospital);

    return 0;
}

void InitHospital(Hospital* hospital) {
    hospital->head = NULL;
    hospital->tail = NULL;
}

void AdmitPatient(Hospital* hospital, int id, char* name) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->prev = NULL;
    newPatient->next = NULL;

    if (hospital->head == NULL) {
        hospital->head = hospital->tail = newPatient;
    } else {
        hospital->tail->next = newPatient;
        newPatient->prev = hospital->tail;
        hospital->tail = newPatient;
    }
    printf("New Patient Admitted: %s (ID %d)\n", name, id);
}

void ShowPatients(Hospital* hospital) {
    Patient* temp = hospital->head;
    if (!temp) {
        printf("\nNo patients in the hospital.\n");
        return;
    }

    printf("\nPatients: ");
    while (temp) {
        printf("%s (ID %d)", temp->name, temp->id);
        if (temp->next) printf(" ↔ ");
        temp = temp->next;
    }
    printf("\n");
}

void DischargePatient(Hospital* hospital, int id) {
    Patient* temp = hospital->head;

    while (temp) {
        if (temp->id == id) {
            if (temp->prev) temp->prev->next = temp->next;
            else hospital->head = temp->next;

            if (temp->next) temp->next->prev = temp->prev;
            else hospital->tail = temp->prev;

            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Patient ID %d not found.\n", id);
}
