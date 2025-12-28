#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

class ICharacter;

class AMateria {
	protected:
		std::string type;

	public:
		AMateria(void);
		AMateria(std::string const &materialType);
		AMateria(AMateria const &src);
		AMateria &operator=(AMateria const &rhs);
		virtual ~AMateria(void);

		std::string const &getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif
