//
//  degree.h
//  C867 - JYM1 TASK 1 - CLASS ROSTER
//
//  Created by Toni Work on 12/19/22.
//
#ifndef degree_h
#define degree_h

#include <stdio.h>

using namespace std;

//C.  Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.

enum DegreeProgram {
	UNDECLARED,
	SECURITY,
	NETWORK,
	SOFTWARE
};
static const std::string degreeProgramString[] = {
	"UNDERCLARED",
	"SECURITY",
	"NETWORK",
	"SOFTWARE"
};

#endif /* degree_h */
