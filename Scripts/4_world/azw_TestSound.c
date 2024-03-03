class azw_TestSound extends BuildingSuper
{
	ref ScriptInvoker Event_OnSoundFadeOutStarted;

	private ref Timer m_EquakeTimer01;
	private ref Timer m_EquakeTimer02;
	private ref Timer m_EquakeTimer03;
	protected ref EffectSound m_Equake_close;
	protected ref EffectSound m_Equake_distant;
	protected ref EffectSound m_SubBass;
	
	protected ref EffectSound m_azwTestTone;

	void azw_TestSound()
	{
		Event_OnSoundFadeOutStarted = new ScriptInvoker();

		if (!m_EquakeTimer01)
		m_EquakeTimer01 = new Timer();
		if (!m_EquakeTimer02)
		m_EquakeTimer02 = new Timer();
		if (!m_EquakeTimer03)
		m_EquakeTimer03 = new Timer();
		
		m_EquakeTimer01.Run( 2 , this ,"StopSound_Timer01" , NULL ,false );
		m_EquakeTimer02.Run( 4 , this ,"StopSound_Timer02" , NULL ,false );
		m_EquakeTimer03.Run( 6 , this ,"StopSound_Timer03" , NULL ,false );

		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )	
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlaySoundLayers, 15, false);
	}
	
	void ~azw_TestSound()
	{
		StopSound();
		
		if (m_EquakeTimer01)
		{
			delete m_EquakeTimer01;
			delete m_EquakeTimer02;
			delete m_EquakeTimer03;
		}

	}

	void PlayTestTone()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )	
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_PlayTestTone, 15, false);
	}

	private void m_PlayTestTone()
	{
		if (!m_azwTestTone || !m_azwTestTone.IsSoundPlaying())
		{
			m_azwTestTone = SEffectManager.PlaySoundOnObject("azw_TestTones_SoundSet", GetGame().GetPlayer(), 0, 0, false);
			m_azwTestTone.SetAutodestroy(true);	
		}
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
			m_Equake_close = SEffectManager.PlaySoundOnObject_shuffledLoop("azw_EQuakeClose_SoundSet", this, 0.1);
			m_Equake_close.Event_OnSoundFadeOutStarted.Insert(PlayTestTone);
		}
	}

	void PlayLoopSound_distant()
	{
		if (!m_Equake_distant || !m_Equake_distant.IsSoundPlaying())
		{
			m_Equake_distant = SEffectManager.PlaySoundOnObject_shuffledLoop("azw_EQuakeDistant_SoundSet", this, 0.1);
			m_Equake_distant.Event_OnSoundFadeOutStarted.Insert(PlayTestTone);
		}
	}

	void PlayLoopSound_onPlayer()
	{
		if (!m_SubBass || !m_SubBass.IsSoundPlaying())
		{
			m_SubBass = SEffectManager.PlaySoundOnObject_shuffledLoop("azw_SubRumble_SoundSet", this, 0.1);
			m_SubBass.Event_OnSoundFadeOutStarted.Insert(PlayTestTone);
		}
	}

	void StopSound()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )	
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_StopSound, 15, false);
	}

	void StopSound_Timer01()
	{
		if (m_Equake_close)
			m_Equake_close.SoundStop();
	}

	void StopSound_Timer02()
	{
		if (m_Equake_distant)
			m_Equake_distant.SoundStop();
	}

	void StopSound_Timer03()
	{
		if (m_SubBass)
			m_SubBass.SoundStop();
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