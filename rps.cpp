#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

std::string Input;

int userInput()
{
	std::cout << "Rock[r], Paper[p] or Scissors[s]?" << '\n' << '\n';
	std::cin >> Input;

	std::transform(Input.begin(), Input.end(), Input.begin(), ::tolower);
	if (Input == "rock" || Input == "r") return 0;
	if (Input == "paper" || Input == "p") return 1;
	if (Input == "scissors" || Input == "s") return 2;
	return -1;
}

std::string choice(int pick)
{
	switch (pick)
	{
		case 0: return "Rock";
		case 1: return "Paper";
		case 2: return "Scissors";
		default: return "Invalid";
	}
}

void determine(int user, int computer)
{
	if (user == computer) std::cout << "Tie!" << '\n';
	else if ((user == 0 && computer == 2) || (user == 1 && computer == 0) || (user == 2 && computer == 1))
		std::cout << "You Win" << '\n';
	else
		std::cout << "You Lose" << '\n';
}

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int	userChoice = userInput();
	int compChoice = std::rand() % 3;

	if (userChoice < 0)
	{
		std::cout << "Invalid Input" << '\n'; return 1;
	}
	std::cout << "You chose: " << choice(userChoice) << '\n';
	std::cout << "Computer chose: " << choice(compChoice) << '\n';
	determine(userChoice, compChoice);
	return (0);
}