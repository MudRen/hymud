// Room: d/kyoto/shangyuan5
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��ԭ");
set("long", @LONG
���������ԭ���������Ǿ�����������ģ�������������Ⱥ���ϴ�
���߲������������ߵ��̵Ľ����������ڶ���������ά����������������
����ɭ�ϡ������ǹ����������鷸��֮ͽ������Ѻ�����
LONG );
set("exits",  ([
        "west"  : __DIR__"guanzhisuo",
        "east"  : __DIR__"shizhengting",
        "north"  : __DIR__"dashiqiao",
        "south"  : __DIR__"nanmen",
      ]));
        setup();
        replace_program(ROOM);
}