 inherit ROOM;
void create()
{
        set("short", "ũ�ߵ�");
        set("long", @LONG
СС��һ��ũ�ߵ꣬���������ʽ������ũ�ߡ�����ǽ�Ϲ�����
���������ұ�ǽ�Ƿ������Ѷ��١��м�һ�����¯��¯��������һλ
�ձ���������¯������ĳ���
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"xzroad2",
        ]));
        set("objects", ([
                __DIR__"npc/seller1" : 1,
        ]) );
        set("coor/x",90);
        set("coor/y",-50);
        set("coor/z",0);
        setup();
replace_program(ROOM); 
}    
