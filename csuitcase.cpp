/** \file csuitcase.cpp
 *  Implementation of CSuitcase classes.
 *  \author Miro Hrončok <miroslav.hroncok@fit.cvut.cz> */

#include <iostream>
#include "csuitcase.hpp"

CStuff::CStuff() {
	danger = false;
}

bool CStuff::Danger() const {
	return danger;
}

int CStuff::Weight() const {
	return weight;
}

int CStuff::Count() const {
	return 1;
}

CClothes::CClothes(string n) {
	name = n;
	weight = 500;
}

CClothes::~CClothes() {
	name.clear();
}

string CClothes::to_string(string pre) const {
	stringstream ss;
	ss << pre << "Clothes (" << name << ")";
	return ss.str();
}

CClothes * CClothes::clone() const {
	return new CClothes(*this);
}

CShoes::CShoes() {
	weight = 750;
}

string CShoes::to_string(string pre) const {
	stringstream ss;
	ss << pre << "Shoes";
	return ss.str();
}

CShoes * CShoes::clone() const {
	return new CShoes(*this);
}

CKnife::CKnife(int b) {
	blade = b;
	if (b > 7)
		danger = true;
	weight = 100;
}

string CKnife::to_string(string pre) const {
	stringstream ss;
	ss << pre << "Knife " << blade << " cm";
	return ss.str();
}

CKnife * CKnife::clone() const {
	return new CKnife(*this);
}

CGPS::CGPS() {
	weight = 250;
}

string CGPS::to_string(string pre) const {
	stringstream ss;
	ss << pre << "GPS";
	return ss.str();
}

CGPS * CGPS::clone() const {
	return new CGPS(*this);
}

CSuitcase::CSuitcase() {
	ds = 8;
	cs = 0;
	stuff = new CStuff * [ds];
}

CSuitcase::CSuitcase(const CSuitcase &x) {
	ds = x.ds;
	cs = x.cs;
	stuff = new CStuff * [ds];
	for (int i = 0; i < cs; i++)
		stuff[i] = x.stuff[i]->clone();
}

CSuitcase & CSuitcase::operator=(const CSuitcase &x) {
	if (this == &x)
		return *this;
	for (int i = 0; i < cs; i++)
		delete stuff[i];
	delete [] stuff;
	ds = x.ds;
	cs = x.cs;
	stuff = new CStuff * [ds];
	for (int i = 0; i < cs; i++)
		stuff[i] = x.stuff[i]->clone();
	return *this;
}

CSuitcase::~CSuitcase() {
	for (int i = 0; i < cs; i++)
		delete stuff[i];
	delete [] stuff;
}

int CSuitcase::Weight() const {
	int w = 2000;
	for (int i = 0; i < cs; i++)
		w += stuff[i]->Weight();
	return w;
}

bool CSuitcase::Danger() const {
	for (int i = 0; i < cs; i++)
		if (stuff[i]->Danger())
			return true;
	return false;
}

int CSuitcase::Count() const {
	int c = 1;
	for (int i = 0; i < cs; i++)
		c += stuff[i]->Count();
	return c;
}

CSuitcase & CSuitcase::Add(const CStuff &x) {
	if (cs == ds)
		makeBigger();
	CStuff * n = x.clone();
	stuff[cs++] = n;
	return *this;
}

void CSuitcase::makeBigger() {
	CStuff ** stuff2 = new CStuff * [ds*2];
	for (int i = 0; i < ds; i++)
		stuff2[i] = stuff[i];
	ds *= 2;
	delete [] stuff;
	stuff = stuff2;
	stuff2 = NULL; // megatrik
}

ostream &operator<<(ostream &out, const CSuitcase &x) {
	out << x.to_string("") << endl;
	return out;
}

CSuitcase * CSuitcase::clone() const {
	return new CSuitcase(*this);
}

string CSuitcase::to_string(string pre) const {
	stringstream ss;
	ss << pre << "Suitcase" << endl;
	for (size_t i = 0; i < pre.size(); i++) {
		if (pre[i] == '+')
			pre[i] = '|';
		if (pre[i] == '-')
			pre[i] = ' ';
		if (pre[i] == '\\')
			pre[i] = ' ';
	}
	for (int i = 0; i < (cs-1); i++)
		ss << stuff[i]->to_string(pre+"+-") << endl;
	if (cs > 0)
		ss << stuff[cs-1]->to_string(pre+"\\-");
	return ss.str();
}
