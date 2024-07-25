/*
 * main.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Novak
 */

#include <main.h>

int main(void)
{
	light_7_seg_init();
	light_buttons_init();
	//light_configure_interrupts_7seg();
	master_configure_gpio();
	master_configure_spi2();

	while(1)
	{
		master_send_data();
		master_recieve_data();
	}


	return 0;
}
