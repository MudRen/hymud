// xiaowu2.c ����
// Java Oct.10 1998
#include <ansi.h>
inherit ROOM;
int do_zhujia();
#include "/quest/givegift.c"
void create()
{
        set("short", "����");
        set("long", @LONG
������С��Ůι��ѵ�����ķ��ݣ��ݽ��Ϲ��źܶ�������ε�
�䳲����δ���ţ����ŵõ�һ����۵����㡣���ƺ���������佬
(zuofengjiang)
LONG
        );

        set("exits", ([
                "west" : __DIR__"xiaoting",
                "east" : __DIR__"xiaowu3",
        ]));

        set("objects", ([
                __DIR__"obj/fengjiang" : 3,
                __DIR__"obj/fengmi" : 1,
        ]));

        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_zhujia","zuofengjiang"); 
}

int do_zhujia()
{
        object ob,me,ob1;
        int b1,b2,exp;
        me=this_player();
        
        if (!(ob = present(me->query("id")+" yufeng", this_player())) )
                return notify_fail("������û�в�����䣬�������佬��\n");

        if( me->query("family/family_name") != "��Ĺ��")
           return notify_fail("�㲻�ǹ�Ĺ�ɵ��˰�!\n");

        if (!me->query_temp("gmjob"))
           return notify_fail("�㻹����ȥ��С��Ů����к��ɡ�\n");
                 
        if ( (int)me->query("jing")<30)
                return notify_fail("��ľ������㣬�޷�����佬��\n");


if (me->query("combat_exp") >1000000)
{
        if ( me->query_temp("gumukill") )
        {
                return notify_fail("���Ǹ����������к���Ů����
                ȥ��һ�����ڸ�ʲô�ɣ�\n");
        }
}
        if( me->is_busy() )
                return notify_fail("�����ں�æ����������佬��\n");

        if ( (int)me->query("qi")<30)
                return notify_fail("����������㣬�޷�����佬��\n");

  message_vision("$N�Ӳ����������,������������佬��\n",me);
me->start_busy(1);
      me->add("jing",-(10+random(10)));
      me->add_temp("gmzyf",1);
  if ( (int)me->query_temp("gmzyf")>(random(13)+8))
 {
        if (!(ob = present(me->query("id")+" yufeng", this_player())) )
                return notify_fail("������û�в�����䣬�������佬��\n");
  message_vision(CYN"$N�������ã����ڽ�������һƿ��佬��\n"NOR,me);
b1=random(30)+60;
b2=random(50)+40;
me->add("jing",-(me->query("jing")/12));
exp=b1;
exp=exp/2+8;
addnl(me,"exp",exp);
me->delete_temp("gmzyf");
me->delete_temp("gmjob");
destruct(ob);
}
      return 1;
} 
