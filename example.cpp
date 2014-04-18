/** \file example.cpp
 *  Example usage of CSuitcase. Based on Progtest.
 *  \author Miro Hrončok <miroslav.hroncok@fit.cvut.cz> */

#include <iostream>
#include <getopt.h>
#include <cstdlib>
#include "csuitcase.hpp"

void showHelp() {
	cout << "This is example of CSuitCase" << endl << endl;
	cout << "It will create a suitcase and will put stuff you set inside" << endl;
	cout << "By adding command line switches, you can add stuff to the suitcase" << endl << endl;
	cout << "--help            Displays this help end exits" << endl;
	cout << "--clothes <<name>  Adds clothes of given name to the suitcase" << endl;
	cout << "--knife <<blade>   Adds knife of given blade length to the suitcase" << endl;
	cout << "--gps             Adds a GPS navigator to the suitcase" << endl;
	cout << "--shoes          Adds a pair of shoes to the suitcase" << endl;
	cout << "--depth <<value>   Adds a copy of the suitcase to the suitcase <<value> times" << endl;
}

int main(int argc, char **argv) {
	CSuitcase example;
	while (1) {
		static struct option long_options[] = {
			{"help",			no_argument,		0,	'h'},
			{"clothes",			required_argument,	0,	'c'},
			{"knife",			required_argument,	0,	'k'},
			{"gps",				no_argument,		0,	'g'},
			{"shoes",			no_argument,		0,	's'},
			{"depth",			required_argument,	0,	'd'},
			{0, 0, 0, 0}
		};

		// getopt_long stores the option index here
		int option_index = 0;

		int c = getopt_long(argc, argv, "hc:k:gsd:", long_options, &option_index);

		// detect the end of the options
		if (c == -1) {
			break;
		}

		switch (c) {
			case 'h':
				showHelp();
				return 0;

			case 'c':
				example.Add(CClothes(optarg));
				break;

			case 'k':
				example.Add(CKnife(atoi(optarg)));
				break;

			case 'g':
				example.Add(CGPS());
				break;

			case 's':
				example.Add(CShoes());
				break;

			case 'd':
				for (int i = 0; i < atoi(optarg); i++)
					example.Add(example);
				break;

			default:
				showHelp();
				return 1;
		}
	}
	cout << "Weight: "  << example.Weight() << endl;
	cout << "Count: " << example.Count() << endl;
	cout <<  "Danger: " << example.Danger()  << endl;
	cout << example << endl;
	return 0;
}
