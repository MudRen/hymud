//citang.c ����
//Hydra

inherit ROOM;

void create()
{
    set("short","����");
    set("long", @LONG
һ�����ã������Ϲ�������������λ�����������˴��ң�д�������й�����
֮�˵����Ρ���������֦���������λεأ���������һ�ˣ�������ӣ�������
�����Ǹ��ɻ�����ˡ�
LONG
    );
    set("exits", ([ 
        "south"         :       "/d/xibei/lianglu8",
    ]) );
    set("objects",([
        __DIR__"npc/rascal"      :   1,
    ]) );

        setup();
}

int valid_leave( object me,string dir)
{
    if ( present("fei zei",environment(me)) && dir == "south")
    {
        return notify_fail("������ס�㣬�������ȹ�����ү��һ����˵��\n");
    }
    return ::valid_leave(me,dir);
}
