//tianjing2.c.天井
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"天井"NOR);
    set("long",@LONG
高台寺的天井，这是一个非常宽阔的广场。正中有一口水井，水平如镜，甘
美如饴，乃是全寺有名的清水井。广场乃是有无数块巨大的花岗岩铺就，上面镌
刻着麒麟、玄龟、松鹤等瑞兽，形态逼真动人。前面摆了一个香台，上面立着一
个有二人来高的青铜大香炉，有几名僧人和香客正在那儿虔诚膜拜。远远的传来
高台寺晚课的钟声，伴随着僧众们整齐的详和的讼经声，你觉得好象身入天界，
摆脱了尘事间的一切烦恼。
LONG);
   
    set("exits",([
        "north"   : __DIR__"dadian2",
        "east"    : __DIR__"xiaoyuan1",
        "west"    : __DIR__"xiaoyuan2",
    ]));
    set("outdoors","xingqing");
    setup();
}

