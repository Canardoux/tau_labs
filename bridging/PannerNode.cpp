#include "dart_api/dart_api.h"
#include "LabSound/LabSound.h"
#include "KeepNode.cpp"
#include "struct.h"
using namespace lab;

DART_EXPORT int createPannerNode(AudioContext* context) {
    auto sample = std::make_shared<PannerNode>(*context);
    return keepNode(sample);
}

DART_EXPORT int PannerNode_panningModel(int nodeIndex) {
    return static_cast<int>(std::dynamic_pointer_cast<PannerNode>(audioNodes.find(nodeIndex)->second)->panningModel());
}

DART_EXPORT void PannerNode_setPanningModel(int nodeIndex, int m) {
    std::dynamic_pointer_cast<PannerNode>(audioNodes.find(nodeIndex)->second)->setPanningModel(PanningMode(m));
}

DART_EXPORT int PannerNode_distanceModel(int nodeIndex) {
    return static_cast<int>(std::dynamic_pointer_cast<PannerNode>(audioNodes.find(nodeIndex)->second)->distanceModel());
}

DART_EXPORT void PannerNode_setDistanceModel(int nodeIndex, int m) {
    std::dynamic_pointer_cast<PannerNode>(audioNodes.find(nodeIndex)->second)->setDistanceModel(DistanceModel(m));
}

DART_EXPORT void PannerNode_setPosition(int nodeIndex, float x, float y, float z) {
    std::dynamic_pointer_cast<PannerNode>(audioNodes.find(nodeIndex)->second)->setPosition(x, y, z);
}

DART_EXPORT void PannerNode_setOrientation(int nodeIndex, float x, float y, float z) {
    std::dynamic_pointer_cast<PannerNode>(audioNodes.find(nodeIndex)->second)->setOrientation(FloatPoint3D(x, y, z));
}

DART_EXPORT void PannerNode_setVelocity(int nodeIndex, float x, float y, float z) {
    std::dynamic_pointer_cast<PannerNode>(audioNodes.find(nodeIndex)->second)->setVelocity(x, y, z);
}

DART_EXPORT int PannerNode_positionX(int nodeIndex) {
    return keepAudioParam(nodeId, 1, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->positionX());
}
DART_EXPORT int PannerNode_positionY(int nodeIndex) {
    return keepAudioParam(nodeId, 2, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->positionY());
}
DART_EXPORT int PannerNode_positionZ(int nodeIndex) {
    return keepAudioParam(nodeId, 3, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->positionZ());
}

DART_EXPORT int PannerNode_orientationX(int nodeIndex) {
    return keepAudioParam(nodeId, 4, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->orientationX());
}
DART_EXPORT int PannerNode_orientationY(int nodeIndex) {
    return keepAudioParam(nodeId, 5, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->orientationY());
}
DART_EXPORT int PannerNode_orientationZ(int nodeIndex) {
    return keepAudioParam(nodeId, 6, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->orientationZ());
}


DART_EXPORT int PannerNode_velocityX(int nodeIndex) {
    return keepAudioParam(nodeId, 7, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->velocityX());
}
DART_EXPORT int PannerNode_velocityY(int nodeIndex) {
    return keepAudioParam(nodeId, 8, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->velocityY());
}
DART_EXPORT int PannerNode_velocityZ(int nodeIndex) {
    return keepAudioParam(nodeId, 9, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->velocityZ());
}

DART_EXPORT int PannerNode_distanceGain(int nodeIndex) {
    return keepAudioParam(nodeId, 10, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->distanceGain());
}
DART_EXPORT int PannerNode_coneGain(int nodeIndex) {
    return keepAudioParam(nodeId, 11, std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->coneGain());
}

DART_EXPORT float PannerNode_refDistance(int nodeIndex) {
    return std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->refDistance();
}
DART_EXPORT void PannerNode_setRefDistance(int nodeIndex, float refDistance) {
    std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->setRefDistance(refDistance);
}

DART_EXPORT float PannerNode_maxDistance(int nodeIndex) {
    return std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->maxDistance();
}
DART_EXPORT void PannerNode_setMaxDistance(int nodeIndex, float maxDistance) {
    std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->setMaxDistance(maxDistance);
}

DART_EXPORT float PannerNode_rolloffFactor(int nodeIndex) {
    return std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->rolloffFactor();
}
DART_EXPORT void PannerNode_setRolloffFactor(int nodeIndex, float rolloffFactor) {
    std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->setRolloffFactor(rolloffFactor);
}

DART_EXPORT float PannerNode_coneInnerAngle(int nodeIndex) {
    return std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->coneInnerAngle();
}
DART_EXPORT void PannerNode_setConeInnerAngle(int nodeIndex, float angle) {
    std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->setConeInnerAngle(angle);
}


DART_EXPORT float PannerNode_coneOuterAngle(int nodeIndex) {
    return std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->coneOuterAngle();
}
DART_EXPORT void PannerNode_setConeOuterAngle(int nodeIndex, float angle) {
    std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->setConeOuterAngle(angle);
}

DART_EXPORT float PannerNode_coneOuterGain(int nodeIndex) {
    return std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->coneOuterGain();
}
DART_EXPORT void PannerNode_setConeOuterGain(int nodeIndex, float angle) {
    std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->setConeOuterGain(angle);
}

DART_EXPORT void PannerNode_getAzimuthElevation(int nodeIndex, AudioContext context, double * outAzimuth, double * outElevation) {
    ContextRenderLock r(context,"getAzimuthElevation");
    std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->getAzimuthElevation(r, outAzimuth, outElevation);
}

DART_EXPORT void PannerNode_dopplerRate(int nodeIndex, AudioContext context) {
    ContextRenderLock r(context, "dopplerRate");
    std::static_pointer_cast<PannerNode>(audioNodes.find(nodeId)->second)->dopplerRate(r);
}
