#pragma once

/**
* File		LS868.h
* Version	v 1.2
* Date		2017. 06. 12
* Details	checkPacket() 멤버함수의 권한을 private로 설정
*
* Copyright 2016. (주)엠알티인터내셔널 all rights reserved.
**/

/**
* berief
*	LS868 Motor Shield 핀 번호에 맞춰 라이브러리 작성
*	SoftwareSerial RX 12 Pin
*				   TX 13 Pin
*	Motor Direction 11 Pin
**/

#ifndef LS868_h
#define LS868_h

#include <stdint.h>
#include <Arduino.h>

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
#define HARD_SERIAL	0x01
#define SOFT_SERIAL	0x02


class LS868
{
public:
	// LS868 Parameter 1 : Product ID(Protocal 참조), Parameter 2 : 시리얼 타입 결정
	LS868(uint8_t product, uint8_t serial_mode);

	/**
	*
	* Data Get Function
	*
	**/

	uint16_t getModuleID(uint8_t m_id);
	int16_t getNowPosition(uint8_t m_id);
	int16_t getTargetPosition(uint8_t m_id);
	uint16_t getNowCurrent(uint8_t m_id);
	uint16_t getLimitCurrent(uint8_t m_id);
	uint16_t getNowTemperature(uint8_t m_id);
	uint16_t getLimitTemperature(uint8_t m_id);
	uint16_t getGainP(uint8_t m_id);
	uint16_t getGainI(uint8_t m_id);
	uint16_t getGainD(uint8_t m_id);
	uint16_t getControlMargin(uint8_t m_id);
	uint16_t getForwardControl(uint8_t m_id);
	uint16_t getVoltage(uint8_t m_id);
	int16_t getBoundaryMax(uint8_t m_id);
	int16_t getBoundaryMin(uint8_t m_id);
	uint8_t getLEDValue(uint8_t m_id, uint8_t m_color);
	uint16_t getModuleVersion(uint8_t m_id);		// 모터 ProductID
	uint16_t getFirmwareVersion(uint8_t m_id);		// 모터 firmware version
	uint32_t getBaudRate(uint8_t m_id);
	int16_t getZeroComp(uint8_t m_id);

	/**
	*
	* Data Set Function
	*
	**/

	void setFactoryReset(uint8_t m_id);
	void setModuleID(uint8_t m_id, uint16_t new_id);
	void setSyncPosition(uint8_t m_id, uint8_t m_mode, int16_t m_position);
	void setSyncLEDControl(uint8_t m_id, uint8_t m_r, uint8_t m_g, uint8_t m_b);
	void setLimitCurrent(uint8_t m_id, uint16_t m_current);
	void setLimitTemperature(uint8_t m_id, uint16_t m_temp);
	void setGainP(uint8_t m_id, uint16_t m_p);
	void setGainI(uint8_t m_id, uint16_t m_i);
	void setGainD(uint8_t m_id, uint16_t m_d);
	void setControlMargin(uint8_t m_id, uint16_t m_margin);
	void setForwardControl(uint8_t m_id, uint16_t m_forward);
	void setBoundaryMax(uint8_t m_id, int16_t m_boundarymax);
	void setBoundaryMin(uint8_t m_id, int16_t m_boundarymin);
	void setBaudRate(uint8_t m_id, uint32_t m_baudrate);
	void setZeroComp(uint8_t m_id, uint16_t m_zerocomp);

	/**
	*
	* Action Function
	*
	**/

	void torquePosition(uint8_t m_id, uint8_t m_torque, int16_t m_position);
	void speedPosition(uint8_t m_id, uint8_t m_speed, int16_t m_position);
	void LEDControl(uint8_t m_id, uint8_t m_r, uint8_t m_g, uint8_t m_b);
	void syncPosition(uint8_t m_id, uint8_t m_mode);
	void syncLED(uint8_t m_id);
	void wheelMode(uint8_t m_id, uint8_t m_speed, uint8_t m_direction);
	void activeStop(uint8_t m_id);
	void passiveStop(uint8_t m_id);

	/**
	*
	* ETC. Function
	*
	**/

	void begin(uint32_t baudrate);	// SoftwereSerial 통신속도 설정 멤버함수

private:
	uint8_t m_write[8];
	uint8_t m_read[8];
	uint8_t c_write[50];
	uint8_t product_id;
	bool serial_flag;
	int pin_direction;

	bool checkPacket(void);			// Packet Check용 멤버함수(coding)
	void eepPROG(uint8_t m_id);		// setMotorID, setZeroComp에는 필요 없음
	void clearBuffer(void);			// m_write, m_read 초기화
	void mTxWrite(uint8_t m_id, uint8_t m_instruction);
	void mRxWrite(void);
};
#endif // !LS868
