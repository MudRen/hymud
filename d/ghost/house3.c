 inherit ROOM;
void create()
{
        object          con, item; 
        set("short", "ʯ��");
        set("long", @LONG
�������ѵ�С·��ͷ����һ����ʽ���ϵ�ʯ�ݣ�����ĳ���Ҳͬ
�����ӣ�������������ɭɭ�ĸо������濿ǽ��һ����ᣵʹ������裬
����ʲô������û�С�
LONG
        );
        set("exits", ([
                "south" : __DIR__"groad6",
        ]));
        set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/yexue" : 1,
        ]));
        set("coor/x",-1100);
        set("coor/y",-90);
        set("coor/z",-20);
        setup();
replace_program(ROOM); 
}     
