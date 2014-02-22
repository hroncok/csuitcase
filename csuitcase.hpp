#ifndef _CSUITCASE_
#define _CSUITCASE_

#include <sstream>
#include <string.h>
using namespace std;

/// Stuff you can put to a suitcase
/** This abstract class represents anything that can be put into a suitcase.
 *  It stores it's weight and information, if the thing is dangerous or not. */
class CStuff {
protected:
	bool danger;
	int weight;
public:
	/// Implicit constructor
	CStuff();
	/// Destructor
	virtual ~CStuff() {};
	/// Gets dangerousness
	/** \return True if the stuff is dangerous */
	virtual bool Danger() const;
	/// Gets weight
	/** \return Weight of the stuff in grams */
	virtual int Weight() const;
	/// Gets the number of stuff in this stuff
	/** Implicitly each stuff is one stuff.
	 *  But sometimes a stuff can contain another stuff.
	 *  \return Number of stuff in this stuff (counting itself as well) */
	virtual int Count() const;
	/// Gets a textual representation of this stuff
	/** For basic stuff, this a one-line text describing the thing.
	 *  If the stuff contains more stuff, it is displayed as a tree. */
	virtual string to_string(string) const = 0;
	/// Cloner
	/** \return Deep copy of the stuff */
	virtual CStuff * clone() const = 0;
};

/// Clothes
class CClothes : public CStuff {
protected:
	string name;
public:
	/// Constructor
	/** \param n Name of the clothes (such as *white underwear*) */
	CClothes(string = "");
	virtual ~CClothes();
	/** \return "Clothes (<name>)" */
	virtual string to_string(string) const;
	virtual CClothes * clone() const;
};

/// Shoes
class CShoes : public CStuff {
public:
	CShoes();
	/** \return "Shoes" */
	virtual string to_string(string) const;
	virtual CShoes * clone() const;
};

/// Knife
/** Knife with a blade of given length.
 *  Blades longer than 7 cm are considered dangerous. */
class CKnife : public CStuff {
protected:
	int blade;
public:
	/// Constructor
	/** \param b Length of the blade in cm */
	CKnife(int = 0);
	/** \return "Knife <length_of_blade> cm" */
	virtual string to_string(string) const;
	virtual CKnife * clone() const;
};

/// GPS navigator
class CGPS : public CStuff {
public:
	CGPS();
	/** \return "GPS" **/
	virtual string to_string(string) const;
	virtual CGPS * clone() const;
};

class CSuitcase : public CStuff {
protected:
	CStuff ** stuff;
	int ds;
	int cs;
	void makeBigger();
public:
	CSuitcase();
	CSuitcase(const CSuitcase &);
	CSuitcase & operator=(const CSuitcase &);
	~CSuitcase();
	virtual int Weight() const;
	virtual bool Danger() const;
	virtual int Count() const;
	CSuitcase & Add(const CStuff &);
	friend ostream &operator<<(ostream &, const CSuitcase &);
	virtual string to_string(string) const;
	virtual CSuitcase * clone() const;
};

#endif
