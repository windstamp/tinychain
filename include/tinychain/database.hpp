#pragma once
#include <algorithm>
#include <tinychain/tinychain.hpp>
#include <sqlite3pp/sqlite3pp.h>
//#include <sqlite3pp/sqlite3ppext.h>

namespace tinychain
{

class database
{
public:
    database()  {};
    database(const database&)  = default;
    database(database&&)  = default;
    database& operator=(database&&)  = default;
    database& operator=(const database&)  = default;

    virtual void print();
    void init();

protected:
    const char* db_name_ = "tinychain.db";
};

class chain_database: public database
{
public:
    
    chain_database()  {};
    chain_database(const chain_database&)  = default;
    chain_database(chain_database&&)  = default;
    chain_database& operator=(chain_database&&)  = default;
    chain_database& operator=(const chain_database&)  = default;

    void print(){
        //for (auto& each : queue_ ) {
        //    log::info("block")<<each.to_string();
        //};
    }
    void test();

    uint64_t height() { return 11u; }

    auto get_last_block() { return true; }

    bool get_block (const sha256_t block_hash, block& b) {
        return true;
    }

    bool get_tx (const sha256_t tx_hash, tx& t) {
        return true;
    }

    virtual ~chain_database(){
        db_conn_.disconnect();
    }

private:
    sqlite3pp::database db_conn_{db_name_};
};

// 相当于是本地钱包的私钥管理
class key_pair_database:public database
{
public:
    typedef std::vector<key_pair> key_pair_list_t;

    key_pair_database()  {};
    key_pair_database(const key_pair_database&)  = default;
    key_pair_database(key_pair_database&&)  = default;
    key_pair_database& operator=(key_pair_database&&)  = default;
    key_pair_database& operator=(const key_pair_database&)  = default;

    void print(){ std::cout<<"class key_pair_database"<<std::endl; }
    void test();

    key_pair get_new_key_pair();

    bool list_keys(key_pair_list_t& key_list);

private:
    sqlite3pp::database db_conn_{db_name_};
};

}// tinychain
