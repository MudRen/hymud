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
                "north" : __DIR__"xzroad1",
                "south" : __DIR__"xzroad3",
                "east" : __DIR__"xzhouse1",
                "west" : __DIR__"xzstore1",
        ]));
        set("outdoors", "wudangfy");
        set("objects", ([
                __DIR__"npc/xiaotong" : 2,
                __DIR__"npc/oldman" : 2,
        ]) );
        set("coor/x",100);
        set("coor/y",-50);
        set("coor/z",0);
        setup();
replace_program(ROOM); 
}      
