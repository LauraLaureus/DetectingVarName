//
//  main.cpp
//  DetectingVarName
//
//  Created by Laura del Pino Díaz on 13/3/17.
//  Copyright © 2017 Laura del Pino Díaz. All rights reserved.
//

#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <set>

/*
 Find the different variable names in a code source. 
 
 The variable name is defined as string found before a '=' symbol.
 */

int main(int argc, const char * argv[]) {

    if(argc == 0){
        std::cout << "Error: Not enough arguments.Expected 1 parameter a filepath" << std::endl;
        return -1;
    }
    else if (argc > 1) {
        std::cout << "Error: Too much.Expected 1 parameter a filepath" << std::endl;
        return -1;
    }
    else{
        std::cout << "Reading file...\n" << std::endl;
        
        std::ifstream file(argv[0]);
        
        
        if (file.is_open()) {
            std::string line;
            std::regex regularExpression ("*=");
            std::smatch match;
            
            std::set<std::string> varNames;
            
            while (std::getline(file, line)) {
                if(std::regex_match(line, match,regularExpression))
                    varNames.insert(match.str());
            }
        }
        
        
    }
    
    
    return 0;
}
