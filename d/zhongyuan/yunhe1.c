// /d/map/zhongyuan/yunhe1.c
// by lala, 1997-12-11
inherit ROOM;

void create()
{   
    set("short","真楚运河边");
    set("long",@LONG
运河继续奔流向前，河里的船只越发的多起来，不但有运盐和米的漕船和官
家的官船，还有不少附近的村民驾驶着小船，这些小船和大船争道，河面上充斥
着船夫的吆喝声和叫骂声，居然还夹杂着一两声孩子的哭喊声。本来碧绿清澈的
河水到这里有些浑浊，水面上漂浮着一些杂物和船头激起的白沫。
    运河此刻流入了宝应县的境内，周围星罗棋布着大大小小的湖泊，其中最大
的射阳湖和白马湖象两面有名的扬州铜镜一样镶嵌在淮南大地上。            
LONG );
    set("exits",([
        "northwest" : __DIR__"yunhe0",
        "south"     : __DIR__"yunhe2",
    ]));                    
    set("outdoors","zhongyuan");
    setup();
}

