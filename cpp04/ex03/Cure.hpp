#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(Cure const &src);
		Cure &operator=(Cure const &rhs);
		~Cure(void);

		AMateria* clone(void) const;
		void use(ICharacter& target);
};

#endif
