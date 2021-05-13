//
//  TestHelper.h
//
//  A module containing helper functions for test programs.
//
//  Do not modify this file.
//

#include <cassert>
#include <string>
#include <iostream>
#include <typeinfo>  // for typeid



//
//  testHelperStartup
//
//  Purpose: To print the starting message for the test program.
//  Parameter(s):
//    <1> name: The name for the test program
//    <2> compile_marks: How many marks the student gets for the
//                       program compiling and starting correctly
//    <3> total_marks: The maximum marks for this test program
//  Precondition(s):
//    <1> name != ""
//    <2> compile_marks <= total_marks
//  Returns: N/A
//  Side Effect: The starting message is printed.  This includes
//               the marks for compiling and starting without
//               crashing.
//
void testHelperStartup (const std::string& name,
                        int compile_marks,
                        int total_marks);

//
//  testHelperIsConst
//
//  Purpose: To determine whether the specified variable is a
//           constant.  
//  Parameter(s):
//    <1> v: The variable to test
//  Precondition(s): N/A
//  Returns: Whether v is a constant in the scope that
//           testHelperIsConst is called from.
//  Side Effect: N/A
//  Note: This "function" is really a pair of functions that
//        work together.  The value returned depends on which
//        function is invoked, which depends on the compile-time
//        type information.
//  Note: This function pair uses templates, which are covered
//        in Section 13 of the course.
//
template <typename T>
bool testHelperIsConst (const T& v) { return true; }
template <typename T>
bool testHelperIsConst (T& v) { return false; }

//
//  testHelperConstant
//
//  Purpose: To perform the tests needed to ensure that a
//           constant is defined correctly.  The constant should
//           be defined with the correct type, as const, and
//           with the correct value.
//  Parameter(s):
//    <1> constant_to_test: The constant to test
//    <2> constant_correct: A constant with the correct type and
//                          value
//    <3> constant_name: The constant's name, expressed as a
//                       string
//  Precondition(s):
//    <1> constant_name != ""
//  Returns: Whether the constant was correct.
//  Side Effect: A message indicating whether the constant was
//               correct is printed.  If the constant is
//               incorrect, the message includes why.
//
template <typename TestType, typename CorrectType>
bool testHelperConstant (TestType& constant_to_test,
                         const CorrectType& constant_correct,
                         const std::string& constant_name)
{
	assert(constant_name != "");

	if(typeid(CorrectType) != typeid(constant_to_test))
	{
		std::cout << "* Incorrect: " << constant_name << " has incorrect type" << std::endl;
		return false;
	}
	else if(!testHelperIsConst(constant_to_test))
	{
		std::cout << "* Incorrect: " << constant_name << " is not const" << std::endl;
		return false;
	}
	else if(constant_to_test != constant_correct)
	{
		std::cout << "* Incorrect: " << constant_name << " has incorrect value, should be " << constant_correct << std::endl;
		return false;
	}
	else
	{
		std::cout << "* Correct" << std::endl;
		return true;
	}
}

//
//  testHelperIsCapturingStandardOutput
//
//  Purpose: To determine if the TestHelper module is capturing
//           data from standard output (cout).
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether output is being captured.
//  Side Effect: N/A
//
bool testHelperIsCapturing ();

//
//  testHelperStartCapture
//
//  Purpose: To begin capturing standard output (cout).  Until
//           testHelperEndCapture is called, all standard
//           output will be stored instead of printed.
//  Parameter(s): N/A
//  Precondition(s):
//    <1> !testHelperIsCapturing()
//  Returns: N/A
//  Side Effect: Any existing captured output is discarded.  The
//               output buffer is flushed.  Then TestHelper
//               module begins to capture all data printed to
//               standard output.
//
void testHelperStartCapture ();

//
//  testHelperEndCapture
//
//  Purpose: To stop capturing standard output (cout).
//  Parameter(s): N/A
//  Precondition(s):
//    <1> testHelperIsCapturing()
//  Returns: The captured output, as a string.
//  Side Effect: The TestHelper module stops capturing data from
//               standard output.  All data captured since
//               testHelperStartCapture was called is printed.
//
std::string testHelperEndCapture ();

//
//  testHelperPrintSummaryHeader
//
//  Purpose: To print the header text for the summary.
//  Parameter(s):
//    <1> indent: How far to indent the results in the summary
//    <2> max_digits: The maximum number of digits in a number
//    <3> didnt_crash_marks: How many marks the student gets for
//                           the program not crashing during the
//                           tests
//  Precondition(s):
//    <1> max_digits >= 1
//  Returns: N/A
//  Side Effect: The header for the summary test is printed.
//               Summary lines printed after this will be
//               indented so that the results begin indent
//               characters to the right.  Numbers will be
//               right-aligned as if they contain a maximum of
//               max_digits digits.
//
void testHelperPrintSummaryHeader (
                                unsigned int indent,
                                unsigned int max_digits,
                                unsigned int didnt_crash_marks);

//
//  testHelperPrintSummaryLine
//
//  Purpose: To print a true/false line for the summary.
//  Parameter(s):
//    <1> text: The description for the line
//    <2> is_correct: Whether the student program produced the
//                    correct output
//  Precondition(s):
//    <1> text != ""
//  Returns: N/A
//  Side Effect: A summary line is printed with description
//               text, followed by "true" or "false", depending
//               on is_correct.
//
void testHelperPrintSummaryLine (const std::string& text,
                                 bool is_correct);

//
//  testHelperPrintSummaryLine
//
//  Purpose: To print a fraction line for the summary.
//  Parameter(s):
//    <1> text: The description for the line
//    <2> achieved: The number of cases correct
//    <3> maximum: The total number of cases
//  Precondition(s):
//    <1> text != ""
//    <2> maximum > 0
//    <3> achieved <= maximum
//  Returns: N/A
//  Side Effect: A summary line is printed with description
//               text, followed by achieved and maximum
//               formatted as a fraction.
//
void testHelperPrintSummaryLine (const std::string& text,
                                 unsigned int achieved,
                                 unsigned int maximum);

//
//  testHelperPrintSummaryLine
//
//  Purpose: To print a percentage line for the summary.
//  Parameter(s):
//    <1> text: The description for the line
//    <2> percentage: The percentage of cases correct
//  Precondition(s):
//    <1> text != ""
//    <2> percentage >= 0.0
//    <3> percentage <= 1.0
//  Returns: N/A
//  Side Effect: A summary line is printed with description
//               text, followed by percentage formatted as a
//               percentage.
//
void testHelperPrintSummaryLine (const std::string& text,
                                 double percentage);

//
//  testHelperMarkAnyAll
//
//  Purpose: To calculate the student mark for a question where
//           there is 1 mark for ever getting the right answer
//           and a second for always getting it.
//  Parameter(s):
//    <1> correct: The number of correct answers
//    <2> maximum: The total number of answers
//  Precondition(s):
//    <1> maximum >= 2
//    <2> correct <= maximum
//  Returns: The student mark.  This will be 0, 1, or 2.
//  Side Effect: N/A
//
unsigned int testHelperMarkAnyAll (unsigned int correct,
                                   unsigned int maximum);

//
//  testHelperPrintMark
//
//  Purpose: To print the student mark for this test program.
//  Parameter(s):
//    <1> achieved: The student mark
//    <2> maximum: The maximum mark
//  Precondition(s):
//    <1> maximum > 0
//    <2> achieved <= maximum
//  Returns: N/A
//  Side Effect: The student mark is printed.  If the student
//               achieved a perfect score, an additional message
//               is printed to show this.
//
void testHelperPrintMark (unsigned int achieved,
                          unsigned int maximum);

//
//  testHelperWaitForEnter
//
//  Purpose: To wait for the user to press [ENTER].
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: A message instructing the user to press [ENTER]
//               is printed.  Then the program wait until the
//               user does so.
//
void testHelperWaitForEnter ();


