/*
 * dht11.c
 *
 *  Created on: Feb 8, 2024
 *      Author: hussamaldean
 */


#include "dht11.h"
#include "stm32f4xx.h"
#include "delay.h"

void dht11_PinA8_Init(void)
{
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
}

void dht11_start(void)
{
	/*Set PA8 as output*/
	GPIOA->MODER|=GPIO_MODER_MODE8_0;
	GPIOA->MODER&=~GPIO_MODER_MODE8_1;

	/*Set the pin low*/
	GPIOA->BSRR=GPIO_BSRR_BR8;

	/*Wait for 18ms*/

	delay(18);

	/*Set the pin to input*/
	GPIOA->MODER&=~GPIO_MODER_MODE8;
}

DHT11_Response_Typedef Check_Response()
{
	uint8_t Response = 0;
	delayuS(40);
	if ((GPIOA->IDR & GPIO_IDR_ID8)!=GPIO_IDR_ID8)
	{
		delayuS (80);
		if ((GPIOA->IDR & GPIO_IDR_ID8)==GPIO_IDR_ID8)
		{
			Response = Response_OK;
		}
		else
		{
			Response = Response_ERR;
		}
	}
	while ((GPIOA->IDR & GPIO_IDR_ID8)==GPIO_IDR_ID8);   // wait for the pin to go low
	return Response;
}

static uint8_t DHT11_Read (void)
{
	uint8_t i=0,j;
	for (j=0;j<8;j++)
	{
		while ((GPIOA->IDR & GPIO_IDR_ID8)!=GPIO_IDR_ID8);   // wait for the pin to go high
		delayuS (40);   // wait for 40 us
		if ((GPIOA->IDR & GPIO_IDR_ID8)!=GPIO_IDR_ID8)   // if the pin is low
		{
			i&= ~(1<<(7-j));   // write 0
		}
		else i|= (1<<(7-j));  // if the pin is high, write 1
		while ((GPIOA->IDR & GPIO_IDR_ID8)==GPIO_IDR_ID8);  // wait for the pin to go low
	}
	return i;
}

void Get_DHT_Data(float * TEMP, float *RH)
{
	  uint8_t Rh_byte1 = DHT11_Read ();

	  uint8_t Rh_byte2 = DHT11_Read ();

	  uint8_t Temp_byte1 = DHT11_Read ();

	  uint8_t Temp_byte2 = DHT11_Read ();

	  uint8_t SUM = DHT11_Read();

	  if (SUM == (uint8_t)(Rh_byte1 + Rh_byte2 + Temp_byte1 + Temp_byte2))
	     {
	         uint16_t rawHumidity = (Rh_byte1 << 8) | Rh_byte2;
	         uint16_t rawTemp = (Temp_byte1 << 8) | Temp_byte2;

	         *RH = rawHumidity / 10.0;

	         if (rawTemp & 0x8000) // negative temp
	         {
	             rawTemp &= 0x7FFF;
	             *TEMP = -rawTemp / 10.0;
	         }
	         else
	         {
	             *TEMP = rawTemp / 10.0;
	         }
	     }
	     else
	     {
	         *RH = -1;
	         *TEMP = -1;
	     }
}
