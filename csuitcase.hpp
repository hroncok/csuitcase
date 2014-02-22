#ifndef _CSUITCASE_
#define _CSUITCASE_

#include <sstream>
#include <string.h>
using namespace std;

class CStuff {
protected:
	bool danger;
	int weight;
public:
	CStuff();
	virtual ~CStuff() {};
	virtual bool Danger() const;
	virtual int Weight() const;
	virtual int Count() const;
	virtual string to_string(string) const = 0;
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
