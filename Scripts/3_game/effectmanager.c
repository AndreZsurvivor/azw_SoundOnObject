/**
\brief Manager class for managing Effect (EffectParticle, EffectSound)
	\warning Keeps a ref to any Effect registered (Created/Played), make sure to perform the necessary cleanup
*/
modded class SEffectManager
{
	static EffectSound PlaySoundOnObject_shuffledLoop(string sound_set, Object parent_object, float fade = 0)
	{
        bool loop = true;
		EffectSound effect_sound = CreateSound(sound_set, parent_object.GetPosition(), fade, fade, loop);
		
		effect_sound.SetParent( parent_object );
		effect_sound.SetLocalPosition( vector.Zero );
		effect_sound.SetAutodestroy(true);
		effect_sound.SoundPlay();
		
		
		
		return effect_sound;
	}
}