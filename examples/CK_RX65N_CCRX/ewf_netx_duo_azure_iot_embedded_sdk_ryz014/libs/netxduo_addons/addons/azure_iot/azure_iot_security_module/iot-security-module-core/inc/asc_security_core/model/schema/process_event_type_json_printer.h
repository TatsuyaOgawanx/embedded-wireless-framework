#ifndef PROCESS_EVENT_TYPE_JSON_PRINTER_H
#define PROCESS_EVENT_TYPE_JSON_PRINTER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#include "flatcc/flatcc_json_printer.h"
#include "flatcc/flatcc_prologue.h"


static void AzureIoTSecurity_ProcessEventType_print_json_enum(flatcc_json_printer_t *ctx, int8_t v)
{

    switch (v) {
    case 0: flatcc_json_printer_enum(ctx, "FORK", 4); break;
    case 1: flatcc_json_printer_enum(ctx, "EXEC", 4); break;
    case 2: flatcc_json_printer_enum(ctx, "EXIT", 4); break;
    default: flatcc_json_printer_int8(ctx, v); break;
    }
}

#include "flatcc/flatcc_epilogue.h"
#endif /* PROCESS_EVENT_TYPE_JSON_PRINTER_H */
