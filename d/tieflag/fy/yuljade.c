 inherit ROOM;
void create()
{
        set("short", "�����鱦��");
        set("long", @LONG
�鱦�����������ǧ������ɵ�����������������֣�����������֮�С���
���к�����������ȭͷ��С���������Ρ����۰�����ա����ܵ�ǽ�Ϲ����˸���
������Ʒ�͸��ֻ�����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"swind1",
]));
        set("objects", ([
        __DIR__"npc/jadeowner" : 1,
                        ]) ); 
        set("coor/x",-1);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
