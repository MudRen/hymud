 inherit ROOM;
void create()
{
        set("short", "�ϱ����");
        set("long", @LONG
�������������ò�����һ���������Ϸ��ͱ�����չ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"laowu",
  "south" : __DIR__"road2",
]));
        set("objects", ([
        __DIR__"npc/trader" : 2,
        __DIR__"npc/trader2" : 1,
                        ]) );
        set("outdoors", "laowu"); 
        set("coor/x",0);
        set("coor/y",12010);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
} 
