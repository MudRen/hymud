 inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�������������ι��ţ�ǰ����һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е�
���������һЩ�滨��ݡ��������������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ���
�㼸��Ҫ�������˲Ų��Ử����
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlong",
                "north" : __DIR__"jlonglang2",
        ]));
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",0);
        setup();
} 
/*
int valid_leave(object me, string dir)
{
    if(  dir == "north" && (string)me->query("gender") != "����")
        return notify_fail("��������ԡ�ң�����ȥ��ʲô��\n");
    return 1;
} 
*/
