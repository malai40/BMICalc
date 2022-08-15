#include<iostream>

// Compare a cin input with a string
bool isEqualStr1Str2(std::string str1, std::string str2) {
	if (str1.compare(str2) == 0) {
		return true;
	}
	
	return false;
}

// Compare a cin input with a list of strings
// Return true if cin input matches anything in the list
bool isStrInList(std::string str, std::string list[], int sizeOfList) {
	int i;
	//int listSize = sizeof(list) / sizeof(std::string);
	for (i = 0; i < sizeOfList; i++) {
		if (isEqualStr1Str2(str, list[i])) {
			return true;
		}
	}

	return false;
}

// Get Metric or Imperial mode from user
int getMeasurementMode() {
	
	std::string metricAns [] = {"metric", "m"};
	std::string impAns [] = {"imperial", "i"};
	
	int sizeMetricAns = sizeof(metricAns) / sizeof(std::string);
	int sizeImpAns = sizeof(impAns) / sizeof(std::string);
	
	std::cout << "Metric (cm, kg) or Imperial (in, lb)?\n";
	std::cout << "Type 'metric', 'm', 'imperial', or 'i'\n";
	
	std::string mode;
	int modeInt = -1;
	
	while (modeInt == -1) {
		std::getline (std::cin, mode);
		if (isStrInList(mode, metricAns, sizeMetricAns)) {
			modeInt = 0;
		} else if (isStrInList(mode, impAns, sizeImpAns)) {
			modeInt = 1;
		} else {
			std::cout << "Invalid input, try again.\n";
		}
	}
	return modeInt;
}

// Get sex
int getSex() {
	std::string maleAns [] = {"male", "Male", "m", "M"};
	std::string femaleAns [] = {"female", "Female", "f", "F"};
	
	int sizeMaleAns = sizeof(maleAns) / sizeof(std::string);
	int sizeFemaleAns = sizeof(femaleAns) / sizeof(std::string);
	
	std::cout << "Male or female?\n";
	
	std::string sex;
	int sexInt = -1;
	
	while (sexInt == -1) {
		std::getline (std::cin, sex);
		if (isStrInList(sex, maleAns, sizeMaleAns)) {
			sexInt = 0;
		} else if (isStrInList(sex, femaleAns, sizeFemaleAns)) {
			sexInt = 1;
		} else {
			std::cout << "Invalid input, try again.\n";
		}
	}
	return sexInt;
}

// Get age
int getAge() {
	std::cout << "Age in years?\n";

	int age;
	int ageInt = -1;

	while (ageInt == -1) {
		try {
			std::cin >> age;
			ageInt = 1;
		} catch (...) {
			std::cout << "Invalid input, try again.\n";
		}
	}

	return age;
}

// Get height (diff dep on mode)
int getHeight(int mode) {
	float height;
	if (mode == 0) {
		//Ask in metric
		std::cout << "Type in height in centimeters.\n";
		std::cin >> height;
	} else {
		//Ask in imperial
		std::cout << "Type in weight in inches.\n";
		std::cin >> height;
	}
	return height;
	
}

// Get weight (diff dep on mode)
int getWeight(int mode) {
	float weight;
	if (mode == 0) {
		//Ask in metric
		std::cout << "Type in weight in kilograms.\n";
		std::cin >> weight;
	} else {
		//Ask in imperial
		std::cout << "Type in weight in pounds.\n";
		std::cin >> weight;
	}
	return weight;
	
}

// Convert imperial weight to metric
float lbToKg(float lbs) {
	return lbs*0.453592;
}

// Convert imperial height to metric
float inToCm(float ins) {
	return ins*2.54;
}

// Convert metric height and weight to BMI
// If mode is 1, use the imperial -> metric conversion helper fns
float getBMI(float kg, float cm, int mode) {
	if (mode == 1) {
		kg = lbToKg(kg);
		cm = inToCm(cm);
	}
	return (kg/((cm/100)*(cm/100)));
}

// Interpret the BMI
// Consider lazily interpreting how much weight to lose or gain as well.
void interpretBMI(float bmi) {
	std::cout << "\nYour BMI is " << bmi << ".\n";
	if (bmi < 18.5) {
		std::cout << "This is in the Underweight range.\n";
	} else if (bmi < 25) {
		std::cout << "This is in the Healthy Weight range.\n";
	} else if (bmi < 30) {
		std::cout << "This is in the Overweight range.\n";
	} else {
		std::cout << "This is in the Obesity range.\n";
	}
}

int main() {
	std::cout << "Welcome to the BMI Calculator.\n";
	
	int mode = getMeasurementMode(); //0 for metric, 1 for imperial
	int sex = getSex(); //0 is male, 1 is female
	int age = getAge();
	float height = getHeight(mode);
	float weight = getWeight(mode);
	
	float bmi = getBMI(weight, height, mode);
	
	interpretBMI(bmi);
}
