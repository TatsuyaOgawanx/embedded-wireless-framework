/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The EWF Thales/Cinterion modem common adapter driver tokenizer patterns and functions
 * 
 * These custom function matching patterns are not reentrant, they can be used by only one interface at a time.
 * If you have more than one adapter at the same time, you will need to provide separate state for each one.
 * The code is prepared for that. Use an instance specific state structure instead of the global static here.
 * 
 ****************************************************************************/

#include "ewf_adapter_thales_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

/************************************************************************//**
 * command response end tokenizer pattern list
 ****************************************************************************/

char ewf_adapter_thales_common_command_response_end_tokenizer_pattern5_str[] = "\r\n+CME ERROR: ???\r\n";
char ewf_adapter_thales_common_command_response_end_tokenizer_pattern4_str[] = "\r\n+CME ERROR: ??\r\n";
char ewf_adapter_thales_common_command_response_end_tokenizer_pattern3_str[] = "\r\n+CME ERROR: ?\r\n";
char ewf_adapter_thales_common_command_response_end_tokenizer_pattern2_str[] = "\r\nERROR\r\n";
char ewf_adapter_thales_common_command_response_end_tokenizer_pattern1_str[] = "\r\nOK\r\n";

static ewf_interface_tokenizer_pattern ewf_adapter_thales_common_command_response_end_tokenizer_pattern5 =
{
    NULL,
    ewf_adapter_thales_common_command_response_end_tokenizer_pattern5_str,
    sizeof(ewf_adapter_thales_common_command_response_end_tokenizer_pattern5_str) - 1,
    true,
};

static ewf_interface_tokenizer_pattern ewf_adapter_thales_common_command_response_end_tokenizer_pattern4 =
{
    &ewf_adapter_thales_common_command_response_end_tokenizer_pattern5,
    ewf_adapter_thales_common_command_response_end_tokenizer_pattern4_str,
    sizeof(ewf_adapter_thales_common_command_response_end_tokenizer_pattern4_str) - 1,
    true,
};

static ewf_interface_tokenizer_pattern ewf_adapter_thales_common_command_response_end_tokenizer_pattern3 =
{
    &ewf_adapter_thales_common_command_response_end_tokenizer_pattern4,
    ewf_adapter_thales_common_command_response_end_tokenizer_pattern3_str,
    sizeof(ewf_adapter_thales_common_command_response_end_tokenizer_pattern3_str) - 1,
    true,
};

static ewf_interface_tokenizer_pattern ewf_adapter_thales_common_command_response_end_tokenizer_pattern2 =
{
    &ewf_adapter_thales_common_command_response_end_tokenizer_pattern3,
    ewf_adapter_thales_common_command_response_end_tokenizer_pattern2_str,
    sizeof(ewf_adapter_thales_common_command_response_end_tokenizer_pattern2_str) - 1,
    false,
};

static ewf_interface_tokenizer_pattern ewf_adapter_thales_common_command_response_end_tokenizer_pattern1 =
{
    &ewf_adapter_thales_common_command_response_end_tokenizer_pattern2,
    ewf_adapter_thales_common_command_response_end_tokenizer_pattern1_str,
    sizeof(ewf_adapter_thales_common_command_response_end_tokenizer_pattern1_str) - 1,
    false,
};

static ewf_interface_tokenizer_pattern* ewf_adapter_thales_common_command_response_end_tokenizer_pattern_ptr = &ewf_adapter_thales_common_command_response_end_tokenizer_pattern1;

/************************************************************************//**
 * command response tokenizer pattern list
 ****************************************************************************/

char ewf_adapter_thales_common_command_response_tokenizer_pattern1_str[] = "\r\n";

static ewf_interface_tokenizer_pattern ewf_adapter_thales_common_command_response_tokenizer_pattern1 =
{
    NULL,
    ewf_adapter_thales_common_command_response_tokenizer_pattern1_str,
    sizeof(ewf_adapter_thales_common_command_response_tokenizer_pattern1_str) - 1,
    false,
};

static ewf_interface_tokenizer_pattern* ewf_adapter_thales_common_command_response_tokenizer_pattern_ptr = &ewf_adapter_thales_common_command_response_tokenizer_pattern1;

/************************************************************************//**
 * URC tokenizer pattern list
 ****************************************************************************/

char ewf_adapter_thales_common_urc_tokenizer_pattern1_str[] = "\r\n";

static ewf_interface_tokenizer_pattern ewf_adapter_thales_common_urc_tokenizer_pattern1 =
{
    NULL,
    ewf_adapter_thales_common_urc_tokenizer_pattern1_str,
    sizeof(ewf_adapter_thales_common_urc_tokenizer_pattern1_str) - 1,
    false,
};

static ewf_interface_tokenizer_pattern* ewf_adapter_thales_common_urc_tokenizer_pattern_ptr = &ewf_adapter_thales_common_urc_tokenizer_pattern1;

/************************************************************************//**
 * Message tokenizer pattern list
 ****************************************************************************/

struct _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
};

static struct _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state = { 0 };

static bool _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_interface_tokenizer_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state* state_ptr =
        (struct _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length == 1)
    {
        state_ptr->prefix_matches = false;
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    /* Define the message prefix and calculate its length */
    const char prefix_str[] = "\r\n^SIS";
    const uint32_t prefix_length = sizeof(prefix_str) - 1;

    /* If the buffer is smaller than the prefix, then it is not yet for us */
    if (buffer_length < prefix_length)
    {
        return false;
    }

    /* If the buffer contains as many characters as the prefix, then look if it is for us */
    if (buffer_length == prefix_length)
    {
        if (ewfl_buffer_equals_buffer(buffer_ptr, prefix_str, prefix_length))
        {
            state_ptr->prefix_matches = true;
            return false;
        }
    }

    /* At this point the buffer it is longer than the prefix */

    /* We did not match the prefix in previous runs, just ignore the rest of the incomming characters */
    if (!state_ptr->prefix_matches)
    {
        return false;
    }
    else
    {
        /* This is for us, stop parsing other tokens further down the list */
        *stop_ptr = true;
    }

    /* At this point we have a matching prefix */

    /* Is the message complete? */
    if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
    {
        /* Set the interface to URC mode */
        if (state_ptr->interface_ptr) state_ptr->interface_ptr->command_mode = false;

        /* Signal the match */
        return true;
    }
    else
    {
        /* Not yet matched */
        return false;
    }
}

static ewf_interface_tokenizer_pattern ewf_adapter_thales_common_message_tokenizer_pattern1 =
{
    NULL,
    NULL,
    0,
    false,
    _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function,
    &ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state
};

#if 0

struct _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state
{
    ewf_interface* interface_ptr;
};

static struct _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state = { 0 };

static bool _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_interface_tokenizer_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state* state_ptr =
        (struct _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length < 2)
    {
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    /* Is the message complete? */
    if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
    {
        /* Set the interface to URC mode */
        if (state_ptr->interface_ptr) state_ptr->interface_ptr->command_mode = false;

        /* Signal the match */
        return true;
    }

    /* Not yet matched */
    return false;
}

static ewf_interface_tokenizer_pattern ewf_adapter_thales_common_message_tokenizer_pattern1 =
{
    &ewf_adapter_thales_common_message_tokenizer_pattern2,
    NULL,
    0,
    false,
    _ewf_adapter_thales_common_message_tokenizer_pattern1_match_function,
    &ewf_adapter_thales_common_message_tokenizer_pattern1_match_function_state
};

#endif

ewf_interface_tokenizer_pattern* ewf_adapter_thales_common_message_tokenizer_pattern_ptr = &ewf_adapter_thales_common_message_tokenizer_pattern1;
