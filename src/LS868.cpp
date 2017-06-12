/**
* File		LS868.ccp
* Version	v 1.1
* Date		2017. 05. 18
* Details	mRxWrite 멤버함수 데이터 처리 개선
*			모든 멤버함수내 delay 개선 또는 삭제
*			checkPacket으로 패킷 확인 후 각 
*
* Copyright 2016. (주)엠알티인터내셔널 all rights reserved.
**/

#include "LS868.h"

#if SOFT_SERIAL
#include <SoftwareSerial.h>
SoftwareSerial softSerial(12, 13);		// RX, TX
#endif

LS868::LS868(uint8_t product, uint8_t serial_mode)
{
	product_id = product;
	pin_direction = 11;
	pinMode(pin_direction, OUTPUT);
	if (serial_mode == HARD_SERIAL)
	{
		serial_flag = true;
	}
	else if (serial_mode == SOFT_SERIAL)
	{
		serial_flag = false;
	}
}


/**
*
* Data Get Function
*
**/

uint16_t LS868::getModuleID(uint8_t m_id)
{
	int16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x01);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x01)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x01);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x01)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

int16_t LS868::getNowPosition(uint8_t m_id)
{
	int16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x02);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x02)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x02);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x02)
				value = m_read[5] << 8 | m_read[6];
		}
	}		

	return value;
}

int16_t LS868::getTargetPosition(uint8_t m_id)
{
	int16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x03);
	this->mRxWrite();

	if (checkPacket())
	{
		if (m_read[2] == m_id && m_read[3] == 0x03)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x03);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x03)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getNowCurrent(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x04);
	this->mRxWrite();

	if (checkPacket())
	{
		if (m_read[2] == m_id && m_read[3] == 0x04)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x04);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x04)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getLimitCurrent(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x05);
	this->mRxWrite();

	if (checkPacket())
	{
		if (m_read[2] == m_id && m_read[3] == 0x05)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x05);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x05)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getNowTemperature(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x06);
	this->mRxWrite();

	if (checkPacket())
	{
		if (m_read[2] == m_id && m_read[3] == 0x06)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x06);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x06)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getLimitTemperature(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x07);
	this->mRxWrite();

	if (checkPacket())
	{
		if (m_read[2] == m_id && m_read[3] == 0x07)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x07);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x07)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getGainP(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x08);
	this->mRxWrite();

	if (checkPacket())
	{
		if (m_read[2] == m_id && m_read[3] == 0x08)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x08);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x08)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getGainI(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x09);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x09)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x09);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x09)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getGainD(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x0A);
	this->mRxWrite();
	
	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x0A)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x0A);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x0A)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getControlMargin(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x0B);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x0B)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x0B);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x0B)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getForwardControl(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x0C);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x0C)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x0C);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x0C)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getVoltage(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x0D);
	this->mRxWrite();

	if (checkPacket())
	{
		if (m_read[2] == m_id && m_read[3] == 0x0D)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x0D);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x0D)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

int16_t LS868::getBoundaryMax(uint8_t m_id)
{
	int16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x0E);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x0E)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x0E);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x0E)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

int16_t LS868::getBoundaryMin(uint8_t m_id)
{
	int16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x0F);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x0F)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x0F);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x0F)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint8_t LS868::getLEDValue(uint8_t m_id, uint8_t m_color)
{
	uint8_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x10);
	this->mRxWrite();

	if (checkPacket())
	{
		if (m_read[2] == m_id && m_read[3] == 0x10)
		{
			switch (m_color)
			{
			case 0x52:	// Red Color
				value = m_read[4];
				break;
			case 0x47:	// Green Color
				value = m_read[5];
				break;
			case 0x42:	// Blue Color
				value = m_read[6];
				break;
			default:
				//Serial.println("Not enter the color name R, G, B");
				break;
			}
		}
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x10);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x10)
			{
				switch (m_color)
				{
				case 0x52:	// Red Color
					value = m_read[4];
					break;
				case 0x47:	// Green Color
					value = m_read[5];
					break;
				case 0x42:	// Blue Color
					value = m_read[6];
					break;
				default:
					//Serial.println("Not enter the color name R, G, B");
					break;
				}
			}
		}
	}

	return value;
}

uint16_t LS868::getModuleVersion(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x11);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x11)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x11);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x11)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint16_t LS868::getFirmwareVersion(uint8_t m_id)
{
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x12);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x12)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x12);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x12)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

uint32_t LS868::getBaudRate(uint8_t m_id)
{
	uint8_t checksum = 0;
	uint32_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x13);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x13)
			value = m_read[4] << 8 | m_read[5];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x13);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x13)
				value = m_read[4] << 8 | m_read[5];
		}
	}

	return value;
}

int16_t LS868::getZeroComp(uint8_t m_id)
{
	uint8_t checksum = 0;
	uint16_t value = 0;

	this->clearBuffer();
	this->mTxWrite(m_id, 0x14);
	this->mRxWrite();

	if (checkPacket())
	{
		if(m_read[2] == m_id && m_read[3] == 0x14)
			value = m_read[5] << 8 | m_read[6];
	}
	else
	{
		this->clearBuffer();
		this->mTxWrite(m_id, 0x14);
		this->mRxWrite();

		if (checkPacket())
		{
			if (m_read[2] == m_id && m_read[3] == 0x14)
				value = m_read[5] << 8 | m_read[6];
		}
	}

	return value;
}

/**
*
* Data Set Function
*
**/


void LS868::setFactoryReset(uint8_t m_id)
{
	this->clearBuffer();
	m_write[4] = 0x53;
	m_write[5] = 0x46;
	m_write[6] = 0x52;
	this->mTxWrite(m_id, 0x40);
	eepPROG(m_id);
}

void LS868::setModuleID(uint8_t m_id, uint16_t new_id)
{
	this->clearBuffer();
	m_write[5] = new_id >> 8;
	m_write[6] = new_id;
	this->mTxWrite(m_id, 0x41);
}

void LS868::setSyncPosition(uint8_t m_id, uint8_t m_mode, int16_t m_position)
{
	this->clearBuffer();
	if (m_mode == 1)
		m_write[4] = 1;
	else if (m_mode == 2)
		m_write[4] = 2;

	m_write[5] = m_mode >> 8;
	m_write[6] = m_mode;
	this->mTxWrite(m_id, 0x42);
	eepPROG(m_id);
}

void LS868::setSyncLEDControl(uint8_t m_id, uint8_t m_r, uint8_t m_g, uint8_t m_b)
{
	this->clearBuffer();
	m_write[4] = m_r;
	m_write[5] = m_g;
	m_write[6] = m_b;
	this->mTxWrite(m_id, 0x43);
	eepPROG(m_id);
}

void LS868::setLimitCurrent(uint8_t m_id, uint16_t m_current)
{
	this->clearBuffer();
	m_write[5] = m_current >> 8;
	m_write[6] = m_current;
	this->mTxWrite(m_id, 0x44);
	eepPROG(m_id);
}

void LS868::setLimitTemperature(uint8_t m_id, uint16_t m_temp)
{
	this->clearBuffer();
	m_write[5] = m_temp >> 8;
	m_write[6] = m_temp;
	this->mTxWrite(m_id, 0x45);
	eepPROG(m_id);
}

void LS868::setGainP(uint8_t m_id, uint16_t m_p)
{
	this->clearBuffer();
	m_write[5] = m_p >> 8;
	m_write[6] = m_p;
	this->mTxWrite(m_id, 0x46);
	eepPROG(m_id);
}

void LS868::setGainI(uint8_t m_id, uint16_t m_i)
{
	this->clearBuffer();
	m_write[5] = m_i >> 8;
	m_write[6] = m_i;
	this->mTxWrite(m_id, 0x47);
	eepPROG(m_id);
}

void LS868::setGainD(uint8_t m_id, uint16_t m_d)
{
	this->clearBuffer();
	m_write[5] = m_d >> 8;
	m_write[6] = m_d;
	this->mTxWrite(m_id, 0x48);
	eepPROG(m_id);
}

void LS868::setControlMargin(uint8_t m_id, uint16_t m_margin)
{
	this->clearBuffer();
	m_write[5] = m_margin >> 8;
	m_write[6] = m_margin;
	this->mTxWrite(m_id, 0x49);
	eepPROG(m_id);
}

void LS868::setForwardControl(uint8_t m_id, uint16_t m_forward)
{
	this->clearBuffer();
	m_write[5] = m_forward >> 8;
	m_write[6] = m_forward;
	this->mTxWrite(m_id, 0x4A);
	eepPROG(m_id);
}

void LS868::setBoundaryMax(uint8_t m_id, int16_t m_boundarymax)
{
	this->clearBuffer();
	m_write[5] = m_boundarymax >> 8;
	m_write[6] = m_boundarymax;
	this->mTxWrite(m_id, 0x4B);
	eepPROG(m_id);
}

void LS868::setBoundaryMin(uint8_t m_id, int16_t m_boundarymin)
{
	this->clearBuffer();
	m_write[5] = m_boundarymin >> 8;
	m_write[6] = m_boundarymin;
	this->mTxWrite(m_id, 0x4C);
	eepPROG(m_id);
}

void LS868::setBaudRate(uint8_t m_id, uint32_t m_baudrate)
{
	this->clearBuffer();
	m_write[4] = m_baudrate >> 16;
	m_write[5] = m_baudrate >> 8;
	m_write[6] = m_baudrate;
	Serial.println(m_baudrate);
	this->mTxWrite(m_id, 0x4D);
	eepPROG(m_id);
}
void LS868::setZeroComp(uint8_t m_id, uint16_t m_zerocomp)
{
	this->clearBuffer();
	m_write[5] = m_zerocomp >> 8;
	m_write[6] = m_zerocomp;
	this->mTxWrite(m_id, 0x4E);
}

/**
*
* Action Function
*
**/

void LS868::torquePosition(uint8_t m_id, uint8_t m_torque, int16_t m_position)
{
	this->clearBuffer();
	m_write[4] = m_torque;
	m_write[5] = m_position >> 8;
	m_write[6] = m_position;
	this->mTxWrite(m_id, 0x82);
}

void LS868::speedPosition(uint8_t m_id, uint8_t m_speed, int16_t m_position)
{
	this->clearBuffer();
	m_write[4] = m_speed;
	m_write[5] = m_position >> 8;
	m_write[6] = m_position;
	this->mTxWrite(m_id, 0x83);
}

void LS868::LEDControl(uint8_t m_id, uint8_t m_r, uint8_t m_g, uint8_t m_b)
{
	this->clearBuffer();
	m_write[4] = m_r;
	m_write[5] = m_g;
	m_write[6] = m_b;
	this->mTxWrite(m_id, 0x84);
}

void LS868::syncPosition(uint8_t m_id, uint8_t m_mode)
{
	this->clearBuffer();
	m_write[4] = m_mode;
	m_write[5] = 0x01;
	m_write[6] = 0x01;
	this->mTxWrite(m_id, 0x85);
}

void LS868::syncLED(uint8_t m_id)
{
	this->clearBuffer();
	m_write[4] = 0x01;
	m_write[5] = 0x01;
	m_write[6] = 0x01;
	this->mTxWrite(m_id, 0x86);
}

void LS868::wheelMode(uint8_t m_id, uint8_t m_speed, uint8_t m_direction)
{
	this->clearBuffer();
	m_write[4] = m_direction;
	m_write[5] = m_speed >> 8;
	m_write[6] = m_speed;
	this->mTxWrite(m_id, 0x87);
}

void LS868::activeStop(uint8_t m_id)
{
	this->clearBuffer();
	this->mTxWrite(m_id, 0x88);
}

void LS868::passiveStop(uint8_t m_id)
{
	this->clearBuffer();
	this->mTxWrite(m_id, 0x89);
}

/**
*
* ETC. Function
*
**/

void LS868::begin(uint32_t baudrate)
{
	if (serial_flag == true)
		Serial.begin(baudrate);
	else if (serial_flag == false)
		softSerial.begin(baudrate);
}

/**
*
*Private Funtion
*
*/

void LS868::eepPROG(uint8_t m_id)
{
	this->clearBuffer();
	m_write[4] = 0x01;
	m_write[5] = 0x02;
	m_write[6] = 0x03;
	delay(1);
	this->mTxWrite(m_id, 0x81);
	delay(1);
}


void LS868::clearBuffer(void)
{
	for (int i = 0; i < 8; i++)
	{
		m_write[i] = 0;
		m_read[i] = 0;
	}
}

void LS868::mTxWrite(uint8_t m_id, uint8_t m_instruction)
{
	digitalWrite(pin_direction, HIGH);

	// 핀 신호 전환 딜레이
	delay(1);

	m_write[0] = 0xFF;
	m_write[1] = product_id;
	m_write[2] = m_id;
	m_write[3] = m_instruction;
	m_write[7] = m_write[2] + m_write[3] + m_write[4] + m_write[5] + m_write[6];

	if (serial_flag == true)
	{
		Serial.write(m_write, 8);
		Serial.flush();

	}
	else if (serial_flag == false)
	{
		softSerial.write(m_write, 8);
		Serial.flush();
	}
}

void LS868::mRxWrite(void)
{
	uint8_t array_address = 0;
	int count = 0;
	digitalWrite(pin_direction, LOW);

	// 핀 신호 전환 딜레이
	delay(1);

	if (serial_flag == true)
	{
		while (Serial.available())
		{
			if (Serial.available() > 0)
			{
				unsigned char m_readtemp = Serial.read();
				m_read[array_address] = m_readtemp;
				array_address++;
			}
			else
				break;
		}
		Serial.flush();
	}
	else if (serial_flag == false)
	{
		while (softSerial.available())
		{
			if (softSerial.available() > 0 && array_address < 8)
			{
				unsigned char m_readtemp = softSerial.read();
				m_read[array_address] = m_readtemp;
				array_address++;
			}
			else
				break;
		}
		softSerial.flush();
	}
}


bool LS868::checkPacket(void)
{
	uint8_t checksum = 0;

	checksum = m_read[2] + m_read[3] + m_read[4] + m_read[5] + m_read[6];
	if (m_read[7] == checksum)
		return true;
	else
		return false;
}