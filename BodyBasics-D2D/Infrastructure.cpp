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


 JsonBuild::JsonBuild(Bone bones[]) {
	
	 Json::Value rootObject;
	 Json::Value Bones;
	 Json::Value Frame;
	 
	 Json::Value spine_01;
	 Json::Value spine_05;
	 Json::Value neck_01;
	 Json::Value head;
	 Json::Value clavicle_l;
	 Json::Value upperarm_l;
	 Json::Value lowerarm_l;
	 Json::Value hand_l;
	 Json::Value clavicle_r;
	 Json::Value upperarm_r;
	 Json::Value lowerarm_r;
	 Json::Value hand_r;
	 Json::Value thigh_l;
	 Json::Value calf_l;
	 Json::Value foot_l;
	 Json::Value thigh_r;
	 Json::Value calf_r;
	 Json::Value foot_r;


	 bonesMap.insert(std::pair<Json::Value, std::string>(spine_01,"spine_01"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(spine_05,"spine_05"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(head,"head"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(clavicle_l,"clavicle_l"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(upperarm_l,"upperarm_l"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(lowerarm_l,"lowerarm_l"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(hand_l,"hand_l"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(clavicle_r,"clavicle_r"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(upperarm_r,"upperarm_r"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(lowerarm_r,"lowerarm_r"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(hand_r,"hand_r"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(thigh_l,"thigh_l"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(calf_l,"calf_l"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(foot_l,"foot_l"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(thigh_r,"thigh_r"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(calf_r,"calf_r"));
	 bonesMap.insert(std::pair<Json::Value, std::string>(foot_r,"foot_r"));
	 
	 
	 

 }
