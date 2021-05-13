//
//  TestHelper.cpp
//
//  Do not modify this file.
//

#include "TestHelper.h"

#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <typeinfo>  // for typeid

using namespace std;

//
//  Capturing output is confusing:
//
//  https://stackoverflow.com/questions/5419356/redirect-stdout-stderr-to-a-string
//
//  There are two different functions with the same name
//    http://www.cplusplus.com/reference/ios/ios/rdbuf/
//    http://www.cplusplus.com/reference/fstream/ofstream/rdbuf/
//

// used to capture output
static std::stringstream capture_stream;
static std::streambuf* ptr_capture_old_puffer = NULL;

// used to format summary
static unsigned int summary_indent     = 0;
static unsigned int summary_max_digits = 0;



void testHelperStartup (const string& name,
                        int compile_marks,
                        int total_marks)
{
	assert(name != "");
	assert(compile_marks <= total_marks);

	//cout << boolalpha;  // print bools as "true" and "false"

	cout << "Running " << name << endl;
	cout << string(name.size() + 8, '~') << endl;
	cout << endl;

	cout << "Compiled and started without crashing" << endl;
	cout << "* Mark: " << compile_marks << " / " << total_marks << endl;
	cout << endl;
}



bool testHelperIsCapturing ()
{
	return ptr_capture_old_puffer != NULL;
}

void testHelperStartCapture ()
{
	assert(!testHelperIsCapturing());

	// process any buffered output
	cout.flush();

	// clear any captured data from before
	capture_stream.str("");

	// begin capturing output data
	ptr_capture_old_puffer = cout.rdbuf(capture_stream.rdbuf());

	assert(testHelperIsCapturing());
}

string testHelperEndCapture ()
{
	assert(testHelperIsCapturing());

	// convert captured output to a string
	string captured_text = capture_stream.str();

	// stop capturing output data
	cout.rdbuf(ptr_capture_old_puffer);
	ptr_capture_old_puffer = NULL;

	// print captured data
	cout << captured_text;

	assert(!testHelperIsCapturing());
	return captured_text;
}



void testHelperPrintSummaryHeader (unsigned int indent,
                                   unsigned int max_digits,
                                   unsigned int didnt_crash_marks)
{
	assert(max_digits >= 1);

	summary_indent     = indent;
	summary_max_digits = max_digits;

	cout << endl;
	cout << endl;
	cout << "Finished tests without crashing" << endl;
	cout << " +" << didnt_crash_marks;
	if(didnt_crash_marks == 1)
		cout << " mark" << endl;
	else
		cout << " marks" << endl;
	cout << endl;

	cout << "Summary:" << endl;
	cout << "--------" << endl;
	cout << endl;

	testHelperPrintSummaryLine("Did not crash", true);
}

void testHelperPrintSummaryLine (const std::string& text,
                                 bool is_correct)
{
	assert(text != "");

	string text_with_colon = text + ": ";
	cout << left << setw(summary_indent) << text_with_colon;
	if(is_correct)
		cout << "Correct";
	else
		cout << "Incorrect";
	cout << endl;
}

void testHelperPrintSummaryLine (const std::string& text,
                                 unsigned int achieved,
                                 unsigned int maximum)
{
	assert(text != "");
	assert(maximum > 0);
	assert(achieved <= maximum);

	string text_with_colon = text + ": ";
	cout << left  << setw(summary_indent    ) << text_with_colon;
	if(achieved == maximum)
		cout << "Correct   (";
	else
		cout << "Incorrect (";
	cout << right << setw(summary_max_digits) << achieved << " / "
	     << right << setw(summary_max_digits) << maximum  << ")" << endl;
}

void testHelperPrintSummaryLine (const std::string& text,
                                 double percentage)
{
	assert(text != "");
	assert(percentage >= 0.0);
	assert(percentage <= 1.0);

	int percentage_as_int = (int)(percentage * 100);
	assert(percentage_as_int >= 0);
	assert(percentage_as_int <= 100);

	string text_with_colon = text + ": ";
	cout << left  << setw(summary_indent) << text_with_colon;
	if(percentage == 1.0)
		cout << "Correct   (";
	else
		cout << "Incorrect (";
	cout << right << setw(3) << percentage_as_int << "%)" << endl;
}

unsigned int testHelperMarkAnyAll (unsigned int correct,
                                   unsigned int maximum)
{
	assert(maximum >= 2);
	assert(correct <= maximum);

	if(correct == maximum)
		return 2;
	else if(correct > 0)
		return 1;
	else
		return 0;
}

void testHelperPrintMark (unsigned int achieved,
                          unsigned int maximum)
{
	assert(maximum >= 1);
	assert(achieved <= maximum);

	cout << endl;
	cout << "Mark: " << achieved << " / " << maximum << endl;
	if(achieved == maximum)
		cout << "*** Perfect! ***" << endl;
	cout << endl;
}

void testHelperWaitForEnter ()
{
	cout << "Press [ENTER] to continue...";
	string dummy;
	getline(cin, dummy);
}
