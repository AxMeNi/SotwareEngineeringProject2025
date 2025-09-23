#include <basic2/building.h>
#include <basic2/rock.h>
#include <iostream>

Building::Building( int id, int nb_rocks ) : id_( id ), rocks_( nb_rocks )
{
    std::cout << "Building::Building(" << id << ") at " << this << std::endl;
    for( unsigned int ir = 0; ir < rocks_.size(); ++ir )
    {
        rocks_[ir] = new Rock;
    }
}
Building::~Building()
{
    std::cout << "Building::~Building(" << id_ << ") at " << this << std::endl;
    for( unsigned int ir = 0; ir < rocks_.size(); ++ir )
    {
        delete rocks_[ir];
    }
}

Building& Building::operator=( const Building& rhs )
{
    std::cout << "Building::op=(" << &rhs << ", " << rhs.id_
              << "), id_ = " << id_ << " at " << this << std::endl;
    if( this != &rhs )
    {
        // do what the destructor does: nothing here
        // do what the copy constructor does:
        id_ = rhs.id_;
    }
    return *this;
}

bool Building::swap_rock(
    Building partner, unsigned int this_index, unsigned int partner_index )
{
    if( this_index < rocks_.size() && partner_index < partner.rocks_.size() )
    {
        Rock* tmp = rocks_[this_index];
        rocks_[this_index] = partner.rocks_[partner_index];
        partner.rocks_[partner_index] = tmp;
        return true;
    }
    return false;
}

std::ostream& operator<<( std::ostream& out, const Building& rhs )
{
    out << "|" << &rhs << " - " << rhs.id_ << "|\n";
    for( unsigned int i = 0; i < rhs.rocks_.size(); ++i )
    {
        out << "| " << rhs.rocks_[i] << "  | << \n";
    }
    return out;
}
