//Writen by lnwm
//lroad5.c

inherit ROOM;

void create()
{
    set("short", "小泥路");
    set("long", @LONG
村子很小，你发现没走两步就到了路的尽头，这里也基本是村子的尽
头，北面又是山坡，也是青城山的一部分，山坡下是一个小树林，密密丛
丛地看不到尽头。紧靠着树林有一座小茅屋，看起来好象没人住的样子。
西北边也有一家农舍.
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"         :       __DIR__ "lroad4",
        "north"         :       __DIR__ "shulin",
        "northeast"     :       __DIR__ "maowu",
        "northwest"     :       __DIR__ "nongjia1",              
                ]));
    
    setup();
    replace_program(ROOM);
}


