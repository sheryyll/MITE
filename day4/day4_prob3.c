/*`3. Weather Monitoring System`  
`Scenario:`  
A `weather station` records temperature and humidity for `different cities`. The system should:  
- Store records using `structures`  
- Allow searching for `temperature of a specific city`  
- Save data to a `file`  

`Input Example:`
    Enter number of cities: 3
    City 1: Mumbai, 32°C, 80%
    City 2: Delhi, 38°C, 60%
    City 3: Chennai, 35°C, 75%
    Enter city name to search: Delhi
`Output Example:
    Weather in Delhi: 38°C, 60% Humidity
    Data saved in "weather_data.txt"*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #define MAX_CITIES 100
    #define FILENAME "weather_data.txt"
    
    
    struct WeatherData_t {
        char city[50];
        int temperature; 
        int humidity;    
    };
    
    typedef struct WeatherData_t WeatherData;
    
    
    void readWeatherData(WeatherData weather[], int n);
    void saveWeatherData(WeatherData weather[], int count);
    WeatherData findWeatherByCity(WeatherData weather[], int count, const char* city_name);
    
    int main() {
        int cityCount;
    
        
        printf("Welcome to the Weather Monitoring System!\n");
        printf("Please enter the number of cities you want to record: ");
        scanf("%d", &cityCount);
    
        
        if (cityCount > MAX_CITIES) {
            printf("Error: Maximum number of cities is %d.\n", MAX_CITIES);
            return 1; 
        }
    
        WeatherData weather[MAX_CITIES];
    
        readWeatherData(weather, cityCount);
    
        saveWeatherData(weather, cityCount);
   
        char city_name[50];
        printf("Enter the name of the city to search for its weather: ");
        scanf("%s", city_name);
    
        WeatherData found_weather = findWeatherByCity(weather, cityCount, city_name);
        
        if (found_weather.temperature != -1) {
            printf("Weather in %s: %d°C, %d Humidity\n", 
                   found_weather.city, 
                   found_weather.temperature, 
                   found_weather.humidity);
        } else {
            printf("Sorry, weather data for %s not found.\n", city_name);
        }
    
        return 0;
    }
   
    void readWeatherData(WeatherData weather[], int n) {
        printf("Please enter the weather details for each city in the following format:\n");
        printf("City Name, Temperature (°C), Humidity (%)\n");
        
        for (int i = 0; i < n; i++) {
            printf("City %d: ", i + 1);
            scanf("%s, %d, %d", 
                  weather[i].city, 
                  &weather[i].temperature, 
                  &weather[i].humidity);
        }
    }
  
    void saveWeatherData(WeatherData weather[], int count) {
        FILE *file = fopen(FILENAME, "w");
        if (file == NULL) {
            printf("Error opening file for writing.\n");
            return;
        }
    
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s, %d°C, %d\n", 
                    weather[i].city, 
                    weather[i].temperature, 
                    weather[i].humidity);
        }
        
        fclose(file);
        printf("Weather data successfully saved in \"%s\".\n", FILENAME);
    }
   
    WeatherData findWeatherByCity(WeatherData weather[], int count, const char* city_name) {
        WeatherData not_found = {"", -1, -1}; 
        for (int i = 0; i < count; i++) {
            if (strcmp(weather[i].city, city_name) == 0) {
                return weather[i]; 
            }
        }
        return not_found;
    