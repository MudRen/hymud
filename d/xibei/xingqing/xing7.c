// room: xing7.c
//by lnwm 97-09-12


inherit ROOM;

void create()
{
        set("short", "黄河沿岸");
        set("long", @LONG
你已来到兴庆府的西门--西化门, 城门楼上, 全副武装的西夏士兵精神抖擞
地来回巡视着. 因为西夏王元昊以武为强国之本, 所以西夏军是组织严明, 战斗
力非常强劲的部队. 城门边站着一队身着战甲, 身背腰刀的西夏兵丁, 他们警惕
地注视着每一个过往的行人. 
LONG
        );
    set("exits", ([ 
                "southwest"     :       __DIR__ "xing6",
                "northeast"     :       __DIR__ "door4",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


