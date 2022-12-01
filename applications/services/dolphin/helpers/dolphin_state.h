#pragma once

#include "dolphin_deed.h"
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

// Function macros helpers
#define REQUIRED_XP(LEVEL)                                            \
    (((LEVEL * LEVEL) + LEVEL) / 2 * LEVEL_XP_REQUIREMENT_INCREMENT - \
     (LEVEL * LEVEL_XP_REQUIREMENT_INCREMENT))
#define LEVEL_FOR_XP_DIVIDEND(XP)                                                               \
    (sqrt(LEVEL_XP_REQUIREMENT_INCREMENT * ((2 * XP) + (LEVEL_XP_REQUIREMENT_INCREMENT / 4))) + \
     (LEVEL_XP_REQUIREMENT_INCREMENT / 2))

#define DOLPHIN_STATE_PATH INT_PATH(DOLPHIN_STATE_FILE_NAME)
#define DOLPHIN_STATE_HEADER_MAGIC 0xD0
#define DOLPHIN_STATE_HEADER_VERSION 0x01
#define LEVEL_XP_REQUIREMENT_INCREMENT 3
#define LEVEL_MAX 255
#define LEVEL_XP_MAX REQUIRED_XP(LEVEL_MAX)
#define STAGE1_FORM_THRESHOLD 1
#define STAGE2_FORM_THRESHOLD 30
#define STAGE3_FORM_THRESHOLD 55
#define BUTTHURT_MAX 14
#define BUTTHURT_MIN 0

typedef struct DolphinState DolphinState;
typedef struct {
    uint8_t icounter_daily_limit[DolphinAppMAX];
    uint8_t butthurt_daily_limit;

    uint32_t flags;
    uint32_t icounter;
    int32_t butthurt;
    uint64_t timestamp;
} DolphinStoreData;

struct DolphinState {
    DolphinStoreData data;
    bool dirty;
};

DolphinState* dolphin_state_alloc();

void dolphin_state_free(DolphinState* dolphin_state);

bool dolphin_state_save(DolphinState* dolphin_state);

bool dolphin_state_load(DolphinState* dolphin_state);

void dolphin_state_clear_limits(DolphinState* dolphin_state);

uint64_t dolphin_state_timestamp();

void dolphin_state_on_deed(DolphinState* dolphin_state, DolphinDeed deed);

void dolphin_state_butthurted(DolphinState* dolphin_state);

uint32_t dolphin_state_xp_to_levelup(uint32_t icounter);

uint32_t dolphin_state_xp_above_last_levelup(uint32_t icounter);

bool dolphin_state_is_levelup(uint32_t icounter);

void dolphin_state_increase_level(DolphinState* dolphin_state);

uint8_t dolphin_get_level(uint32_t icounter);
