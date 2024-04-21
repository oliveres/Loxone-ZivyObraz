// Počet aktivních analogových vstupů
#define NUM_AI 4

// Pojmenování hodnot a nastavení desetinných míst
char* inputNames[NUM_AI] = {"teplotaVenku", "SoC_baterie", "spotrebaDomu", "vykonFVE"};
int decimalPlaces[NUM_AI] = {1, 0, 3, 0};

float sum[NUM_AI] = {0};
int count[NUM_AI] = {0};

unsigned int startTime = getcurrenttime();
unsigned int lastReadTime = getcurrenttime();

while (TRUE) {
    unsigned int currentTime = getcurrenttime();

    if (currentTime - lastReadTime >= 5) {
        for (int i = 0; i < NUM_AI; i++) {
            float inputValue = getinput(i);
            sum[i] += inputValue;
            count[i]++;
        }
        lastReadTime = currentTime;
    }

    if (currentTime - startTime >= 30) {
        char outputText[512] = "";

        for (int j = 0; j < NUM_AI; j++) {
            if (count[j] > 0) {
                float average = sum[j] / count[j];
                float multiplier = pow(10.0, decimalPlaces[j]);
                float roundedAverage = round(average * multiplier) / multiplier;
                
                char formattedValue[32];
            if (decimalPlaces[j] == 0) {
                snprintf(formattedValue, 32, "%d", (int)roundedAverage);
          } else {
                snprintf(formattedValue, 32, "%f", roundedAverage);
            }               

                char valueText[64];
                snprintf(valueText, 64, "&%s=%s", inputNames[j], formattedValue);
                strcat(outputText, valueText);

                sum[j] = 0;
                count[j] = 0;
            }
        }

        if (strlen(outputText) > 0) {
            setoutputtext(0, outputText);
        }

        startTime = currentTime;
    }

    sleep(100);
}
