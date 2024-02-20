//Program to get weather report.

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 30
#define URL_LENGTH 500

void readUserInput(char* cityName)
{
    printf("Get weather report:\n");
    printf("Enter city name: ");
    scanf("%s", cityName);
}

void showWeatherReport(char* cityName)
{
    char urlFirstPart[URL_LENGTH] = {"https://api.openweathermap.org/data/2.5/weather?q="};
    char urlSecondPart[URL_LENGTH] = {"&appid=abe3a0f4d0b6cebfbe7393b4b4e3aa28&units=metric"};
    char url[URL_LENGTH];

    sprintf(url, "%s%s%s", urlFirstPart, cityName, urlSecondPart);
    char command[URL_LENGTH];
    sprintf(command, "curl \"%s\" > weather.txt", url);
    // printf("%s", command);
    system(command);

    FILE *fpWeather = fopen("weather.txt", "r");
    fseek(fpWeather, 0, SEEK_END);
    int fileSize = ftell(fpWeather);
    fseek(fpWeather, 0, SEEK_SET);
    char weatherData[fileSize];
    fread(weatherData, sizeof(weatherData), 1, fpWeather);
    fclose(fpWeather);
    char *token = (char*)strtok(weatherData, ":");

    while(token != NULL)
    {
        if(strcmp(token, "{\"temp\"") == 0)
        {
            token = (char*)strtok(NULL, ",");
            printf("Temperature: %s\n", token);
            break;
        }
       
        token = (char*)strtok(NULL, ":");
    }

}

void main()
{
	char cityName[LENGTH];
    readUserInput(cityName);
    showWeatherReport(cityName);
	
}
