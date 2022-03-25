#pragma once
#include<iostream>
#include<json/json.h>
#include<WinSock2.h>
#include<vector>
#include<string>
#include<map>

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


typedef struct _Vector4
{
	float x;
	float y;
	float z;
	float w;
} 	Vector4;
typedef struct _Vector3
{
	float x;
	float y;
	float z;
} 	Vector3;


typedef struct _Bone {
	//std::string boneName;
	Vector4 boneQuat;
	Vector3 bonePosition;
}	Bone;

class JsonBuild
{
public:
	JsonBuild(Bone bones[]);
	//void ParseBone(Json::Value jsonObject, const std::string& BoneName);
private:
	std::vector<std::string>boneNames;
	std::vector<Json::Value>boneJsonObjects;
	std::map<Json::Value, std::string>bonesMap;

}; 