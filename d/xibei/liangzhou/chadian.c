//chadian.c

inherit ROOM;

void create()
{
        set("short","��Ҷի");
        set("long", @LONG
һ����ԭ�˿��Ĳ�Ҷ���ӣ���һ���꣬���ŵ�һ��ŨŨ�Ĳ��㡣����
��æ�Ž��մӽ��а���Ĳ�Ҷ��װ�ڲ�ͬ��С�Ĺ��������û�������
����������ǽ��һ����ʣ�����һ�ų��������ӣ������м���ż��ײ��
�����������������Ʒһ�����޴����ٺ͵�����һ�Ĳ辭��
LONG

        );
        set("exits", ([ 
                "north"         :       __DIR__ "lroad5",            
                ])
        );
        set( "objects",([
            __DIR__"npc/waiter":1,
        ]) );
//      replace_program(ROOM);
        setup();
}

