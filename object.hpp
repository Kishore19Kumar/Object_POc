#include <string>
#include <vector>
#include <fstream>
//////////////////////////
#include <fcntl.h>



#include <sys/stat.h>
#include <boost/filesystem.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <cstdint>
#include <boost/filesystem.hpp>


///////////////////////
#include "EntityBase.h"
#include "s3service.pb.h"
#include "serversocket.hpp"
#include "mssql.hpp"

//////////////////////
#include <sstream>
#include <openssl/sha.h>
class object : public EntityBase
{	
    std::string m_objectId, m_bucketId, m_objectName, m_creationTimestamp, m_error, m_versionStatus, m_versionId, m_fileSize,m_unique_multipart_id;
    std::vector<char> m_data;
    bool m_bExists;

    // create table Msys_Objects(objectId varchar(255) PRIMARY KEY, objectName varchar(255) NOT NULL, creationTimestamp varchar(255) NOT NULL, bucketId varchar(255) FOREIGN KEY REFERENCES Msys_Buckets(bucketId))

    auto readFromFile(serverSocket& ssWrite, const std::string& objectPath, s3service::s3object& objResponse);

	bool writeToFile(serverSocket& ss, s3service::s3object& objectRequest);

    void setClassVariables(database& d);
    static std::string generateVersionId(const std::string& filename);

//    GUID getUploadId(const std::string& objectKey);
//
//    std::string getMd5Checksum(const std::string& data);
//
//	std::string getETag();
//
//	std::string getFinalETag(std::vector<std::string>& etags);
//
//	std::string getObjectKey();
	
	bool isObjectPresent();

	inline void setData(const std::vector<char>& data);

    public:
	object(const std::string& bucketId, const std::string& objectName, database& d);
	void putObject(serverSocket& ss, s3service::s3object& objectRequest, s3service::s3object& objectResponse,database& d,std::string BucketVersion);

	
	void deleteObject(database& d);

	void downloadObject(serverSocket& ssWrite, s3service::s3object& objectRequest, s3service::s3object& objectResponse, database& d);
	
	
	
	
	void getObjectProperties(serverSocket& ss, s3service::s3object& objectRequest, s3service::s3object& objectResponse, database& d);
	void initMultiPartUpload(serverSocket& ss, s3service::s3object& objectRequest, s3service::s3object& objectResponse, database& d);
	void putMultiPartUpload(serverSocket& ss, s3service::s3object& objectRequest, s3service::s3object& objectResponse, database& d);
	void completeMultiPartUpload(serverSocket& ss, s3service::s3object& objectRequest, s3service::s3object& objectResponse, database& d);
	void abortMultiPartUpload(serverSocket& ss, s3service::s3object& objectRequest, s3service::s3object& objectResponse, database& d);
	void listMultiPartUpload(serverSocket& ss, s3service::s3object& objectRequest, s3service::s3object& objectResponse, database& d);
	long getFileSize(std::string filename);
	//int uploadFile(serverSocket& ss, string file_name);
	int downloadFile(serverSocket& ss, string file_name, unsigned long long bytes);
	
	
	// bool copyObject(wstring targetBucket);

	// GUID createMultipartUpload();

	// std::string uploadPart(const std::string& body, long objectSize, GUID uploadId, int partNumber, std::string checksum);

	// std::vector<std::string> completeMultipartUpload(std::string body, const GUID uploadId);
	
	// bool listParts(int maxParts, int partNumber);
	
	// bool listMultipartUploads(int maxParts, const int partNumber);
	
	// bool abortMultipartUpload(const int partNumber);

//	bool getObjectTagging(std::string versionID = "dummy value");
//
//	bool putObjectTagging(wstring checksum, wstring versionID = "dummy value");

	inline std::string getObjectName();

	inline std::string getBucketId();

	inline std::string getObjectId();

	inline std::vector<char> getData();

	inline std::string getCreationTimestamp();

	inline bool doesObjectExists();

	std::string getErrorMessage();

    ~object();    
};
