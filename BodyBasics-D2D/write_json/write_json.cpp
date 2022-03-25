std::string write_Json(JointOrientation jointOrientations[], Joint joints[]) {
    
    Json::Value JsonRoot;
    Json::Value Frame;
    Json::Value Bones;
    //Json::Value JsonInfo;
    std::vector<Json::Value>BonesList;
    //Json::Value BonesArray[] = {};
    
    std::vector<std::string>BonesName;


    Json::Value root;
    Json::Value pelvis;
    Json::Value spine_01;
    Json::Value spine_03;
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
    Json::Value thigh_r;
    Json::Value calf_r;
    Json::Value foot_r;
    Json::Value ball_r;
    Json::Value thigh_l;
    Json::Value calf_l;
    Json::Value foot_l;
    Json::Value ball_l;
    
    Json::Value SourceData;
    //BonesList.push_back(root);
    //BonesList.push_back(pelvis);
    //BonesList.push_back(spine_05);
    BonesList.push_back(spine_01);
    BonesList.push_back(spine_03);
    BonesList.push_back(neck_01);
    BonesList.push_back(head);
    BonesList.push_back(clavicle_l);
    BonesList.push_back(upperarm_l);
    BonesList.push_back(lowerarm_l);
    BonesList.push_back(hand_l);
    BonesList.push_back(clavicle_r);
    BonesList.push_back(upperarm_r);
    BonesList.push_back(lowerarm_r);
    BonesList.push_back(hand_r);
    BonesList.push_back(thigh_r);
    BonesList.push_back(calf_r);
    BonesList.push_back(foot_r);
    BonesList.push_back(ball_r);
    BonesList.push_back(thigh_l);
    BonesList.push_back(calf_l);
    BonesList.push_back(foot_l);
    BonesList.push_back(ball_l);
    

    BonesName.push_back("spine_01");
    BonesName.push_back("spine_03");
    BonesName.push_back("neck_01");
    BonesName.push_back("head");
    BonesName.push_back("clavicle_l");
    BonesName.push_back("uppearm_l");
    BonesName.push_back("lowerarm_l");
    BonesName.push_back("hand_l");
    BonesName.push_back("clavicle_r");
    BonesName.push_back("upperarm_r");
    BonesName.push_back("lowerarm_r");
    BonesName.push_back("hand_r");
    BonesName.push_back("thigh_r");
    BonesName.push_back("calf_r");
    BonesName.push_back("foot_r");
    BonesName.push_back("ball_r");
    BonesName.push_back("thigh_l");
    BonesName.push_back("calf_l");
    BonesName.push_back("foot_l");
    BonesName.push_back("ball_l");
    
    int boneIndex = 0;
    for(Json::Value &bone:BonesList){
        bone["Position"].append(joints[boneIndex].Position.X);
        bone["Position"].append(joints[boneIndex].Position.Y);
        bone["Position"].append(joints[boneIndex].Position.Z);
        
        bone["Rotation"].append(jointOrientations[boneIndex].Orientation.x);
        bone["Rotation"].append(jointOrientations[boneIndex].Orientation.y);
        bone["Rotation"].append(jointOrientations[boneIndex].Orientation.z);
        bone["Rotation"].append(jointOrientations[boneIndex].Orientation.w);
        boneIndex++;
    }

    for (int i = 0; i < BonesName.size(); i++) {
        Bones[BonesName[i]] = Json::Value(BonesList[i]);
    }
    
    Frame["DataSource"] = Json::Value("Kinect");

    JsonRoot["Frame"] = Json::Value(Frame);
    JsonRoot["Bones"] = Json::Value(Bones);
    
   
    if (JsonRoot.isNull()) {
        return "";
    }
    else {
        return JsonRoot.toStyledString();
    }
}