 // Room: /d/oldpine/spath3.c
inherit ROOM; 
void create()
{
        set("short", "���µ�");
        set("long", @LONG
����һ����ֱ���µ��������ϵͣ���·���Գ������������������
�ּ���Լ�����������ߴ�����ˮ��������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"spath4",
  "north" : __DIR__"spath2",
]));
        set("no_clean_up", 0);
        set("outdoors", "oldpine"); 
        set("coor/x",520);
        set("coor/y",2340);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}   
