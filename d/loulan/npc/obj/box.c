 inherit ITEM;
void create()
{
        set_name("樟木镶金箱", ({ "woodcase"}) );
        set_weight(50000); 
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "个");
                set("long", "一口极为珍贵的樟木镶金箱，八只角上，都包着黄金，锁环自然也是黄金\n的，上面锁了一把巨大黄金锁．你可以试试拗断（niu）它。\n");
                set("value", 1);
        }
        
} 
int is_container() { return 1; } 
void init()
{
        add_action("do_niu","niu");
} 
int do_niu(string arg)
{
        object bai;
        object me;
        me = this_player();
        if(!arg="woodcase"||!arg="樟木镶金箱") return 0;
        message_vision("$N试着拗了拗樟木镶金箱的黄金锁...\n",me);
        if(!query_temp("been_get") && me->query_temp("marks/knight_kill_wang"))
        {
                if (me->query("force_factor") < 50)
                {
                        return notify_fail("你使出全身的力量，但是黄金锁丝毫未损。\n");
                }
                else
                {       
                        bai = new("/d/loulan/npc/bai");
                        bai->move(this_object());
                        message_vision("$N手腕用力，黄金锁嘎蹦而断．樟木镶金箱盖缓缓地自动开启．．\n",me);
                        set_temp("been_get",1);
                   this_object()->set("closed",0);
                }
        }
        else
        {
                return notify_fail("你没有办法拗断黄金锁，看来只好放弃了。\n");
        }
        return 1;
}    
