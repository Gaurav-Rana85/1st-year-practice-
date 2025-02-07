#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Doctor {
    char name[50];
    char specialty[50];
    int id;
    char availableDays[100];
};

struct Appointment {
    int doctorId;
    char date[20];
    char time[10];
    int appointmentId;
};

struct Patient {
    char name[50];
    int age;
    char contact[15];
    int id;
    int appointmentCount;
    struct Appointment *appointments;
};

struct Doctor *doctors = NULL;
struct Patient *patients = NULL;
int doctorCount = 0, patientCount = 0, appointmentIdCounter = 0;

void getInput(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int validateIntegerInput(const char *prompt) {
    char buffer[10];
    int valid = 0;
    int num = 0;

    while (!valid) {
        getInput(prompt, buffer, sizeof(buffer));
        valid = 1;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isdigit(buffer[i])) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            num = atoi(buffer);
        } else {
            printf("Invalid input, please enter a valid number.\n");
        }
    }
    return num;
}

void registerPatient() {
    struct Patient newPatient;

    getInput("Enter patient name: ", newPatient.name, sizeof(newPatient.name));
    newPatient.age = validateIntegerInput("Enter patient age: ");
    getInput("Enter contact number: ", newPatient.contact, sizeof(newPatient.contact));

    newPatient.id = ++patientCount;
    newPatient.appointmentCount = 0;
    newPatient.appointments = NULL;

    patients = realloc(patients, patientCount * sizeof(struct Patient));
    patients[patientCount - 1] = newPatient;

    printf("Patient Registered Successfully! ID: %d\n", newPatient.id);
}

void registerDoctor() {
    struct Doctor newDoctor;

    getInput("Enter doctor name: ", newDoctor.name, sizeof(newDoctor.name));
    getInput("Enter specialty: ", newDoctor.specialty, sizeof(newDoctor.specialty));
    getInput("Enter available days (comma separated): ", newDoctor.availableDays, sizeof(newDoctor.availableDays));

    newDoctor.id = ++doctorCount;

    doctors = realloc(doctors, doctorCount * sizeof(struct Doctor));
    doctors[doctorCount - 1] = newDoctor;

    printf("Doctor Registered Successfully! ID: %d\n", newDoctor.id);
}

void viewAllDoctors() {
    if (doctorCount == 0) {
        printf("\nNo doctors are registered yet.\n");
        return;
    }

    printf("\n** Doctor List **\n");
    printf("+-----+--------------------+----------------------+----------------------------+\n");
    printf("| ID  | Name               | Specialty            | Available Days             |\n");
    printf("+-----+--------------------+----------------------+----------------------------+\n");

    for (int i = 0; i < doctorCount; i++) {
        printf("| %-3d | %-18s | %-20s | %-26s |\n", doctors[i].id, doctors[i].name, doctors[i].specialty, doctors[i].availableDays);
    }

    printf("+-----+--------------------+----------------------+----------------------------+\n");
}

void checkDoctorAvailability() {
    char specialty[50], day[20];
    int found = 0;

    getInput("Enter specialty to search: ", specialty, sizeof(specialty));
    getInput("Enter day (e.g., Monday): ", day, sizeof(day));

    printf("\nDoctors available for '%s' on '%s':\n", specialty, day);
    printf("+-----+---------------------+----------------------+----------------------------+\n");
    printf("| ID  | Name                | Specialty            | Available Days             |\n");
    printf("+-----+---------------------+----------------------+----------------------------+\n");

    for (int i = 0; i < doctorCount; i++) {
        if (strcasecmp(doctors[i].specialty, specialty) == 0) {
            char *availableDays = strdup(doctors[i].availableDays);
            char *token = strtok(availableDays, ",");
            while (token != NULL) {
                if (strcasecmp(token, day) == 0) {
                    found = 1;
                    printf("| %-3d | %-19s | %-20s | %-26s |\n",
                           doctors[i].id, doctors[i].name, doctors[i].specialty, doctors[i].availableDays);
                    break;
                }
                token = strtok(NULL, ",");
            }
            free(availableDays);
        }
    }

    printf("+-----+---------------------+----------------------+----------------------------+\n");

    if (!found) {
        printf("No doctors available for the specified specialty and day.\n");
    }
}

void showAndExportPatientRecords() {
    if (patientCount == 0) {
        printf("No patients are registered yet.\n");
        return;
    }

    printf("\n** Patient Records **\n");
    printf("+-----+--------------------+-----+------------------+\n");
    printf("| ID  | Name               | Age | Contact          |\n");
    printf("+-----+--------------------+-----+------------------+\n");

    for (int i = 0; i < patientCount; i++) {
        printf("| %-3d | %-18s | %-3d | %-16s |\n",
               patients[i].id, patients[i].name, patients[i].age, patients[i].contact);
    }

    printf("+-----+--------------------+-----+------------------+\n");
}

void registerAppointment() {
    if (doctorCount == 0) {
        printf("No doctors available for appointments.\n");
        return;
    }

    printf("\n** Available Doctors **\n");
    viewAllDoctors();

    int doctorId = validateIntegerInput("Enter the doctor ID you wish to book an appointment with: ");
    if (doctorId <= 0 || doctorId > doctorCount) {
        printf("Invalid doctor ID.\n");
        return;
    }

    printf("\n** Available Patients **\n");
    for (int i = 0; i < patientCount; i++) {
        printf("%d. %s\n", patients[i].id, patients[i].name);
    }

    int patientId = validateIntegerInput("Enter the patient ID for the appointment: ");
    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    char date[20], time[10];
    getInput("Enter appointment date (DD/MM/YYYY): ", date, sizeof(date));
    getInput("Enter appointment time (HH:MM): ", time, sizeof(time));

    struct Appointment newAppointment;
    newAppointment.doctorId = doctorId;
    strcpy(newAppointment.date, date);
    strcpy(newAppointment.time, time);
    newAppointment.appointmentId = ++appointmentIdCounter;

    struct Patient *patient = &patients[patientId - 1];
    patient->appointments = realloc(patient->appointments, (patient->appointmentCount + 1) * sizeof(struct Appointment));
    patient->appointments[patient->appointmentCount] = newAppointment;
    patient->appointmentCount++;

    printf("Appointment registered successfully! Appointment ID: %d\n", newAppointment.appointmentId);
}

void viewPatientAppointments() {
    if (patientCount == 0) {
        printf("No patients are registered yet.\n");
        return;
    }

    int patientId = validateIntegerInput("Enter the patient ID to view appointments: ");
    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    struct Patient *patient = &patients[patientId - 1];

    if (patient->appointmentCount == 0) {
        printf("No appointments found for patient: %s\n", patient->name);
        return;
    }

    printf("\nAppointments for %s (ID: %d):\n", patient->name, patient->id);
    printf("+------------+---------+----------+\n");
    printf("| Date       | Time    | Doctor ID|\n");
    printf("+------------+---------+----------+\n");

    for (int i = 0; i < patient->appointmentCount; i++) {
        printf("| %-10s | %-7s | %-8d |\n",
               patient->appointments[i].date,
               patient->appointments[i].time,
               patient->appointments[i].doctorId);
    }

    printf("+------------+---------+----------+\n");
}

void viewMedicalHistory() {
    if (patientCount == 0) {
        printf("No patients are registered yet.\n");
        return;
    }

    int patientId = validateIntegerInput("Enter the patient ID to view medical history: ");
    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    struct Patient *patient = &patients[patientId - 1];

    printf("\nMedical History for %s (ID: %d):\n", patient->name, patient->id);
    if (patient->appointmentCount == 0) {
        printf("No medical history available.\n");
        return;
    }

    printf("+------------+---------+------------+--------------------+\n");
    printf("| Date       | Time    | Doctor ID  | Doctor Name        |\n");
    printf("+------------+---------+------------+--------------------+\n");

    for (int i = 0; i < patient->appointmentCount; i++) {
        int doctorId = patient->appointments[i].doctorId;
        char *doctorName = "Unknown";

        for (int j = 0; j < doctorCount; j++) {
            if (doctors[j].id == doctorId) {
                doctorName = doctors[j].name;
                break;
            }
        }

        printf("| %-10s | %-7s | %-10d | %-18s |\n",
               patient->appointments[i].date,
               patient->appointments[i].time,
               doctorId,
               doctorName);
    }

    printf("+------------+---------+------------+--------------------+\n");
}

void preRegisterDoctors() {
    struct Doctor predefinedDoctors[] = {
        {"Dr. Aakash Gupta", "Cardiologist", ++doctorCount, "Monday,Wednesday,Friday"},
        {"Dr. Kavita Sharma", "Dermatologist", ++doctorCount, "Tuesday,Thursday,Saturday"},
        {"Dr. Rahul Verma", "Neurologist", ++doctorCount, "Monday,Thursday,Sunday"},
        {"Dr. Priya Singh", "Pediatrician", ++doctorCount, "Wednesday,Friday,Saturday"}
    };

    int predefinedCount = sizeof(predefinedDoctors) / sizeof(predefinedDoctors[0]);
    doctors = realloc(doctors, predefinedCount * sizeof(struct Doctor));
    for (int i = 0; i < predefinedCount; i++) {
        doctors[i] = predefinedDoctors[i];
    }

    doctorCount = predefinedCount;
}

void menu() {
    int choice;

    do {
        printf("\n** Hospital Management System **\n");
        printf("1. Register Patient\n");
        printf("2. Register Doctor\n");
        printf("3. View All Doctors\n");
        printf("4. Check Doctor Availability\n");
        printf("5. Show and Export Patient Records\n");
        printf("6. Register Appointment\n");
        printf("7. View Patient Appointments\n");
        printf("8. View Medical History\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        choice = validateIntegerInput("");

        switch (choice) {
            case 1: registerPatient(); break;
            case 2: registerDoctor(); break;
            case 3: viewAllDoctors(); break;
            case 4: checkDoctorAvailability(); break;
            case 5: showAndExportPatientRecords(); break;
            case 6: registerAppointment(); break;
            case 7: viewPatientAppointments(); break;
            case 8: viewMedicalHistory(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    for (int i = 0; i < patientCount; i++) {
        free(patients[i].appointments);
    }
    free(doctors);
    free(patients);
}

int main() {
    preRegisterDoctors();
    menu();
    return 0;
}
