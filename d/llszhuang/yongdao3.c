inherit ROOM;
#include <ansi.h>
int do_pick(string arg);
void create()
{
       set("short", "����ɽׯ");
        set("long",
"����ׯԺ��ʯ�ף�ʯ�׳��ֳ�һ�����������ɫ��ʯ���Ա���һ����\n"
"ɽ����ɽʯ���������һ�Ѹֹգ�ֱ��û�����ֹ��Ա�б����һ�����ã�\n"
"�����ϵİ׷�������ɫ�ġ�\n"
);
        set("no_magic", "1");

        set("exits", ([ /* sizeof() == 2 */
          "north" : __DIR__"dynamic/jiuqu1",
          "southeast" : __DIR__"yongdao2",
        ]));

        set("item_desc", ([
                "�ֹ�": "����һ�Ѿ��������ĸֹգ���������������꣬����ȴ������
�\n",
        ]) );

        set("have_weapon",1);
        setup();
}
int init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object me,killer;
        int i;

        me = this_player();

        if( !arg || arg != "�ֹ�" )
                return 0;
        if( query("have_weapon") != 1 )
                return notify_fail("�ֹ��Ѿ��������ˡ�\n");

        i = me->query("neili");
        if( random(i)<2000 )
        {
                i -= 200;
                if( i<1 ) i = 1;
                me->set("neili",i);
                return notify_fail("��ʹ�����̵���������ҡ���Ÿֹգ��ɸֹ���˿��
����\n");
        }
        me->add("neili",-1000);
        message_vision("$N�����������ѸֹմӼ�ɽʯ���а��˳�����\n����...\n"+BLU
"��Ȼһ�����紵��...��..��..��..��...\n"NOR,me);
        set("have_weapon",0);
        killer = new(__DIR__"npc/wraith");
        killer->move(this_object());
        killer->set_leader(me);
        killer->kill_ob(me);
        me->fight_ob(killer);
        return 1;
}

