class azw_TestSound extends BuildingSuper
{
	ref Timer eQuakeTimer;
	protected ref EffectSound m_Equake_close;
	protected ref EffectSound m_Equake_distant;
	protected ref EffectSound m_SubBass;
	
    void azw_TestSound()
    {
		if (!eQuakeTimer)
        eQuakeTimer = new Timer();
		
		eQuakeTimer.Run(15 , this ,"StopSound" , NULL ,false );
		
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )	
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlaySoundLayers, 15, false);
    }

	void ~azw_TestSound()
    {
		StopSound();
		
		if (eQuakeTimer)
		delete eQuakeTimer;
    }

	void PlaySoundLayers()
	{
		PlayLoopSound_close();
		PlayLoopSound_distant();
		PlayLoopSound_onPlayer();
	}

	void PlayLoopSound_close()
	{
		if (!m_Equake_close || !m_Equake_close.IsSoundPlaying())
			m_Equake_close = SEffectManager.PlaySoundOnObject("azw_EQuakeClose_SoundSet", this, 0, 0, true);
	}

	void PlayLoopSound_distant()
	{
		if (!m_Equake_distant || !m_Equake_distant.IsSoundPlaying())
			m_Equake_distant = SEffectManager.PlaySoundOnObject("azw_EQuakeDistant_SoundSet", this, 0, 0, true);
	}

	void PlayLoopSound_onPlayer()
	{
		if (!m_SubBass || !m_SubBass.IsSoundPlaying())
			m_SubBass = SEffectManager.PlaySoundOnObject("azw_SubRumble_SoundSet", this, 0, 0, true);
	}

	void StopSound()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )	
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_StopSound, 15, false);
	}

	private void m_StopSound()
	{
		if (m_Equake_close)
			m_Equake_close.SoundStop();

		if (m_Equake_distant)
			m_Equake_distant.SoundStop();

		if (m_SubBass)
			m_SubBass.SoundStop();
	}
};