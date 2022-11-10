#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent an agency, in other word, a node in the agency list
typedef struct Agency {
    char name[25];
    char phoneNumber[15];
    double turnover;
    struct Agency *next;
} Agency;

// Allocate memory and input data for a new agency
Agency *newAgency() {
    Agency *agency = (Agency *)malloc(sizeof(Agency));

    fflush(stdin);
    printf("Enter agency name: ");
    gets(agency->name);

    printf("Enter agency phone number: ");
    scanf("%s", agency->phoneNumber);

    printf("Enter agency turnover: ");
    scanf("%lf", &agency->turnover);
    agency->next = NULL;

    return agency;
}

// Display an agency
void displayAgency(Agency *agency) {
    printf("%-25s\t%-15s\t%-15.2lf\n", agency->name, agency->phoneNumber, agency->turnover);
}

// A list of agencies
typedef struct AgencyList {
    Agency *head;
    Agency *tail;
} AgencyList;

// Add an agency to the end of the list
void addAgency(AgencyList *agencyList, Agency *agency) {
    if (agencyList->head == NULL) {
        agencyList->head = agency;
        agencyList->tail = agency;
    } else {
        agencyList->tail->next = agency;
        agencyList->tail = agency;
    }
}

// Display all agencies in the list
void displayAgencyList(AgencyList *agencyList) {
    if (agencyList->head == NULL) {
        printf("Agency list is empty!\n");
    } else {
        printf("%-25s\t%-15s\t%-15s\n", "Agency Name", "Phone Number", "Turnover");
        Agency *agency = agencyList->head;
        while (agency != NULL) {
            displayAgency(agency);
            agency = agency->next;
        }
    }
    printf("\n");
}

// A city with a list of agencies
typedef struct City {
    char name[25];
    AgencyList agencyList;
    struct City *next;
} City;

// Allocate memory and input name for a new city
City *createCity(char *name) {
    City *city = (City *)malloc(sizeof(City));
    strcpy(city->name, name);
    city->agencyList.head = NULL;
    city->agencyList.tail = NULL;
    city->next = NULL;
    return city;
}

// Display a city
void displayCity(City *city) {
    printf("The city of %s\n", city->name);
    displayAgencyList(&city->agencyList);
}

// A company has a list of cities
typedef struct Company {
    char name[25];
    City *head;
    City *tail;
} Company;

// Add a city to the end of the list
void addCity(Company *company, City *city) {
    if (company->head == NULL) {
        company->head = city;
        company->tail = city;
    } else {
        company->tail->next = city;
        company->tail = city;
    }
}

// Add an agency to the end of the list of agencies in a city
void addAgencyAtCity(Company *company, Agency *agency, char *cityName) {
    City *city = company->head;
    while (city != NULL) {
        if (strcmp(city->name, cityName) == 0) {
            addAgency(&city->agencyList, agency);
            return;
        }
        city = city->next;
    }
}

// Update the information of an agency in some city
void updateAgencyAtCity(Company *company, char *agencyName, char *cityName) {
    City *city = company->head;
    while (city != NULL) {
        if (strcmp(city->name, cityName) == 0) {
            Agency *agency = city->agencyList.head;
            while (agency != NULL) {
                if (strcmp(agency->name, agencyName) == 0) {
                    printf("Enter new agency phone number: ");
                    scanf("%s", agency->phoneNumber);

                    printf("Enter new agency turnover: ");
                    scanf("%lf", &agency->turnover);
                    return;
                }
                agency = agency->next;
            }
        }
        city = city->next;
    }
}

// Remove some agency in some city
void removeAgencyAtCity(Company *company, char *agencyName, char *cityName) {
    City *city = company->head;
    while (city != NULL) {
        if (strcmp(city->name, cityName) == 0) {
            Agency *agency = city->agencyList.head;
            Agency *prevAgency = NULL;
            while (agency != NULL) {
                if (strcmp(agency->name, agencyName) == 0) {
                    if (prevAgency == NULL) {
                        city->agencyList.head = agency->next;
                    } else {
                        prevAgency->next = agency->next;
                    }
                    free(agency);
                    return;
                }
                prevAgency = agency;
                agency = agency->next;
            }
        }
        city = city->next;
    }
}

// Find a city by name
City *findCity(Company *company, char *cityName) {
    City *city = company->head;
    while (city != NULL) {
        if (strcmp(city->name, cityName) == 0) {
            return city;
        }
        city = city->next;
    }
    return NULL;
}

// Check if a city with certain name exists in the company
int cityExist(Company *company, char *cityName) {
    return findCity(company, cityName) != NULL;
}

// Find an agency by name in a city
Agency *findAgencyAtCity(Company *company, char *agencyName, char *cityName) {
    City *city = company->head;
    while (city != NULL) {
        if (strcmp(city->name, cityName) == 0) {
            Agency *agency = city->agencyList.head;
            while (agency != NULL) {
                if (strcmp(agency->name, agencyName) == 0) {
                    return agency;
                }
                agency = agency->next;
            }
        }
        city = city->next;
    }
    return NULL;
}

// Check if an agency with certain name exists in a city
int agencyExsistsAtCity(Company *company, char *agencyName, char *cityName) {
    return findAgencyAtCity(company, agencyName, cityName) != NULL;
}

// Display all cities in the company
void displayCompany(Company *company) {
    printf("%s Company\n", company->name);
    City *city = company->head;
    while (city != NULL) {
        displayCity(city);
        city = city->next;
    }
}

// Menu options
void menu() {
    printf("1. Add a city\n");
    printf("2. Add an agency at a city\n");
    printf("3. Update an agency at a city\n");
    printf("4. Remove an agency at a city\n");
    printf("5. Display company\n");
    printf("6. Find an agency at a city\n");
    printf("0. Exit\n");
}

int main() {
    Company company;
    strcpy(company.name, "IUH Software");
    company.head = NULL;
    company.tail = NULL;
    char cityName[25];
    char agencyName[25];
    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            // Add a city
            case 1: {
                fflush(stdin);
                printf("Enter city name: ");
                gets(cityName);
                City *city = createCity(cityName);
                addCity(&company, city);
                break;
            }
            // Add an agency at a city
            case 2: {
                fflush(stdin);
                printf("Enter city name: ");
                gets(cityName);
                // If the city does not exist, create a new city
                if (!cityExist(&company, cityName)) {
                    printf("The city does not exist. Create a new city.\n");
                    // Add city
                    City *city = createCity(cityName);
                    addCity(&company, city);
                }

                // Add agency to the city
                Agency *agency = newAgency();
                addAgencyAtCity(&company, agency, cityName);
                break;
            }
            // Update an agency at a city
            case 3: {
                printf("Enter city name: ");
                fflush(stdin);
                gets(cityName);

                // Check if city exists
                if (!cityExist(&company, cityName)) {
                    printf("City does not exist\n");
                    break;
                }

                printf("Enter agency name: ");
                fflush(stdin);
                gets(agencyName);

                // Check if agency exists
                if (!agencyExsistsAtCity(&company, agencyName, cityName)) {
                    printf("Agency does not exist\n");
                    break;
                }

                // If both city and agency exist, update the agency
                updateAgencyAtCity(&company, agencyName, cityName);
                break;
            }
            // Remove an agency at a city
            case 4: {
                printf("Enter city name: ");
                fflush(stdin);
                gets(cityName);

                // Check if city exists
                if (!cityExist(&company, cityName)) {
                    printf("City does not exist\n");
                    break;
                }

                printf("Enter agency name: ");
                fflush(stdin);
                gets(agencyName);

                // Check if agency exists
                if (!agencyExsistsAtCity(&company, agencyName, cityName)) {
                    printf("Agency does not exist\n");
                    break;
                }

                // If both city and agency exist, remove the agency
                removeAgencyAtCity(&company, agencyName, cityName);
                break;
            }
            case 5: {
                displayCompany(&company);
                break;
            }
            case 6: {
                printf("Enter city name: ");
                fflush(stdin);
                gets(cityName);

                // Check if city exists
                if (!cityExist(&company, cityName)) {
                    printf("City does not exist\n");
                    break;
                }

                printf("Enter agency name: ");
                fflush(stdin);
                gets(agencyName);

                // Check if agency exists
                if (!agencyExsistsAtCity(&company, agencyName, cityName)) {
                    printf("Agency does not exist\n");
                    break;
                }

                // If both city and agency exist, find the agency
                Agency *agency = findAgencyAtCity(&company, agencyName, cityName);
                printf("%-25s\t%-15s\t%-15s\n", "Agency Name", "Phone Number", "Turnover");
                displayAgency(agency);
                break;
            }
            case 0: {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
        printf("\n");
    } while (choice != 0);

    return 0;
}