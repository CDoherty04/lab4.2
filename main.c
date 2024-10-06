#include <stdio.h>

int main() {
    float temperature, converted_temp;
    int input_scale, target_scale;

    // Input the temperature value
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    // Choose the input scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &input_scale);

    // Choose the conversion target 
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);

    // Convert int scale to String representation
    char* scale_names[] = {"Celsius", "Fahrenheit", "Kelvin"};

    printf("Temperature in %s to transfer to %s: %f", scale_names[input_scale-1], scale_names[target_scale-1], temperature);

    return 1;
}
