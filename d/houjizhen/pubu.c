// pubu.c
// by dicky

inherit ROOM;
#include <ansi.h>
#include <command.h>
string look_chi();

void create()
{
        set("short",HIW "瀑布" NOR);
        set("long", @LONG
山中小溪逆流而上，眼前赫然出现一条飞泻而下的瀑布。这是天山的水融
化后，经过河流流出后，行至此处，陡然从悬崖峭壁上跌水直泻，犹如一条白
练从天而降，两条玉龙般的水柱冲向幽深谷底，溅起几丈高的白浪，恰似云倾
雪翻，钟鼓雷鸣一般。由于水势湍急且此地潮暖，因此并不结冰。
LONG
);
        set("outdoors", "houjizhen");
        set("item_desc",([            
            "pool" : (: look_chi :),
        ]));
        set("exits", ([ 
          "eastdown" : __DIR__"xiaoxi1",
          ]));


        setup();
}

void init()
{
        add_action("do_jump", "xi");
}

int do_jump(string arg)
{
        int i, j;
        object me, room, *ob, *inv;
        me = this_player();

        if (!(room = find_object(__DIR__"chi")))
              room = load_object(__DIR__"chi");
        ob = all_inventory(room);
        j = sizeof(ob);

	if(!living(me) ) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");

	if( !arg || arg == "" || arg != "pool" )
		return notify_fail("你要干什么？\n");
        
	if((me->query_encumbrance()*20) > me->query_max_encumbrance() && !wizardp(me))
		return notify_fail("你身上的东西太多了！\n");




        tell_object(me, GRN "你走到池边，除去衣物，便要跳进浴仙池。\n"NOR);
        tell_room(environment(me), me->name()+"转身走到池边，好象是要跳进池里游水去。\n", ({ me }));
       if(j>0){
       if(j>1)
            return notify_fail(HIR"你突然发现池水中有人，而且还不止一个，你连忙退了回来。\n"NOR);
            tell_object(me, "你突然发现池水中有人！\n");
               for(i=0; i<sizeof(ob); i++) {
                 if(!living(ob[i])) continue;
                 if(me->query("gender") == ob[i]->query("gender")){
                   if(me->query("gender") == "女性")
                       tell_object(me, "定眼一看，原来也是个女子。你轻轻一笑，纵身跳下水去。\n");
                   if(me->query("gender") =="男性")
                       tell_object(me, "定眼一看，原来也是个男子。你轻轻一下，纵身跳下水去。\n");
                   tell_room(environment(me), me->name()+"转身走到池边，好象是要跳进池里游水去。\n", ({ me })); 
                   me->move(__DIR__"chi");
                   return 1;
                   }
                 else{ 
                   tell_object(me, "定眼一看，原来对方是位。。。。你脸上一红，连忙穿上衣服退了回来。\n");
                   tell_room(environment(me), me->name()+"转身走到池边，顿了一顿，又退了回来。\n", ({ me })); 
                   }
                }
        return 1; 
        } 
    me->move(__DIR__"chi");
    return 1;
}

string look_chi()
{
	object me, room;
	me = this_player();
	if (!(room = find_object(__DIR__"chi")))
	     room = load_object(__DIR__"chi");

	return "别人在洗澡，你跑这里看什么看？也不害臊！";
}