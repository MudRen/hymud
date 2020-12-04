// Change by Server
// hp cmds (Mon  09-04-95)
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
int potential_lv(int exp);
 
int main(object me, string arg)
{
	object ob;
	mapping my;
  int i;
	seteuid(getuid(me));
 
	if(!arg)
{
		ob = me;
me->set_temp("xmud", 1);
}
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");
 
	my = ob->query_entire_dbase();
    printf("$name%s\n",ob->query("name"));
    printf("$clshp#\n$qixue#%d|%d|%d\n",	my["qi"], my["eff_qi"], my["max_qi"]);
    printf("$clsjl#\n$jing#%d|%d|%d\n",	my["jing"], my["eff_jing"], my["max_jing"]);
    printf("$clsnl#\n$neili#%d|%d|%d\n",	my["neili"], my["neili"], my["max_neili"]);
    printf("$nowhp# 潜能%7d 经验%7d\n",
        (int)ob->query("potential") - (int)ob->query("learned_points"),

        my["combat_exp"] );
    printf("$nowhp# 食物%7d 水量%7d\n",
        my["food"],
       my["water"]);
        printf("$dengji# %d   \n$#\n",
                 ob->query("levels"));
  if (me->query("qi",1) <= me->query("max_qi",1)*1/3)
	write(ob->query("name")+"的气血小于三分之一。\n");
	else if (me->query("qi",1) <= me->query("max_qi",1)/2)
	write(ob->query("name")+"的气血小于一半。\n");
	else if (me->query("qi",1) <= me->query("max_qi",1)*2/3)
	write(ob->query("name")+"的气血小于三分之二。\n");
	
	
	if (me->query("jing",1) <= me->query("max_jing",1)*1/3)
	write(ob->query("name")+"的精小于三分之一。\n");
	else if (me->query("jing",1) <= me->query("max_jing",1)/2)
	write(ob->query("name")+"的精小于一半。\n");
	else if (me->query("jing",1) <= me->query("max_jing",1)*2/3)
	write(ob->query("name")+"的精小于三分之二。\n");

if ( me->query("max_neili",1)>10)
{
	if (me->query("neili",1) <= me->query("max_neili",1)*1/3)
	write(ob->query("name")+"的内力小于三分之一。\n");
	else if (me->query("neili",1) <= me->query("max_neili",1)/2)
	write(ob->query("name")+"的内力小于一半。\n");
	else if (me->query("neili",1) <= me->query("max_neili",1)*2/3)
	write(ob->query("name")+"的内力小于三分之二。\n");
}
	if( interactive(me)	&&	query_idle( me) > 30 ) 
	write(ob->query("name")+"是不是该干点什么事了?\n");
return 1;
}
int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;
        return grade;
}
 
int help(object me)
{
	write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}

