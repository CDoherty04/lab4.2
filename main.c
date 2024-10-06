#include <stdio.h>

// Conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Meant for scale choice input
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
    
    // Perform the conversion
    if (input_scale == target_scale) {
        printf("No conversion needed.\n");
        converted_temp = temperature;
    } else if (input_scale == 1 && target_scale == 2) {
        converted_temp = celsius_to_fahrenheit(temperature);
    } else if (input_scale == 1 && target_scale == 3) {
        converted_temp = celsius_to_kelvin(temperature);
    } else if (input_scale == 2 && target_scale == 1) {
        converted_temp = fahrenheit_to_celsius(temperature);
    } else if (input_scale == 2 && target_scale == 3) {
        converted_temp = fahrenheit_to_kelvin(temperature);
    } else if (input_scale == 3 && target_scale == 1) {
        converted_temp = kelvin_to_celsius(temperature);
    } else if (input_scale == 3 && target_scale == 2) {
        converted_temp = kelvin_to_fahrenheit(temperature);
    }

    // Convert int scale to String representation
    char *scale_names[] = {"Celsius", "Fahrenheit", "Kelvin"};

    printf("%f in %s is %f in %s", temperature, scale_names[input_scale - 1], converted_temp, scale_names[target_scale - 1]);

    return 1;
}
