//Writen by lnwm
//lroad1.c

inherit ROOM;

void create()
{
    set("short", "小泥路");
    set("long", @LONG
一个小村子的入口，这里位于青城山的后山，向西你能望见青城山翠
绿的山色。向北透过重重的绿色构成的屏障，你隐隐能看到几间小茅屋的
屋顶.时而有几缕炊烟袅袅而上，给这里凭添了几分幽静。
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"     :        "/d/xinan/qingcheng_shan",
//        "west"      :       __DIR__ "houshan",
        "north"     :       __DIR__ "lroad2",
        ]));
    set("objects",([
                __DIR__ "npc/kid" : 1,
                  ])                  
    );
    setup();
    replace_program(ROOM);
}


