#include <memory>
#include <odb/core.hxx>
#include <odb/lazy-ptr.hxx>
#include <set>
#include <string>
/*------Edit----------*/
#include <vector>

using std::vector;
using odb::lazy_shared_ptr;
using odb::lazy_weak_ptr;
/*------End----------*/
using std::string;

#pragma db view
class StarCount{
public:
	int stars;
	int count;
};

#pragma db view query("select top 1 text, last_elapsed_time from sys.dm_exec_query_stats cross apply sys.dm_exec_sql_text(sql_handle) order by last_execution_time desc")
class LastQueryTime{
public:
	std::string text;
	long elapsed_time;
};

// ---------------------------------------------
// No need to change anything above this line
// ---------------------------------------------
#pragma db object
class hours{
public:
    #pragma db id
        int id;
        string hours;

    #pragma db inverse(hours_)
    lazy_weak_ptr<business> business_;
};

#pragma db object
class business{
public:
    #pragma db id
     string city;

    #pragma db not_null
     lazy_shared_ptr<hours> hours_;
};

#pragma db object
class review{
public:
    #pragma db id
	    int id;
	    int business_id;
        int user_id;

    #pragma db not_null
        lazy_shared_ptr<user> user_;
};

#pragma db object
class user{
public:
#pragma db id
    int id;

#pragma db value_not_null inverse(user_)
    std::vector<lazy_weak_ptr<review> > review_;
};

/*
 CREATE TABLE " user " (
"id" varchar (22) NOT NULL ,
" name " varchar (255) DEFAULT NULL ,
" review_count " int DEFAULT NULL ,
" yelping_since " datetime DEFAULT NULL ,
" useful " int DEFAULT NULL ,
" funny " int DEFAULT NULL ,
" cool " int DEFAULT NULL ,
" fans " int DEFAULT NULL ,
" average_stars " float DEFAULT NULL ,
" compliment_hot " int DEFAULT NULL ,
" compliment_more " int DEFAULT NULL ,
" compliment_profile " int DEFAULT NULL ,
" compliment_cute " int DEFAULT NULL ,
" compliment_list " int DEFAULT NULL ,
" compliment_note " int DEFAULT NULL ,
" compliment_plain " int DEFAULT NULL ,
" compliment_cool " int DEFAULT NULL ,
" compliment_funny " int DEFAULT NULL ,
" compliment_writer " int DEFAULT NULL ,
" compliment_photos " int DEFAULT NULL ,
PRIMARY KEY ("id")
);


CREATE TABLE " business " (
"id" varchar (22) NOT NULL ,
" name " varchar (255) DEFAULT NULL ,
" neighborhood " varchar (255) DEFAULT NULL ,
" address " varchar (255) DEFAULT NULL ,
" city " varchar (255) DEFAULT NULL ,
" state " varchar (255) DEFAULT NULL ,
" postal_code " varchar (255) DEFAULT NULL ,
" latitude " float DEFAULT NULL ,
" longitude " float DEFAULT NULL ,
" stars " float DEFAULT NULL ,
" review_count " int DEFAULT NULL ,
" is_open " tinyint DEFAULT NULL ,
PRIMARY KEY ("id")
);
CREATE TABLE " category " (
" business_id " varchar (22) NOT NULL ,
" category " varchar (255) DEFAULT NULL ,
);
CREATE TABLE " checkin " (
" business_id " varchar (22) NOT NULL ,
" date " varchar (255) DEFAULT NULL ,
" count " int DEFAULT NULL ,
);
CREATE TABLE " elite_years " (
" user_id " varchar (22) NOT NULL ,
" year " char (4) DEFAULT NULL ,
);
CREATE TABLE " friend " (
" user_id " varchar (22) NOT NULL ,
" friend_id " varchar (22) DEFAULT NULL ,
);
CREATE TABLE " hours " (
"id" int not null ,
" hours " varchar (255) DEFAULT NULL ,
" business_id " varchar (22) NOT NULL ,
PRIMARY KEY ("id")
);
CREATE TABLE " photo " (
"id" varchar (22) NOT NULL ,
" business_id " varchar (22) NOT NULL ,
" caption " varchar (255) DEFAULT NULL ,
" label " varchar (255) DEFAULT NULL ,
PRIMARY KEY ("id"),
);
CREATE TABLE " review " (
"id" varchar (22) NOT NULL ,
" stars " int DEFAULT NULL ,
" date " datetime DEFAULT NULL ,
" text " text ,
" useful " int DEFAULT NULL ,
" funny " int DEFAULT NULL ,
3
" cool " int DEFAULT NULL ,
" business_id " varchar (22) NOT NULL ,
" user_id " varchar (22) NOT NULL ,
PRIMARY KEY ("id"),
);
CREATE TABLE "tip" (
" user_id " varchar (22) NOT NULL ,
" business_id " varchar (22) NOT NULL ,
" text " text ,
" date " datetime DEFAULT NULL ,
" likes " int DEFAULT NULL ,
);

 test remotely!
*/
