/*3. Cricket Scoreboard System"
"Scenario:"
A "cricket club" records match scores in an array.
The system should:
Find the "highest and lowest score"
Calculate the "average score"
Use "arrays" for data storage and "looping techniques" for computation.

"Input Example:"
Enter scores of 5 matches: 245 189 320 270 150
"Output Example:"
Highest Score: 320
Lowest Score: 150
Average Score: 234.8*/

#include <stdio.h>
#define MATCHES 5

void inputdata(int score[MATCHES]) {
    printf("Enter the scores of %d matches: ", MATCHES);
    for (int i = 0; i < MATCHES; i++) {
        scanf("%d", &score[i]);
    }
}

int findHighest(int score[MATCHES]) {
    int highest = score[0];
    for (int i = 1; i < MATCHES; i++) {
        if (score[i] > highest) {
            highest = score[i];
        }
    }
    return highest;
}

int findLowest(int score[MATCHES]) {
    int lowest = score[0];
    for (int i = 1; i < MATCHES; i++) {
        if (score[i] < lowest) {
            lowest = score[i];
        }
    }
    return lowest;
}

float calculateAverage(int score[MATCHES]) {
    int sum = 0;
    for (int i = 0; i < MATCHES; i++) {
        sum += score[i];
    }
    return (float)sum / MATCHES;
}

int main() {
    int scores[MATCHES];

    
    inputdata(scores);

    
    int highest = findHighest(scores);
    int lowest = findLowest(scores);
    float average = calculateAverage(scores);

    
    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.2f\n", average);

    return 0;
}
