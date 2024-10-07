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

// Categorization function
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay warm, it's freezing outside.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors, it's extremely hot.\n");
    }
}

// Function to get a valid temperature input from the user
float get_valid_temperature() {
    float temperature;
    while (1) {
        printf("Enter the temperature: ");
        if (scanf("%f", &temperature) == 1) {
            return temperature;
        } else {
            printf("Invalid temperature value. Please enter a valid number.\n");
            // Clear the input buffer to avoid an infinite loop
            while (getchar() != '\n');
        }
    }
}

// Function to get a valid scale choice from the user
int get_valid_choice(const char* prompt) {
    int choice;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 3) {
            return choice;
        } else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            // Clear the input buffer to avoid an infinite loop
            while (getchar() != '\n');
        }
    }
}

int main()
{
    float temperature, converted_temp;
    int input_scale, target_scale;

    // Get valid inputs for the temperature, input scale, and target scale
    temperature = get_valid_temperature();
    input_scale = get_valid_choice("Choose the input scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    target_scale = get_valid_choice("Convert to: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");

    // if a Kelvin value was inputted it should be positive
    if (temperature < 0 && input_scale == 3) {
        printf("Kelvin values should be positive.\n");
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

    // Categorize the temperature based on Celsius value
    float temp_in_celsius = temperature;
    if (input_scale == 2) {
        temp_in_celsius = fahrenheit_to_celsius(temperature);
    } else if (input_scale == 3) {
        temp_in_celsius = kelvin_to_celsius(temperature);
    }

    printf("\nConverted temperature: %.2f %s\n", converted_temp, scale_names[target_scale - 1]);
    categorize_temperature(temp_in_celsius);

    printf("\n");
    return 1;
}
