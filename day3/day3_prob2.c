/*2. DNA Sequence Pattern Finder"
"Scenario:"
A "biotech lab" is analyzing DNA sequences. Given a "DNA string" (containing only 'A', 'T', 'G', 'C'),
check if a "specific pattern exists in it".

Use "string functions" to "find and count occurrences" of a given pattern.

"Input Example:"
Enter DNA Sequence: ATGCGATCGT
Enter pattern to search: ATG
"Output Example:"
Pattern found 1 time(s) in the DNA sequence.*/

#include <stdio.h>
#include <string.h>


int countPatternOccurrences(char *dna, char *pattern) {
    int count = 0;
    char *ptr = dna;

    while ((ptr = strstr(ptr, pattern)) != NULL) {
        count++;
        ptr++; 
    }

    return count;
}

int main() {
    char dna[100], pattern[20];


    printf("Enter DNA Sequence: ");
    scanf("%s", dna);

    
    printf("Enter pattern to search: ");
    scanf("%s", pattern);

   
    int occurrences = countPatternOccurrences(dna, pattern);

    
    printf("Pattern found %d time(s) in the DNA sequence.\n", occurrences);

    return 0;
}
