//yizhan1.c

inherit ROOM;

void create()
{
        set("short","驿站");
        set("long", @LONG
凉州城的驿馆，供来往的官差休息打尖，院落不大，只有小小的几间
厢房,但却人来人往十分繁忙。南首有一个马厩.  差人到了凉州城若要继
续赶路，多半要换一下坐骑, 凉州是盛产良马之地, 在这里换上的坐骑多
半错不了。
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "lroad1",
                ])
        );
//      replace_program(ROOM);
        setup();
}

