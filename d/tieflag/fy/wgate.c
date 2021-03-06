 inherit ROOM;
void create()
{
        set("short", "风云西城门");
        set("long", @LONG
西城门阁矮小而破旧，守城卫兵斜戴着红樱帽，搂着长枪在打瞌睡。也许因为
西城区所住皆贫困撩倒之徒，这里的治安和卫生都不是很好。狂风掠过之时，满地
垃圾随风飞舞，夜幕降临之后，惨号和狞笑声此起彼伏。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/tieflag/fycycle/fywest",
  "east" : __DIR__"wcloud5",
  "up"   : "/d/tieflag/fywall/wupgate",
]));
        set("objects", ([
        __DIR__"npc/wind_solider": 2, 
        __DIR__"npc/cloud_solider": 2, 
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",-60);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me)){
        if( dir == "east" && ob=present("garrison", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
                        return notify_fail(ob->name()+"向你喝道：不可手持兵器入风云城！\n"); 
                }
        } 
        if( dir == "up" && ob=present("garrison", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(((string)(inv[i]->name()) == "风云战甲") && (int)(inv[i]->query("equipped")))
                        return 1; 
                }
                return notify_fail(ob->name()+"向你喝道：闲杂人等不可上登护城墙！\n");
        }
                tell_room("/d/fywall/wupgate",
                "城墙下" + me->name() + "往" + to_chinese(dir) + "离开了。\n");
        
        
         if( me->query("class")== "shenshui"||me->query("class")== "knight"||
            me->query("class")== "bat"||me->query("class")== "wolfmount")
            {
                if( dir == "east" && ob=present("garrison", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(((string)(inv[i]->name()) == "风云战甲") && (int)(inv[i]->query("equipped")))
                        return 1; 
                }
                return notify_fail(ob->name()+"大声喝止：皇上有令，番帮野民，不得入城！\n");
        }
                tell_room("/d/fywall/wupgate",
                "城墙下" + me->name() + "往" + to_chinese(dir) + "离开了。\n");
        }
        return 1;
        
        }
        else return 1;
}  
