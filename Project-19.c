#include <studio.h>
#include <stidlb.h>
#include <string.h>
#include <time.h>

#define MAX_MACHINES 100

// Data storage
typedef struct {
    char name[50];
    struct tm last_maintenance;
    int maintenance_interval; // in days
} Machine;

// Global machine storage array
Machine machines[MAX_MACHINES];
int machine_count = 0;

void add machine() {
   if (machine_count >= MAX_MACHINE){
       printf("Maximum number of machines reached.\n");
       return;
   }
   
   Machine new_machine;
   printf("Enter machine's name: ");
   scanf("%s", new_machnie.name);
   
   // Enter the last maintenance data
   printf("Enter year of last maintenance (yyyy): ");
   int year, month, day;
   scanf("%d-%d-%d", &year, &month, &day);
   new_machine.last_maintenance.tm_year = year - 1900;
   new_machine.last_maintenance.tm_month = month -1;
   new_machine.last_maintenance.tm_day = day;
   
   // Enter maintenance interval (in days) 
   printf("Enter maintenance interval in days ");
   scanf("%d",&new_maintenance_interval);

   machines[machine_count+++] = new_machine;
   printf("The machine is added successfully);
}

void show_maintenance_schedule(){
    printf("\nMachine maintenance schedule :\n");
    for (int i = 0; i < machine_count; i++) {
        Machine m = machines[i];
        struct tm next_maintenance = m.last_maintenance;
        next_maintenance.tm_mday += m.maintenance_interval;
        mktime(&next_maintenance);

        printf("Machine: %s\n", m.name);
        printf("Next maintenance: %d-%d-%d\n",
               next_maintenance.tm_year + 1900,
               next_maintenance.tm_mon + 1,
               next_maintenance.tm_mday);
        printf("\n");
    }
}

// Fuction for saving data to a file
void save_data(const char *filename) {
    FILE *file = fopen(fileman, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < machine_count; i++) {
        Machine m = machines[i];
        fprintf(file, "%s,%d-%d-%d,%d\n", m.name,
                m.last_maintenance.tm_year + 1900,
                m.last_maintenance.tm_mon + 1,
                m.last_maintenance.tm_mday,
                m.maintenance_interval);
    }

    fclose(file);
}

// Function to load data from a file
void load_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%49[^,],%d-%d-%d,%d\n", machines[machine_count].name,
                   &machines[machine_count].last_maintenance.tm_year,
                   &machines[machine_count].last_maintenance.tm_mon,
                   &machines[machine_count].last_maintenance.tm_mday,
                   &machines[machine_count].maintenance_interval) != EOF) {
        machines[machine_count].last_maintenance.tm_year -= 1900;
        machines[machine_count].last_maintenance.tm_mon -= 1;
        machine_count++;
    }

    fclose(file);
}

int main() {
    int choice;
    const char *filename = "matches.txt";

    load_data(filename); // Loading data at startup

    while (1) {
        printf("\nMenu: \n");
        printf("1. Add а new machine\n");
        printf("2. Show maintenance schedule\n");
        printf("3. Save data\n");
        printf("4. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_machine();
                break;
            case 2:
                show_maintenance_schedule();
                break;
            case 3:
                save_data(filename);
                printf("Data saved successfully.\n");
                break;
            case 4:
                save data(filename); // Record data on exit
                printf("Exit the program.\n");
                return 0;
            default:
                printf("Invalid selection!\n");
        }
    }

    return 0;
}
