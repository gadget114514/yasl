#pragma once

#include <inttypes.h>

#include "prime/prime.h"
#include "interpreter/YASL_Object.h"
#include "interpreter/list.h"

#define LEN(v) (*((int64_t*)(v).value))

#define HT_BASESIZE 30

#define FOR_TABLE(i, item, table) Item_t *item; for (size_t i = 0; i < (table)->size; i++) \
                                                  if (item = &table->items[i], item->key.type != Y_END && !YASL_ISUNDEF(item->key))

typedef struct {
    struct YASL_Object key;
    struct YASL_Object value;
} Item_t;

struct Table {
    size_t size;
    size_t base_size;
    size_t count;
    Item_t *items;
};

static Item_t TOMBSTONE = { { Y_END, { Y_END } }, { Y_END, { Y_END } } }; //(struct YASL_Object) {Y_END, Y_END};

void del_item(Item_t* item);

struct Table *table_new(void);
void table_insert(struct Table *table, const struct YASL_Object key, const struct YASL_Object value);
void table_insert_string_int(struct Table *table, char *key, int64_t key_len, int64_t val);
void table_insert_literalcstring_cfunction(struct Table *ht, char *key, int (*addr)(struct YASL_State *), int num_args);
struct YASL_Object table_search(const struct Table *const table, const struct YASL_Object key);
struct YASL_Object table_search_string_int(const struct Table *const table, char *key, int64_t key_len);
void table_del(struct Table *table);
void table_del_string_int(struct Table *table);

struct RC_UserData* rcht_new(void);
struct RC_UserData* rcht_new_sized(const int base_size);
void rcht_del_data(struct RC_UserData *hashtable);
void rcht_del_rc(struct RC_UserData *hashtable);
void rcht_del_cstring_cfn(struct RC_UserData *hashtable);
