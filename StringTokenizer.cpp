#include <iostream>

#include "StringTokenizer.hpp"

using namespace std;

StringTokenizer::StringTokenizer(string resource) {
	this->token = ',';
	this->currentPos = 0;
	this->lastPos = 0;
	this->resource = resource;
	this->finished = false;
}

StringTokenizer::StringTokenizer(string resource, char token) {
	this->currentPos = 0;
	this->lastPos = 0;
	this->resource = resource;
	this->token = token;
	this->finished = false;
}

StringTokenizer::~StringTokenizer() {}

string StringTokenizer::nextElement() {
	return this->nextElement(this->token);
}

string StringTokenizer::nextElement(char token) {
	if(finished) return string();

	lastPos = currentPos == 0 ? 0 : currentPos + 1;
	currentPos = resource.find_first_of(token, ++currentPos);

	if(currentPos == -1) {
		finished = true;
		return resource.substr(lastPos);
	}
	
	return resource.substr(lastPos, currentPos - lastPos);
}

