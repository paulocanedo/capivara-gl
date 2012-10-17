/* 
 * File:   StringTokenizer.h
 * Author: paulocanedo
 *
 * Created on 8 de Agosto de 2012, 15:15
 */

#ifndef STRINGTOKENIZER_H
#define	STRINGTOKENIZER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <string>

using namespace std;

class StringTokenizer {
	private:
		char token;
		int currentPos;
		int lastPos;
		string resource;
		bool finished;

	public:
		StringTokenizer(string);
		StringTokenizer(string, char);
		~StringTokenizer();

		string nextElement();
		string nextElement(char);
                inline bool isFinished() {return finished;}
};


#ifdef	__cplusplus
}
#endif

#endif	/* STRINGTOKENIZER_H */

