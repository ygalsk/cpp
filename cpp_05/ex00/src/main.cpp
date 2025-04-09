/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:02:53 by dkremer           #+#    #+#             */
/*   Updated: 2025/03/07 18:58:10 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::left;

int main() 
{
    cout << "══════════════════════════════════════════" << endl;
    cout << endl;
    cout << RED << "          Bureaucrat Test Results       " << RESET << endl;
    cout << endl << "══════════════════════════════════════════" << endl;
    cout << YELLOW << "          Test 1: Grade too high        " << RESET << endl;
    cout << "──────────────────────────────────────────" << endl;
    try 
    {
        Bureaucrat bob("Bob", 1);
        bob.incrementGrade();
    }
    catch (std::exception &e) 
    {
        cout << RED << "Error: " << e.what() <<RESET << endl;
    }

    cout << "══════════════════════════════════════════" << endl;
    cout << YELLOW << "          Test 2: Grade too low         " << RESET << endl;
    cout << "──────────────────────────────────────────" << endl;
    try 
    {
        Bureaucrat larry("Larry", 150);
        larry.decrementGrade();
    }
    catch (std::exception &e) 
    {
        cout << RED << "Error: " << e.what() << RESET << endl;
    }

    cout << "══════════════════════════════════════════" << endl;
    cout << YELLOW << "          Test 3: increment Grade         " << RESET << endl;
    cout << "──────────────────────────────────────────" << endl;
    try 
    {
        Bureaucrat larry("Jimmy", 150);
        larry.incrementGrade();
    }
    catch (std::exception &e) 
    {
        cout << RED << "Error: " << e.what() <<RESET << endl;
    }
    
    cout << "══════════════════════════════════════════" << endl;
    cout << YELLOW << "          Test 4: decrement Grade         " << RESET << endl;
    cout << "──────────────────────────────────────────" << endl;
    try 
    {
        Bureaucrat larry("Manny", 1);
        larry.decrementGrade();
    }
    catch (std::exception &e) 
    {
        cout << RED << "Error: " << e.what() <<RESET << endl;
    }
    
    cout << "══════════════════════════════════════════" << endl;
    
    return 0;
}