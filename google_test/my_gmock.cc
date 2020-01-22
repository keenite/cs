#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataBaseConnect {
public:
   virtual bool login(string username, string password) {return true;}
   virtual bool logout(string username) {return true;}
   virtual int fetchRecord() {return -1;}
};

class MockDB : public DataBaseConnect {
public:
   MOCK_METHOD0(fetchRecord, int ());
   MOCK_METHOD1(logout, bool (string username));
   MOCK_METHOD2(login, bool (string username, string password));
};

class MyDataBase {
   DataBaseConnect &dbC;
public:
   MyDataBase(DataBaseConnect & _dbC) : dbC(_dbC) {}
   int Init(string username, string password) {
      if (dbC.login(username, password) != true) {
         cout << "DB Failure\n";
         return -1;
      } else {
         cout << "DB Success\n";
         return 1;
      }
   }
};


TEST(MyDBTest, LoginSuccess) {
   MockDB mdb;
   MyDataBase db(mdb);
   //EXPECT_CALL(mdb, login("Terminator", "I'm Back"))
   EXPECT_CALL(mdb, login(_, _))
      .Times(AtLeast(1))
      .WillOnce(Return(true));

   int retValue = db.Init("Terminator", "I'm Back");

   EXPECT_EQ(retValue, 1);
}

TEST(MyDBTest, LoginFailure) {
   MockDB mdb;
   MyDataBase db(mdb);
   EXPECT_CALL(mdb, login(_, _))
      .Times(AtLeast(1))
      .WillOnce(Return(false));
   //.WillRepeatedly(Return(falase));

   int retValue = db.Init("Terminator", "I'm Back");

   EXPECT_EQ(retValue, -1);
}

TEST(MyDBTest, LoginTest) {
   MockDB mdb;
   MyDataBase db(mdb);
   //ON_CALL is func may be called, even called will return True
   //ON_CALL(mdb, login(_, _)).WillByDefault(Return(true));
   ON_CALL(mdb, login(_, _)).WillByDefault(Return(true));
   int retValue = db.Init("Terminator", "I'll be Back");
   EXPECT_EQ(retValue, 1);
}
