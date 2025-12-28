#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain: Neural network initialized" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "";
	}
}

Brain::Brain(Brain const &src) {
	std::cout << "Brain: Copying thoughts and memories" << std::endl;
	*this = src;
}

Brain &Brain::operator=(Brain const &rhs) {
	std::cout << "Brain: Transferring consciousness" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain: Neural network shutting down" << std::endl;
}

void Brain::setIdea(int index, std::string const &idea) {
	if (index >= 0 && index < 100) {
		this->ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return this->ideas[index];
	}
	return "";
}
