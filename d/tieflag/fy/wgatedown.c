 inherit ROOM;
void create()
{
        set("short", "西护城河");
        set("long", @LONG
浅浅的护城河水道因为日渐疏忽，已经只剩下湿润的泥土了。河道边上有
个隧道入口，黑黑不见尽头。入口上面用有几个似乎是一阳指所致的大字，字
体古朴有力，可惜词不达意，「初来是客，小处随便」。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"up" : "/d/tieflag/fy/wgate",
  "enter" : __DIR__"wnewbie1",
  
]));
        set("objects", ([
  //      __DIR__"npc/wind_solider" : 2,
    //    __DIR__"npc/cloud_solider": 2, 
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-60);
        set("coor/z",-10);
        
        setup();
}

int valid_leave(object me, string dir)
{
        if(dir == "enter"){
    if( me->query("mark/newbie")< 300 && (int) me->query("combat_exp")<300000)
                {me->add("mark/newbie",1);
                return 1;               }
        else  return notify_fail("一股气劲将你推了出来，一把悠悠的声音传来：自力更生，丰衣足食！\n");
        }
        return 1;
}  
