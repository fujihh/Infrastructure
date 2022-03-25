#pragma once
#include<iostream>
#include<json/json.h>
#include<WinSock2.h>
#include<vector>
#include<string>

class UDPClient {
public:
	UDPClient(int port,std::string ip, std::string Msg);
	
	~UDPClient();

private:
	//WORD vVersionRequested;
	//WSADATA wsaData;
	SOCKET clientSocket;
	SOCKADDR_IN socketAddr;
	int cPort;
	std::string cIP;

	const char* sendBuf;

};

namespace Bones {
	//extern const std::string root;
	//extern const std::string pelvis;
	//extern const std::string spine_03;
	extern const Json::Value spine_01;
	extern const Json::Value spine_05;
	extern const Json::Value neck_01;
	extern const Json::Value head;

	extern const Json::Value clavicle_l;
	extern const Json::Value upperarm_l;
	extern const Json::Value lowerarm_l;
	extern const Json::Value hand_l;

	extern const Json::Value clavicle_r;
	extern const Json::Value upperarm_r;
	extern const Json::Value lowerarm_r;
	extern const Json::Value hand_r;

	extern const Json::Value thigh_l;
	extern const Json::Value calf_l;
	extern const Json::Value foot_l;
	//extern const Json::Value ball_r;

	extern const Json::Value thigh_r;
	extern const Json::Value calf_r;
	extern const Json::Value foot_r;
	//extern const Json::Value ball_r;
}

struct bones
{
	Json::Value spine_01;
};
class JsonBuild
{
public:
	JsonBuild(Json::Value jsonObject );
	//void ParseBone(Json::Value jsonObject, const std::string& BoneName);
private:
	std::vector<std::string>boneNames;
	std::vector<Json::Value>boneJsonObjects;
}; 