//
// Created by vulko on 2023/3/13.
//

#ifndef DEMO_CPP_CAPPLICATION_H
#define DEMO_CPP_CAPPLICATION_H


class CApplication {

public:
    ~CApplication();
    static void run();

private:
    static void init();
    static void free();
    static void command();

};


#endif //DEMO_CPP_CAPPLICATION_H
