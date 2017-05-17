#ifndef TWITTERHANDLER_HPP
#define TWITTERHANDLER_HPP

#include <string>

struct twitterData
{

};

class TwitterHandler {
private:
	twitterData myTwitterData;





public:
	TwitterHandler();
	~TwitterHandler();

	void Initialize(std::string Twitterlink);
	void EstablishConnectionWithTwitter();
	void GetTwitterData(twitterData twitterdata);



};


#endif