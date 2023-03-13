//
// Created by vulko on 2023/3/13.
//

#include "CApplication.h"
#include "CLogInit.h"

#ifdef _WIN32
#include<Windows.h>
#endif

#include <iostream>
#include <sstream>

CApplication::~CApplication() {
    free();
}

void CApplication::run() {
    init();
    command();
}

void CApplication::init() {
    CLogInit::init();
}

void CApplication::free() {
    CLogInit::free();
}

void CApplication::command() {

    std::string input_str;

    do {

        std::string input;
        std::getline(std::cin, input);

        LOG_INFO("user input : {}", input);

        std::stringstream ss(input);
        std::vector<std::string> args;
        std::string tmp;
        while (std::getline(ss, tmp, ' ')) {
            args.emplace_back(tmp);
        }

        if (!args.empty()) {
            auto& cmd = args[0];

            if (cmd == "exit") {
                break;
            }
            else if (cmd == "logger") {
                if (args.size() > 2) {
                    CLogInit::set_level(args[1], args[2]);
                }
            }
        }

    } while (true);

}
