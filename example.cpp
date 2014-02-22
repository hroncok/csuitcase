/** \file example.cpp
 *  Example usage of CSuitcase. Based on Progtest.
 *  \author Miro Hrončok <miroslav.hroncok@fit.cvut.cz> */

#include <iostream>
#include "csuitcase.hpp"

int main(void) {
	CSuitcase T0;
	T0 . Add ( CKnife ( 7 ) );
	T0 . Add ( CGPS () );
	T0 . Add ( CClothes ( "red T-shirt" ) );
	T0 . Add ( CShoes () );
	cout << T0;
	/*-----------------
	Suitcase
	+-Knife 7 cm
	+-GPS
	+-Clothes (red T-shirt)
	\-Shoes
	-------------------*/
	// T0 . Weight () = 3600, T0 . Count () = 5, T0 . Danger () = false
	cout << T0 . Weight () << endl << T0 . Count ()  << endl <<  T0 . Danger ()  << endl;

	CSuitcase T1;
	T1 . Add ( CKnife ( 5 ) );
	T1 . Add ( CClothes ( "red T-shirt" ) );
	T1 . Add ( CClothes ( "blue jeans" ) );
	T1 . Add ( CShoes () );
	cout << T1;
	/*-----------------
	Suitcase
	+-Knife 5 cm
	+-Clothes (red T-shirt)
	+-Clothes (blue jeans)
	\-Shoes
	-------------------*/
	// T1 . Weight () = 3850, T1 . Count () = 5, T1 . Danger () = false
	cout << T1 . Weight () << endl << T1 . Count ()  << endl <<  T1 . Danger ()  << endl;

	CSuitcase T2;
	T2 . Add ( CKnife ( 8 ) ) . Add ( CClothes ( "white underwear" ) ) . Add ( CShoes () );
	T2 . Add ( CClothes ( "red T-shirt" ) );
	T2 . Add ( CClothes ( "brown jacket" ) );
	T2 . Add ( CShoes () );
	cout << T2;
	/*-----------------
	Suitcase
	+-Knife 8 cm
	+-Clothes (white underwear)
	+-Shoes
	+-Clothes (red T-shirt)
	+-Clothes (brown jacket)
	\-Shoes
	-------------------*/
	// T2 . Weight () = 5100, T2 . Count () = 7, T2 . Danger () = true
	cout << T2 . Weight () << endl << T2 . Count ()  << endl <<  T2 . Danger ()  << endl;

	CSuitcase T3;
	T3 . Add ( CKnife ( 8 ) ) . Add ( CClothes ( "white underwear" ) ) . Add ( CShoes () );
	T3 . Add ( T0 ) . Add ( T1 ) . Add ( T2 );
	cout << T3;
	/*-----------------
	Suitcase
	+-Knife 8 cm
	+-Clothes (white underwear)
	+-Shoes
	+-Suitcase
	| +-Knife 7 cm
	| +-GPS
	| +-Clothes (red T-shirt)
	| \-Shoes
	+-Suitcase
	| +-Knife 5 cm
	| +-Clothes (red T-shirt)
	| +-Clothes (blue jeans)
	| \-Shoes
	\-Suitcase
	  +-Knife 8 cm
	  +-Clothes (white underwear)
	  +-Shoes
	  +-Clothes (red T-shirt)
	  +-Clothes (brown jacket)
	  \-Shoes
	-------------------*/
	// T3 . Weight () = 15900, T3 . Count () = 21, T3 . Danger () = true
	cout << T3 . Weight () << endl << T3 . Count ()  << endl <<  T3 . Danger ()  << endl;

	T3 . Add ( T3 );
	cout << T3;
	/*-----------------
	Suitcase
	+-Knife 8 cm
	+-Clothes (white underwear)
	+-Shoes
	+-Suitcase
	| +-Knife 7 cm
	| +-GPS
	| +-Clothes (red T-shirt)
	| \-Shoes
	+-Suitcase
	| +-Knife 5 cm
	| +-Clothes (red T-shirt)
	| +-Clothes (blue jeans)
	| \-Shoes
	+-Suitcase
	| +-Knife 8 cm
	| +-Clothes (white underwear)
	| +-Shoes
	| +-Clothes (red T-shirt)
	| +-Clothes (brown jacket)
	| \-Shoes
	\-Suitcase
	  +-Knife 8 cm
	  +-Clothes (white underwear)
	  +-Shoes
	  +-Suitcase
	  | +-Knife 7 cm
	  | +-GPS
	  | +-Clothes (red T-shirt)
	  | \-Shoes
	  +-Suitcase
	  | +-Knife 5 cm
	  | +-Clothes (red T-shirt)
	  | +-Clothes (blue jeans)
	  | \-Shoes
	  \-Suitcase
		+-Knife 8 cm
		+-Clothes (white underwear)
		+-Shoes
		+-Clothes (red T-shirt)
		+-Clothes (brown jacket)
		\-Shoes
	-------------------*/
	// T3 . Weight () = 31800, T3 . Count () = 42, T3 . Danger () = true
	cout << T3 . Weight () << endl << T3 . Count ()  << endl <<  T3 . Danger ()  << endl;

	T3 . Add ( T3 );
	cout << T3;
	/*-----------------
	Suitcase
	+-Knife 8 cm
	+-Clothes (white underwear)
	+-Shoes
	+-Suitcase
	| +-Knife 7 cm
	| +-GPS
	| +-Clothes (red T-shirt)
	| \-Shoes
	+-Suitcase
	| +-Knife 5 cm
	| +-Clothes (red T-shirt)
	| +-Clothes (blue jeans)
	| \-Shoes
	+-Suitcase
	| +-Knife 8 cm
	| +-Clothes (white underwear)
	| +-Shoes
	| +-Clothes (red T-shirt)
	| +-Clothes (brown jacket)
	| \-Shoes
	+-Suitcase
	| +-Knife 8 cm
	| +-Clothes (white underwear)
	| +-Shoes
	| +-Suitcase
	| | +-Knife 7 cm
	| | +-GPS
	| | +-Clothes (red T-shirt)
	| | \-Shoes
	| +-Suitcase
	| | +-Knife 5 cm
	| | +-Clothes (red T-shirt)
	| | +-Clothes (blue jeans)
	| | \-Shoes
	| \-Suitcase
	|   +-Knife 8 cm
	|   +-Clothes (white underwear)
	|   +-Shoes
	|   +-Clothes (red T-shirt)
	|   +-Clothes (brown jacket)
	|   \-Shoes
	\-Suitcase
	  +-Knife 8 cm
	  +-Clothes (white underwear)
	  +-Shoes
	  +-Suitcase
	  | +-Knife 7 cm
	  | +-GPS
	  | +-Clothes (red T-shirt)
	  | \-Shoes
	  +-Suitcase
	  | +-Knife 5 cm
	  | +-Clothes (red T-shirt)
	  | +-Clothes (blue jeans)
	  | \-Shoes
	  +-Suitcase
	  | +-Knife 8 cm
	  | +-Clothes (white underwear)
	  | +-Shoes
	  | +-Clothes (red T-shirt)
	  | +-Clothes (brown jacket)
	  | \-Shoes
	  \-Suitcase
		+-Knife 8 cm
		+-Clothes (white underwear)
		+-Shoes
		+-Suitcase
		| +-Knife 7 cm
		| +-GPS
		| +-Clothes (red T-shirt)
		| \-Shoes
		+-Suitcase
		| +-Knife 5 cm
		| +-Clothes (red T-shirt)
		| +-Clothes (blue jeans)
		| \-Shoes
		\-Suitcase
		  +-Knife 8 cm
		  +-Clothes (white underwear)
		  +-Shoes
		  +-Clothes (red T-shirt)
		  +-Clothes (brown jacket)
		  \-Shoes
	-------------------*/
	// T3 . Weight () = 63600, T3 . Count () = 84, T3 . Danger () = true
	cout << T3 . Weight () << endl << T3 . Count ()  << endl <<  T3 . Danger ()  << endl;

	T3 . Add ( CGPS () );
	cout << T3;
	/*-----------------
	Suitcase
	+-Knife 8 cm
	+-Clothes (white underwear)
	+-Shoes
	+-Suitcase
	| +-Knife 7 cm
	| +-GPS
	| +-Clothes (red T-shirt)
	| \-Shoes
	+-Suitcase
	| +-Knife 5 cm
	| +-Clothes (red T-shirt)
	| +-Clothes (blue jeans)
	| \-Shoes
	+-Suitcase
	| +-Knife 8 cm
	| +-Clothes (white underwear)
	| +-Shoes
	| +-Clothes (red T-shirt)
	| +-Clothes (brown jacket)
	| \-Shoes
	+-Suitcase
	| +-Knife 8 cm
	| +-Clothes (white underwear)
	| +-Shoes
	| +-Suitcase
	| | +-Knife 7 cm
	| | +-GPS
	| | +-Clothes (red T-shirt)
	| | \-Shoes
	| +-Suitcase
	| | +-Knife 5 cm
	| | +-Clothes (red T-shirt)
	| | +-Clothes (blue jeans)
	| | \-Shoes
	| \-Suitcase
	|   +-Knife 8 cm
	|   +-Clothes (white underwear)
	|   +-Shoes
	|   +-Clothes (red T-shirt)
	|   +-Clothes (brown jacket)
	|   \-Shoes
	+-Suitcase
	| +-Knife 8 cm
	| +-Clothes (white underwear)
	| +-Shoes
	| +-Suitcase
	| | +-Knife 7 cm
	| | +-GPS
	| | +-Clothes (red T-shirt)
	| | \-Shoes
	| +-Suitcase
	| | +-Knife 5 cm
	| | +-Clothes (red T-shirt)
	| | +-Clothes (blue jeans)
	| | \-Shoes
	| +-Suitcase
	| | +-Knife 8 cm
	| | +-Clothes (white underwear)
	| | +-Shoes
	| | +-Clothes (red T-shirt)
	| | +-Clothes (brown jacket)
	| | \-Shoes
	| \-Suitcase
	|   +-Knife 8 cm
	|   +-Clothes (white underwear)
	|   +-Shoes
	|   +-Suitcase
	|   | +-Knife 7 cm
	|   | +-GPS
	|   | +-Clothes (red T-shirt)
	|   | \-Shoes
	|   +-Suitcase
	|   | +-Knife 5 cm
	|   | +-Clothes (red T-shirt)
	|   | +-Clothes (blue jeans)
	|   | \-Shoes
	|   \-Suitcase
	|     +-Knife 8 cm
	|     +-Clothes (white underwear)
	|     +-Shoes
	|     +-Clothes (red T-shirt)
	|     +-Clothes (brown jacket)
	|     \-Shoes
	\-GPS
	-------------------*/
	// T3 . Weight () = 63850, T3 . Count () = 85, T3 . Danger () = true
	cout << T3 . Weight () << endl << T3 . Count ()  << endl <<  T3 . Danger ()  << endl;
	return 0;
}
