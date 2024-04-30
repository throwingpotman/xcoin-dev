// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>

namespace CryptoNote {
namespace parameters {

const uint32_t HF_APR18_HEIGHT                               = 1; // offset by one! actually 70913
const uint32_t HF_SEP18_HEIGHT                               = 119000; 

const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 7237;
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW         = 50;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 500;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(2100000000000000);
const unsigned EMISSION_SPEED_FACTOR                         = 21;
const uint64_t GENESIS_BLOCK_REWARD                          = UINT64_C(42);
const uint64_t SECOND_BLOCK_REWARD                           = UINT64_C(840000000000000);
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 128000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V4  = 350000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V3  = 20000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 10000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000);

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   LEGACY_DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   LEGACY_DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   LEGACY_DIFFICULTY_LAG                                = 15;  // !!!
const size_t   LWMA_DIFFICULTY_WINDOW                             = 60; // blocks
const size_t   LWMA_DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting - not used atm
const size_t   LWMA_DIFFICULTY_LAG                                = 0;  // !!!
static_assert(2 * LEGACY_DIFFICULTY_CUT <= LEGACY_DIFFICULTY_WINDOW - 2, "Bad LEGACY_DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint32_t MAX_BLOCK_SIZE_INITIAL_SWITCH_BLOCK_HEIGHT    = HF_SEP18_HEIGHT; // Block version 5: MAX_BLOCK_SIZE_INITIAL, previously PREVIOUS_MAX_BLOCK_SIZE_INITIAL
const size_t   PREVIOUS_MAX_BLOCK_SIZE_INITIAL               = 20 * 1024;
const size_t   MAX_BLOCK_SIZE_INITIAL                        = 120 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = MAX_BLOCK_SIZE_INITIAL * 75 / 100;  // was: CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 0;
const uint32_t UPGRADE_HEIGHT_V2                                = 1;
const uint32_t UPGRADE_HEIGHT_V3                                = 2;
const uint32_t UPGRADE_HEIGHT_V4                                = HF_APR18_HEIGHT;
const uint32_t UPGRADE_HEIGHT_V5                                = HF_SEP18_HEIGHT;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "Xcoin";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MAJOR_VERSION_5                         =  5;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  20000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  2000;

const int      P2P_DEFAULT_PORT                              =  28688;
const int      RPC_DEFAULT_PORT                              =  28689;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 128 * 1024 * 1024; // 128 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 12;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 100000000;      // 100000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const char* const SEED_NODES[] = { "communitypool.org:28688", "explorer.xcoincrypto.org:28688", "54.39.195.212:28688", "173.208.176.252:28688" };


struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
  {1, "abdbc7c33d9be1f06ae4e1987246625b1f6e46b99820e4693baa7f395b4a8edf"},
  {100, "2eacadb21b2773834d24a5440e17c57a746e2898e20445340d9a1fb49c9bfc82"},
  {1000, "ac9a2aa114b1ceea5ac5538d275bef2c3ac191e95bff68a149546f9c075564d6"},
  {10000, "07f9dc9440a70784a197a3a57b2eb7063d0ebae1117107a33f38b532c8df52a1"},
  {50000, "abe389870d55e2837900da6beb0994697a821a4a3756ac6cde94faf7a9c86a4a"},
  {70000, "3b687fdc617bc656bf187d4955fbfa79b00f66553f3c3f8674fd891fb6b1ffc8"},
  {100000, "1748391c8dafaa4bf06f816b7328c6603b6cfc2dd65595b9b522f0f7f09e6ecc"},
  {110000, "08487cc0c9fce7b1793b0c3ecbbe909bb32cfeac1fe73787a9b149dc39b71ccc"},
  {118999, "6b0e552662fe24ab8b0ffde263e090671d7b241592b5fa7c9b186fcd636556ca"},
  {119000, "e3937ca528f5a6a6cff00cabc172ab8ef3549f67f3e97501ac5e4d6754d08e00"},
  {119001, "0dd51bdf6229c0ba8b584a0607a17f97afdcd495323a401218b2862fa27a232a"},
  {150000, "2a0b4251d2e62203188dbe411d5c04ccc54063ce78d817b5bb80d81b92723b7f"},
  {200000, "8af5100dde879736887a21fbd34611817ea6c56eb91fc1e696e0b9ce68775b04"},
  {200069, "fc36d51bf68f3ac1ef5c2071371a454dbadd4f2a0f0ff92d56d2015e9dc074b9"},
  {200070, "9d206d02613be8e83fb84cc676bdadf77f2f245bcce5a499373b1501abd4c891"},
  {200071, "c77fc6a66f1cfcccccba9d8bcc07889fa14590794e1719639f31b0d92aff67d0"},
  {200072, "6010623af89385f80d7a93e855af2deee234b6a4e6100165f21dfc91c30783d5"},
  {205000, "208f2bd3d639410d235a9a71653309d1bc6b08050569ebcd3c9ab6338609394b"},
  {210238, "39ec1618b90def4d343121f273e081fc506cb21d15681f8e9fb51718683c6865"},
  {300000, "45ca93248b0d00b070c57d8d3d59597a0d1f5ff3125ad7a59d814a4e9d147c6e"},
  {350000, "d7834869655dfeab311f832f7e41dfd7fc223f0f71f7bcf7aaf6f4785c9ff58f"},
  {400000, "0c4cbbd92ffd38d5a396a8621be8b8ea8fdc01818b1dd1fc3b6314fb11c6b26c"},
  {450000, "c586b92446b8a8d481a92cb2ac07d7747df40f991b2e2996ce0952ca8bd785f2"},
  {500000, "4853b04a66623b03e4a2b86f63ed8e8aa236007a4c8c72dfd10376fcb18c405a"},
  {550000, "315f92c57b515d55b071693e2f841aab26c0f02e32660caa4b5b03b67453984c"},
  {600000, "9c825b8cc32062e4962aca0161f709162dee5bd20aea7a60993fcc463e09b411"},
  {650000, "4a7730c04b8edd662218c85a9f7bb9667ad78c601a660cf1b2c420d22d3899d8"},
  {684863, "b951866bdcc9363ac15d6f560b36e38cc637371a9982245ec53993705c530d4a"}
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS



