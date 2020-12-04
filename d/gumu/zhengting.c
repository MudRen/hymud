// zhengting.c ����
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_sleep(string arg);

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ������������Ӧ��ͣ�����ѹ�ľ֮��Ķ�����ȴ��֪
�����˰㵽����ȥ�ˡ������ж�����һλ������Ů�������ϰڷ���һ
��ʯͷ���ɵĴ�(chuang)�����к�ϵ��һ�����ӣ���֪����ʲô��
�ģ�����֮�⣬���ް��衣
LONG
        );

        set("exits", ([
                "west" : __DIR__"liangong",
                "north" : __DIR__"xiaoting",
                "south" : __DIR__"houting",
        ]));

	set("roomif","$botten#ѵ������|��ɱ����|����ѵ��|������ɱ:ask long about job|ask yang about job|ask long about ʧ��|ask yang about ʧ��$#");	 

        set("objects", ([
                "quest/menpaijob/gumu/zf/longnv" : 1,
                "/d/biwu/champion_gm":1,
                "quest/menpaijob/gumu/yangguo":1
        ]));
        set("valid_startroom",1);

        set("item_desc", ([
        "chuang": "����һ����"+HIB"ǧ�꺮��"NOR+"��ɵĺ��񴲡�\n"
        ]) );
        setup();
        "/clone/board/gumu_b"->foo();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
        object me=this_player();
        int lvl_force, c_exp, c_skill;

        if( !arg || arg == "" ) {
                return notify_fail("��Ҫ˯���Ķ���\n");
        }

        lvl_force=(int)me->query_skill("force",1);
        if(lvl_force>150) //force ���� 150
                {
                message_vision("$N�����˺��񴲣���ʼǱ���ڹ���ʹ��Ϣ���д�С���졣\n",this_player());
                if (random(20)>12) {
                        message_vision("$N��Ϣ��ϣ�ֻ���þ���������Ϣ���������ڶ�����\n", this_player());
                        c_exp=me->query("combat_exp");
                        c_skill=me->query_skill("force",1);
                        if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<250))
                        {
                                me->improve_skill("force", random(lvl_force));
                        }
                        me->receive_damage("qi",random(lvl_force/3));
                }
                else
                        message_vision("$N��Ϣ��ϣ�վ������������������������ûʲô������\n", this_player());
                }
        else
                message_vision("$N���Ϻ��񴲣�ֻ���ñ���̹ǣ���������һ���Ǳ�����������������\n", this_player());
        return 1;
}