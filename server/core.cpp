#include "core.h"

#include "messagetypes.h"
#include "loglevels.h"

Core::Core() {
	tcpServer = new TcpServer();
	communicationHandler = new HandleCommunication();
	dbManager = new DBManager("server.sqlite");

	connect(tcpServer, &TcpServer::newDataRecieved_signal, communicationHandler, &HandleCommunication::parseJson_slot);
	connect(communicationHandler, &HandleCommunication::parsingDone_signal, communicationHandler,
			&HandleCommunication::processMessage_slot);
	//connect(communicationHandler, &HandleCommunication::processMessageDone_signal, communicationHandler);
}

Core::~Core() {
	delete tcpServer;
	delete communicationHandler;
}

void Core::processMessageAck_slot(int returnCode) {
	switch (returnCode){
		case (int)LogLevel::DEBUG:
			break;
		case (int)LogLevel::INFO:
			break;
		case (int)LogLevel::WARNING:
			break;
		case (int)LogLevel::CRITICAL:
			break;
		default:break;
	}


}


