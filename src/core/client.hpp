#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>
//
#include <nonCopyable.hpp>
//
#include <ext/SFMLAdapter.hpp>
#include <core/dataset.hpp>

class Server;
struct OutputData;
struct InputData;

/*TODO
 *have autonomous thread which renders until next data is received
 *networking stuff( ip etc. )
 *render only differences from previous data
 */


class Client : virtual NonCopyable, SFMLAdapter
{
public:
	Client();
	~Client();

	InputData requestInputData() noexcept;
	void receiveOutputData( OutputData outputData ) noexcept;

	void connect( Server* server );
	void disconnect();

	bool isConnected() const noexcept;
private:
	void render( const OutputData& outputData );

	Dataset mDataset;
	Server* mServer = nullptr;
};

#endif
