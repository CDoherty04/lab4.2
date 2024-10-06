#include <stdio.h>

int is_valid_choice(int choice) {
    return choice >= 1 && choice <= 3;
}

int main()
{
    float temperature, converted_temp;
    int input_scale, target_scale;

    // Input the temperature value
    printf("Enter the temperature: ");
    if (scanf("%f", &temperature) != 1)
    {
        printf("Invalid temperature value.\n");
        return 1;
    }

    // Choose the input scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &input_scale) != 1 || !is_valid_choice(input_scale))
    {
        printf("Invalid choice for the input scale.\n");
        return 1;
    }

    // Choose the conversion target scale
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &target_scale) != 1 || !is_valid_choice(target_scale))
    {
        printf("Invalid choice for the target scale.\n");
        return 1;
    }
    
    // Convert int scale to String representation
    char *scale_names[] = {"Celsius", "Fahrenheit", "Kelvin"};

    printf("Temperature in %s to transfer to %s: %f", scale_names[input_scale - 1], scale_names[target_scale - 1], temperature);

    return 1;
}
