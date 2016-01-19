#ifndef JASMINE_INSTRUCTION_H
#define JASMINE_INSTRUCTION_H

#include "jobject.h"

#include <array>

using namespace std;

class Instruction : public JObject{
	public:

		Instruction();
		
		virtual ~Instruction();
		 
		 
		 
	protected:
		u1 opcode;
		
		// oprand list
};

#endif // INSTRUCTION_H
