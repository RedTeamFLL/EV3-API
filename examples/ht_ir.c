#include <ev3.h>

bool isExitButtonPressed() {
    return ButtonIsDown(BTNEXIT);
}

/**
 * Example program that uses the HiTechnic IR Sensor.
 * The program checks every 100ms the direction of a beacon.
 * Stop the program by pressing the back/exit button of the robot.
 */
int main () {
    /**
     * Initialize HT Ir sensor connected at port 1
     */
    InitEV3();
    SetAllSensors(HTIrV2, NULL, NULL, NULL);

    while (!isExitButtonPressed()) {

        /**
         * Read the direction of a beacon transmitting modulated ir signal (AC)
         */
        int direction = ReadHTIrV2Sensor(IN_1, Modulated);

        LcdClean();
        LcdTextf(LCD_COLOR_BLACK, 0, LcdRowToY(1), "Direction: %d", direction);
        Wait(100);
    }

    FreeEV3();
    return 0;
}
