// xian-steps.c from mool

inherit SKILL;

string *dodge_msg = ({
    "$n一个「月上歌舞」，随着$N的攻势飘起，从容躲过这一招。\n",
    "$n使出一招「月夜舞翩跹」，猛然纵起丈余，结果$N扑了个空。\n",
    "$n身形一摇，幻出几个人影，一招「碎影舞斜阳」躲过了$N的攻势。\n",
    "$n一招「玉醉影仙」纵身跃起，倏忽已落至$N身后。\n",
    "$n左一摇，右一晃，一招「云深不知处」已轻松闪过。\n",
    "$n双足一点，斜斜飞起，使出「媚天仙」已闪到$N身侧。\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge") ;
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int effective_level() { return 12;}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
            return notify_fail("你的体力太差了，不能练翩仙步法。\n");

        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xian-steps/" + action;
}
