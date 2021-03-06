//citang.c 祠堂
//Hydra

inherit ROOM;

void create()
{
    set("short","祠堂");
    set("long", @LONG
一所祠堂，大厅上供着无数神主牌位，梁间悬满了大匾，写着族中有过功名
之人的名衔。厅上四五枝红烛点得明晃晃地，居中坐着一人，折扇轻挥，看来他
就是那个采花大盗了。
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
        return notify_fail("飞贼拦住你，想跑吗，先过了老爷这一关再说！\n");
    }
    return ::valid_leave(me,dir);
}
