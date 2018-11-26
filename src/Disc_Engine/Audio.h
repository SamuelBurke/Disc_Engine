#ifndef DISC_ENGINE_AUDIO_H
#define DISC_ENGINE_AUDIO_H

#include <memory>
#include <string>

namespace Disc_Engine
{
struct AudioImpl;

class Audio
{
public:
	//Audio();
	Audio(std::string _file); // Calls Load.

	void Load(std::string _file); // Loads in the audio file.
	void Play(float _volume, float _varianceMin, float _varianceMax); // Variety of play.
	void Play(); // Plays the audio.

private:
	std::shared_ptr<AudioImpl> m_impl;
};
}


#endif // !DISC_ENGINE_AUDIO_H
