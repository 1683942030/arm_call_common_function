LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE	:= test
LOCAL_ARM_MODE	:= arm
LOCAL_CPP_EXTENSION	:= .cpp
LOCAL_SRC_FILES	:= test.cpp call.cpp

include $(BUILD_EXECUTABLE)

all:
	adb push F:\3rd\armTest\obj\local\armeabi-v7a/test /data/local/tmp/
	adb shell "su -c chmod 755 /data/local/tmp/test"