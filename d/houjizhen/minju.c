// minju.c
// by dicky

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
������һ���ƾɵ����СԺ��Ժ���ұ���һ��ĥ�̣�����ĥ
����һ�ھ��������𻵵�ũ�߱���㶪��һ�ߡ������һ�úܴ�
�Ļ�������Ҷ���÷ǳ�ïʢ�������м�Ƭ�·���Ƭ�����沼����
Ѫ����
LONG
	);

	set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 2 */
 		"south" : __DIR__"shilu3",
	]));

        set("fu_count",2);

	setup();
//	replace_program(ROOM);
}

void init()
{
	if (!this_player()->query_temp("chazhao_times"))
	        this_player()->set_temp("chazhao_times",
			1+random(50));
	add_action("do_chazhao", "chazhao");
}

int do_chazhao()
{
        object me, ob;

        me = this_player();
                
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

        if ( !me->query_temp("taxue/ask_master"))
		return notify_fail("������˰��죬����ʲôҲû���ҵ���\n");

        if ( me->query_temp("chazhao_times") == 0 )
        {
                message_vision(HIB"$NͻȻ�о�һ����Ѫֱ�����ţ�����һ�ڣ����˹�ȥ��\n"NOR, me);
                me->set_temp("chazhao_times",
			1+random(50));
                me->unconcious();
                return 1;
        }

        me->add_temp("chazhao_times", -1);        

        message_vision("$N��ϸ���ڷ�������ң�����ʲôҲû���ҵ���\n", me);

	if ( random (40) == 10 
        && !present("pozhu fu", me)
        && query("fu_count") >= 1)
        {
        add("fu_count", -1);
	ob=new(__DIR__"obj/futou");
	ob->move(me);
	message_vision(HIC"$NͻȻ�ҵ�һ�Ѻ�����ĸ�ͷ��\n"NOR, me);
        }
        return 1;
}
