#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "�Ϸ���");
        set("long", @LONG
һ���������������ڴ������һ����լ�ķ����£����չ����俪������������
�֣������ں������·����������һ�����ۣ��������⣬����Ƿ��Ƴ����������
�����ķ��������ķ��Ķ�����һƷ�Ӳ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind4",
  "north" : __DIR__"swind2",
  "east" : __DIR__"yitea",
  "west" : "/d/tieflag/yingou/yingou",
]));  
    set("outdoors", "fengyun");
    set("coor/x",0);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
