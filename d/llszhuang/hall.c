#include <ansi.h>
inherit ROOM;
string *s1 = ({ "��","��","ã","��","��","˭","��","��","��","��","��","��",
                "��","��","��","��","��","��","��","ɽ","��","��","��","��"});
void create()
{
        set("short", YEL"ɽׯ����"NOR);
        set("long",
"������δ����һ˿�����������������������Ƣ���߽�������ӭ����\n"
"һ���������īɽˮ��ī���ݺ����죬�ʷ�������¡������ϻ����ɽ��\n"
"���ͼ������ãã�󺣣���������ѩɽ�����Ʋ��������˶�����ֹ֮�У�\n"
"�Ա���һ�����������ʲ�ã���˭������[2;37;0m���������ﻹ����\n"
"��[2;37;0m[2;37;0m��������ɽ��˶ཿ[2;37;0m����������Ȼ����\n"
"�ûʣ����ƻֺ꣬�������ܸо��е㲻̫Э���ĵط����ƺ�����һ·����\n"
"���Ų�̫�������ǲ���Ӧ�úú�(think)�أ�Ȼ���ٽ�ȥ��\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "south" : __DIR__"dynamic/jiuqu16",
          "north" : __DIR__"neishi",
        ]));
        set("no_magic", "1");

        setup();
}

int init()
{
        add_action("do_think","think");
        add_action("do_uncover","uncover");
}

int do_think(string arg)
{
        object me;

        me = this_player();
        if( random(me->query("int"))<20 )
        {
                write("���밡�룬����������Դ����װ׵��Խ�����һ�ء�\n");
                me->receive_damage("jing",100);
        }
        else
        {
                write("����ͷ��˼��ͻȻ���ֵ�����һ�鷽ש(brick)�ƺ���Ե�ر�Ĺ�
�����������(uncover)\n");
                me->set_temp("marks/xanadu_hall1",1);
        }
        return 1;
}

int do_uncover(string arg)
{
          object me;
        int i,j,k,l;

        me = this_player();
        if(!arg || arg != "brick" || !me->query_temp("marks/xanadu_hall1") )//|| wizardp(me) )
                return 0;
        message_vision(GRN"$NС������ذѵذ�ש�ҿ���ֻ����������һ������...\n"NOR,me);
       if( random(10) > 5 ) {
        message_vision(RED"һ��ţëϸ����$N�������������У�ֻ����һ���Һ���ϸ����������ǰ�Դ�������\n"NOR,me);
                me->receive_wound("qi",random(me->query("kar"))*50);
                COMBAT_D->report_status(me,me,1);
         }
        else
         message_vision(RED"һ��ţëϸ����$N������$N���ɵĶ��˿�ȥ��\n"NOR,me);
         if( me->query("qi") > 100 )
                {
                        me->delete_temp("marks/xanadu_hall1");
                        i=random(9);
                        j=random(9);
                        k=random(6);
                        l=random(6);
                        me->set_temp("marks/xanadu_hall2",l*1000+k*100+j*10+i);
 write("�㾪�긦�������ֵذ巭�����ı������һ��С�֣�"+s1[i]+s1[9+j]+s1[18+k]+s1[18+l]+"\n");


                }
        return 1;
}

