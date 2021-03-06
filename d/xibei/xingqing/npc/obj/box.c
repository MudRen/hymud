//box.c.剑匣
//data:1997.12.28
//by dan

#include <ansi.h>
#include <localtime.h>

inherit ITEM;

void create()
{
        seteuid(getuid());
        seteuid(geteuid());
        set_name("剑匣", ({ "jian xia", "xia", "box" }));
        set_weight(3000);
        set_max_encumbrance(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
      set("long", "一只样式古朴的石匣，上刻有<<剑匣>>二字,盒盖(top)上很特别有几个按纽....\n"+
              "------------------------------------------------------------\n"+
              "|                                                          |\n"+
              "|       "+BLINK HIY"金"NOR+"      "+BLINK HIC"木"NOR+"      "+BLINK HIB"水"NOR+"      "+
                    BLINK  HIR"火"NOR+"      "+BLINK YEL"土"NOR+"      "+BLINK HIM"相火"NOR+"       |\n"+
              "|                                                          |\n"+
              "------------------------------------------------------------\n");
                set("value", 80);
                set("dan",0);
                set("dan_number",1);
         }
}

int is_container() { return 1; }

void init()
{
    add_action("do_an","an");
}

int do_an( string arg )
{
    object me,ob,room;
    int time,hour,i,j,k;
    mixed *ltime;
    time = time();
    ltime = localtime( time*60 );
    hour = ltime[LT_HOUR];
    me = this_player();
    ob = this_object();
    room = environment( me );
    j = ob ->query("dan");
    if ( !arg )
    return notify_fail("你按了一下盒子，很结实，达不开的说....\n");
    if ( arg != "金" && arg != "水" && arg != "木" && arg != "火" 
          && arg != "土" && arg != "相火" )
    return notify_fail("你瞎按些什么.....?\n");
    j = j +1;
    k = 0;
    if ( arg == "金" && ( hour == 1||hour == 7||hour == 13||hour ==19))
    k = 1;
    if ( arg == "木" && ( hour == 2||hour == 8||hour == 14||hour ==20))
    k = 1;
    if ( arg == "水" && ( hour == 3||hour == 9||hour == 15||hour == 21))
    k = 1;
    if ( arg == "火" && ( hour == 4||hour == 10||hour == 16||hour == 22))
    k = 1;
    if ( arg == "土" && ( hour == 5||hour == 11||hour == 17||hour == 23))
    k = 1;
    if ( arg == "相火" && ( hour == 6||hour == 12||hour == 18||hour ==24 ))
    k = 1;
    if ( k == 0 )
    {
         ob ->set("dan",0);
         return notify_fail("盒子上的按纽似乎按不动的说....\n");
    }
    if ( hour != j )
    {
         ob-> set("dan",0);
         return notify_fail("盒子上的按纽一松盒盖似乎松动了一些,但一摸一动不动....\n");
    }   
    write("盒盖吱吱一声响，似乎有些松动.....\n");
    if ( j < 24 )
    {
         ob ->set("dan",j);
         return 1;
    }
    ob ->set("dan",0);
    if( ob->query("dan_number")== 0 )
    return notify_fail("剑匣一下迸开，里面什么也没有....\n");
    write("剑匣一下迸开，里面掉出一把宝剑.....\n");
    new(__DIR__"jian4")->move( room );
    ob ->set("dan_number",0);
    return 1;     
}    

