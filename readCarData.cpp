#include <iostream>
#include <fstream>
using namespace std;
// This file is ONLY an example of how to load a struct from a file



// struct for car variables
struct Car{
    enum {MAX_CHAR_LEN = 100};
    char name[MAX_CHAR_LEN];
    double MPG;
    int Cylinders;
    double Displacement;
    double Horsepower;
    double Weight;
    double Acceleration;
    int Model;
    char Origin[100];
    bool ValidEntry;
    Car();
    
};


const int MAX_CARS = 500;
// Reads the cars from the file
Car readcar(ifstream &inFile){
    Car car; 
    inFile.get(car.name, Car::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> car.MPG;
    inFile.ignore(100,';');
    inFile >> car.Cylinders;
    inFile.ignore(100,';');
    inFile >> car.Displacement;
    inFile.ignore(100,';');
    inFile >> car.Horsepower;
    inFile.ignore(100,';');
    inFile >> car.Weight;
    inFile.ignore(100,';');
    inFile >> car.Acceleration;
    inFile.ignore(100,';');
    inFile >> car.Model;
    inFile.ignore(100,';');
    inFile >> car.Origin;
    inFile.ignore(100,'\n');
    // If we reached the end of the file while reading, then the entry is not valid
    car.ValidEntry = !inFile.eof();
    return car;
}

//default constructor for Car
Car::Car(){
for(int index = 0; index < MAX_CHAR_LEN; index ++){
name[index] = '\0';
Origin[index] = '\0';
}
MPG = 0;
Cylinders = 0;
Displacement = 0;
Horsepower = 0;
Weight = 0;
Acceleration = 0;
Model = 0;
ValidEntry = false;
}

// reads every car in file
int readCars(Car cars[]) {
    ifstream carFile("cars.txt");
    int numCars = 0;
    while(carFile.peek() != EOF && numCars < MAX_CARS) {
        cars[numCars] = readcar(carFile);
        numCars++;
    }
    return numCars;
}






// Validates the integer values entered by the user are actually integers
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

// Validates the double values entered by the user are actually doubles
double readDouble(const char prompt[]){
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
// adds car
void AddCar(Car NewCar[])
{

  for(int index = 0; index < MAX_CARS; index ++)
  {
   
    if(NewCar[index].ValidEntry == false){
  
      cout << "Car Name: " << endl;
      
      cin.getline(NewCar[index].name, MAX_CARS);
      NewCar[index].MPG = readDouble("Enter the MPG: ");
      NewCar[index].Cylinders = readInt("Enter the Cylinders: ");
      NewCar[index].Displacement = readDouble("Enter the Displacement: ");
      NewCar[index].Horsepower = readDouble("Enter the Horsepower: ");
      NewCar[index].Weight = readDouble("Enter the Weight(Lb): ");
      NewCar[index].Acceleration = readDouble("Enter the Acceleration: ");
      NewCar[index].Model = readInt("Enter the Model: ");
      cout << "Enter the Origin: ";
      cin >> NewCar[index].Origin;
      cin.ignore(100,'\n');
      
      NewCar[index].ValidEntry = true;
      break;
    }
  }
}




// removes cars
void removeCar(Car car[MAX_CARS])
{
  int deleteNum = -1;
  while (deleteNum < 0 || deleteNum > 500){
    deleteNum = readInt("Enter Index of Car To Delete: ");
    car[deleteNum].ValidEntry = false;
  }
}

// prints the data from a single car
void printCar(Car car)
{
cout << car.name << ';' << car.MPG << ';' << car.Cylinders << ';' << car.Displacement << ';' << car.Horsepower << ';' << car.Weight << ';' << car.Acceleration << ';' << car. Model << ';' << car.ValidEntry << ';' << car.Origin << ';';
}
// prints all the cars that belong to a specific origin
void PrintCarsByOrigin(Car car[])
{
  string CarOrigin = "";
  cout << "Enter Car Origin: ";
  cin >> CarOrigin;
  for(int index = 0; index < MAX_CARS; index ++){
    if (car[index].Origin == CarOrigin){
      cout << "index" << index << ": ";
      printCar(car[index]);
      cout << endl;
    }

  }
}
// prints all cars 
void printCars(Car car[])
{
  for(int index = 0; index < MAX_CARS; index ++)
  {
   Car onecar = car[index];
    if(onecar.ValidEntry == true){
      cout << "index" << index << ": ";
      printCar(car[index]);
      cout << endl;
    }
  }
}
// main function with the display menu
int main() {
    Car cars[MAX_CARS]; 
    int num = readCars(cars);
    cout << "Cars: " << num << endl;
    
    int indX = 0;
    while (indX != -1){
      cout << "\n";
      cout << "Enter 1 to display the car list" << endl;
      cout << "Enter 2 to add a car to the list" << endl;
      cout << "Enter 3 to display cars by origin" << endl;
      cout << "Enter 4 to Remove a car from the list" << endl;
      cout << "Enter -1 to Exit" << endl;
      indX = readInt("What would you like to do: ");
     
      cin.ignore(100,'\n');
    
      if(indX == 4){
        removeCar(cars);
      }
      else if(indX == 2){
        AddCar(cars);
      }
      else if(indX == 3){
        PrintCarsByOrigin(cars);
      }
      else if(indX == -1){
        break;
      }
      else if(indX == 1){
        printCars(cars);
      }
      else{
        cout << "Invalid Command";
      }
      
      }
  
    return 0;
}
