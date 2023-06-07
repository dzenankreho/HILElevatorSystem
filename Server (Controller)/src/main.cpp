#include "mbed.h"
#include "ServerController.h"

int main(int argc, char *argv[]) {
    
    ServerController serverController;
    Elevator elevator1, elevator2;
    serverController.registerElevator(elevator1);
    serverController.registerElevator(elevator2);

	serverController.run();

    return 0;
}
