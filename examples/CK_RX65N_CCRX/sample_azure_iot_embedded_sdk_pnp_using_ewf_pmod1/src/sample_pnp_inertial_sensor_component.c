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

#include <math.h>
#include "nx_api.h"
#include "nx_azure_iot_hub_client.h"
#include "nx_azure_iot_hub_client_properties.h"
#include "RX_ZMOD4XXX_Common.h"
#include "ICM20948/icm20948.h"
#include "ICM20948/icm_i2c.h"

#define DOUBLE_DECIMAL_PLACE_DIGITS                                     (2)

#define SAMPLE_PNP_INERTIAL_COMPONENT_NAME                       "Inertial"

/* TODO : Add property name */
static const CHAR sample_pnp_accelerometerx_property_name[] = "accelerometerX";
static const CHAR sample_pnp_accelerometery_property_name[] = "accelerometerY";
static const CHAR sample_pnp_accelerometerz_property_name[] = "accelerometerZ";
static const CHAR sample_pnp_gyroscopex_property_name[] = "gyroscopeX";
static const CHAR sample_pnp_gyroscopey_property_name[] = "gyroscopeY";
static const CHAR sample_pnp_gyroscopez_property_name[] = "gyroscopeZ";
static const CHAR sample_pnp_compassx_property_name[] = "compassX";
static const CHAR sample_pnp_compassy_property_name[] = "compassY";
static const CHAR sample_pnp_compassz_property_name[] = "compassZ";

static CHAR telemetry_buffer[256];
//axises my_gyro;
//axises my_accel;

UINT sample_inertial_sensor_telemetry_messages_send(NX_AZURE_IOT_HUB_CLIENT *pnp_client_ptr);

UINT sample_inertial_sensor_telemetry_messages_send(NX_AZURE_IOT_HUB_CLIENT *pnp_client_ptr)
{
UINT status;
NX_PACKET *packet_ptr;
UINT data_length;
NX_AZURE_IOT_JSON_WRITER json_writer;

INT temp = 20;

    /* Create a telemetry message packet.  */
    if ((status = nx_azure_iot_hub_client_telemetry_message_create(pnp_client_ptr, &packet_ptr, NX_WAIT_FOREVER)))
    {
        return (status);
    }

    if ((status = (nx_azure_iot_hub_client_telemetry_component_set(packet_ptr, SAMPLE_PNP_INERTIAL_COMPONENT_NAME, sizeof(SAMPLE_PNP_INERTIAL_COMPONENT_NAME) - 1, NX_WAIT_FOREVER))))
    {
        return(status);
    }

     /* Build telemetry JSON payload.  */
     if (nx_azure_iot_json_writer_with_buffer_init(&json_writer, telemetry_buffer, sizeof(telemetry_buffer)))
     {
         nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
         return(NX_NOT_SUCCESSFUL);
     }

     /* Get the inertial sensor data */
     /* TODO : Add function to get the itertial sensor data */
//	icm20948_gyro_read_dps(&my_gyro);
//	icm20948_accel_read_g(&my_accel);


     /* Append ambient light property name and value.  */
     /* TODO : Replace real data from temp.*/
     if (nx_azure_iot_json_writer_append_begin_object(&json_writer) ||
		   nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_accelerometerx_property_name,
																	  sizeof(sample_pnp_accelerometerx_property_name) - 1,
																	  temp) ||
		   nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_accelerometerx_property_name,
																	  sizeof(sample_pnp_accelerometerx_property_name) - 1,
																	  temp) ||
	       nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_accelerometery_property_name,
																	  sizeof(sample_pnp_accelerometery_property_name) - 1,
																	  temp) ||
		   nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_accelerometerz_property_name,
																	  sizeof(sample_pnp_accelerometerz_property_name) - 1,
																	  temp) ||
		   nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_gyroscopex_property_name,
																	  sizeof(sample_pnp_gyroscopex_property_name) - 1,
																	  temp) ||
		   nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_gyroscopey_property_name,
																	  sizeof(sample_pnp_gyroscopey_property_name) - 1,
																	  temp) ||
		   nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_gyroscopez_property_name,
																	  sizeof(sample_pnp_gyroscopez_property_name) - 1,
																	  temp) ||
		   nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_compassx_property_name,
																	  sizeof(sample_pnp_compassx_property_name) - 1,
																	  temp) ||
		   nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_compassy_property_name,
																	  sizeof(sample_pnp_compassy_property_name) - 1,
																	  temp) ||
		   nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  (UCHAR *)sample_pnp_compassz_property_name,
																	  sizeof(sample_pnp_compassz_property_name) - 1,
																	  temp) ||
         nx_azure_iot_json_writer_append_end_object(&json_writer))
     {
         nx_azure_iot_json_writer_deinit(&json_writer);
         nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
         return(NX_NOT_SUCCESSFUL);
     }

     data_length = nx_azure_iot_json_writer_get_bytes_used(&json_writer);
     if ((status = nx_azure_iot_hub_client_telemetry_send(pnp_client_ptr, packet_ptr,
                                                          (UCHAR *)telemetry_buffer, data_length, NX_WAIT_FOREVER)))
     {
         nx_azure_iot_json_writer_deinit(&json_writer);
         nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
         return(status);
     }

     nx_azure_iot_json_writer_deinit(&json_writer);
     /* TODO : Replace real data from temp. */
//     printf("Telemetry message sent: accel_x = %f, accel_y = %f, accel_z = %f, ", my_accel.x, my_accel.y, my_accel.z);
//     printf("gyro_x = %f, gyro_y = %f, gyro_z = %f ", my_gyro.x, my_gyro.y, my_gyro.z);
     printf("compass_x = %d, compass_y = %d, compass_z = %d\r\n", (INT)temp, (INT)temp, (INT)temp);

    return(NX_AZURE_IOT_SUCCESS);
}
