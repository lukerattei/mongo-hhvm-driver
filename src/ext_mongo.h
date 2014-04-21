#ifndef incl_HPHP_EXT_MONGO_H_
#define incl_HPHP_EXT_MONGO_H_

#include "mongo_common.h"
#include "bson_decode.h"
namespace HPHP {

static void mongoc_log_handler(mongoc_log_level_t log_level,
                               const char *log_domain, const char *message,
                               void *user_data) {
   if (log_level < MONGOC_LOG_LEVEL_INFO) {
      mongoc_log_default_handler(log_level, log_domain, message, NULL);
   }
}

class mongoExtension : public Extension {
public:
  mongoExtension() : Extension("mongo") {}
  virtual void moduleInit() {

    mongoc_log_set_handler(mongoc_log_handler, NULL);
    _initMongoClientClass();
    _initMongoCursorClass();
    _initMongoCollectionClass();
    _initBSON();
    loadSystemlib();
  }

private:
  void _initMongoClientClass();
  void _initMongoCursorClass();
<<<<<<< HEAD
  void _initMongoCollectionClass();
=======
  void _initBSON();
>>>>>>> 421cdba51a5411a2c01a5d900b4fde755d0fc53f
};

} // namespace HPHP

#endif // incl_HPHP_EXT_MONGO_H_
