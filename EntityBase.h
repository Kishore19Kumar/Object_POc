#pragma once

#include "s3service.pb.h"

#include <ctime>

class EntityBase
{
	void getEntityResponse(s3service::serviceRequestResponse &response);
	void displayEntityResponse(s3service::serviceRequestResponse &response);

	public:

	std::string getUniqueId()
	{
		std::srand(std::time(nullptr));

		return std::to_string(std::rand());
	}

	std::string getCurrentTimeStamp()
	{
		time_t rawtime;
  		struct tm *timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, 80, "%FT%TZ", timeinfo);

		return buffer;
	}
};
