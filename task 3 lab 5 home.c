#include <stdio.h>

int main() {
    int prod_cat, cust_cat, order_num;
    double order_amount, distance;
    double discount_rate = 0.0;
    double discount_amount, final_amount;
    double delivery_charge = 0.0;
    double priority_charge = 0.0;
    double total_payable;
    int free_shipping = 0;
    int priority_eligible = 0;
    int group_rem;

    printf("E-Commerce Order Processing System\n");
    printf("Select Product Category:\n");
    printf("1. Electronics\n");
    printf("2. Clothing\n");
    printf("3. Books\n");
    printf("4. Household\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &prod_cat);

    printf("\nSelect Customer Category:\n");
    printf("1. Regular\n");
    printf("2. Premium\n");
    printf("3. Corporate\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &cust_cat);

    printf("\nEnter Order Number: ");
    scanf("%d", &order_num);
    printf("Enter Order Amount (Rs.): ");
    scanf("%lf", &order_amount);
    printf("Enter Delivery Distance (km): ");
    scanf("%lf", &distance);

    switch (prod_cat) {
        case 1:
            switch (cust_cat) {
                case 1: discount_rate = 0.05; break;
                case 2: discount_rate = 0.10; break;
                case 3: discount_rate = 0.15; break;
                default: printf("Invalid customer category.\n"); return 1;
            }
            break;
        case 2:
            switch (cust_cat) {
                case 1: discount_rate = 0.10; break;
                case 2: discount_rate = 0.15; break;
                case 3: discount_rate = 0.20; break;
                default: printf("Invalid customer category.\n"); return 1;
            }
            break;
        case 3:
            switch (cust_cat) {
                case 1: discount_rate = 0.08; break;
                case 2: discount_rate = 0.12; break;
                case 3: discount_rate = 0.18; break;
                default: printf("Invalid customer category.\n"); return 1;
            }
            break;
        case 4:
            switch (cust_cat) {
                case 1: discount_rate = 0.07; break;
                case 2: discount_rate = 0.14; break;
                case 3: discount_rate = 0.20; break;
                default: printf("Invalid customer category.\n"); return 1;
            }
            break;
        default:
            printf("Invalid product category.\n");
            return 1;
    }

    discount_amount = order_amount * discount_rate;
    final_amount = order_amount - discount_amount;

    if (final_amount >= 5000.0 || cust_cat == 2 || cust_cat == 3) {
        free_shipping = 1;
        delivery_charge = 0.0;
    } else {
        free_shipping = 0;
        delivery_charge = distance * 15.0;
    }

    if ((cust_cat == 2 || cust_cat == 3) && order_amount >= 10000.0) {
        priority_eligible = 1;
        priority_charge = 500.0;
    } else {
        priority_eligible = 0;
        priority_charge = 0.0;
    }

    group_rem = order_num % 4;
    total_payable = final_amount + delivery_charge + priority_charge;

    printf("\n================ ORDER SUMMARY ================\n");
    
    switch (prod_cat) {
        case 1: printf("Product Category: Electronics\n"); break;
        case 2: printf("Product Category: Clothing\n"); break;
        case 3: printf("Product Category: Books\n"); break;
        case 4: printf("Product Category: Household\n"); break;
    }

    switch (cust_cat) {
        case 1: printf("Customer Category: Regular\n"); break;
        case 2: printf("Customer Category: Premium\n"); break;
        case 3: printf("Customer Category: Corporate\n"); break;
    }

    printf("Original Order Amount: Rs. %.2f\n", order_amount);
    printf("Applied Discount: %.0f%%\n", discount_rate * 100);
    printf("Discount Amount: Rs. %.2f\n", discount_amount);
    printf("Payable Amount (Post Discount): Rs. %.2f\n", final_amount);
    printf("Delivery Distance: %.2f km\n", distance);
    printf("Shipping Status: %s\n", free_shipping ? "Free Shipping" : "Standard Shipping");
    printf("Delivery Charge: Rs. %.2f\n", delivery_charge);
    printf("Priority Delivery: %s\n", priority_eligible ? "Qualifies for Priority" : "Normal Delivery");
    printf("Priority Charge: Rs. %.2f\n", priority_charge);

    switch (group_rem) {
        case 0: printf("Processing Group: Group A\n"); break;
        case 1: printf("Processing Group: Group B\n"); break;
        case 2: printf("Processing Group: Group C\n"); break;
        case 3: printf("Processing Group: Group D\n"); break;
    }

    printf("-----------------------------------------------\n");
    printf("TOTAL AMOUNT PAYABLE: Rs. %.2f\n", total_payable);
    printf("===============================================\n");

    return 0;
}
