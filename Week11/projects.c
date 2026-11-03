#include <stdio.h>
#include "projects.h"
#include "utilities.h"

void addProject(Project projects[], int *count, int capacity) {
    if (*count >= capacity) { printf("Project list is full.\n"); return; }
    Project p;
    p.id = readInt("Enter project ID: ");
    readString("Enter title: ", p.title, 40);
    p.budget = readDouble("Enter budget: ");
    
    printf("Enter start date:\n");
    p.startDate.day = readInt("  Day: ");
    p.startDate.month = readInt("  Month: ");
    p.startDate.year = readInt("  Year: ");
    
    printf("Enter end date:\n");
    p.endDate.day = readInt("  Day: ");
    p.endDate.month = readInt("  Month: ");
    p.endDate.year = readInt("  Year: ");

    projects[*count] = p;
    (*count)++;
    printf("Project added.\n");
}

void displayProjects(Project projects[], int count) {
    if (count == 0) { printf("No projects to display.\n"); return; }
    printf("\n%-6s %-20s %12s %-12s %-12s\n", "ID", "Title", "Budget", "Start Date", "End Date");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %12.2f %02d/%02d/%04d  %02d/%02d/%04d\n",
               projects[i].id, projects[i].title, projects[i].budget,
               projects[i].startDate.day, projects[i].startDate.month, projects[i].startDate.year,
               projects[i].endDate.day, projects[i].endDate.month, projects[i].endDate.year);
    }
}