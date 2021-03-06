 // XXDER@FY
inherit ROOM;
void create()
{
        set("short", "槐树上");
        set("long", @LONG
树很高，你爬到了树顶后发现院墙只到树的一半多一点，在这里你终于
看到了天空。你四周都是槐树茂密的枝叶，你看不到树下面的情况，但在这
里你可以清楚地看到前院的练武场，还有大厅的一切。
LONG
        ); 
   set("item_desc", ([
   ]) ); 
   set("objects", ([
      __DIR__"obj/nest": 1,

   ]) ); 
   set("outdoors", "qingping");
        set("coor/x",170);
        set("coor/y",2000);
        set("coor/z",20);
   setup();
} 
void init()
{
   add_action("do_search", "search");
   add_action("do_jump", "jump");
   add_action("do_look", "look");
} 
int do_look(string arg)
{
        if(arg != "nest") return 0;
        if(this_player()->query_temp("marks/foundnest", )) return 0;
        write("你要看什麽？\n");
        return 1;
}
int do_jump(string arg)
{
   object me, room; 
   me = this_player();
   if(!arg || arg != "down") return 0;
   message_vision("$N从树上跋身而起，轻飘飘地落到了院墙上。\n\n", me);
   room = find_object(__DIR__"wall"); 
   if(!objectp(room)) room=load_object(__DIR__"wall");
      me->move(room);
      message("vision",me->name()+"轻飘飘地落到了院墙上。\n", environment(me), me); 
   return 1;
} 
int do_search(string arg)
{
   object  me;
  
   me = this_player();
   if (!arg || arg != "tree" && arg != "树") return 0;
   tell_object(me, "你仔细的查看了树冠，在一个分枝上发现一个鸟窝。\n"); 
   me->set_temp("marks/foundnest", 1);
   return 1;
} 
void reset()
{
   object *inv;
   object item1, item2, nest;
   ::reset(); 
   nest = present("nest", this_object());
   inv = all_inventory(nest);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/egg");
      item1->move(nest);
      item2 = new(__DIR__"obj/key");
      item2->move(nest);
   }
}     
