#ifndef building_h
#define building_h

#include <iostream>
#include <dyn_array.h>

class Rock; // Forward declaration: Rock is a type, defined elsewhere

class Building {
	public:
		/*!
		 * Creates a Building with identifier and a number of 
		 * rocks in its collection
		 */
		Building(int id, int nb_rocks);
		Building();
		Building(const Building& rhs); // CONSTRUCTEUR PAR COPIE
		Building& operator=(const Building& rhs); // ASSIGNMENT OPERATOR
		Building(const Building&& rhs): rocks_(rhs.rocks_.size()) //CONSTRUCTEUR DE MOVE
		~Building();

		const Rock* get_rock(int index) const;
		bool swap_rock(
				Building partner, 
				unsigned int this_index, 
				unsigned int partner_index
		);
	private:
		friend std::ostream& operator<<(std::ostream& out, const Building& rhs);
		int id_;
		DynArray<Rock*> rocks_;
};

#endif 

