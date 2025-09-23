#ifndef building_h
#define building_h

#include <iostream>
#include <basic2/dyn_array.h>

class Rock; // Forward declaration: Rock is a type, defined elsewhere

class Building
{
public:
    /*!
     * Creates a Building with identifier and a number of
     * rocks in its collection
     */
    Building( int id, int nb_rocks );
    Building() : id_( -1 )
    {
        std::cout << "Building::Building(), id_ = " << id_ << " at " << this
                  << std::endl;
    }
    Building( const Building& rhs ) : id_( rhs.id_ )
    {
        std::cout << "Building::Building(" << &rhs << ", " << rhs.id_
                  << ") id_ = " << id_ << " at " << this << std::endl;
    }
    Building& operator=( const Building& rhs );
    ~Building();

    //const Rock* get_rock( int index ) const;
    bool swap_rock(
        Building partner, unsigned int this_index, unsigned int partner_index );

private:
    friend std::ostream& operator<<( std::ostream& out, const Building& rhs );
    int id_;
    DynArray< Rock* > rocks_;
};

#endif 

