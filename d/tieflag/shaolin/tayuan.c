 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ƕ��ֳ�סԺ����Ժ����������������������Ϊ���߷�����������
�շ���������Ķ������շ�����˫��̤������������̹Ȼ����̬��ׯ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"lixue",
  "westup" : __DIR__"ganlu",
]));
        set("outdoors", "shaolinfy");
        set("coor/x",-220);
        set("coor/y",260);
        set("coor/z",50);
        setup();
        create_door("westup", "ľ��", "eastdown", DOOR_CLOSED);
}      
