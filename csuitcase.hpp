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

class CClothes : public CStuff {
protected:
	string name;
public:
	CClothes(string = "");
	virtual ~CClothes();
	virtual string to_string(string) const;
	virtual CClothes * clone() const;
};

class CShoes : public CStuff {
public:
	CShoes();
	virtual string to_string(string) const;
	virtual CShoes * clone() const;
};

class CKnife : public CStuff {
protected:
	int blade;
public:
	CKnife(int = 0);
	virtual string to_string(string) const;
	virtual CKnife * clone() const;
};

class CGPS : public CStuff {
public:
	CGPS();
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
