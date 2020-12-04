// mazemap.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{ 
        object mazeobj;
        string mazedd;
        if (me->is_busy())
                return notify_fail("你现在正忙。\n");

//if ((int)me->query("combat_exp",1) >6000000 && !me->query("hyvip"))
//return notify_fail("只有会员或新玩家才可以使用这个命令。\n");

if(environment(me)->query("magicset")==1
       
       )
			return notify_fail("此处无法使用！ 附近全是道路，让你心神一乱。\n");

if (me->is_busy())
return notify_fail("你正在忙？\n");
if (me->is_fighting())
return notify_fail("你正在打？\n");

        if ((time() - me->query_temp("maze/map") < 3))
                return notify_fail("系统气喘嘘地叹道：慢慢来 ....\n");  
        

                
        if (me->query("jing") < 5)
                return notify_fail("你现在精神状态不佳，还是等会再查吧。\n");
        
        //mazeobj = me->query("startroom"); 
mazedd=me->query("startroom");

if (arg) mazedd="/d/city/guangchang";

if (!mazedd)
return notify_fail("找不到你设定的起点地区！\n");
if(environment(me)->query("maze")) 
	{
	me->set_temp("nomg",1);
	me->start_busy(10);
}
        me->add("jing", -5);
        me->set_temp("maze/map", time());
        me->move(mazedd);

        return 1;
}