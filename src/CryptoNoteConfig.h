// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
//TODO Currency-specific address prefix
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0xAB;
//TODO Choose maturity period for your currency
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 60;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30;

//TODO Specify total number of available coins
//TODO ((uint64_t)(-1)) equals to 18446744073709551616 coins
//TODO or you can define number explicitly UINT64_C(858986905600000000)
const uint64_t MONEY_SUPPLY                                  =UINT64_C(858986905600000000) ;
const unsigned EMISSION_SPEED_FACTOR                         = 18;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

//TODO Define number of blocks for block size median calculation
const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 10000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
//TODO Define number of digits
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
//TODO Define minimum fee for transactions
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = MINIMUM_FEE;

//TODO Define preferred block's target time
const uint64_t DIFFICULTY_TARGET                             = 180; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
//TODO There are options to tune CryptoNote's difficulty retargeting function.
//TODO We recommend not to change it.
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 30;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        =  20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

//TODO Put here the name of your currency
const char     CRYPTONOTE_NAME[]                             = "Monsterly";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010601ff0001808088a8b9b07029b2e4c0281c0b02e7c53292b32c1d0cbff8883f8024f5142ee494ffbbd088071210138dc57b313e2560fa75f5d7c9a6132575255220aefb3603bc70826adc83c5dd2";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

//TODO This port will be used by the daemon to establish connections with p2p network
const int      P2P_DEFAULT_PORT                              = 32080;
//TODO This port will be used by the daemon to interact with simlewallet
const int      RPC_DEFAULT_PORT                              = 32081;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "85ae8734f72ad1ee295abc0da05a49852d4dbbc8c5d17a619b5f4bdf26a0128d";

//TODO Add here your network seed nodes
const std::initializer_list<const char*> SEED_NODES = {
  //"your_seed_ip1.com:8080",
  //"your_seed_ip2.com:8080",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
  //{ 10000, "84b6345731e2702cdaadc6ce5e5238c4ca5ecf48e3447136b2ed829b8a95f3ad" },
   { 1100, "990a83b3e77ba5def86311da34793e09fa3b0a2875571bd59449173fddf4e129" },
    { 4200, "76af92fc41eadf9c99df91efc08011d0fce6f3f55b131da2449c187f432f91f7" },
    { 11000, "970c15459e4d484166c36e303fcf35886e14633b40b1fe4e3f250eb03eaca1f8" },
    { 22000, "ae9ab36c4ff2cf215d49ffa4358d108dd777b8897c2d873a064dc103fea2b5ab" },
    { 33000, "3fac95a900e65391d693e2cb331a26c757595baac133b9fa24936dd50fc7465f" },
    { 44000, "071a97648427ad25ec206ae7101534c9b011376f05dee04780b5edb22f9a919e" },
    { 47000, "a2fda9ea94260ed7177aec5b74802606bc7800d4a1713f761ac71a0883b4b480" },
    { 55000, "57f48bc9b2dddace94bddc8858cf1cdf5e68cc0db763d7ebcab71b388755e0ce" },
    { 66000, "90a2bc9e75503d386d41c48e698d474c337291f8c4417d63e90a8b5727f06320" },
    { 80550, "169e6b813b8ee072735bf7f7dc45b9b712b89a1317d1a4e672f6bba785a564fc" },
    { 99000, "2a83ce4fbd12ccb2eb60869d11d6b4212e8a810ab33408a2feaa3066d2853d9f" },
    { 122000, "926e915d84af28a8908809ae94f75bdea50d99d2d1a67fd5598bb91ccdf62c83" },
    { 132000, "b58a6b387d3120ea11061642a6a78a9a4b7800b77a44fae7ec1c73b60f2e375f" },
    { 136212, "5a935b048194d8b6ffb33b744c73cbe632da4f3c4d5e4c4488967d9431ba2a36" },
    { 136213, "336b687fdb96457cf4060072f76fc9e4e9281744822e0892c9ea128445bbebc7" },
    { 137000, "ae73be718076ab00371f81fa5f604c9e020f25abcb48f85b631bde0cabaff048" },
    { 143000, "2a9dc9638f091078a67d085ae97caa28f1061c0ae088463977f3df6435a9b585" },
    { 145000, "4b2bbfc07f42ae151119f732e568cba3bee2a0031e3eded2c94958b830e07e5a" },
    { 147000, "fe3eaf9a565426fe0498377157b62edd3c139e4b18803a4ca9bb6f78a6c0686b" },
    { 156700, "c3f250d8009ac15860095835e3f3c696c470fada129cae6e0946e1cdc1d2f51a" },
    { 159200, "fa120a1ef19a13c3fc629a781e37e31617c36e0b99321e3959a7e3f25ff281d3" },
    { 222000, "f74f764b1f3df8ab039657f73486fcc3a91dab2018e38b5c1d7838bb6a947711" },
    { 252525, "7798185c79c06fe58f04f69d7f5f0b0d2a08003fd1c9b11707b5d54d63b26832" },
    { 253000, "43c3acbd7e235d2efbf9409c8c3e1bfdc29780b200804608b668f8d5b2251220" },
    { 258852, "9f2b0ff556c8088b498928e835134727aede39832bf3c66cc439384b12bab289" },
    { 317000, "775fe833c74ca0e0de22a259364379e83a1b228c99cfdabc52e50beabacf08d3" },
    { 336336, "0075d20bf2b378750a5cc34baa208f75bf3119c5cb009b2b4182e733dff34b67" },
    { 360000, "296cf882a4d14a12de1403ff9326b446ba3694b032fa46e33136a58903897475" },
    { 385000, "79de0d2a49a2ad3407003931c0caa2cd040594519fcaf955ae724909334883ee" },
    { 418020, "23f02d8af6318504659e94c55047ac464ad35d42ca4af5668c279f1e484fad19" },
};
} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
