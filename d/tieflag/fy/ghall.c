 inherit ROOM;
#include <room.h>
void create()
{
        set("short", "��ʨ�ھִ���");
        set("long", @LONG
����̺���ɣ�������棬�����ֻ���������������˲��������ˬ���㽻��
�ѣ��ҷǴ��ֲ�ʶ��Ŀ������֮��������һʨƤ���Σ����Ҹ�������˸��һ��ɫ��
ľ�鰸������ǰ����������Ķ���һ����ھ�Ѻ�ڵĻ�Ʊ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"goldlion",
  "east" : __DIR__"ginhall",
  "north" : __DIR__"gmoney",
]));
        set("objects", ([
        __DIR__"npc/gmaster" : 1,
                        ]) ); 
        set("coor/x",20);
        set("coor/y",40);
        set("coor/z",0);
        setup();
        create_door("north", "����", "south", DOOR_CLOSED); 
} 
