 inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
���Ƴ����������ҵĵط�����Ȼ��ˣ����ﻹ������������ֻҪ����ó����ģ�
������У������ǳԵĻ�����ġ�������һ���ƾɵ�Сͤ�ӣ�����ľ���һ���ϵ�
ʿ���������Ƿ��Ƴ������ֺŵĲ��̡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ecloud3",
  "west" : __DIR__"ecloud1",
  "north": __DIR__"bupu",
  "south": __DIR__"jijian",
]));
        set("objects", ([
        __DIR__"npc/fatman" : 1,
        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",20);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
