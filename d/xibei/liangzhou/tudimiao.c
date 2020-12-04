//tudimiao.c

inherit ROOM;

void create()
{
    set("short","土地庙");
    set("long", @LONG
一个破旧的土地庙，由于年久失修，已经残破不堪了。庙对门靠墙处，供奉
着一尊土地菩萨，前面的供桌上面布满了灰尘。这里曾经香火旺盛，但不知为什
么这几年衰败了下来。现在这里成了乞丐避风取暖的地方了。
LONG
    );
    set("exits", ([ 
        "north"         :       __DIR__ "lroad1",
    ]) );
        
    set("objects",([
        __DIR__"npc/beggar"     :   1,
    ]) );
        
    setup();
}

