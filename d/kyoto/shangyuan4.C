// Room: d/kyoto/shangyuan4
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��ԭ");
set("long", @LONG
���������ԭ���������Ǿ�����������ģ�������������Ⱥ���ϴ�
���߲������������ߵ��̵Ľ����������ڶ�����������һ��С���֪��
ͬ��ʲô�ط���������һ����ʯ�ţ��������Ƿ����ľ������ġ�

LONG );
set("exits",  ([
        "south"  : __DIR__"dashiqiao",
        "north"  : __DIR__"shangyuan3",
        "west"  : __DIR__"xiaoxiang2",
        "east"  : __DIR__"xiaoxiang3",
      ]));
        setup();
        replace_program(ROOM);
}