 inherit ROOM;
void create()
{
        set("short", "����Ӫ��");
        set("long", @LONG
�����ת�˼�Ȧ����ǰ��һ��յأ��յ������˼������𣬿������ζ�˱�
������������������ĺ�������ɢɢ�ؿ�������ߣ��������Ÿ�ʽ������������
�����������ƾɲ�������Ұ�ķ紵�����������졣
LONG
        );
        set("exits", ([ 
                "southeast" : __DIR__"deserted",
                "north" : __DIR__"camp",
                "northwest": __DIR__"banditcamp2",
                        ]));
        set("objects", ([
                __DIR__"npc/bandit1" : 1,
        ]));
        set("outdoors", "eren"); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
