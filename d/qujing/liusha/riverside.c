//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "�ӱ�");
  set ("long", @LONG

�ӱ߾��ǿ�ľ���������������Ȼ��һֻ����Ҳû�С�ǰ����
��һ��ʯ������д�š�[1;33m��ɳ��[m���������֣��������ľ����ԡ���
����ɳ�磬��ǧ��ˮ���ëƮ����«�����׳�����ԭ������
���߾���������������
LONG);
  set("exits", ([
        "westup":   "/d/qujing/village/road1",
        "eastdown"  : __DIR__"river",
        ]));
  set("outdoors", "xy7");
  setup();
}
void init()
{
        add_action("do_dive","dive");
}

int do_dive()
{
        object me = this_player();
        object zhou;


        message_vision(HIY "$N����һԾ�����������\n" NOR, me);
        me->move(__DIR__"hedi1");
        message_vision(HIY "$N�ӽ�������������\n"NOR,me);
        return 1;
}
