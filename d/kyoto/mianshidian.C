// Room: d/kyoto/mianshidian
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��ʳ��");
set("long", @LONG
���Ǿ�����������ʳ�㣬������۸�����Ů����ϲ������˾����㡣
���������ʳƷ��ζ���ɿڣ������ڳ���������һ������;���е����Ƕ�
�����������Ϻܶ�ķ��ţ����֮�ࡣ�ű߷���һ���Ŀ�ƣ�paizi����
�����ۡ�
LONG );
set("exits",  ([
        "north"  : __DIR__"qianbending4",
        "south"  : __DIR__"xiaoxiang3",
      ]));
        setup();
        replace_program(ROOM);
}