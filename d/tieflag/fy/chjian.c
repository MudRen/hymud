 inherit ROOM;
void create()
{
        set("short", "��ڼ�");
        set("long", @LONG
һ��ֻ��һ���˵�С���䡣�����һ��ǽ���пף�������������Ժ������Ĵ�
�����ڡ�������ֻ����Сľ�ʺͶ���ǽ�Ϲ��˷Ŷ�����ľ�塣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"church",
]));
        set("objects", ([
        __DIR__"npc/chantou" : 1,
                        ]) ); 
        set("coor/x",10);
        set("coor/y",-19);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
