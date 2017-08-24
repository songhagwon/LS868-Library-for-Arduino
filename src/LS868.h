#pragma once

/*
 * File		LS868.h
 * Version	v 1.4(공개 전)
 * Date		2017. 08. 21
 * Update	변경사항 없음
 *
 * Copyright 2016. (주)엠알티인터내셔널 all rights reserved.
 */

 /*
  *	Noted items : 2017. 04. 26
  *	LS868 Motor Shield for UNO 회로도에 맞춰 핀 설정
  *	SoftwareSerial RX 12 Pin
  *				   TX 13 Pin
  *	Motor Direction   11 Pin
  */

#ifndef LS868_H
#define LS868_H

#include <stdint.h>
#include <Arduino.h>
#include <SoftwareSerial.h>

// 파라미터 제어용
#define RED		0x52
#define GREEN	0x47
#define BLUE	0x42
#define CW		0x01
#define CCW		0x02
#define ALL		0xFE
#define TORQUE	0x01
#define SPEED	0x02

// LSM 모듈 선택
#define MICRO	0xB0
#define MINI	0xC0
#define MIDDLE	0xD0
#define MEGA	0xE0

// 시리얼 선택
#if defined(UBRRH) || defined(UBRR0H)
#define SERIAL 0
#define SOFT_SERIAL	4
#endif
#if defined(UBRR1H)
#define SERIAL1 1
#define SOFT_SERIAL	4
#endif
#if defined(UBRR2H)
#define SERIAL2 2
#define SOFT_SERIAL	4
#endif
#if defined(UBRR3H)
#define SERIAL3 3
#define SOFT_SERIAL	4
#endif

class LS868
{
public:
	// LS868 Para1 : Product ID(Protocal 참조), Para2 : 시리얼 타입 결정
	LS868(uint8_t p_product, uint8_t p_choiceSerial);
	// LS868 Para1 : Product ID(Protocal 참조), Para2 : 시리얼 타입 결정, Para3 : SoftSerial Rx, Para4 : SoftSerial Tx
	LS868(uint8_t p_product, uint8_t p_choiceSerial, int p_rxPin, int p_txPin);

	/*
	 *
	 * Data Get Function
	 *
	 */

	uint16_t getModuleID(uint8_t p_id);
	int16_t getNowPosition(uint8_t p_id);
	int16_t getTargetPosition(uint8_t p_id);
	uint16_t getNowCurrent(uint8_t p_id);
	uint16_t getLimitCurrent(uint8_t p_id);
	uint16_t getNowTemperature(uint8_t p_id);
	uint16_t getLimitTemperature(uint8_t p_id);
	uint16_t getGainP(uint8_t p_id);
	uint16_t getGainI(uint8_t p_id);
	uint16_t getGainD(uint8_t p_id);
	uint16_t getControlMargin(uint8_t p_id);
	uint16_t getForwardControl(uint8_t p_id);
	uint16_t getVoltage(uint8_t p_id);
	int16_t getBoundaryMax(uint8_t p_id);
	int16_t getBoundaryMin(uint8_t p_id);
	uint8_t getLedValue(uint8_t, uint8_t p_id);
	uint16_t getModuleVersion(uint8_t p_id);		// 모터 ProductID
	uint16_t getFirmwareVersion(uint8_t p_id);		// 모터 firmware version
	uint32_t getBaudRate(uint8_t p_id);
	int16_t getZeroComp(uint8_t p_id);

	/*
	 *
	 * Data Set Function
	 *
	 */

	void setFactoryReset(uint8_t p_id);
	void setModuleID(uint8_t p_currentId, uint16_t p_changeId);
	void setSyncPosition(uint8_t p_id, uint8_t p_mode, int16_t p_position);
	void setSyncLedControl(uint8_t p_id, uint8_t p_red, uint8_t p_green, uint8_t p_blue);
	void setLimitCurrent(uint8_t p_id, uint16_t p_current);
	void setLimitTemperature(uint8_t p_id, uint16_t p_celsius);
	void setGainP(uint8_t p_id, uint16_t p_proportional);
	void setGainI(uint8_t p_id, uint16_t p_integral);
	void setGainD(uint8_t p_id, uint16_t p_derivative);
	void setControlMargin(uint8_t p_id, uint16_t p_margin);
	void setForwardControl(uint8_t p_id, uint16_t p_forward);
	void setBoundaryMax(uint8_t p_id, int16_t p_boudarymax);
	void setBoundaryMin(uint8_t p_id, int16_t p_boundarymin);
	void setBaudRate(uint8_t p_id, uint32_t p_baudrate);
	void setZeroComp(uint8_t p_id, uint16_t p_zerocomp);

	/*
	 *
	 * Action Function
	 *
	 */

	void torquePosition(uint8_t p_id, uint8_t p_torque, int16_t p_position);
	void speedPosition(uint8_t p_id, uint8_t p_speed, int16_t p_position);
	void ledControl(uint8_t p_id, uint8_t p_red, uint8_t p_green, uint8_t p_blue);
	void syncPosition(uint8_t p_id, uint8_t p_mode);
	void syncLedControl(uint8_t p_id);
	void wheelMode(uint8_t p_id, uint8_t p_speed, uint8_t p_direction);
	void activeStop(uint8_t p_id);
	void passiveStop(uint8_t p_id);

	/*
	 *
	 * ETC. Function
	 *
	 */

	void begin(uint32_t p_baudrate);					// SoftwereSerial 통신속도 설정 함수
	unsigned char checkPacket(uint8_t p_id, uint8_t p_instruction);		// Packet Check 함수

private:
	uint8_t transmissionBuffer[8];	// LSM Write buffer
	uint8_t receiveBuffer[50];		// LSM Read buffer -> 모듈 추가 시 버퍼 크기 확장 필요
	uint8_t usingBuffer[8];			// 사용할 데이터만 뽑아서 저장하는 버퍼
	uint8_t serialNumber;			// 시리얼 종류 저장 변수
	uint8_t c_write[64];			// LSC buffer (임시 -> 추후 구현)
	uint8_t productId;
	int pinDirection;
	bool receiveIsRun;				// 진행여부 확인(readData()에서 사용)
	unsigned char index;			// 버퍼 인덱스
	unsigned char previousIndex;	// 버퍼 확인지점 인덱스

	void eepPROG(uint8_t p_id);
	void sendBuffer(uint8_t p_id, uint8_t p_instruction);
	void sendBuffer(uint8_t p_id, uint8_t p_instruction, uint8_t p_para1, uint8_t p_para2, uint8_t p_para3);
	void readBuffer(void);
	void readData(uint8_t p_tempRead);			// RX data 저장
	void arrangeBuffer(uint8_t isRunCheck);
	// void searchPacket(uint8_t p_id, uint8_t p_instruction); -> 추후 모듈 추가 시 구현
	int returnValue(bool WhatIsPin);


};
#endif // !LS868
