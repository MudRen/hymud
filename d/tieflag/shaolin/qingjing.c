 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�徲¥");
        set("long", @LONG
һ����¥���͵͵ģ��Ҷ��ϵ����������֡��徲����¥��һ�ź�ľ
������Ͳ��ϡ��Ĳ��ż�ֻ�Ǻ���һֻ��ƿ�������µĲ��ż����ʻ���
�������⣬���ޱ����ǽ��һ������� 
                        �ͽ̾��� 
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"diyuan",
]));
        set("objects", ([
                __DIR__"npc/girlfi" : 1,
       ]) );
        set("coor/x",-230);
        set("coor/y",390);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}  
