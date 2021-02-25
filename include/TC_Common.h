#include <stdio.h>

#ifndef __TC_COMMON_H__
#define __TC_COMMON_H__

#define TC_SERVER_SERVICE_NAME            "lge.tc.QtDBus.tcServer"
#define TC_CLIENT_SERVICE_NAME            "lge.tc.QtDBus.tcClient"
#define TC_AUDIO_SERVICE_NAME            "lge.tc.QtDBus.tcAudio"

//#define USE_SYSTEM_BUS
#define ASYNC_CALL
//#define AUTO_START_SERVER

typedef enum
{
    REQ_INDEX_MESSAGE_ID,
    REQ_INDEX_MESSAGE_TYPE,
    REQ_INDEX_CATEGORY_ID,
    REQ_INDEX_FUNCTION_ID,
    REQ_INDEX_TESTCASE_ID,
    REQ_IDEX_MAX_SIZE
} reqMessage;

typedef enum 
{
    DUMMY_TEST_1 = 1,
    DUMMY_TEST_2,
    DUMMY_TEST_3,
    DUMMY_TEST_4,
    DUMMY_TEST_5,
    DUMMY_TEST_6,
} testType;

typedef enum {
    MESSAGE_ID_BSP_TEST = 11,
    MESSAGE_ID_VIDEO_TEST,
    MESSAGE_ID_RADIO_TEST,
    MESSAGE_ID_MCU_TEST,
    MESSAGE_ID_ETHERNET_TEST,
    MESSAGE_ID_AUDIO_TEST,
    MESSAGE_ID_ALL_AUTO_TEST,
    MESSAGE_ID_MAX
} messageID;

typedef enum {
    MESSAGE_TYPE_REQUEST =1,
    MESSAGE_TYPE_RESPONSE
} messageType;


typedef enum {
    CATEGORY_ID_BASIC = 21,
    CATEGORY_ID_INTERFACE,
    CATEGORY_ID_AUDIO,
    CATEGORY_ID_DDR_UFS,
    CATEGORY_ID_ETHERNET,
    CATEGORY_ID_RADIO,
    CATEGORY_ID_SECURITY,
    CATEGORY_ID_TERMINAL,
    CATEGORY_ID_USB,
    CATEGORY_ID_VIDEO
} categoryID;

typedef enum {
    FUNCTION_ID_A2B = 50,
    FUNCTION_ID_APPLE_CP,
    FUNCTION_ID_AUDIO,
    FUNCTION_ID_BOOT,
    FUNCTION_ID_CAN,
    FUNCTION_ID_PROCESSOR
} functionID;

typedef enum {
    TEST_CASE_ID_A1 = 100,
    TEST_CASE_ID_A2,
    TEST_CASE_ID_A3
} testCaseID;

typedef enum {
    TEST_RESULT_OK = 0,
    TEST_RESULT_NG
} testResult;

typedef struct _message {
    messageID msgID;
    messageType msgType; //req: 1  resp: 2
    categoryID catID;
    functionID funcID;
    testCaseID tcID;
    testResult result;  //ok: 0 ng : 1
    QString errorMsg;
} testCaseMessage;

class TestCaseMessage : public QVariant
{
public:
    //testCaseMessage msg;
    messageID msgID;
    messageType msgType; //req: 1  resp: 2
    categoryID catID;
    functionID funcID;
    testCaseID tcID;
    testResult result;  //ok: 0 ng : 1
    QString errorMsg;

    void setMessageID(const int input)   //Just for test
    {
        switch(input)
        {
            case DUMMY_TEST_1:
                msgID = MESSAGE_ID_AUDIO_TEST;                
                break;
            case DUMMY_TEST_2:
            case DUMMY_TEST_3:
            case DUMMY_TEST_4:
                break;
        }
    }

    messageID getMessageID() const
    {
        return msgID;
    }
}; 

/*
messageID TestCaseMessage::parseMessageID()
{
    return TestCaseMessage::msgID;
}
*/
#endif
