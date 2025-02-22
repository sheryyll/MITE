/*1. Movie Recommendation System (Sorting by Rating) 
`Scenario:`  
A `movie streaming platform` sorts and suggests movies based on user ratings. The system should:  
- Sort `movies based on ratings` (descending)  
- Allow `linear search` for a movie by name  
- Display `the top 3 movies`  

`Operations Example:`  
Movies: 
[{"Title": "Movie A", "Rating": 8.5}, 
 {"Title": "Movie B", "Rating": 9.2}, 
 {"Title": "Movie C", "Rating": 7.8}]

Sorted by Rating: Movie B (9.2), Movie A (8.5), Movie C (7.8)
Search 'Movie A': Found (Rating: 8.5)*/
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100

typedef struct {
    char title[50];
    float rating;
} Movie;


void sortMovies(Movie movies[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}


int searchMovie(Movie movies[], int n, char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(movies[i].title, name) == 0) {
            return i; 
        }
    }
    return -1; 
}


void displayTopMovies(Movie movies[], int n) {
    printf("Top 3 Movies:\n");
    for (int i = 0; i < n && i < 3; i++) {
        printf("%s (%.1f)\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES] = {
        {"Movie A", 8.5},
        {"Movie B", 9.2},
        {"Movie C", 7.8},
        {"Movie D", 9.0},
        {"Movie E", 6.5}
    };
    int n = 5;
    
    sortMovies(movies, n);
    
    printf("Movies sorted by rating:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (%.1f)\n", movies[i].title, movies[i].rating);
    }
    
    displayTopMovies(movies, n);
    
    char searchTitle[50];
    printf("\nEnter movie name to search: ");
    scanf("%49s", searchTitle);
    
    int index = searchMovie(movies, n, searchTitle);
    if (index != -1) {
        printf("Found: %s (Rating: %.1f)\n", movies[index].title, movies[index].rating);
    } else {
        printf("Movie not found.\n");
    }
    
    return 0;
}