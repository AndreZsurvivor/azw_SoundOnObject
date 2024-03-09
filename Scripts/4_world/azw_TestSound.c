class azw_TestSound extends BuildingSuper
{
	ref azw_SoundLoop SoundClose;
	ref azw_SoundLoop SoundClose2;
	ref azw_SoundLoop SoundDistant;
	ref azw_SoundLoop SoundSubBass;
	
	private ref Timer m_EquakeTimer01;
	private ref Timer m_EquakeTimer02;

	void azw_TestSound()
	{

		SoundClose		= new azw_SoundLoop();
		SoundClose2		= new azw_SoundLoop();
		SoundDistant	= new azw_SoundLoop();
		SoundSubBass	= new azw_SoundLoop();
		
		SoundClose.Init("azw_EQuakeClose_SoundSet",		this, 10, 2);
		SoundClose2.Init("azw_EQuakeClose_SoundSet",	this, 10, 2);
		SoundDistant.Init("azw_EQuakeDistant_SoundSet",	this, 10, 2);
		SoundSubBass.Init("azw_SubRumble_SoundSet",		this, 5, 2);
		
		SoundClose.Play();
		//SoundDistant.Play();
		//SoundSubBass.Play();

		
		if (!m_EquakeTimer01)
			m_EquakeTimer01 = new Timer();
		
		if (!m_EquakeTimer02)
			m_EquakeTimer02 = new Timer();
		
		//m_EquakeTimer01.Run( 5, this, "StopSound", NULL, false );
		//m_EquakeTimer02.Run( 2, this, "PlaySoundDelayed", NULL, false );
	}
	
	void ~azw_TestSound()
	{
		StopSound();
		
		if (m_EquakeTimer01)
			delete m_EquakeTimer01;
		
		if (!m_EquakeTimer02)
			delete m_EquakeTimer02;
	}
	
	void PlaySoundDelayed()
	{
		SoundClose2.Play();
	}
	
	void StopSound()
	{
		SoundClose.StopHard();
		SoundClose2.StopHard();
		SoundDistant.StopHard();
		SoundSubBass.StopHard();
	}
}