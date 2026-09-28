#include <stdio.h>

int main() {
    int status = 0;
    int choice;
    int op;
    int device;
    int mode;

    printf("Smart Home Security Controller\n");
    printf("1. Manage Individual Device\n");
    printf("2. Select Security Mode\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nSelect Operation:\n");
            printf("1. Activate Device\n");
            printf("2. Deactivate Device\n");
            printf("3. Check Device Status\n");
            printf("4. Toggle Device\n");
            printf("Enter operation: ");
            scanf("%d", &op);

            printf("\nSelect Device:\n");
            printf("1. Main Door Lock (Bit 0 / Value 1)\n");
            printf("2. Alarm System (Bit 1 / Value 2)\n");
            printf("3. CCTV Camera (Bit 2 / Value 4)\n");
            printf("4. Motion Sensor (Bit 3 / Value 8)\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch (op) {
                case 1:
                    switch (device) {
                        case 1: status |= (1 << 0); break;
                        case 2: status |= (1 << 1); break;
                        case 3: status |= (1 << 2); break;
                        case 4: status |= (1 << 3); break;
                        default: printf("Invalid device selected.\n"); break;
                    }
                    break;
                case 2:
                    switch (device) {
                        case 1: status &= ~(1 << 0); break;
                        case 2: status &= ~(1 << 1); break;
                        case 3: status &= ~(1 << 2); break;
                        case 4: status &= ~(1 << 3); break;
                        default: printf("Invalid device selected.\n"); break;
                    }
                    break;
                case 3:
                    switch (device) {
                        case 1: printf("Door Lock Status: %s\n", (status & (1 << 0)) ? "ACTIVE" : "INACTIVE"); break;
                        case 2: printf("Alarm System Status: %s\n", (status & (1 << 1)) ? "ACTIVE" : "INACTIVE"); break;
                        case 3: printf("CCTV Camera Status: %s\n", (status & (1 << 2)) ? "ACTIVE" : "INACTIVE"); break;
                        case 4: printf("Motion Sensor Status: %s\n", (status & (1 << 3)) ? "ACTIVE" : "INACTIVE"); break;
                        default: printf("Invalid device selected.\n"); break;
                    }
                    break;
                case 4:
                    switch (device) {
                        case 1: status ^= (1 << 0); break;
                        case 2: status ^= (1 << 1); break;
                        case 3: status ^= (1 << 2); break;
                        case 4: status ^= (1 << 3); break;
                        default: printf("Invalid device selected.\n"); break;
                    }
                    break;
                default:
                    printf("Invalid operation selected.\n");
                    break;
            }
            break;

        case 2:
            printf("\nSelect Security Mode:\n");
            printf("1. Home Mode (Door Lock + CCTV)\n");
            printf("2. Away Mode (All Devices)\n");
            printf("3. Night Mode (Door Lock + Alarm + Motion Sensor)\n");
            printf("Enter mode: ");
            scanf("%d", &mode);

            switch (mode) {
                case 1:
                    status = 1 | 4;
                    break;
                case 2:
                    status = 1 | 2 | 4 | 8;
                    break;
                case 3:
                    status = (status & 4) | (1 | 2 | 8);
                    break;
                default:
                    printf("Invalid mode selected.\n");
                    break;
            }
            break;

        default:
            printf("Invalid selection.\n");
            break;
    }

    printf("\n================ SYSTEM STATUS ================\n");
    printf("Binary Value Status: %d%d%d%d\n", 
            (status >> 3) & 1, 
            (status >> 2) & 1, 
            (status >> 1) & 1, 
            status & 1);
    
    printf("Main Door Lock (Bit 1): %s\n", (status & 1) ? "ACTIVE" : "INACTIVE");
    printf("Alarm System   (Bit 2): %s\n", (status & 2) ? "ACTIVE" : "INACTIVE");
    printf("CCTV Camera    (Bit 4): %s\n", (status & 4) ? "ACTIVE" : "INACTIVE");
    printf("Motion Sensor  (Bit 8): %s\n", (status & 8) ? "ACTIVE" : "INACTIVE");

    printf("Full System State: %s\n", ((status & 15) == 15) ? "FULLY ARMED" : "PARTIALLY ARMED / UNARMED");
    printf("===============================================\n");

    return 0;
}
