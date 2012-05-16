/**
 * @file error.hpp
 * @author John Sullivan (jsull003 at ucr.edu)
 * @date December 28, 2010
 *
 * @brief Defines a useful error handling macro and function.
 **/

#pragma once

#include <exception>
#include <iostream>

/**
 * @brief Calls @ref error() with the proper file name and line number included
 *        by default.
 *
 * @param e[in] The exception to throw.
 **/
#define ERROR(e) error(e, __FILE__, __LINE__)

/**
 * @brief Prints information on the error to standard error and then throws the
 *        given exception.
 *
 * Example of error output
 * <i>Exception thrown in file "foo.hpp" at line 10. what() returns "foo not
 * properly constructed"</i>
 *
 * @param zerror[in] The exception to throw.
 * @param zfile[in]  The name of the file the error occured.
 * @param zline[in]  The line where the error occured.
 **/
template<class T>
inline void error(T zerror, const char *zfile, int zline)
{
#ifndef ERROR_NOPRINT
    std::cerr << "Exception thrown in file \"" << zfile << "\" at line " << zline << ". what() returns \"" << zerror.what() << "\"" << std::endl;
#endif

    throw zerror;
}
