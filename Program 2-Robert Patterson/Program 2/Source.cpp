// Robert Patterson 
// CS 201-002

#include <iostream>
#include <cmath>
using namespace std;

//Set method for total area
float calculateTotalArea(int numberOfWalls, float length, float width, int sides) {
	//return calc
	return (length * width) * numberOfWalls * sides; 
	// both is twice either interior or exterior
}
//Method setting num of cans
int calculateNumberOfCans(float totalArea) {
	float areaPerCan = 400;
	//return calc
	return (int)ceil(totalArea / areaPerCan);
	// ceil for rounding off to nearest integer
}
//Method for interior cost
float costOfPaintingInterior(int numberOfCans) {
	float priceOfCan = 100;
	return numberOfCans * priceOfCan;
}
//Method for exterior
float costOfPaintingExterior(int numberOfCans) {
	float priceOfCan = 150;
	return numberOfCans * priceOfCan;
}
//Method for both
float costOfPaintingBothSides(int numberOfCans) {
	return costOfPaintingInterior(numberOfCans) + costOfPaintingExterior(numberOfCans);
}

//Main Program
int main() {
	//Variables
	int choice, sides, walls, cans;
	float length, width, total_area, cost;

	//Main Menu
	cout << endl << "WELCOME TO PAINTING HELPER APP";
	cout << endl << "1 - Paint only Interior";
	cout << endl << "2 - Paint only Exterior";
	cout << endl << "3 - Paint Both sides" << endl;
	cin >> choice;
	//Viable options
	switch (choice) {
	case 1:
		sides = 1;
		cout << endl << "Enter number of walls: ";
		//Ask for num of walls
		cin >> walls;
		cout << endl << "Enter length of a wall [feet]: ";
		//Ask for length
		cin >> length;
		cout << endl << "Enter width of a wall [feet]: ";
		//Ask for width
		cin >> width;
		//Set variable to method
		total_area = calculateTotalArea(walls, length, width, sides);
		cout << endl << "Total area to be painted: " << total_area << " sq. ft";
		cans = calculateNumberOfCans(total_area);
		cout << endl << "Total number of cans needed: " << cans;
		cost = costOfPaintingInterior(cans);
		cout << endl << "Total cost for painting: $" << cost;


		break;
		//Repeat for exterior
	case 2:
		sides = 1;
		cout << endl << "Enter number of walls: "; cin >> walls;
		cout << endl << "Enter length of a wall [feet]: "; cin >> length;
		cout << endl << "Enter width of a wall [feet]: "; cin >> width;
		total_area = calculateTotalArea(walls, length, width, sides);
		cout << endl << "Total area to be painted: " << total_area << " sq. ft";
		cans = calculateNumberOfCans(total_area);
		cout << endl << "Total number of cans needed: " << cans;
		cost = costOfPaintingExterior(cans);
		cout << endl << "Total cost for painting: $" << cost;

		break;
		//Repeat for both 
	case 3:
		sides = 2;
		cout << endl << "Enter number of walls: "; cin >> walls;
		cout << endl << "Enter length of a wall [feet]: "; cin >> length;
		cout << endl << "Enter width of a wall [feet]: "; cin >> width;
		total_area = calculateTotalArea(walls, length, width, sides);
		cout << endl << "Total area to be painted: " << total_area << " sq. ft";
		cans = calculateNumberOfCans(total_area);
		cout << endl << "Total number of cans needed: " << cans;
		cost = costOfPaintingBothSides(cans);
		cout << endl << "Total cost for painting: $" << cost;

		break;
		//Set default for unknown input
	default:
		cout << endl << "Unknown input";
		exit(0);
		break;
	}


	return 0;
}
