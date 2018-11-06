#include "Audio.h"

#include <AL/al.h>
#include <vorbis/vorbisfile.h>

#include <vector>
#include <iostream>

namespace Disc_Engine
{


struct AudioImpl
{
	ALuint id;

	~AudioImpl()
	{
		alDeleteBuffers(1, &id);
	}

	void load_ogg(std::string _fileName, std::vector<char> &_buffer, ALenum &_format, ALsizei &_freq)
	{
		int endian = 0;
		int bitStream = 0;
		long bytes = 0;
		char array[2048] = { 0 };
		vorbis_info *pInfo = NULL;
		OggVorbis_File oggFile = { 0 };

		//use the inbuilt fopen to create a file descriptor
		if (ov_fopen(_fileName.c_str(), &oggFile) != 0)
		{
			std::cout << "Failed to open file '" << _fileName << "' for decoding" << std::endl;
			throw std::exception();
		}

		//extract information from the file header
		pInfo = ov_info(&oggFile, -1);

		//record the format required by OpenAL
		if (pInfo->channels == 1)
		{
			_format = AL_FORMAT_MONO16;
		}
		else
		{
			_format = AL_FORMAT_STEREO16;
		}

		//record the sample rate required by OpenAL
		_freq = pInfo->rate;

		//keep reading bytes from the file to populate the output buffer
		while (true)
		{
			//read bytes into temporary array
			bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);

			if (bytes < 0)
			{
				ov_clear(&oggFile);
				std::cout << "Failed to decode file '" << _fileName << "'." << std::endl;
				throw std::exception();
			}

			else if (bytes == 0)
			{
				break;
			}

			//copy from temporary array into output buffer
			_buffer.insert(_buffer.end(), array, array + bytes);
		}

		//clean up and close the file
		ov_clear(&oggFile);
	}
};

//Audio::Audio()
//{
//
//}

Audio::Audio(std::string _file)
{
	Load(_file);
}

void Audio::Load(std::string _file)
{
	m_impl = std::make_shared<AudioImpl>();

	ALenum format = 0;
	ALsizei freq = 0;
	std::vector<char> bufferData;

	alGenBuffers(1, &m_impl->id);

	m_impl->load_ogg(_file.c_str(), bufferData, format, freq);

	alBufferData(m_impl->id, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq);

	
}

void Audio::Play(float _volume, float _varianceMin, float _varianceMax)
{
	_varianceMin *= 1000.0f;
	_varianceMax *= 1000.0f;

	float variance = (std::rand() % ((int)_varianceMin + 1 - (int)_varianceMax) + (int)_varianceMin) / 1000.0f;
	//return std::rand() % (max + 1 - min) + min;

	ALuint sourceID = 0;
	alGenSources(1, &sourceID);
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSource3f(sourceID, AL_POSITION, 0.0f, 0.0f, 0.0f);

	alSourcei(sourceID, AL_BUFFER, m_impl->id);
	alSourcef(sourceID, AL_PITCH, variance);
	alSourcef(sourceID, AL_GAIN, _volume);
	alSourcePlay(sourceID);

	//audioSources.push_back(sourceID);
}

void Audio::Play()
{
	ALuint sourceID = 0;
	alGenSources(1, &sourceID);
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

	alSource3f(sourceID, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(sourceID, AL_BUFFER, m_impl->id);
	alSourcePlay(sourceID);

	//audioSourecs.push_back(sourceID);
}

}