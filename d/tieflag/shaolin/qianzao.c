 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ǧɮ��");
        set("long", @LONG
�����󷹵����ڣ��������ڴ��������������������������������
֮�ϣ��ֳ־ް���������з�ʳ��������ǧɮ��ÿ��ʳ�������������
ϸ������ɮ�ˣ����������������Ȼ���޲��ʣ��������Ǵ�����ѧ��
�÷�����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"fanting",
 "north" : __DIR__"bohuo",  
]));
        set("objects", ([
                __DIR__"obj/wok" : 3,
       ]) );
        set("coor/x",-230);
        set("coor/y",300);
        set("coor/z",60);
        setup();
        create_door("east", "ľ��", "west", DOOR_CLOSED); 
}  
