#include "wifi_conn.h"
#include "fat_init.h"
#include "http_client.h"

void init(){
    init_wifi_conn();
    init_fat();
    init_http_client();
    
}