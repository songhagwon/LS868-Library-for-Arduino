/*
 * File		LS868.ccp
 * Version	v 1.4(공개 전)
 * Date		2017. 08. 21
 * Update	수신데이터 처리 개선
 *			패킷확인기능 추가
 *			핀 신호 전환 딜레이 User Guide 권장시간으로 변경
 *
 * Copyright 2016. (주)엠알티인터내셔널 all rights reserved.
 */

 /*
  *	Noted items : 2017. 08. 22
  * 현재 checkPacket(), arrangeBuffer(), searchPacket()은 별 의미 없음 -> 일부 기능 미리 구현
  *	추가 제품 적용 시 코드 수정 요망
  */

#include "LS868.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

LS868::LS868(uint8_t p_product,uint8_t p_choiceSerial)
{
	productId = p_product;
	serialNumber = p_choiceSerial;
	pinDirection = 11;
	receiveIsRun = false;				// readData()에서 사용
	pinMode(pinDirection, OUTPUT);

	digitalWrite(pinDirection, HIGH);	// pinDirection을 HIGH로 초기화
}

LS868::LS868(uint8_t p_product, uint8_t p_choiceSerial, int p_rxPin, int p_txPin)
{
	productId = p_product;
	serialNumber = p_choiceSerial;
	pinDirection = 11;
	receiveIsRun = false;				// readData()에서 사용
	pinMode(pinDirection, OUTPUT);

	digitalWrite(pinDirection, HIGH);	// pinDirection을 HIGH로 초기화
		
}

SoftwareSerial softSerial(12, 13);

/*
 *
 * Data Get Function
 *
 */

uint16_t LS868::getModuleID(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x01;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

int16_t LS868::getNowPosition(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x02;
	int16_t value = 50;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];
	return value;
}

int16_t LS868::getTargetPosition(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x03;
	int16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

uint16_t LS868::getNowCurrent(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x04;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];
	
	return value;
}

uint16_t LS868::getLimitCurrent(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x05;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

uint16_t LS868::getNowTemperature(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x06;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

uint16_t LS868::getLimitTemperature(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x07;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

uint16_t LS868::getGainP(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x08;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

uint16_t LS868::getGainI(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x09;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];
	
	return value;
}

uint16_t LS868::getGainD(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x0A;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

uint16_t LS868::getControlMargin(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x0B;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

uint16_t LS868::getForwardControl(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x0C;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];
	
	return value;
}

uint16_t LS868::getVoltage(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x0D;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

int16_t LS868::getBoundaryMax(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x0E;
	int16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;

}

int16_t LS868::getBoundaryMin(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x0F;
	int16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

uint8_t LS868::getLedValue(uint8_t p_id, uint8_t m_color)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x10;
	uint8_t color = m_color;
	uint8_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
	{
		switch (color)
		{
		case 0x52:	// Red Color
			value = usingBuffer[4];
			break;
		case 0x47:	// Green Color
			value = usingBuffer[5];
			break;
		case 0x42:	// Blue Color
			value = usingBuffer[6];
			break;
		default:
			break;
		}
	}

	return value;
}

uint16_t LS868::getModuleVersion(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x11;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];
	
	return value;
}

uint16_t LS868::getFirmwareVersion(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x12;
	uint16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];
	
	return value;
}

uint32_t LS868::getBaudRate(uint8_t p_id)
{

	uint8_t id = p_id;
	uint8_t instruction = 0x13;
	uint32_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[4] << 8 | usingBuffer[5];
		value = value << 8 | usingBuffer[6];

	return value;
}

int16_t LS868::getZeroComp(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x14;
	int16_t value = 0;

	this->sendBuffer(id, instruction);
	this->readBuffer();

	if (checkPacket(id, instruction) == 0)
		value = usingBuffer[5] << 8 | usingBuffer[6];

	return value;
}

/*
 *
 * Data Set Function
 *
 */


void LS868::setFactoryReset(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x40;
	uint8_t parameter1 = 0x53;
	uint8_t parameter2 = 0x46;
	uint8_t parameter3 = 0x52;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setModuleID(uint8_t p_currentId, uint16_t p_changeId)
{
	uint8_t id = p_currentId;
	uint8_t instruction = 0x41;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_changeId >> 8;
	uint8_t parameter3 = p_changeId;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	// EEPROM에 저장할 필요 없음
}

void LS868::setSyncPosition(uint8_t p_id, uint8_t p_mode, int16_t p_position)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x42;
	uint8_t parameter1 = p_mode;
	uint8_t parameter2 = p_position >> 8;
	uint8_t parameter3 = p_position;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setSyncLedControl(uint8_t p_id, uint8_t p_red, uint8_t p_green, uint8_t p_blue)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x43;
	uint8_t parameter1 = p_red;
	uint8_t parameter2 = p_green;
	uint8_t parameter3 = p_blue;
	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setLimitCurrent(uint8_t p_id, uint16_t p_current)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x44;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_current >> 8;
	uint8_t parameter3 = p_current;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setLimitTemperature(uint8_t p_id, uint16_t p_celsius)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x45;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_celsius >> 8;
	uint8_t parameter3 = p_celsius;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setGainP(uint8_t p_id, uint16_t p_proportional)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x46;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_proportional >> 8;
	uint8_t parameter3 = p_proportional;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setGainI(uint8_t p_id, uint16_t p_integral)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x47;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_integral >> 8;
	uint8_t parameter3 = p_integral;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setGainD(uint8_t p_id, uint16_t p_derivative)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x48;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_derivative >> 8;
	uint8_t parameter3 = p_derivative;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setControlMargin(uint8_t p_id, uint16_t p_margin)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x49;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_margin >> 8;
	uint8_t parameter3 = p_margin;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setForwardControl(uint8_t p_id, uint16_t p_forward)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x4A;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_forward >> 8;
	uint8_t parameter3 = p_forward;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setBoundaryMax(uint8_t p_id, int16_t p_boundarymax)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x4B;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_boundarymax >> 8;
	uint8_t parameter3 = p_boundarymax;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setBoundaryMin(uint8_t p_id, int16_t p_boundarymin)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x4C;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_boundarymin >> 8;
	uint8_t parameter3 = p_boundarymin;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setBaudRate(uint8_t p_id, uint32_t p_baudrate)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x4D;
	uint8_t parameter1 = p_baudrate >> 16;
	uint8_t parameter2 = p_baudrate >> 8;
	uint8_t parameter3 = p_baudrate;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
}

void LS868::setZeroComp(uint8_t p_id, uint16_t p_zerocomp)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x4E;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = p_zerocomp >> 8;
	uint8_t parameter3 = p_zerocomp;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	this->eepPROG(id);
	// EEPROM에 저장할 필요 없음
}

/*
 *
 * Action Function
 *
 */

void LS868::torquePosition(uint8_t p_id, uint8_t p_torque, int16_t p_position)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x82;
	uint8_t parameter1 = p_torque;
	uint8_t parameter2 = p_position >> 8;
	uint8_t parameter3 = p_position;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
}

void LS868::speedPosition(uint8_t p_id, uint8_t p_speed, int16_t p_position)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x83;
	uint8_t parameter1 = p_speed;
	uint8_t parameter2 = p_position >> 8;
	uint8_t parameter3 = p_position;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
}

void LS868::ledControl(uint8_t p_id, uint8_t p_red, uint8_t p_green, uint8_t p_blue)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x84;
	uint8_t parameter1 = p_red;
	uint8_t parameter2 = p_green;
	uint8_t parameter3 = p_blue;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
}

void LS868::syncPosition(uint8_t p_id, uint8_t p_mode)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x85;
	uint8_t parameter1 = p_mode;
	uint8_t parameter2 = 0x01;
	uint8_t parameter3 = 0x01;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
}

void LS868::syncLedControl(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x86;
	uint8_t parameter1 = 0x01;
	uint8_t parameter2 = 0x01;
	uint8_t parameter3 = 0x01;
	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
}

void LS868::wheelMode(uint8_t p_id, uint8_t p_speed, uint8_t p_direction)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x87;
	uint8_t parameter1 = p_direction;
	uint8_t parameter2 = p_speed >> 8;
	uint8_t parameter3 = p_speed;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
}

void LS868::activeStop(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x88;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = 0x00;
	uint8_t parameter3 = 0x00;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
}

void LS868::passiveStop(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x89;
	uint8_t parameter1 = 0x00;
	uint8_t parameter2 = 0x00;
	uint8_t parameter3 = 0x00;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
}

/*
 *
 * ETC. Function
 *
 */

void LS868::begin(uint32_t p_baudrate)
{
	uint32_t baudrate = p_baudrate;

#if defined(SERIAL)
	if (serialNumber == SERIAL)				Serial.begin(baudrate);
	else if (serialNumber == SOFT_SERIAL)	softSerial.begin(baudrate);
#endif
#if defined(SERIAL1)
	if (serialNumber == SERIAL1)			Serial1.begin(baudrate);
	else if (serialNumber == SOFT_SERIAL)	softSerial.begin(baudrate);
#endif
#if defined(SERIAL2)
	if (serialNumber == SERIAL2)			Serial2.begin(baudrate);
	else if (serialNumber == SOFT_SERIAL)	softSerial.begin(baudrate);
#endif
#if defined(SERIAL3)
	if (serialNumber == SERIAL3)			Serial3.begin(baudrate);
	else if (serialNumber == SOFT_SERIAL)	softSerial.begin(baudrate);
#endif
}

unsigned char LS868::checkPacket(uint8_t p_id, uint8_t p_instruction)
{
	uint8_t id = p_id;
	uint8_t instruction = p_instruction;
	unsigned char checksum = 0;
	unsigned char errorMassage = 0;				// 2017. 08. 22 오류목록 : 0, 1, 2, 3, 4, 5 -> 추가 제품 적용 시 처리방식 개선 필요

	for (int i = previousIndex; i < previousIndex + 8; i++)
	{
		usingBuffer[i] = receiveBuffer[i];
		// Check point
		// Serial.print("using buffer : ");
		// Serial.println(usingBuffer[i]);
	}

	/*// Code Test :
	usingBuffer[0] = 0xFF;
	usingBuffer[1] = 0xB0;
	usingBuffer[2] = 0x01;
	usingBuffer[3] = 0x05;
	*/

	// 프로토콜과 비교
	if (usingBuffer[0] == 0xFF &&			// Header
		usingBuffer[1] == productId &&		// product id
		usingBuffer[2] == id &&				// module id
		usingBuffer[3] == instruction)		// instruction
	{
		for (int i = 2; i < 7; i++)
		{
			checksum += usingBuffer[i];
		}
		if (checksum == usingBuffer[7])
			errorMassage = 0;          // checksum까지 읽히면 패킷 이상 없음		-> 패킷 삭제
		else
			errorMassage = 1;		// parameter 오류 (정상 진행 할 것)			-> 패킷 삭제 (최종 구현 : 패킷 2~3번 추가 확인 후 최종 삭제)
	}
	else
	{
		if (usingBuffer[0] != 0xFF)				errorMassage = 2;	// Hearder 오류		-> 패킷 삭제
		else if (usingBuffer[1] != productId)	errorMassage = 3;  // productId 오류	-> 패킷 삭제 (제품 추가 시 처리방식 변경 요망)
		else if (usingBuffer[2] != id)			errorMassage = 4;	// id 오류			-> 패킷 저장
		else if (usingBuffer[3] != instruction)	errorMassage = 5;  // instruction 오류	-> 패킷 저장
	}
	// Check point:
	// Serial.print("error massage : ");
	// Serial.println(error massage);

	arrangeBuffer(errorMassage);
	return errorMassage;
}

/*
 *
 * Private Funtion
 *
 */

void LS868::eepPROG(uint8_t p_id)
{
	uint8_t id = p_id;
	uint8_t instruction = 0x81;
	uint8_t parameter1 = 0x01;
	uint8_t parameter2 = 0x02;
	uint8_t parameter3 = 0x03;

	this->sendBuffer(id, instruction, parameter1, parameter2, parameter3);
	delay(1);
}

void LS868::sendBuffer(uint8_t p_id, uint8_t p_instruction)
{

	digitalWrite(pinDirection, HIGH);

	delay(1);// 핀 신호 전환 딜레이

	transmissionBuffer[0] = 0xFF;
	transmissionBuffer[1] = productId;
	transmissionBuffer[2] = p_id;
	transmissionBuffer[3] = p_instruction;
	transmissionBuffer[4] = 0x00;
	transmissionBuffer[5] = 0x00;
	transmissionBuffer[6] = 0x00;
	transmissionBuffer[7] = transmissionBuffer[2] + transmissionBuffer[3] + transmissionBuffer[4] + transmissionBuffer[5] + transmissionBuffer[6];

#if defined(SERIAL)
	if (serialNumber == SERIAL)				Serial.write(transmissionBuffer, 8);
	else if (serialNumber == SOFT_SERIAL)	softSerial.write(transmissionBuffer, 8);
#endif
#if defined(SERIAL1)
	if (serialNumber == SERIAL)				Serial1.write(transmissionBuffer, 8);
	else if (serialNumber == SOFT_SERIAL)	softSerial.write(transmissionBuffer, 8);
#endif
#if defined(SERIAL2)
	if (serialNumber == SERIAL2)			Serial2.write(transmissionBuffer, 8);
	else if (serialNumber == SOFT_SERIAL)	softSerial.write(transmissionBuffer, 8);
#endif
#if defined(SERIAL3)
	if (serialNumber == SERIAL3)			Serial3.write(transmissionBuffer, 8);
	else if (serialNumber == SOFT_SERIAL)	softSerial.write(transmissionBuffer, 8);
#endif

	for (int i = 0; i < 8; i++)			// 버퍼 초기화
	{
		// Check point :
		// Serial.print(" trans buffer : ");
		// Serial.println(transmissionBuffer[i]);
		transmissionBuffer[i] = 0;
	}
}

void LS868::sendBuffer(uint8_t p_id, uint8_t p_instruction, uint8_t p_para1, uint8_t p_para2, uint8_t p_para3)
{
	digitalWrite(pinDirection, HIGH);

	delay(1);// 핀 신호 전환 딜레이

	transmissionBuffer[0] = 0xFF;
	transmissionBuffer[1] = productId;
	transmissionBuffer[2] = p_id;
	transmissionBuffer[3] = p_instruction;
	transmissionBuffer[4] = p_para1;
	transmissionBuffer[5] = p_para2;
	transmissionBuffer[6] = p_para3;
	transmissionBuffer[7] = transmissionBuffer[2] + transmissionBuffer[3] + transmissionBuffer[4] + transmissionBuffer[5] + transmissionBuffer[6];

#if defined(SERIAL)
	if (serialNumber == SERIAL)				Serial.write(transmissionBuffer, 8);
	else if (serialNumber == SOFT_SERIAL)	softSerial.write(transmissionBuffer, 8);
#endif
#if defined(SERIAL1)
	if (serialNumber == SERIAL)				Serial1.write(transmissionBuffer, 8);
	else if (serialNumber == SOFT_SERIAL)	softSerial.write(transmissionBuffer, 8);
#endif
#if defined(SERIAL2)
	if (serialNumber == SERIAL2)			Serial2.write(transmissionBuffer, 8);
	else if (serialNumber == SOFT_SERIAL)	softSerial.write(transmissionBuffer, 8);
#endif
#if defined(SERIAL3)
	if (serialNumber == SERIAL3)			Serial3.write(transmissionBuffer, 8);
	else if (serialNumber == SOFT_SERIAL)	softSerial.write(transmissionBuffer, 8);
#endif

	for (int i = 0; i < 8; i++)			// 버퍼 초기화
	{
		// Check point :
		// Serial.print(" trans buffer : ");
		// Serial.println(transmissionBuffer[i]);
		transmissionBuffer[i] = 0;
	}
}


void LS868::readBuffer(void)
{
	digitalWrite(pinDirection, LOW);
	delay(2); 	// 핀 신호 전환 딜레이

#if defined(SERIAL)
	while (Serial.available())
	{
		if (Serial.available() > 0)
		{
			char tempRead = Serial.read();
			readData(tempRead & 0xFF);
		}
	}
#endif
#if defined(SERIAL1)
	while (Serial1.available())
	{
		if (Serial1.available() > 0)
		{
			char tempRead = Serial1.read();
			readData(tempRead & 0xFF);
		}
	}
#endif
#if defined(SERIAL2)
	while (Serial2.available())
	{
		if (Serial2.available() > 0)
		{
			char tempRead = Serial2.read();
			readData(tempRead & 0xFF);
		}
	}
#endif
#if defined(SERIAL3)
	while (Serial3.available())
	{
		if (Serial3.available() > 0)
		{
			char tempRead = Serial3.read();
			readData(tempRead & 0xFF);
		}
	}
#endif
#if defined(SOFT_SERIAL)
	while (softSerial.available())
	{
		if (softSerial.available() > 0)
		{
			char tempRead = softSerial.read();
			readData(tempRead & 0xFF);
		}
	}
#endif

	delay(1);
	digitalWrite(pinDirection, HIGH);
}
void LS868::readData(uint8_t p_tempRead)
{
	receiveBuffer[index] = p_tempRead;

	// check point :
	// Serial.print(index);
	// Serial.print(" : ");
	// Serial.print(receiveBuffer[index]);

	if (receiveBuffer[index] == 0xFF)	// 0xFF가 들어오면 데이터 저장 시작
	{
		receiveIsRun = true;
		previousIndex = index;
		// Check point :
		// Serial.print("previousIndex : ");
		// Serial.println(previousIndex);
	}
	if (receiveIsRun == true) {
		index++;
		if (index - previousIndex == 8)
			receiveIsRun = false;
	}
}

void LS868::arrangeBuffer(uint8_t p_isRunCheck)
{
	uint8_t isRunCheck = p_isRunCheck;

	if (isRunCheck == 0 ||
		isRunCheck == 1 ||
		isRunCheck == 2 ||
		isRunCheck == 3)
	{
		// Check point :
		// Serial.print("get index : ");
		// Serial.println(index);

		for (int i = previousIndex; i < index; i++)
		{
			if (i == index - 8)
				receiveBuffer[i] = 0;
			else
				receiveBuffer[i] = receiveBuffer[i + 8];
		}
		index = index - 8;
	}

	if (index > 40) index = 0;	// 5번 초과 누적 시 불필요 데이터로 취급 
								// -> 전체 삭제 (모듈 추가 시 변경필요)
	 // Check point:
	 // Serial.print("current index : ");
	 // Serial.println(index);
}
\
/* 추후 모듈 추가 시 구현
void LS868::searchPacket(uint8_t p_id, uint8_t p_instruction)
{
	uint8_t id = p_id;
	uint8_t instruction = p_instruction;
}
*/
