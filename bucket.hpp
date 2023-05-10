#include <string>
#include <map>

#include "s3service.pb.h"
#include "EntityBase.h"
#include "mssql.hpp"

class bucket : public EntityBase
{
	std::string m_bucketName, m_accountId, m_error, m_arn, m_creationTimestamp, m_bucketId,m_bucketVersion;
	std::map<std::string, std::string> m_tags;
	bool m_bExists;

    void setClassVariables(database& d);

    void setTags(std::map<std::string, std::string>& m);

    public:
	
	bucket(const std::string& bucketName, const std::string& accountId, database& d);
	
	void createBucket(s3service::s3bucket& bucketResponse, database& d);
	
	void deleteBucket(s3service::s3bucket& bucketResponse, database& d);
	
	// void putBucketPolicy(string bucketName,char *accessId, string bucketAccess = "true", string policyContent);
	
	// string getBucketPolicy(string bucketName, char* accountId);
	
	// string putBucketVersioning(string bucketName, char* accountId);
	
	// string getBucketVersioning(string bucketName,char* accoundId);
	
	void putBucketTags(std::map<std::string, std::string>& tags, s3service::s3bucket& bucketResponse,database& d);
	
	void listBucketTags(s3service::s3bucket& bucketResponse);

	void deleteBucketTags(s3service::s3bucket& bucketResponse,database& d);
	void put_Bucket_Version(s3service::s3bucket& bucketResponse,database& d);
	void get_Bucket_Version(s3service::s3bucket& bucketResponse,database& d);
	void list_object_version(s3service::s3bucket& bucketResponse,database& d);
	void list_object(s3service::s3bucket& bucketResponse,database& d);
	std::string getBucketName();

    std::string getBucketId();

    std::string getAccountId();

    std::string getArn();
    
    std::string getCreationTimestamp();

	std::string getErrorMessage();

	bool doesBucketExists();

	std::map<std::string, std::string> getTags();
	std::string getBucketVersion();
	
	virtual ~bucket();
	
	
};
