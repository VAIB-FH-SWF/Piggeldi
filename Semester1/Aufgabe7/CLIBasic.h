/* 
 * File:   CLI.h
 * Author: fredde
 *
 * Created on 10. Oktober 2015, 21:46
 */

#ifndef CLI_H
#define	CLI_H

#include <string>

class CLIBasic
{
public:
    /**
     * Defaultkonstrukor des CLI
     */
    CLIBasic();
    /**
     * Liest eine integer Zahl ein
     * @return int
     */
    int leseIntegerZahl();
    /**
     * Liest eine gleitkomma Zahl ein (double)
     * @return double
     */
    double leseGleitkommaZahl();
    /**
     * Liest einen Text ein (std::string)
     * @return string
     */
    std::string leseText();

    virtual ~CLIBasic();
private:



};

#endif	/* CLI_H */

