class azw_TestSound extends BuildingSuper
{
	ref azw_SoundLoop SoundClose;
	ref azw_SoundLoop SoundClose2;
	ref azw_SoundLoop SoundDistant;
	ref azw_SoundLoop SoundSubBass;
	
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
		
		SoundClose.SetFadeIn(0.5);
		SoundClose.SetFadeOut(10);
		SoundClose.SetTimer(5);
		SoundClose.Play();
		//SoundDistant.Play();
		//SoundSubBass.Play();
	}
	
	void ~azw_TestSound()
	{
		StopSound();
		delete SoundClose;
		delete SoundClose2;
		delete SoundDistant;
		delete SoundSubBass;
	}

	void StopSound()
	{
		SoundClose.Stop();
		SoundClose2.Stop();
		SoundDistant.Stop();
		SoundSubBass.Stop();
	}
}