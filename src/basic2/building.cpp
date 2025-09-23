#include <basic2/building.h>
#include <rock.h>
#include <iostream>

Building::Building(int id, int nb_rocks) : id_(id), rocks_(nb_rocks) {
	std::cout << "Building::Building(" << id 
		<< ") at " << this << std::endl;
	for(unsigned int ir = 0; ir < rocks_.size(); ++ ir) {
		rocks_[ir] = new Rock;
	}
}

Building::Building() : id_(-1) , rocks_(0){ //Construteur par défaut de Building
	std::cout << "Building::Building(), id_ = " 
		<< id_ << " at " << this << std::endl;
}

Building::~Building() {
	std::cout << "Building::~Building(" << id_  
		<< ") at " << this << std::endl;
	for(unsigned int ir = 0; ir < rocks_.size(); ++ ir) {
		delete rocks_[ir];
	}
}

Building::Building(const Building& rhs): id_(rhs.id_), rocks_(rhs.rocks_) { // COPY CONSTRUCTOR
	// ON NE VEUT PAS QUE LE COSNTRUCTEUR PAR COPIE DES ROCKS COPIE L'ADRESSE DES ROCKS DE L'ARRAY RHS, on doit créer un nouvel array
	std::cout << "Building::Building(" << &rhs << ", " << rhs.id_
		<< ") id_ = " << id_ << " at " << this << std::endl;
	delete[] rocks_;
	for (unsigned int i = 0; i < rocks_.size(); i++) {
		rocks_[i] = new Rocks(*rhs.rocks_[i]); //ON APPELLE LE CONSTRUCTEUR PAR COPIE DE ROCKS DONC ON RECUPERE LE CONTENU 
	}
}

Building& Building::operator=(const Building& rhs) { // ASSIGNMENT OPERATOR
	std::cout << "Building::op=(" << &rhs << ", " << rhs.id_ 
		<< "), id_ = " << id_ << " at " << this << std::endl;
	if(this != &rhs) {
		// do what the destructor does: nothing here
		for (unsigned int ir = 0 ; ir<rocks_.size() ; ++ir) {
			delete rocks_[ir];
		}
		// do what the copy constructor does:
		id_ = rhs.id_;
		for (unsigned int ir = 0; ir < rocks.size(); ++ir)
			rocks_[ir] = new Rock (*rhs.rocks_[ir]); //>> Opérateur d'affectation de dyn_array, il faut le définir
	}
	return *this;
}	

Building::Building(const Building&& rhs) : 
}

bool Building::swap_rock(
		Building partner, 
		unsigned int this_index, 
		unsigned int partner_index
) {
	if(this_index < rocks_.size() && partner_index < partner.rocks_.size()) {
		Rock* tmp = rocks_[this_index];
		rocks_[this_index] = partner.rocks_[partner_index];
		partner.rocks_[partner_index] = tmp;
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Building& rhs) {
	out << "|" << &rhs << " - " << rhs.id_ << "|\n";
	for(unsigned int i = 0; i < rhs.rocks_.size(); ++i ) {
		out << "| " << rhs.rocks_[i] << "  | << \n";
	}
	return out;
}

