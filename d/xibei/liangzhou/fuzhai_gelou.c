//fuzhai_gelou.c ��¥
//Hydra

inherit ROOM;

void create()
{
    set("short","��¥");
    set("long", @LONG
Ư����С��¥���������ż�С��ס�ĵط���
LONG
    );
    set("exits", ([ 
        "up"            :       __DIR__"fuzhai_gelou2",
        "south"         :       __DIR__"fuzhai_zoulang2",
    ]) );

    set("objects",([
        __DIR__"npc/yahuan"     :   1,
    ]) );
        setup();
}

int valid_leave( object me,string dir )
{
    object ob;
    if ( dir == "up" && !me->query_temp("����/can_enter_gelou"))
    {
        if(objectp(ob=present("ya huan",environment(me)))
         && ob->can_act() )
            return notify_fail("Ѿ����ס���㣬������С��Ĺ뷿������ô�Ҵ�����\n");
        else
            return notify_fail("�˼ҵĹ뷿��Ҳ������\n");
    }
    return ::valid_leave(me,dir);
}
