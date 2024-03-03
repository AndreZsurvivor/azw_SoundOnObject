class azw_TestSound extends BuildingSuper
{
	ref ScriptInvoker Event_OnSoundFadeOutStarted;
	ref Timer eQuakeTimer;
	protected ref EffectSound m_Equake_close;
	protected ref EffectSound m_Equake_distant;
	protected ref EffectSound m_SubBass;
	
	protected ref EffectSound m_azwTestTone;

	void azw_TestSound()
	{
		Event_OnSoundFadeOutStarted = new ScriptInvoker();
		if (!eQuakeTimer)
		eQuakeTimer = new Timer();
		//eQuakeTimer.Run(15 , this ,"StopSound" , NULL ,false );

		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )	
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlaySoundLayers, 15, false);
	}
	
	void ~azw_TestSound()
	{
		StopSound();
		
		if (eQuakeTimer)
		delete eQuakeTimer;
	}

	void azw_playTestToneLater()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )	
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(azw_playTestTone, 15, false);
	}

	void azw_playTestTone()
	{
		
		if (!m_azwTestTone || !m_azwTestTone.IsSoundPlaying())
		m_azwTestTone = SEffectManager.PlaySoundOnObject_shuffledLoop("azw_TestTones_SoundSet", GetGame().GetPlayer(), 0, 0);
		
		if (m_azwTestTone)
		m_azwTestTone.Start();


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
		{
			m_Equake_close = SEffectManager.PlaySoundOnObject_shuffledLoop("azw_EQuakeClose_SoundSet", this, 0, 1);
			m_Equake_close.Event_OnSoundFadeOutStarted.Insert(azw_playTestTone);
		}
	}

	void PlayLoopSound_distant()
	{
		if (!m_Equake_distant || !m_Equake_distant.IsSoundPlaying())
		{
			m_Equake_distant = SEffectManager.PlaySoundOnObject_shuffledLoop("azw_EQuakeDistant_SoundSet", this, 0, 0.5);
			m_Equake_distant.Event_OnSoundFadeOutStarted.Insert(azw_playTestTone);
		}
	}

	void PlayLoopSound_onPlayer()
	{
		if (!m_SubBass || !m_SubBass.IsSoundPlaying())
		{
			m_SubBass = SEffectManager.PlaySoundOnObject_shuffledLoop("azw_SubRumble_SoundSet", this, 0, 1.5);
			m_SubBass.Event_OnSoundFadeOutStarted.Insert(azw_playTestTone);
		}
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