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
using std::shared_ptr;
using std::weak_ptr;
using odb::lazy_ptr;
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

class user;
class review;
class business;
class hours;

#pragma db object
class user{
public:
	#pragma db id //column("id") type("VARCHAR(22)") not_null
		string id;
		string name;

	#pragma db value_not_null inverse(user_id)
		//std::vector<lazy_weak_ptr<review>> review_;
        //std::vector<std::weak_ptr<review>> review_;
        std::vector<lazy_ptr<review>> review_;

	const std::string& getName() {
		return name;
	}

	const std::string& getId() {
		return id;
	}

};

#pragma db object
class review{
public:
    #pragma db id
	    string id;
	    //string business_id;
        //string user_id;

    #pragma db not_null
        std::shared_ptr<user> user_id;
		//lazy_shared_ptr<user> user_id;

	#pragma db not_null
		//lazy_shared_ptr<business> business_;
        shared_ptr<business> business_id;
};



#pragma db object
class business{
public:
    #pragma db id
		string id;

    #pragma db value_not_null inverse(business_id)
            //std::vector<lazy_weak_ptr<review>> review_;
            //std::vector<weak_ptr<review>> review_;
            std::vector<lazy_ptr<review>> review_;
    #pragma db value_not_null inverse(business_id)
        //std::vector<lazy_weak_ptr<hours>> hours_;
        //std::vector<weak_ptr<hours>> hours_;
        std::vector<lazy_ptr<hours>> hours_;
};

#pragma db object
class hours{
public:
    #pragma db id
	    int id;
	    string hours;

    #pragma db not_null
	    //lazy_shared_ptr<business> business_id;
        shared_ptr<business> business_id;
};

