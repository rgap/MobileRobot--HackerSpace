#ifndef ACTIONCONTROL_H_
#define ACTIONCONTROL_H_

#include <opencv2/opencv.hpp>
#include "../DataTransfer/SerialDevice.h"

using namespace cv;
using namespace std;

#define SEND_SIGNALS 1

////////////////// ACTIONS
#define DEFAULT '0'

#define PARAR '1'
#define AVANZAR '2'
#define RETROCEDER '3'

#define GIRO_DER '4'
#define GIRO_IZQ '5'
#define INICIAL_PALA '6'

#define RECOGER_LATA '7'
#define BUSCAR '8'

//////////////////////////;

#define SEND_ACTION(action) \
		if (SEND_SIGNALS){ (*dev.serialStream) << action; cout<<"Sending signal..."<<endl; }

class ActionControl {
private:
	SerialDevice dev;
	int timeCount;
	int stopCount;
	bool busy;
public:
	ActionControl();
	void initialize(std::string devicePath);
	void send(char action = DEFAULT);

	bool isBusy();
	virtual ~ActionControl();
};

#endif /* ACTIONCONTROL_H_ */