file(GLOB_RECURSE SOURCE_FILES "src/*.c")

idf_component_register(SRCS ${SOURCE_FILES}
                    REQUIRES esp_wifi nvs_flash fatfs
                    INCLUDE_DIRS "includes")
