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




 JsonBuild::JsonBuild(BoneTransLation bonesTranslation[]) {
	
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


	 bonesMap.insert(std::pair<std::string,Json::Value>("spine_01", spine_01));
	 bonesMap.insert(std::pair<std::string,Json::Value>("spine_05", spine_05));
	 bonesMap.insert(std::pair<std::string,Json::Value>("head", head));
	 bonesMap.insert(std::pair<std::string,Json::Value>("clavicle_l", clavicle_l));
	 bonesMap.insert(std::pair<std::string,Json::Value>("upperarm_l", upperarm_l));
	 bonesMap.insert(std::pair<std::string,Json::Value>("lowerarm_l", lowerarm_l));
	 bonesMap.insert(std::pair<std::string,Json::Value>("hand_l", hand_l));
	 bonesMap.insert(std::pair<std::string,Json::Value>("clavicle_r", clavicle_r));
	 bonesMap.insert(std::pair<std::string,Json::Value>("upperarm_r", upperarm_r));
	 bonesMap.insert(std::pair<std::string,Json::Value>("lowerarm_r", lowerarm_r));
	 bonesMap.insert(std::pair<std::string,Json::Value>("hand_r", hand_r));
	 bonesMap.insert(std::pair<std::string,Json::Value>("thigh_l", thigh_l));
	 bonesMap.insert(std::pair<std::string,Json::Value>("calf_l", calf_l));
	 bonesMap.insert(std::pair<std::string,Json::Value>("foot_l", foot_l));
	 bonesMap.insert(std::pair<std::string,Json::Value>("thigh_r", thigh_r));
	 bonesMap.insert(std::pair<std::string,Json::Value>("calf_r", calf_r));
	 bonesMap.insert(std::pair<std::string,Json::Value>("foot_r", foot_r));

	 if (bonesTranslation == NULL) {
		 return;
	 }
	 int len = sizeof(bonesTranslation) / sizeof(bonesTranslation);
	 if (len != bonesMap.size()) {
		 return;
	 }

	 for (std::pair<std::string,Json::Value> bonePair : bonesMap) {
		 bonePair.second["Position"].append(bonesTranslation->bonePosition.x);
		 bonePair.second["Position"].append(bonesTranslation->bonePosition.y);
		 bonePair.second["Position"].append(bonesTranslation->bonePosition.z);
		 
		 bonePair.second["Rotation"].append(bonesTranslation->boneQuat.x);
		 bonePair.second["Rotation"].append(bonesTranslation->boneQuat.y);
		 bonePair.second["Rotation"].append(bonesTranslation->boneQuat.z);
		 bonePair.second["Rotation"].append(bonesTranslation->boneQuat.w);
		 
		 Bones[bonePair.first] = Json::Value(bonePair.second);
	 }

	 rootObject["Bones"].append(Bones);
	 rootObject["Frame"].append(Frame);

 }
