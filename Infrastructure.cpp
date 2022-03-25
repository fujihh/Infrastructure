#include"Infrastructure.h"

#pragma comment(lib,"ws2_32.lib")
 UDPClient::UDPClient(int port, std::string ip,std::string Msg){
	//:cPort(port)
	//,cIP(ip)
	//,clientSocket(socket(AF_INET, SOCK_DGRAM, 0))
	cPort = port;
	cIP = ip;

	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	int err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		WSACleanup();
		return;
	}

	clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	socketAddr.sin_port = htons(cPort);
	socketAddr.sin_family = AF_INET;
	socketAddr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());

	sendBuf = Msg.c_str();

	sendto(clientSocket, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&socketAddr, sizeof(socketAddr));

}
 UDPClient::~UDPClient() {
	 closesocket(clientSocket);
	 WSACleanup();
 }



 //namespace Bones {
	// const std::string spine_01 = "spine_01";
	// const std::string spine_05 = "spine_05";
	// const std::string neck_01= "neck_01";
	// const std::string head = "head";
	// const std::string clavicle_l = "clavicle_l";
	// const std::string upperarm_l = "upperarm_l";
	// const std::string lowerarm_l = "lowerarm_l";
	// const std::string hand_l = "hand_l";
	// 
	// const std::string clavicle_r = "clavicle_r";
	// const std::string upperarm_r = "upperarm_r";
	// const std::string lowerarm_r = "lowerarm_r";
	// const std::string hand_r = "hand_r";

	// const std::string thigh_l= "thigh_l";
	// const std::string hand_l = "calf_l";
	// const std::string hand_l = "foot_l";
	// 
	// const std::string thigh_r= "thigh_r";
	// const std::string hand_r = "calf_r";
	// const std::string hand_r = "foot_r";

 //}

 JsonBuild::JsonBuild(Json::Value jsonObject) {
	
	 Json::Value rootObject;
	 Json::Value Bones;
	 Json::Value Frame ;

	 Json::Value ;
	 

 }
