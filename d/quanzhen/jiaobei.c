// jiaobei.c �̱�
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�̱�");
        set("long", @LONG
������ȫ��̵Ḻ̌����ڵأ�·������һ���(bei)��������
�߾������������ĵ�����������--ȫ��̵Ĵ����ˡ�������һ��ʯ
�ף���֪��ͨ�������������ɽ��·��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie6",
                "eastup" : __DIR__"damen",
                "west" : __DIR__"shijianyan",
        ]));
        set("item_desc", ([
        "bei": CYN"
        ����������
������������������
������������ȫ����
������������������
�������������桡��
������������������
�������������š���
������������������
�������������̡���
������������������
������������������
\n"NOR
        ]) );
        set("objects",([
                __DIR__"npc/zhao" : 1,
                "/kungfu/class/xueshan/sd1" : 1,
                "/kungfu/class/xueshan/sd2" : 1,
                "/kungfu/class/xueshan/sd3" : 1,
                "/kungfu/class/xueshan/sd4" : 1,
        ]));

        setup();
        //replace_program(ROOM);
}
void init()
{
        add_action("do_kan","pai");
}

int do_kan(string arg)
{
        object me=this_player();
        object ob;


        if (!arg || (arg != "�̱�" && arg != "bei"))
                return notify_fail("��Ҫ��ʲô����\n");


if(me->query("jinyong/book10"))
return notify_fail("�������Ḻ̌���\n");

call_out("leavet",0);


                return notify_fail(HIR"�������Ḻ̌���ͻȻ���һ��Ⱥ��ʿ����Χ����������ͷ�ĵ�ʿ˵��:���� �����ߣ�\n"NOR);
}

void leavet(object me)
{
me=this_player();	
me->move(__DIR__"jianzhen");
}