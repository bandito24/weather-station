#include "fat_init.h"


void init_fat() {

  sdmmc_host_t host = SDMMC_HOST_DEFAULT();
  host.flags = SDMMC_HOST_FLAG_1BIT;
  host.max_freq_khz = SDMMC_FREQ_DEFAULT;

  sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();
  slot_config.width = 1; // 1-bit mode
  slot_config.clk = 14;  // SD_MMC_CLK
  slot_config.cmd = 15;  // SD_MMC_CMD
  slot_config.d0 = 2;    // SD_MMC_D0

  sdmmc_card_t *card;
  esp_vfs_fat_sdmmc_mount_config_t mount_config = {
      .format_if_mount_failed = false,
      .max_files = 5,
      .allocation_unit_size = 16 * 1024};

  esp_err_t ret = esp_vfs_fat_sdmmc_mount(FS_BASE, &host, &slot_config,
                                          &mount_config, &card);
  if (ret != ESP_OK) {
    ESP_LOGE("SD", "Failed to mount SD card: %s", esp_err_to_name(ret));
  } else {
    ESP_LOGI("SD", "SD card mounted successfully");
    sdmmc_card_print_info(stdout, card);
  }
}