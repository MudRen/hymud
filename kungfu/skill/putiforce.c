// iceforce.c2

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("菩堤心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

int effective_level() { return 14;}

int learn_bonus()
{
	return 3;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 15;
}

