/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v11.0
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 12.0.0
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: c44a1146-4635-4aa2-a0e4-e3b1cfde2b76
  called_from_default_init: true
  selectedCore: cm33_core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'uart_cmsis_common'
- type_id: 'uart_cmsis_common_9cb8e302497aa696fdbb5a4fd622c2a8'
- global_USART_CMSIS_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'gpio_adapter_common'
- type_id: 'gpio_adapter_common_57579b9ac814fe26bf95df0a384c36b6'
- global_gpio_adapter_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * FLEXCOMM0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FLEXCOMM0'
- type: 'flexcomm_usart'
- mode: 'transfer'
- custom_name_enabled: 'false'
- type_id: 'flexcomm_usart_ed63debb5f147199906723fc49ad2e72'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'FLEXCOMM0'
- config_sets:
  - transferCfg:
    - transfer:
      - init_rx_transfer: 'true'
      - rx_transfer:
        - data_size: '10'
      - init_tx_transfer: 'true'
      - tx_transfer:
        - data_size: '10'
      - init_callback: 'false'
      - callback_fcn: ''
      - user_data: ''
    - quick_selection: 'QuickSelection1'
  - usartConfig_t:
    - usartConfig:
      - clockSource: 'FXCOMFunctionClock'
      - clockSourceFreq: 'BOARD_BootClockPLL150M'
      - baudRate_Bps: '115200'
      - syncMode: 'kUSART_SyncModeDisabled'
      - parityMode: 'kUSART_ParityDisabled'
      - stopBitCount: 'kUSART_OneStopBit'
      - bitCountPerChar: 'kUSART_8BitsPerChar'
      - loopback: 'false'
      - txWatermark: 'kUSART_TxFifo0'
      - rxWatermark: 'kUSART_RxFifo1'
      - enableMatchAddress: 'false'
      - matchAddressConfig:
        - matchAddress: '0'
        - addressMode: 'automatic'
      - enableRx: 'true'
      - enableTx: 'true'
      - enableHardwareFlowControl: 'false'
      - enableRTS: 'false'
      - clockPolarity: 'kUSART_RxSampleOnFallingEdge'
      - enableContinuousSCLK: 'false'
    - quick_selection: 'QuickSelection1'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const usart_config_t FLEXCOMM0_config = {
  .baudRate_Bps = 115200UL,
  .syncMode = kUSART_SyncModeDisabled,
  .parityMode = kUSART_ParityDisabled,
  .stopBitCount = kUSART_OneStopBit,
  .bitCountPerChar = kUSART_8BitsPerChar,
  .loopback = false,
  .txWatermark = kUSART_TxFifo0,
  .rxWatermark = kUSART_RxFifo1,
  .enableRx = true,
  .enableTx = true,
  .enableHardwareFlowControl = false,
  .enableMode32k = false,
  .clockPolarity = kUSART_RxSampleOnFallingEdge,
  .enableContinuousSCLK = false
};
usart_handle_t FLEXCOMM0_handle;
uint8_t FLEXCOMM0_rxBuffer[FLEXCOMM0_RX_BUFFER_SIZE];
const usart_transfer_t FLEXCOMM0_rxTransfer = {
  .rxData = FLEXCOMM0_rxBuffer,
  .dataSize = FLEXCOMM0_RX_BUFFER_SIZE
};
uint8_t FLEXCOMM0_txBuffer[FLEXCOMM0_TX_BUFFER_SIZE];
const usart_transfer_t FLEXCOMM0_txTransfer = {
  .data = FLEXCOMM0_txBuffer,
  .dataSize = FLEXCOMM0_TX_BUFFER_SIZE
};

static void FLEXCOMM0_init(void) {
  USART_Init(FLEXCOMM0_PERIPHERAL, &FLEXCOMM0_config, FLEXCOMM0_CLOCK_SOURCE);
  USART_TransferCreateHandle(FLEXCOMM0_PERIPHERAL, &FLEXCOMM0_handle, NULL, NULL);
}

/***********************************************************************************************************************
 * FLEXCOMM2 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FLEXCOMM2'
- type: 'flexcomm_usart'
- mode: 'transfer'
- custom_name_enabled: 'false'
- type_id: 'flexcomm_usart_ed63debb5f147199906723fc49ad2e72'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'FLEXCOMM2'
- config_sets:
  - transferCfg:
    - transfer:
      - init_rx_transfer: 'true'
      - rx_transfer:
        - data_size: '10'
      - init_tx_transfer: 'true'
      - tx_transfer:
        - data_size: '10'
      - init_callback: 'false'
      - callback_fcn: ''
      - user_data: ''
    - quick_selection: 'QuickSelection1'
  - usartConfig_t:
    - usartConfig:
      - clockSource: 'FXCOMFunctionClock'
      - clockSourceFreq: 'BOARD_BootClockPLL150M'
      - baudRate_Bps: '115200'
      - syncMode: 'kUSART_SyncModeDisabled'
      - parityMode: 'kUSART_ParityDisabled'
      - stopBitCount: 'kUSART_OneStopBit'
      - bitCountPerChar: 'kUSART_8BitsPerChar'
      - loopback: 'false'
      - txWatermark: 'kUSART_TxFifo0'
      - rxWatermark: 'kUSART_RxFifo1'
      - enableMatchAddress: 'false'
      - matchAddressConfig:
        - matchAddress: '0'
        - addressMode: 'automatic'
      - enableRx: 'true'
      - enableTx: 'true'
      - enableHardwareFlowControl: 'false'
      - enableRTS: 'false'
      - clockPolarity: 'kUSART_RxSampleOnFallingEdge'
      - enableContinuousSCLK: 'false'
    - quick_selection: 'QuickSelection1'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const usart_config_t FLEXCOMM2_config = {
  .baudRate_Bps = 115200UL,
  .syncMode = kUSART_SyncModeDisabled,
  .parityMode = kUSART_ParityDisabled,
  .stopBitCount = kUSART_OneStopBit,
  .bitCountPerChar = kUSART_8BitsPerChar,
  .loopback = false,
  .txWatermark = kUSART_TxFifo0,
  .rxWatermark = kUSART_RxFifo1,
  .enableRx = true,
  .enableTx = true,
  .enableHardwareFlowControl = false,
  .enableMode32k = false,
  .clockPolarity = kUSART_RxSampleOnFallingEdge,
  .enableContinuousSCLK = false
};
usart_handle_t FLEXCOMM2_handle;
uint8_t FLEXCOMM2_rxBuffer[FLEXCOMM2_RX_BUFFER_SIZE];
const usart_transfer_t FLEXCOMM2_rxTransfer = {
  .rxData = FLEXCOMM2_rxBuffer,
  .dataSize = FLEXCOMM2_RX_BUFFER_SIZE
};
uint8_t FLEXCOMM2_txBuffer[FLEXCOMM2_TX_BUFFER_SIZE];
const usart_transfer_t FLEXCOMM2_txTransfer = {
  .data = FLEXCOMM2_txBuffer,
  .dataSize = FLEXCOMM2_TX_BUFFER_SIZE
};

static void FLEXCOMM2_init(void) {
  USART_Init(FLEXCOMM2_PERIPHERAL, &FLEXCOMM2_config, FLEXCOMM2_CLOCK_SOURCE);
  USART_TransferCreateHandle(FLEXCOMM2_PERIPHERAL, &FLEXCOMM2_handle, NULL, NULL);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  FLEXCOMM0_init();
  FLEXCOMM2_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}