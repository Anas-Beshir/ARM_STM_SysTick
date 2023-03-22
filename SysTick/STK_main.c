#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"NVIC_interface.h"


int	main(void)
{
	/*	Initialization Part		*/
	
	/*	System Clk init			*/
	MRCC_voidSysClkInit();
	
	/*	Toggle Led C13	GPIOC	*/
	/*	1- Enable Per Clk "RCC" Port C		*/
	MRCC_voidEnablePerClk(RCC_APB2,4);
	
	/*	Direction for C13 is output Push Pull */
	MDIO_voidSetPinDirection(PORTC, PIN13, OUT_2MHZ_PP);
	
	/*	SysTick initilaization	*/
	STK_voidInit();
	
	
	while(1)
	{
		/*	Toggle led */
		MDIO_voidSetPinValue(PORTC, PIN13, DIO_LOW);
		STK_voidBusyWait(1000000);
		MDIO_voidSetPinValue(PORTC, PIN13, DIO_HIGH);
		STK_voidBusyWait(1000000);
	}
	return 0;
}