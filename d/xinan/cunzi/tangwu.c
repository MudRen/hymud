//Writen by lnwm
//tangwu.c

inherit ROOM;

void create()
{
        set("short", "堂屋");
        set("long", @LONG
窗明几净的一间大屋子，屋内摆设井井有条，砖石所铺的地下一尘不
染。屋里也没有人，看来勤快的男女主人都出去工作了。这样的农家在这
一带已经算是家境相当好的。屋内正中还摆着一张古色古香的八仙桌，可
能是男主人的传家宝.
LONG
        );
        set("exits", ([
            "south"         :       __DIR__ "yuanluo",
                ]));
        
        setup();
}



