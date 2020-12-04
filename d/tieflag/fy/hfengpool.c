 inherit ROOM;
#include <room.h> 
void create()
{
        set("short", "枫叶泉");
        set("long", @LONG
风云城中的枫叶泉是方圆五百里最著名的一口温泉。水温适中，泉水呈淡红,
故而得名枫叶。它不但有去腐生肌的奇效，据说还有延年益寿的妙用。武林第一
美人林仙儿每天都以此泉水浣面（ｗａｓｈ），来保持她如花似玉的容貌。
LONG
        );
        set("exits", ([
                "west" : __DIR__"hfenglang3",
        ]));
        set("objects", ([
                __DIR__"npc/xianu": 2,
        ]) );
        set("outdoors", "fengyun");
        set("no_fly", 1);
        set("coor/x",45);
        set("coor/y",45);
        set("coor/z",0);
        setup();
        create_door("west", "檀木门", "east", DOOR_CLOSED); 
} 
void init()
{
        add_action("do_jump", "wash"); 
} 
int do_jump()
{
        object me;
        int wait;
        me = this_player();
        me->add_temp("jumpinpool",1);
        wait = random( 50 - (int)me->query("con")) + 4 * (int)me->query_temp("jumpinpool");
        if ( wait <= 20) wait = 21;
        message_vision("$N缓步走入泉水中．\n",me);
        tell_object(me,"你感到全身无比的舒泰．．\n");
        remove_call_out("curehimup");
   call_out("curehimup", wait, me);
        if(!me->query("宿命B/武当_枫叶") && !random(10))
                call_out("give_maple_leaf",5,me);
return 1;
}  
int give_maple_leaf(object me)
{
        object leaf;
        
        if(!me || !present(me,this_object()))
                return 1;
        tell_object(me,"一片红红的枫叶飘了过来，你好奇的将它拾了起来。\n");
        leaf=new("/d/tieflag/fy/obj/mapleleaf");
        leaf->move(me);
        return 1;
}  
void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
        {
        message_vision("$N的精气神全恢复了！！\n", me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        if(!random(30)) me->delete_temp("jumpinpool");
        }
return;
}   
