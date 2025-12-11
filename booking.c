#include <stdio.h>
#include <string.h>
#include <time.h>

#define FILE_NAME "bookings.txt"

// BookingSimple structure defined here (The single definition)
typedef struct {
    char name[50];
    int seat;
    char source[50];
    char destination[50];
} BookingSimple;

// Print ticket
void printTicket() {
    int seat;
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200];
    
    printf("Enter seat number: ");
    scanf("%d", &seat);
    
    if(fp == NULL) {
        printf("No bookings found.\n");
        return;
    }
    
    while(fgets(line, sizeof(line), fp)) {
        BookingSimple b;
        sscanf(line, "%[^,],%d,%[^,],%[^\n]", b.name, &b.seat, b.source, b.destination);
        
        if(b.seat == seat) {
            printf("\n================================\n");
            printf("        TRANSPORT TICKET\n");
            printf("================================\n");
            printf("Passenger: %s\n", b.name);
            printf("Seat No:   %d\n", b.seat);
            printf("From:      %s\n", b.source);
            printf("To:        %s\n", b.destination);
            printf("Status:    CONFIRMED\n");
            printf("================================\n");
            fclose(fp);
            return;
        }
    }
    
    fclose(fp);
    printf("Ticket not found for seat %d.\n", seat);
}

// Ticket menu
void ticketMenu() {
    int choice;
    do {
        printf("\n--- TICKET PRINTING ---\n");
        printf("1. Print Ticket\n");
        printf("2. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) printTicket();
        else if(choice != 2) printf("Invalid choice.\n");
    } while(choice != 2);
    
    printf("Returning...\n");
}