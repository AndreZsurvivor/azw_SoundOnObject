class CfgPatches
{
	class azw_SoundOnObject
	{
		units[]				=	{"azw_TestSound"};
		weapons[]			=	{};
		requiredVersion		=	0.1;
		requiredAddons[]	=	{"DZ_Data","DZ_Scripts"};
	};
};
class CfgMods
{
	class azw_SoundOnObject
	{
		name				=	"azw_SoundOnObject";
		credits				=	"AndreZ";
		author				=	"AndreZ";
		authorID			=	"0";
		type				=	"mod";
		dependencies[]		=	{"World"};
		class defs
		{
			class worldScriptModule
			{
				value		=	"";
				files[]		=	{"azw_SoundOnObject\Scripts\4_world"};
			};
		};
	};
};
class CfgDestroy
{
	class BuildingHit
	{
		sound[]={};
	};
};
class CfgVehicles
{	class HouseNoDestruct;
	class azw_TestSound: HouseNoDestruct
	{
		scope=2;
		model="DZ\gear\radio\walkietalkie.p3d";
	};
};
class CfgSoundCurves
{
	class azw_EQuakeClose_VolumeCurve
	{
		points[]=
		{
			{0,1},
			{0.1,0.65},
			{0.2,0.40},
			{0.3,0.10},
			{0.4,0.00},
			{0.5,0.00},
			{0.6,0.00},
			{0.7,0.00},
			{0.8,0.00},
			{0.9,0.00},
			{1.0,0.00}
		};
	};

	class azw_EQuakeDistant_VolumeCurve
	{
		points[]=
		{
			{0,0.10},
			{0.1,0.35},
			{0.2,0.60},
			{0.3,0.90},
			{0.4,1.00},
			{0.5,0.90},
			{0.6,0.75},
			{0.7,0.25},
			{0.8,0.15},
			{0.9,0.07},
			{1.0,0.00}
		};
	};

	class azw_SubRumble_VolumeCurve
	{
		points[]=
		{
			{ 0.0, 0.9751 },
			{ 0.1, 0.6332 },
			{ 0.2, 0.4307 },
			{ 0.3, 0.3009 },
			{ 0.4, 0.2128 },
			{ 0.5, 0.1503 },
			{ 0.6, 0.1043 },
			{ 0.7, 0.0695 },
			{ 0.8, 0.0426 },
			{ 0.9, 0.0213 },
			{ 1.0, 0.0041 }
		};
	};
};
class CfgSound3DProcessors
{
	class azw_SubRumble3DProcessingType
	{
		type="emitter";
		innerRange	= 50;
		range		= 150;
	};
};
class CfgDistanceFilters
{
	class azwTestAttenuationFilter
	{
		type = "lowPassFilter";
		minCutoffFrequency = 150;
		qFactor = 1;
		innerRange = 10;
		range = 1000;
		powerFactor = 32;
	};
};

class CfgSoundShaders
{
	class azw_EQuakeClose_SoundShader
	{
		samples[]=
		{	
			{ "azw_SoundOnObject\Sounds\EarthQuake_Loop_01", 1 },
			{ "azw_SoundOnObject\Sounds\EarthQuake_Loop_02", 1 },
			{ "azw_SoundOnObject\Sounds\EarthQuake_Loop_03", 1 },
			{ "azw_SoundOnObject\Sounds\EarthQuake_Loop_04", 1 }
		};
		volume	= 1;
		range	= 500;
		//limitation=0;
	};

	class azw_EQuakeDistant_SoundShader
	{
		samples[]=
		{	
			{ "azw_SoundOnObject\Sounds\EarthQuake_Distasnt_Loop_01", 1 },
			{ "azw_SoundOnObject\Sounds\EarthQuake_Distasnt_Loop_02", 1 },
			{ "azw_SoundOnObject\Sounds\EarthQuake_Distasnt_Loop_03", 1 },
			{ "azw_SoundOnObject\Sounds\EarthQuake_Distasnt_Loop_04", 1 }
		};
		volume	= 1;
		range	= 500;
		//limitation=0;
	};
	
	class azw_SubRumble_SoundShader
	{
		samples[]=
		{	
			{ "azw_SoundOnObject\Sounds\SubBassRumble_Loop_01", 1 }
		};
		volume	= 0.9;
		range	= 150;
		//limitation=0;
	};
};
class CfgSoundSets
{
	class azw_EQuakeClose_SoundSet
	{
		soundShaders[]=	{ "azw_EQuakeClose_SoundShader" };
		volumeFactor = 0.9;
		doppler = 0;
		spatial = 1;
		volumeCurve="azw_EQuakeClose_VolumeCurve";
		distanceFilter = "none";

	};

	class azw_EQuakeDistant_SoundSet
	{
		soundShaders[]=	{ "azw_EQuakeDistant_SoundShader" };
		volumeFactor = 0.9;
		doppler = 0;
		spatial = 1;
		volumeCurve="azw_EQuakeDistant_VolumeCurve";
		distanceFilter = "none";

	};

	class azw_SubRumble_SoundSet
	{
		soundShaders[]=	{ "azw_SubRumble_SoundShader" };
		volumeFactor = 0.9;
		doppler = 0;
		spatial = 1;
		sound3DProcessingType="azw_SubRumble3DProcessingType";
		volumeCurve="azw_SubRumble_VolumeCurve";
		distanceFilter = "none";

	};
	
};
