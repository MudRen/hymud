#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"藏宝图"NOR, ({ "map" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张皱皱的羊皮藏宝图，你可以读一读（ｒｅａｄ）．\n");
          } 
        
}
void init()
{
        if(environment(this_object())==this_player())
        add_action("do_read","read");
        add_action("do_go","go");
} 
int do_read(string arg)
{
        object me;
        mapping exits;
        string *dirs;
        string thisdir;
        if(arg != "map") return 0;
        me=this_player();
        if(find_call_out("markit")== -1)
        call_out("markit",random(60)+20,me);
        if (query("already"))
        {
                return notify_fail("孔雀图中的东西似乎被别人得到了。\n");
        }
        if( !mapp(exits = environment(me)->query("exits")) ) 
        {
                tell_object(me,"孔雀图就埋在附近！\n");
                return 1;
        }
        dirs = keys(exits);
        thisdir = dirs[random(sizeof(dirs))];
        set("thisdir",thisdir);
        tell_object(me,"孔雀图似乎应该在"+thisdir+"的方向！\n");
        return 1;
} 
int do_go(string arg)
{
        if(arg==query("thisdir"))
        this_player()->add_temp("going",1);
        return 0;
}
int markit(object me)
{
        object design;
        if(me->query_temp("going") <= 10 || environment()!=me) return 1;
        if(!query("already"))
        {
        design = new("/d/tieflag/obj/design");
                tell_object(me,"\n你一弯腰，从『藏宝图』所指示的地方挖出孔雀图！\n");
                design->move(me);
                me->delete_temp("going");
                set("already",1);
        }
        return 1;
}    
