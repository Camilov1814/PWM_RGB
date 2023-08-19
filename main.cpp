/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
UnbufferedSerial pc(USBTX, USBRX,9600);
using namespace std;

int main()
{
    // Initialise the digital pin LED1,LED2 and LED3 as an output
    PwmOut ledR(LED1);
    PwmOut ledG(LED2);
    PwmOut ledB(LED3);

    float numR, numG, numB;
    string hexCode;
    do {
        cout << "Ingresa el codigo HEX: ";
        cin >> hexCode;

        if (hexCode.size() != 7 || hexCode[0] != '#') {
            cout << "Valor hexadecimal no válido. Asegúrese de incluir el '#' al inicio y usar 6 dígitos." << endl;
        }
    } while (hexCode.size() != 7 || hexCode[0] != '#');
    hexCode.erase(hexCode.begin());
    
    uint32_t rgbValue = stoul(hexCode, nullptr, 16);
    
    numR= 1-((float)(rgbValue >> 16) / 255.0f);
    numG=1-((float)((rgbValue >> 8) & 0xFF) / 255.0f);
    numB=1-((float)(rgbValue & 0xFF) / 255.0f);

    

    ledR.write(numR);
    ledG.write(numG);
    ledB.write(numB);

    while (true) {
        ThisThread::sleep_for(BLINKING_RATE);
        
    }
}
