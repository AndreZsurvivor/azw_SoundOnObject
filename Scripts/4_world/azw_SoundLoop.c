class azw_SoundLoop
{
    ref ScriptInvoker Event_OnSoundFadeOutStarted;
    protected ref Timer m_LoopTimer;

    protected ref EffectSound m_Sound_A;
	protected ref EffectSound m_Sound_B;

    protected bool m_IsInitalized;
    protected bool m_IsPlaying;

    protected float m_LoopLength;
    protected float m_FadeLength;

    protected string m_SoundSet;
    protected Object m_ParentObject;



    void azw_SoundLoop()
    {
        Event_OnSoundFadeOutStarted = new ScriptInvoker();
        m_LoopTimer = new Timer();
        
        m_IsInitalized = false;
    }

    void ~azw_SoundLoop()
    {
        delete m_LoopTimer;
    }

    void Init(string sound_set, Object parent_object, float length, float fade)
    {
        m_SoundSet = sound_set;
        m_ParentObject = parent_object;
        m_LoopLength = length;
        m_FadeLength = fade;
        m_IsPlaying = false;
        m_IsInitalized = true;
    }

    void Play()
    {
        m_IsPlaying = true;

        if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )	
		    GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_PlaySound_A, 5, false);
    }

    void Stop()
    {
        m_IsPlaying = false;
    }
	
	void StopHard()
    {
        m_IsPlaying = false;
        if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_StopSounds, 15, false);
    }

    Object GetParentObject()
    {
        return m_ParentObject;
    }

    private void m_PlaySound_A()
	{
		if (!m_Sound_A || !m_Sound_A.IsSoundPlaying())
		{
			
			m_Sound_A = SEffectManager.azwPlaySoundOnObject_shuffledLoop(m_SoundSet, m_ParentObject, m_FadeLength);
			m_LoopTimer.Run( m_LoopLength, this, "m_StopSounds", NULL, false );
            
            if (m_IsPlaying)
                m_Sound_A.Event_OnSoundFadeOutStarted.Insert(m_PlaySound_B);
            
            return;
		}
        if (m_Sound_A || m_Sound_A.IsSoundPlaying())
        {
            m_Sound_A.SoundPlay();
        }
	}
    
    private void m_PlaySound_B()
	{
		if (!m_Sound_B || !m_Sound_B.IsSoundPlaying())
		{
			
			m_Sound_B = SEffectManager.azwPlaySoundOnObject_shuffledLoop(m_SoundSet, m_ParentObject, m_FadeLength);
			m_LoopTimer.Run( m_LoopLength, this, "m_StopSounds", NULL, false );
            if (m_IsPlaying)
                m_Sound_B.Event_OnSoundFadeOutStarted.Insert(m_PlaySound_A);
            
            return;
		}
        if (m_Sound_B || m_Sound_B.IsSoundPlaying())
        {
            m_Sound_B.SoundPlay();
        }
	}

    private void m_StopSounds()
	{
		if (m_Sound_A && m_Sound_A.IsSoundPlaying())
        {
            if (!m_IsPlaying)
               m_Sound_A.Event_OnSoundFadeOutStarted.Remove(m_PlaySound_B);
            
            m_Sound_A.SoundStop();
        }

		if (m_Sound_B && m_Sound_B.IsSoundPlaying())
        {
            if (!m_IsPlaying)
                m_Sound_B.Event_OnSoundFadeOutStarted.Remove(m_PlaySound_A);
            
            m_Sound_B.SoundStop();
        }		
	}
}