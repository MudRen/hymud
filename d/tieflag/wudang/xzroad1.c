 inherit ROOM;
void create()
{
        set("short", "�ֵ�");
        set("long", @LONG
����ʯ���̳ɵĵ�·����ɨ�ø�Ǭ����������Сͯ�ڽֵ��ϻ���
׷����ˣ���ֵ������Ǻ�ש���ɵķ��ݣ���λ�������е����ڼ���ǰ
�������졣
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"xiaozhen",
                "south" : __DIR__"xzroad2",
                "east" : __DIR__"xzdong",
        //"west" : AREA_BAWANG"xinghuacun",
        ]));
        set("outdoors", "wudangfy");
        set("objects", ([ 
                __DIR__"npc/dog": 1,
                __DIR__"npc/xiaotong": 2 
        ]) );
        set("coor/x",100);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
replace_program(ROOM); 
} 
