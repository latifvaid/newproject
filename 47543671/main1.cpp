// 
// Author: Prof. Latif Vaid, U. of Illinois Chicago, Fall 2020
// Project 3 P1
// 
// 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
/* make struct called Movies
 * it has int id, int year, srting title since thats what we want to read*/
struct Movies{
    int MovieID, Year;
    string Title;
};
// making readMovies function to read the file and get what needed 
int readMovies(string filename, Movies* movies){
  int i = 0;
  int MovieID, Year;
  string Title, temp;
  ifstream infile(filename);
  if (!infile.good()){
    return -1;
  }
  getline(infile, temp);      //skip first line
  getline(infile, temp);      // gets the second line and prints it/
  cout << "**" << temp << endl;
  while(!infile.eof()){
      infile>> MovieID;
      // getline(infile,filename);
      movies[i].MovieID = MovieID;
      infile>>Year;
      movies[i].Year = Year;
      getline(infile, Title);
      Title = Title.substr(1);  //skip spaces when reading the file
      movies[i].Title = Title;
      i++;

   }
   return i;
}

// printing first and last movie and then sorting by MovieID and by title
void outputMovies(Movies* movies, int N)
{    
        //output
    cout << "**First movie: " << movies[0].MovieID << " " << movies[0].Year << " '" << movies[0].Title << "'" << endl;
    cout << "**Last movie: " << movies[N-1].MovieID << " " << movies[N-1].Year << " '" << movies[N-2].Title << "'" << endl;
    Movies temp;
    for(int i=0; i < N - 1; i++) {		                //sorting by MovieID so we can let lowest to highest
        for(int j=i+1;j < N - 1; j++) {
            if(movies[i].MovieID > movies[j].MovieID) {   // compares MovieID :if it is  greater then second it takes it and puts it in temp variable
                temp  = movies[i];
                movies[i]= movies[j];              
                movies[j]= temp;
            }
        }
    }
      //output after sorting
    cout << "**MOVIES BY ID**" << endl;
    for(int i = 0; i < N - 1; i++){
    cout << movies[i].MovieID;
    cout << " " << movies[i].Year << " '" << movies[i].Title << "'" << endl;
   }
   
    
  for(int i=0; i < N - 1; i++) {		  //sorting by alphabetically 
    for(int j=i+1;j < N - 1; j++) {
        if(movies[i].Title > movies[j].Title) { //checking if movies have greater alphabet if then taking the movie and prints where it belongs
            temp  = movies[i];
            movies[i]= movies[j];
            movies[j]= temp;
            }
        }
    }
       cout << "**MOVIES BY TITLE**" << endl;
    for(int i = 0; i < N - 1; i++){
    cout << movies[i].MovieID;
    cout << " " << movies[i].Year << " '" << movies[i].Title << "'" << endl;
        
   }
    cout << "**Done**" << endl;
}

int main(){                           //main function for opning the files and going through it//
  string filename;
  int N;
  
  cout << "Movies filename> ";        // inputfile name
  cin >> filename;                    //asking filename
  
  Movies* movies;                // array of movies;
  movies = new Movies[1000];
  N = readMovies(filename, movies);
  // if (N < 0)
  // {
  // cout << "*Error: input file '" << filename << "' could not be opened" << endl;
  // delete[] students;
  // return 0;
  // }
  outputMovies(movies, N);
  delete[] movies;
  return 0;
}