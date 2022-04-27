#pragma once

#include "Resource.h"
#include "ResourceManager.h"
#include "Entity.h"

namespace ToolKit
{

  class TK_API Audio : public Resource
  {
  public: 
    TKResouceType(Audio)

    Audio();
    Audio(String file);
    ~Audio();

    virtual void Init(bool flushClientSideArray = true) override;
    virtual void Load() override;
    virtual void UnInit() override;

  public:
    uint m_buffer;
  };

  class TK_API AudioManager : public ResourceManager
  {
  public:
    AudioManager();
    virtual ~AudioManager();
    virtual void Init() override;
    virtual void Uninit() override;
    virtual bool CanStore(ResourceType t);
    virtual ResourcePtr CreateLocal(ResourceType type);

  public:
    void* m_device = nullptr;
    void* m_context = nullptr;
  };

  class TK_API AudioSource : public Entity
  {
  public:
    AudioSource();
    ~AudioSource();

    virtual EntityType GetType() const override;
    void AttachAudio(std::shared_ptr<Audio> audio);
    void SetLoop(bool enable);
    void SetVolume(float val);

  public:
    std::shared_ptr<Audio> m_audio;
    uint m_source = 0;
  };

  class TK_API AudioPlayer
  {
  public:
    static void Play(AudioSource* source);
    static void Stop(AudioSource* source);
    static void Rewind(AudioSource* source);
    static void Pause(AudioSource* source);
  };

}
