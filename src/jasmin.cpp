// jasmin.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "classloader.h"
#include "deassembler.h"
#include "htmlformator.h"

#ifndef _NO_NAMESPACE_
using namespace std;
#endif


int jasmineMain(int argc, char* argv[]);

void deasm(const char* className, const char* htmlFilename);

void classDump(const char* origClass, const char* newClass);

extern void testToolkit();

int main(int argc, char* argv[]) {
  return jasmineMain(argc, argv);
  //testToolkit();
}

void printUsage()
{
    cout << "jasmin classname htmlfilename" << endl;
}


int jasmineMain(int argc, char* argv[])
{
	if(argc <= 3) {
		printUsage();
		return 1;
	}
	
	const char* cmd = argv[1];
	if(strcmp(cmd, "-asm") == 0) {
		//Deasm
		deasm(argv[2], argv[3]);
	}
	else if(strcmp(cmd, "-dump") == 0) {
		classDump(argv[2], argv[3]);
	}

	getchar();
	return 0;
}


void classDump(const char* origClass, const char* newClass) {
	ClassLoader*loader = new ClassLoader();
	JClass* javaClass = loader->loadClass(origClass);
	if( (javaClass != (JClass*)0) && (javaClass->isValid())) {
		JBuffer buffer;
		UINT classFileLength = javaClass->serialize(&buffer);
		FILE* newclass;
		newclass = fopen(newClass, "w+b");
		if(newclass) {
			fwrite((const u1*)(buffer.getBuffer()), sizeof(u1), classFileLength, newclass);
			fclose(newclass);
			cout << "Completed, press any key to continue...";
		}
		else {
			cout << "Cant create new class file!" << endl;
		}
	}
	
	else {
		cout << "Invalid Java class!" <<endl;
	}

	delete javaClass;
	delete loader;
}


void deasm(const char* className, const char* htmlFilename) {
	ClassLoader*loader = new ClassLoader();
	JClass* javaClass = loader->loadClass(className);
	if( (javaClass != (JClass*)0) && (javaClass->isValid())) {
		Deassembler* dump = new Deassembler(javaClass);
        HtmlFormator format;
        JFont keywordFont;
        JColor keywordColor;
		keywordColor.setBlue(128);
		keywordFont.setFontColor(keywordColor);
		format.setFont(keywordFont, HtmlFormator::KEYWORD);
		dump->setFormator(&format);
		dump->dump();
		FILE* fp = fopen(htmlFilename, "w");
		if(fp) {
			const char* htmlString = format.getHtmlString();
			fwrite(htmlString, strlen(htmlString), 1, fp);
		}
		fclose(fp);
		delete dump;
		cout << "Dump over, press any key to continue..." << endl;
	}

	else {
		cout << "Invalid Java class!" <<endl;
	}

	delete javaClass;
	delete loader;
}
