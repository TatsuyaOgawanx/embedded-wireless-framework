if(NOT ASC_COMPONENT_CONFIGURATION)
  set(ASC_COMPONENT_CONFIGURATION_PLAT OFF)
endif()

if(NOT ASC_COMPONENT_COMMAND_EXECUTOR)
  set(ASC_OPERATIONS_POOL_ENTRIES 0)
  set(ASC_COMPONENT_CONFIGURATION_PLAT OFF)
endif()

if(NOT ASC_COLLECTOR_BASELINE_ENABLED)
  set(ASC_BASELINE_REPORT_POOL_ENTRIES 0)
  set(ASC_COMPONENT_BASELINE_PLAT OFF)
endif()

if(NOT ASC_COLLECTOR_LOG_ENABLED)
  set(ASC_LOG_REPORT_POOL_ENTRIES 0)
endif()

if(NOT ASC_COLLECTOR_NETWORK_ACTIVITY_ENABLED)
  set(ASC_COLLECTOR_NETWORK_ACTIVITY_SEND_EMPTY_EVENTS OFF)
  set(ASC_COLLECTOR_NETWORK_ACTIVITY_MAX_IPV4_OBJECTS_IN_CACHE 0)
  set(ASC_COLLECTOR_NETWORK_ACTIVITY_MAX_IPV6_OBJECTS_IN_CACHE 0)
endif()

if(NOT ASC_COLLECTOR_PROCESS_ENABLED)
  set(ASC_COLLECTOR_PROCESS_SEND_EMPTY_EVENTS OFF)
  set(ASC_COLLECTOR_PROCESS_IN_CACHE 0)
  set(ASC_COLLECTOR_PROCESS_MODE_AGGREGATED_DISABLE OFF)
endif()

if(NOT ASC_DYNAMIC_FACTORY_ENABLED)
  set(ASC_DYNAMIC_COMPONENTS_MAX 0)
  set(ASC_DYNAMIC_COLLECTORS_MAX 0)
  set(ASC_DYNAMIC_FACTORY_PATH OFF)
  set(ASC_DYNAMIC_FACTORY_PATH_RUNTIME_SET OFF)
endif()

if(FLATCC_NO_ASSERT)
  set(FLATCC_ASSERT OFF)
endif()

if(NOT ASC_DYNAMIC_MEMORY_ENABLED)
  set(ASC_SERIALIZER_USE_CUSTOM_ALLOCATOR ON)
  set(ASC_EMITTER_PAGE_CACHE_SIZE 1)
else()
  set(FLATCC_EMITTER_PAGE_SIZE 14016)
endif()
