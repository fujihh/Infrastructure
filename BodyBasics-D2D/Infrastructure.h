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


typedef struct _BoneTransLation {
	//std::string boneName;
	Vector4 boneQuat;
	Vector3 bonePosition;
}	BoneTransLation;

class JsonBuild
{
public:
	JsonBuild(BoneTransLation bonesTranslation[]);//是否需要array 更加安全 ——待定——
	//void ParseBone(Json::Value jsonObject, const std::string& BoneName);
private:
	std::vector<std::string>boneNames;
	std::vector<Json::Value>boneJsonObjects;
	std::map<std::string, Json::Value>bonesMap;

}; 