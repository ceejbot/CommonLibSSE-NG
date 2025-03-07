#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTempEffect.h"

namespace RE
{
	class BGSArtObject;
	class ReferenceEffectController;

	class ReferenceEffect : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ReferenceEffect;
		inline static constexpr auto Ni_RTTI = NiRTTI_ReferenceEffect;
		inline static constexpr auto TYPE = TEMP_EFFECT_TYPE::kRefDefault;

		~ReferenceEffect() override;  // 00

		// override (BSTempEffect)
		const NiRTTI*    GetRTTI() const override;                           // 02
		void             Detach() override;                                  // 27
		bool             Update(float a_arg1) override;                      // 28
		bool             GetManagerHandlesSaveLoad() const override;         // 2A
		bool             GetClearWhenCellIsUnloaded() const override;        // 2B
		TEMP_EFFECT_TYPE GetType() const override;                           // 2C - { return 8; }
		void             SaveGame(BGSSaveGameBuffer* a_buf) override;        // 2D
		void             LoadGame(BGSLoadGameBuffer* a_buf) override;        // 2E
		void             FinishLoadGame(BGSLoadGameBuffer* a_buf) override;  // 2F

		// add
		virtual void        Init();                                  // 36 - { return 0; }
		virtual void        Suspend();                               // 37 - { return; }
		virtual void        Resume();                                // 38 - { return; }
		virtual void        ClearTarget();                           // 39
		virtual void        UpdateParentCell(NiAVObject* a_object);  // 3A
		virtual void        UpdatePosition();                        // 3B - { return; }
		virtual NiAVObject* GetAttachRoot();                         // 3C
		virtual bool        GetAttached();                           // 3D - { return 1; }
		virtual void        DetachImpl();                            // 3E - { return; }

		// members
		ReferenceEffectController* controller;     // 30
		ObjectRefHandle            target;         // 38
		ObjectRefHandle            aimAtTarget;    // 3C
		bool                       finished;       // 40
		bool                       ownController;  // 41
		std::uint16_t              pad42;          // 42
		std::uint32_t              pad44;          // 44
	private:
		KEEP_FOR_RE()
	};
	static_assert(sizeof(ReferenceEffect) == 0x48);
}
