// 楚州地图 /d/city/chuzhou/npc/obj/map_chuzhou.c

inherit ITEM;

void create()
{
    set_name("楚州地图", ({ "chuzhou ditu", "map" }));
    set_weight(20);
    set( "long", @LONG
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                                                                      ┃
┃                         楚  州  地  图                               ┃
┠───────────────────────────────────┨
┃                                                                      ┃
┃                  文通塔 北门     青云路—上清宫                      ┃
┃                       ＼ ｜       ／                                 ┃
┃           宅院—驸马巷 天宝路—北市—钱庄                            ┃
┃                    ｜         ／                                     ┃
┃             码头—西市—镇淮楼  客店   衙门—牢房                    ┃
┃                    ｜         ＼ ｜     ｜                           ┃
┃                  新罗坊 胯下桥—东市—炎兴街—东门                   ┃
┃                           ｜     ｜     ｜                           ┃
┃                    茶肆—南市  杂货铺 韩信祠                         ┃
┃                         ／  ＼                                       ┃
┃                      赌场   升平街—弄玉坊                           ┃
┃                               ｜                                     ┃
┃                       当铺—物华街—扬威镖局—马厩                   ┃
┃                                ＼                                    ┃
┃                                南门—龙光阁                          ┃
┃                                                                      ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛                                   
LONG
    );    
    if (clonep())
        set_default_object(__FILE__);
    else {
        set( "unit", "张" );
        set( "value", 50 );
    }
}
