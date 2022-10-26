/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

#include "nx_api.h"
#include "nx_azure_iot_hub_client.h"
#include "nx_azure_iot_hub_client_properties.h"
#include "RX_ZMOD4XXX_Common.h"

#define SAMPLE_PNP_GAS_COMPONENT_NAME									"Gas"
#define DOUBLE_DECIMAL_PLACE_DIGITS                                     (2)

/* TODO : Add property name */
static const CHAR sample_pnp_iaq_property_name[] = "iaq";
static const CHAR sample_pnp_oaq_property_name[] = "oaq";

static UCHAR telemetry_buffer[256];

UINT sample_gas_telemetry_messages_send(NX_AZURE_IOT_HUB_CLIENT *pnp_client_ptr);

UINT sample_gas_telemetry_messages_send(NX_AZURE_IOT_HUB_CLIENT *pnp_client_ptr)
{
UINT status;
NX_PACKET *packet_ptr;
UINT data_length;
NX_AZURE_IOT_JSON_WRITER json_writer;
double temp;

    /* Create a telemetry message packet.  */
    if ((status = nx_azure_iot_hub_client_telemetry_message_create(pnp_client_ptr, &packet_ptr, NX_WAIT_FOREVER)))
    {
        return(status);
    }

    if ((status = nx_azure_iot_hub_client_telemetry_component_set(packet_ptr, SAMPLE_PNP_GAS_COMPONENT_NAME, sizeof(SAMPLE_PNP_GAS_COMPONENT_NAME) - 1, NX_WAIT_FOREVER)))
    {
        return(status);
    }


    /* Build telemetry JSON payload.  */
    if (nx_azure_iot_json_writer_with_buffer_init(&json_writer, telemetry_buffer, sizeof(telemetry_buffer)))
    {
        nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
        return(NX_NOT_SUCCESSFUL);
    }

    /* TODO : Add function to get the Gas sensor data */
    temp = 20;
//	start_iaq_1st_gen_demo();
//	start_oaq_1st_gen_demo();


    /* Append ambient light property name and value.  */
    /* TODO : Replace real data from temp.*/
    if (nx_azure_iot_json_writer_append_begin_object(&json_writer) ||
        nx_azure_iot_json_writer_append_property_with_double_value(&json_writer,
                                                                   (UCHAR *)sample_pnp_iaq_property_name,
                                                                   sizeof(sample_pnp_iaq_property_name) - 1,
																   temp,
                                                                   DOUBLE_DECIMAL_PLACE_DIGITS) ||
		nx_azure_iot_json_writer_append_property_with_double_value(&json_writer,
																   (UCHAR *)sample_pnp_oaq_property_name,
																   sizeof(sample_pnp_oaq_property_name) - 1,
																   temp,
																   DOUBLE_DECIMAL_PLACE_DIGITS) ||
        nx_azure_iot_json_writer_append_end_object(&json_writer))
    {
    	printf("Telemetry message failed to build message\r\n");
        nx_azure_iot_json_writer_deinit(&json_writer);
        nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
        return(NX_NOT_SUCCESSFUL);
    }

    data_length = nx_azure_iot_json_writer_get_bytes_used(&json_writer);
    if ((status = nx_azure_iot_hub_client_telemetry_send(pnp_client_ptr, packet_ptr,
                                                         (UCHAR *)telemetry_buffer, data_length, NX_WAIT_FOREVER)))
    {
    	printf("Telemetry message send failed!: error code = 0x%08x\r\n", status);
        nx_azure_iot_json_writer_deinit(&json_writer);
        nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
        return(status);
    }

    nx_azure_iot_json_writer_deinit(&json_writer);
    nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
    /* TODO : Replace real data from temp.*/
    printf("Telemetry message sent: IAQ = %.2lf, OAQ = %.2lf\r\n", temp, temp);

    return(NX_AZURE_IOT_SUCCESS);
}
