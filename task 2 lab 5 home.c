#include <stdio.h>

int main() {
    int dept;
    float theory, practical, attendance;
    int min_theory, min_practical, min_att;
    int passed = 0;
    int distinction = 0;
    int seat_rem;

    printf("University Examination Result Processing System\n");
    printf("Select Department:\n");
    printf("1. Computer Science\n");
    printf("2. Electrical Engineering\n");
    printf("3. Business Administration\n");
    printf("4. Mathematics\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &dept);

    printf("Enter Theory Marks: ");
    scanf("%f", &theory);
    printf("Enter Practical Marks: ");
    scanf("%f", &practical);
    printf("Enter Attendance Percentage: ");
    scanf("%f", &attendance);

    switch (dept) {
        case 1:
            min_theory = 50;
            min_practical = 40;
            min_att = 75;
            break;
        case 2:
            min_theory = 55;
            min_practical = 45;
            min_att = 75;
            break;
        case 3:
            min_theory = 50;
            min_practical = 35;
            min_att = 80;
            break;
        case 4:
            min_theory = 60;
            min_practical = 40;
            min_att = 75;
            break;
        default:
            printf("Invalid department selection.\n");
            return 1;
    }

    if (theory >= min_theory && practical >= min_practical && attendance >= min_att) {
        passed = 1;
    }

    if (theory >= 85 && practical >= 80 && attendance >= 90) {
        distinction = 1;
    }

    seat_rem = ((int)theory) % 3;

    printf("\n================ EXAMINATION REPORT ================\n");
    switch (dept) {
        case 1: printf("Department: Computer Science\n"); break;
        case 2: printf("Department: Electrical Engineering\n"); break;
        case 3: printf("Department: Business Administration\n"); break;
        case 4: printf("Department: Mathematics\n"); break;
    }

    printf("Theory Marks: %.2f (Min Required: %d)\n", theory, min_theory);
    printf("Practical Marks: %.2f (Min Required: %d)\n", practical, min_practical);
    printf("Attendance: %.2f%% (Min Required: %d%%)\n", attendance, min_att);
    
    switch (seat_rem) {
        case 0: printf("Seat Classification: Seat Category A\n"); break;
        case 1: printf("Seat Classification: Seat Category B\n"); break;
        case 2: printf("Seat Classification: Seat Category C\n"); break;
    }

    printf("Distinction Eligibility: %s\n", distinction ? "Eligible" : "Not Eligible");
    printf("Final Result: %s\n", passed ? "Passed" : "Failed");
    printf("====================================================\n");

    return 0;
}
