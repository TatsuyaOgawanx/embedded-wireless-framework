
#include "r_smc_entry.h"

#include <platform.h>

#include <r_cmt_rx_if.h>

#include <tx_api.h>

#include "hardware_setup.h"

void _tx_timer_interrupt(void);

/* CMT Timer callback used as the system tick. */
void timer_callback(void * pdata)
{
    _tx_timer_interrupt();
}


void platform_setup(void)
{
    uint32_t chan;
    
    /* Create periodic timer for the system tick. */
    R_CMT_CreatePeriodic(TX_TIMER_TICKS_PER_SECOND, timer_callback, &chan);

	/* User Switch on CK RX65N*/
	R_GPIO_PinDirectionSet(GPIO_PORT_D_PIN_1, GPIO_DIRECTION_INPUT);

    /* Initialize LED2, LED3, LED4, LED6 on CK RX65N*/
    R_GPIO_PinDirectionSet(GPIO_PORT_1_PIN_7, GPIO_DIRECTION_OUTPUT); //LED2_R
    R_GPIO_PinDirectionSet(GPIO_PORT_A_PIN_5, GPIO_DIRECTION_OUTPUT); //LED2_G
    R_GPIO_PinDirectionSet(GPIO_PORT_A_PIN_7, GPIO_DIRECTION_OUTPUT); //LED2_B

    R_GPIO_PinDirectionSet(GPIO_PORT_2_PIN_2, GPIO_DIRECTION_OUTPUT); //LED3
    R_GPIO_PinDirectionSet(GPIO_PORT_A_PIN_3, GPIO_DIRECTION_OUTPUT); //LED4
    R_GPIO_PinDirectionSet(GPIO_PORT_2_PIN_5, GPIO_DIRECTION_OUTPUT); //LED6

    R_GPIO_PinWrite(GPIO_PORT_1_PIN_7, GPIO_LEVEL_HIGH); //LED2_R
    R_GPIO_PinWrite(GPIO_PORT_A_PIN_5, GPIO_LEVEL_HIGH); //LED2_G
    R_GPIO_PinWrite(GPIO_PORT_A_PIN_7, GPIO_LEVEL_HIGH); //LED2_B

    R_GPIO_PinWrite(GPIO_PORT_2_PIN_2, GPIO_LEVEL_HIGH); //LED3
    R_GPIO_PinWrite(GPIO_PORT_A_PIN_3, GPIO_LEVEL_HIGH); //LED4
    R_GPIO_PinWrite(GPIO_PORT_2_PIN_5, GPIO_LEVEL_HIGH); //LED6

	/* Set the warm start to Cold/Warm Start Determination Flag */
    //SYSTEM.RSTSR1.BIT.CWSF = 1;

}
