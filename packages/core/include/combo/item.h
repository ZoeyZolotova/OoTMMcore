#ifndef INCLUDED_COMBO_ITEMS_H
#define INCLUDED_COMBO_ITEMS_H

#include <combo/types.h>
#include <combo/data/items.h>

/* Add funcs */
#define IA_OOT_RUPEE            0x00
#define IA_MM_RUPEE             0x01
#define IA_OOT_WALLET           0x02
#define IA_MM_WALLET            0x03
#define IA_OOT_BOMBS            0x04
#define IA_MM_BOMBS             0x05
#define IA_OOT_NUTS             0x06
#define IA_MM_NUTS              0x07
#define IA_NUT_UPGRADE          0x08
#define IA_OOT_BOMBCHU          0x09
#define IA_MM_BOMBCHU           0x0a
#define IA_OOT_ARROWS           0x0b
#define IA_MM_ARROWS            0x0c
#define IA_OOT_BOW              0x0d
#define IA_MM_BOW               0x0e
#define IA_SEEDS                0x0f
#define IA_SLINGSHOT            0x10
#define IA_OOT_NORMAL           0x11
#define IA_MM_NORMAL            0x12
#define IA_OOT_STICKS           0x13
#define IA_MM_STICKS            0x14
#define IA_STICK_UPGRADE        0x15
#define IA_OOT_HOOKSHOT         0x16
#define IA_MM_HOOKSHOT          0x17
#define IA_OOT_TRADE_CHILD      0x18
#define IA_OOT_TRADE_ADULT      0x19
#define IA_MM_TRADE1            0x1a
#define IA_MM_TRADE2            0x1b
#define IA_MM_TRADE3            0x1c
#define IA_OOT_OCARINA          0x1d
#define IA_MM_OCARINA           0x1e
#define IA_OOT_BOTTLE_NEW       0x1f
#define IA_OOT_BOTTLE_REFILL    0x20
#define IA_MM_BOTTLE_NEW        0x21
#define IA_MM_BOTTLE_REFILL     0x22
#define IA_OOT_BEANS            0x23
#define IA_MM_BEANS             0x24
#define IA_OOT_SWORD            0x25
#define IA_MM_SWORD             0x26
#define IA_OOT_BOMB_BAG         0x27
#define IA_MM_BOMB_BAG          0x28
#define IA_OOT_SHIELD           0x29
#define IA_MM_SHIELD            0x2a
#define IA_TUNIC                0x2b
#define IA_BOOTS                0x2c
#define IA_STRENGTH             0x2d
#define IA_SCALE                0x2e
#define IA_OOT_QUEST            0x2f
#define IA_MM_QUEST             0x30
#define IA_OOT_HEART            0x31
#define IA_MM_HEART             0x32
#define IA_OOT_DEFENSE_UPGRADE  0x33
#define IA_MM_DEFENSE_UPGRADE   0x34
#define IA_OOT_HEART_PIECE      0x35
#define IA_MM_HEART_PIECE       0x36
#define IA_OOT_SMALL_KEY        0x37
#define IA_MM_SMALL_KEY         0x38
#define IA_OOT_KEY_RING         0x39
#define IA_MM_KEY_RING          0x3a
#define IA_OOT_SKELETON_KEY     0x3b
#define IA_MM_SKELETON_KEY      0x3c
#define IA_NONE                 0xff

typedef struct GameState_Play GameState_Play;

typedef struct ComboItemQuery
{
    s16 gi;
    s16 giRenew;
    u16 ovFlags;
    u8  ovType;
    u8  sceneId;
    u8  roomId;
    u8  id;
    u8  from;
}
ComboItemQuery;

typedef struct ComboItemOverride
{
    u8  player;
    u8  playerFrom;
    s16 giRaw;
    s16 gi;
}
ComboItemOverride;

extern u16 gMaxRupees[];
extern u16 gWalletDigits[];

#if defined(GAME_OOT)
# define gOotMaxRupees gMaxRupees
extern u16 gMmMaxRupees[];
#endif

#if defined(GAME_MM)
# define gMmMaxRupees gMaxRupees
extern u16 gOotMaxRupees[];
#endif

extern const u8 kMaxSticks[];
extern const u8 kMaxNuts[];
extern const u8 kMaxBombs[];
extern const u8 kMaxArrows[];
extern const u8 kMaxSeeds[];
extern const u8 kOotTradeChild[];
extern const u8 kOotTradeAdult[];
extern const u8 kMmTrade1[];
extern const u8 kMmTrade2[];
extern const u8 kMmTrade3[];

void comboSyncItems(void);

void reloadSlotOot(GameState_Play* play, int slot);
void reloadSlotMm(GameState_Play* play, int slot);

int  comboAddItemMm(s16 gi, int noEffect);
int  comboAddItemOot(s16 gi, int noEffect);
void comboAddItemSharedMm(s16 gi, int noEffect);
void comboAddItemSharedOot(s16 gi, int noEffect);
int  comboAddItemEffect(GameState_Play* play, s16 gi);
void comboAddItemSharedForeignEffect(GameState_Play* play, s16 gi);

void comboAddBossKeyOot(u16 dungeonId);
void comboAddCompassOot(u16 dungeonId);
void comboAddMapOot(u16 dungeonId);
void comboAddBossKeyMm(u16 dungeonId);
int  comboAddStrayFairyMm(u16 dungeonId);
void comboAddMapMm(u16 dungeonId);
void comboAddCompassMm(u16 dungeonId);

void comboAddMagicUpgradeOot(int level);
void comboAddMagicUpgradeMm(int level);

int  comboAddItem(GameState_Play* play, s16 gi);
int  comboAddItemLegacy(GameState_Play* play, s16 gi);
int  comboAddItemLegacyNoEffect(s16 gi);

int comboAddItemEx(GameState_Play* play, const ComboItemQuery* q, int updateText);

int isItemLicensed(s16 gi);
int isItemFastBuy(s16 gi);
int isItemBuyable(s16 gi);

int comboItemPrecondEx(const ComboItemQuery* q, s16 price);
s16 comboRenewable(s16 gi, s16 def);

#define ITEM_QUERY_INIT { 0 }

void comboGiveItem(Actor* actor, GameState_Play* play, const ComboItemQuery* q, float a, float b);
void comboGiveItemNpc(Actor* actor, GameState_Play* play, s16 gi, int npcId, float a, float b);
void comboGiveItemNpcEx(Actor* actor, GameState_Play* play, s16 gi, int npcId, int flags, float a, float b);
void comboItemOverride(ComboItemOverride* dst, const ComboItemQuery* q);

#endif

u8 comboSceneKey(u8 sceneId);
