#include <iostream>
#include <cstring>
#include <sstream>


int main() {
	int matrix_1[3][3], matrix_2[3][3], res[3][3];
	bool failure = false;
	char ch;

	for (int i = 0; i < 3; i++) {
		for (std::string string; std::getline(std::cin, string); ) {
			std::istringstream stream(string);

			for (int j = 0; j < 3; j++) {
				if (!(stream >> matrix_1[i][j])) {
					failure = true;
					break;
				}
			}
			break;
		}
	}

	if (failure) {	
		std::cout << "An error has occured while reading numbers from line" << std::endl;
		return 0;
	}

	std::cin >> ch;

	if ((ch != '+') && (ch != '-') && (ch != '*')) {
		std::cout << "An error has occured while reading numbers from line" << std::endl;
		return 0;
	}

	std::cin.ignore();

	for (int i = 0; i < 3; i++) {
		for (std::string string; std::getline(std::cin, string); ) {
			std::istringstream stream(string);

			for (int j = 0; j < 3; j++) {
				if (!(stream >> matrix_2[i][j])) {
					failure = true;
					break;
				}
			}
			break;
		}
	}


	if (!failure) {
		switch (ch) {

		case '+': {
			std::cout << std::endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					res[i][j] = matrix_1[i][j] + matrix_2[i][j];
					std::cout << res[i][j] << ' ';
				}
				std::cout << std::endl;
			}
			
			break;
		}


		case '-': {
			std::cout << std::endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					res[i][j] = matrix_1[i][j] - matrix_2[i][j];
					std::cout << res[i][j] << ' ';
				}
				std::cout << std::endl;
			}
			
			break;
		}

		case '*': {
			std::cout << std::endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					res[i][j] = 0;
					for (int k = 0; k < 3; k++)
						res[i][j] += matrix_1[i][k] * matrix_2[k][j];
					
					std::cout << res[i][j] << " ";
					}
				std::cout << std::endl;
				}
			
			break; 
			}
		}

	}

	else {
		std::cout << "An error has occured while reading numbers from line" << std::endl;
	}

	return 0;
}
