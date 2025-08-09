#include "oled.h"
#include "dht11.h"
#include "delay.h"

float temp,hum;

char oled_buff[20];


int main(void)
{
	SSD1306_Init();
	SSD1306_GotoXY (0,0);
	SSD1306_Puts ("DHT22", &Font_11x18, 1);
	SSD1306_UpdateScreen(); //display

	dht11_PinA8_Init();

	GPIOA->MODER|=GPIO_MODER_MODE5_0;
	GPIOA->MODER&=~GPIO_MODER_MODE5_1;

	while(1)
	{
		dht11_start();
		if(Check_Response()==Response_OK)
		{
			Get_DHT_Data(&temp,&hum);

			sprintf(oled_buff,"Temp=%0.1f C",temp);
			SSD1306_GotoXY (0,20);
			SSD1306_Puts(oled_buff,&Font_11x18, 1);

			sprintf(oled_buff,"Hum=%0.1f RH",hum);
			SSD1306_GotoXY (0,40);
			SSD1306_Puts(oled_buff,&Font_11x18, 1);

			SSD1306_UpdateScreen();

		}

		delay(1000);
		GPIOA->ODR ^=GPIO_ODR_OD5;
	}
}


