//yudian.c
inherit ROOM;

void create()
{
        set("short","玉器店");
        set("long", @LONG
这是一家波斯商人开的玉器店，门脸不大却十分出名。店主是一位老
商人，很久很久以前就来到了中国，虽说是金发碧眼的外国人，却能说一
口流利的中国话。在这里你能买到各种名贵的珠宝，你也可以拿中国的古
董来这里估价或出售，价钱一般来说还比较公道。
LONG
        );
        set("exits", ([ 
                "north"         :       __DIR__ "lroad4",
                ])
        );
//      replace_program(ROOM);
        setup();
}

